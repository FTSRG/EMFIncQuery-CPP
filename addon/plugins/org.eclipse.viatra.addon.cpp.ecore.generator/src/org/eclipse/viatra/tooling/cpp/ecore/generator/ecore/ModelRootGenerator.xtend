package org.eclipse.viatra.tooling.cpp.ecore.generator.ecore

import java.util.List
import org.eclipse.emf.ecore.EClass
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.fs.FileSystemAccess
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.ClassHelper
import org.eclipse.emf.ecore.EPackage
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.NamespaceHelper
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper

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
						return T::LocalImplementation::_instances__x__x__x__x__x__x__x;
					}
				};
			}
		}
		
		#endif
		
	'''
	
	static def compileSource(List<EPackage> packages) '''
		
		#include "ModelRoot.h"
		
		#include<fstream>
		#include<picojson.h>

		«FOR pack : packages»
			«val namespaceHelper = NamespaceHelper::getNamespaceHelper(pack)»
			#include"«namespaceHelper.toString("_")»_def.h"
		«ENDFOR»
		#include<Viatra/Query/Model/ModelElement.h>
		
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
							modelElements[id] = is_remote
								? dynamic_cast<ModelElement*>(new «helper.genRemoteName»(id, node))
								: dynamic_cast<ModelElement*>(new «helper.genLocalName»(id));
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
						switch( EPackage )
						«FOR pack : packages»
							«FOR eclass : pack.eContents.filter(EClass)
						»if (type == "«eclass.name»")
						«val helper = new ClassHelper(eclass)»
							{	
								auto * modelElement = dynamic_cast<«helper.genInterfaceName»*>(modelElements[id]);
								«FOR ref : EClassGenerator::getAllEReference(eclass)»
									«val refHelper = CppHelper::getAssociationHelper(ref)»
									«refHelper.setterName»()
									elem.get<int32_t>("«ref.name»");
									if(  )
										modelElement -> «refHelper.setterName»(«value»);
									«IF refHelper.multiple»
									
									«ELSE»
									
									«ENDIF»
								«ENDFOR»
								«FOR attrib : EClassGenerator::getAllEAttribute(eclass)»
									«val attribHelper = CppHelper::getAttributeHelper(attrib)»
									«IF attribHelper.multiple»
									
									«ELSE»
									
									«ENDIF»
								«ENDFOR»
							}
							else «ENDFOR»
						«ENDFOR»
						«/* else */»
							throw std::string("ModelElement type cannot be read");
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
	
}