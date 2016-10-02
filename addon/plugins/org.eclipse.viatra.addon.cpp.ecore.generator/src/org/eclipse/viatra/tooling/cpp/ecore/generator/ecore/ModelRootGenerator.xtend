package org.eclipse.viatra.tooling.cpp.ecore.generator.ecore

import java.util.List
import org.eclipse.emf.ecore.EClass
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.fs.FileSystemAccess
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.ClassHelper
import org.eclipse.emf.ecore.EPackage
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.NamespaceHelper
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper
import org.eclipse.emf.ecore.EClassifier
import org.eclipse.emf.ecore.EEnum
import org.eclipse.emf.ecore.EDataType

class ModelRootGenerator {
				
	static def generateModelRoot(List<EPackage> packages, FileSystemAccess fsa) {
		fsa.generateFile("ModelRoot.h", compileHeader(packages))
		fsa.generateFile("ModelRoot.cpp", compileSource(packages))
	}

	static def compileHeader(List<EPackage> packages) '''
		
		#ifndef _MODELROOT__H__
		#define _MODELROOT__H__
		
		#include<map>
		#include"Viatra/Query/Model/ModelElement.h"
		#include"Viatra/Query/Matcher/ModelIndex.h"
		
		
		namespace Viatra {
			namespace Query {
				namespace Model {
					class ModelRoot
					{
					public:
						ModelRoot(const char * configjson);
						~ModelRoot()
						{
							FreeAllModelElement();
						}
		
						Viatra::Query::Model::ModelElement* findModelElementByID(int32_t id)
						{
							return modelElements.at(id);
						}
		
					private:
						void FreeAllModelElement();
						std::map<int, Viatra::Query::Model::ModelElement*> modelElements;
		
					};
		
				};
		
				template<typename T>
				struct ModelIndex<T, Viatra::Query::Model::ModelRoot> {
					static const std::list<T*>& instances(const Viatra::Query::Model::ModelRoot* modelRoot)
					{
						return T::LocalImplementation::Instances();
					}
				};
			}
		}
		
		#endif
		
	'''
	
	static def compileSource(List<EPackage> packages) '''
		
		#include "ModelRoot.h"
		
		#include<fstream>
		«FOR pack : packages»
			#include"«pack.name»_def.h"
			#include"«pack.name»/EnumHelper.h"
		«ENDFOR»
		
		#define PICOJSON_USE_INT64
		#include<picojson.h>
		
		
		using namespace Viatra::Query::Model;
										
		ModelRoot::ModelRoot(const char * configjson)
		{
			try {
				std::ifstream ifs(configjson);
				picojson::value root;
				std::string err = picojson::parse(root, ifs);
				if (!err.empty()) {
					throw err;
				}
		
				auto localnode = root.get("localnode").get<std::string>();
		
				auto elements = root.get("model").get<picojson::value::array>();
		
				// Creating class instances
				for (auto & elem : elements)
				{
					bool is_remote = elem.get(":node").get<std::string>() != localnode;
					std::string type = elem.get(":type").get<std::string>();
					int id = static_cast<int>(elem.get(":id").get<double>());
					if (modelElements.find(id) != modelElements.end())
						throw std::string("Identifier is already used");
		
					auto node = nullptr;
		
					«FOR pack : packages»
						«FOR eclass : pack.eContents.filter(EClass)
					»if (type == "«eclass.name»")
					«val helper = new ClassHelper(eclass)»
					«val namespaceHelper = NamespaceHelper::getNamespaceHelper(eclass)»
							modelElements[id] = is_remote
								? dynamic_cast<ModelElement*>(new ::«namespaceHelper.toString("::")»::«helper.genRemoteName»(id, node))
								: dynamic_cast<ModelElement*>(new ::«namespaceHelper.toString("::")»::«helper.genLocalName»(id));
						else «ENDFOR»
					«ENDFOR»

						throw std::string("ModelElement type cannot be read");

				}		
				
				// Filling class instances with data
				for (auto & elem : elements)
				{
					bool is_remote = elem.get(":node").get<std::string>() != localnode;
					std::string type = elem.get(":type").get<std::string>();
					int id = static_cast<int>(elem.get(":id").get<double>());
					auto modelElement = modelElements.find(id)->second;
				
					if( !is_remote )
					{
						switch( modelElements[id]->get_type_id() ){
							«FOR pack : packages»
								«FOR eclass : pack.eContents.filter(EClass)»
									«val helper = new ClassHelper(eclass)»
									case «helper.FQN»::type_id :
										{	
											auto * modelElement = dynamic_cast<«helper.FQN»*>(modelElements[id]);
											picojson::value ref_elem;
											picojson::value attrib_elem;
											picojson::array as_array;
											
											«FOR ref : EClassGenerator::getAllEReference(eclass)»
												«val refHelper = CppHelper::getAssociationHelper(ref)»
												«val refType = ref.EType»
												«val refTypeFQN = CppHelper::getTypeHelper(refType).FQN»
												ref_elem = elem.get("«ref.name»");
												
												«IF refHelper.multiple»
													if( ref_elem.is<picojson::array>() )
													{
														as_array = ref_elem.get<picojson::array>();	
														std::vector<«refTypeFQN»*> as_vector(as_array.size());
														for(int i = 0 ; i < as_array.size() ; ++i)
														{
															int64_t id = as_array[i].get<int64_t>();
															as_vector[i] = dynamic_cast<«refTypeFQN»*>(modelElements[id]);
														}
														modelElement->«refHelper.setterName»(as_vector);
													}
												«ELSE»
													if( ref_elem.is<int64_t>() )
													{
														modelElement->«refHelper.setterName»(
															dynamic_cast<«refTypeFQN»*>(modelElements[ref_elem.get<int64_t>()])
														);
													}
												«ENDIF»
											«ENDFOR»
											«FOR attrib : EClassGenerator::getAllEAttribute(eclass)»
												«val attribHelper = CppHelper::getAttributeHelper(attrib)»
												«val attribType = attrib.EType»
												«val attribTypeFQN = CppHelper::getTypeHelper(attribType).FQN»
												«val jsonType = getJsonType(attribType)»
												attrib_elem = elem.get("«attrib.name»");
												
												«IF attribHelper.multiple»
													if( attrib_elem.is<picojson::array>() )
													{
														auto as_array = attrib_elem.get<array>();	
														std::vector<«attribTypeFQN»*> as_vector(as_array.size());
														for(int i = 0 ; i < as_array.size() ; ++i)
														{
															«IF attribType instanceof EEnum»
																as_vector[i] = EnumHelper<«attribTypeFQN»>::ParseFromString(as_array[i].get<«jsonType»>());
															«ELSEIF attribType.name == "EBoolean"»
																as_vector[i] = as_array[i].get<«jsonType»>() == "true";
															«ELSEIF attribType.name == "EChar"»
																as_vector[i] = as_array[i].get<«jsonType»>()[0];
															«ELSE»
																as_vector[i] = as_array[i].get<«jsonType»>();
															«ENDIF»
														}
														modelElement->«attribHelper.setterName»(as_vector);
													}
												«ELSE»
													if( attrib_elem.is<«jsonType»>() )
													{
														«IF attribType instanceof EEnum»
															modelElement->«attribHelper.setterName»( EnumHelper<«attribTypeFQN»>::ParseFromString(attrib_elem.get<«jsonType»>()) );
														«ELSEIF attribType.name == "EBoolean"»
															modelElement->«attribHelper.setterName»( attrib_elem.get<«jsonType»>() == "true" );
														«ELSEIF attribType.name == "EChar"»
															modelElement->«attribHelper.setterName»( attrib_elem.get<«jsonType»>()[0] );
														«ELSE»
															modelElement->«attribHelper.setterName»( attrib_elem.get<«jsonType»>() );
														«ENDIF»
													}
												«ENDIF»
											«ENDFOR»
										}
										break;
										
								«ENDFOR»
							«ENDFOR»
						}
					}
				}		
			}
			catch (std::string& str)
			{
				std::cout << str << std::endl;
				FreeAllModelElement();
				throw;
			}
			catch (std::exception& ex)
			{				
				std::cout << ex.what() << std::endl;
				FreeAllModelElement();
				throw;
			}
			catch (...)
			{				
				std::cout << "Unexpected exception" << std::endl;
				FreeAllModelElement();
				throw;
			}
		}
		
		void ModelRoot::FreeAllModelElement()
		{
			for (auto & ptr : modelElements)
			{
				delete ptr.second;
			}
		}

	'''
	
	static val PRIMITIVE_TO_JSONTYPE = #{
		"EString" -> "::std::string",
		"EInt" -> "int64_t",
		"ELong" -> "int64_t",
		"EDouble" -> "double",
		"EFloat" -> "double",
		"EShort" -> "int64_t",
		"EChar" -> "std::string",
		"EBoolean" -> "std::string"
	}
	
	def static getJsonType(EClassifier classifier) {
		if(classifier instanceof EEnum) 
			return "::std::string"
		if(classifier instanceof EClass) 
			return "int64_t"
		if(classifier instanceof EDataType) 
			return PRIMITIVE_TO_JSONTYPE.get(classifier.name)
		throw new Exception("Problem at getJsonType");
	}
	
}