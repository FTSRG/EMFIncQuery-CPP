/*******************************************************************************
 * Copyright (c) 2014-2016 Robert Doczi, IncQuery Labs Ltd.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Robert Doczi - initial API and implementation
 *******************************************************************************/
package org.eclipse.viatra.tooling.cpp.ecore.generator.ecore

import com.google.common.base.Joiner
import java.util.ArrayList
import java.util.List
import org.eclipse.emf.ecore.EAttribute
import org.eclipse.emf.ecore.EClass
import org.eclipse.emf.ecore.EReference
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.fs.FileSystemAccess
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.NamespaceHelper

import static extension org.eclipse.viatra.query.tooling.cpp.localsearch.util.fs.PathUtils.*

/**
 * @author Robert Doczi
 */
class EClassGenerator {
	
	public static val instanceVariable = "_instances__x__x__x__x__x__x__x";
		
	public static int id = 0;
	
	static def genInterfaceName(EClass clazz) {
		"I"+clazz.name
	}
	
	static def genRemoteName(EClass clazz) {
		"Remote"+clazz.name
	}
	
	static def genLocalName(EClass clazz) {
		"Local"+clazz.name
	}
	
	
	/**
	 * Returns all the inherited and contained EReference
	 */
	public static def List<EReference> getAllEReference(EClass clazz) {
		var List<EReference> assoc = new ArrayList<EReference>();
		
		assoc += clazz.getEReferences;
		for( parent : clazz.getEAllSuperTypes )
			assoc += parent.getEReferences
			
		return assoc
	}
	
	
	/**
	 * Returns all the inherited and contained EAttribute
	 */
	public static def List<EAttribute> getAllEAttribute(EClass clazz) {
		var List<EAttribute> attrib = new ArrayList<EAttribute>();
		
		attrib += clazz.getEAttributes;
				
		for( parent : clazz.getEAllSuperTypes)
			attrib += parent.getEAttributes;
			
		return attrib
	}
	
		
	static def generateClass(EClass clazz, FileSystemAccess fsa) {
		fsa.generateFile(clazz.name.h, clazz.compileHeader)
		fsa.generateFile(clazz.name.cpp, clazz.compileSource)
	}

	static def compileHeader(EClass clazz) '''
		«val guard = CppHelper::getGuardHelper(Joiner.on('_').join(NamespaceHelper::getNamespaceHelper(clazz)) + '_' + clazz.name)»
		«guard.start»
		
		«val ns = NamespaceHelper::getNamespaceHelper(clazz)»
		#include "«ns.toString("/")»_decl.h"
		
		««« TODO this does not work with if there are multiple Ecore files referenced in model
		«FOR parent : clazz.getEGenericSuperTypes.map[getEClassifier]»
			#include "«NamespaceHelper::getNamespaceHelper(parent).toString("/")»/«parent.name».h"
		«ENDFOR»
		
		#include <string>
		#include <list>
		#include <vector>
		
		#include <Viatra/Query/Model/ModelElement.h>
		#include <Viatra/Query/Model/RemoteElement.h>
		#include <Viatra/Query/Model/LocalElement.h>
		#include <Viatra/Query/Model/IModelElemService.h>
		
		«FOR namespaceFragment : ns»
			namespace «namespaceFragment» {
		«ENDFOR»	
		
		class «clazz.genInterfaceName»;
		class «clazz.genRemoteName»;
		class «clazz.genLocalName»;
		
		«compileInterfaceCode(clazz)»
		
		«compileRemoteClassCode(clazz)»
		
		«compileLocalClassCode(clazz)»
		
		«FOR namespaceFragment : ns»
			} /* namespace «namespaceFragment» */
		«ENDFOR»
		
		«guard.end»
	'''

	
	static def compileInterfaceCode(EClass clazz) '''
		«val List<EReference> assoc = clazz.getEReferences.toList»
		
		class «clazz.genInterfaceName» : 
			«FOR parent : clazz.getESuperTypes»
				public virtual «parent.genInterfaceName»,
			«ENDFOR» 
			public virtual Viatra::Query::Model::ModelElement
		{
		public:
			using RemoteImplementation = «clazz.genRemoteName»;
			using LocalImplementation = «clazz.genLocalName»;
			«clazz.genInterfaceName»(Viatra::Query::Model::id_t id, bool present)
				: ModelElement(id, present)
				«FOR base : clazz.getESuperTypes»
					, «base.genInterfaceName»(id, present)
				«ENDFOR»
			{}
		
			virtual ~«clazz.genInterfaceName»() {}
			static constexpr unsigned short type_id = «id++»;
						
			static constexpr unsigned short get_static_type_id() {
				return type_id;
			}
			
			unsigned short get_type_id() override {
				return type_id;
			}
		
			«FOR a : clazz.getEAttributes»
				«val ah = CppHelper::getAttributeHelper(a)»
				virtual void «ah.setterName»(«ah.cppType» newVal) = 0;
				virtual «ah.returnType» «ah.getterName»() const = 0;
			«ENDFOR»
			
			«FOR a : assoc»
				«val ah = CppHelper::getAssociationHelper(a)»
				virtual void «ah.setterName»(«ah.cppType» newVal) = 0;
				virtual «ah.returnType» «ah.getterName»() const = 0;
			«ENDFOR»
		};
	'''
	
	static def compileRemoteClassCode(EClass clazz) '''
		
		class «clazz.genRemoteName» : 
			public Viatra::Query::Model::RemoteElement, 
			public «clazz.genInterfaceName»
		{
		public:
			«clazz.genRemoteName»(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
			
			virtual ~«clazz.genRemoteName»();
			
			unsigned short get_type_id() override {
				return «clazz.genInterfaceName»::type_id;
			}

			«FOR a : clazz.getAllEAttribute»
				«val ah = CppHelper::getAttributeHelper(a)»
				void «ah.setterName»(«ah.cppType» newVal) override;
				«ah.returnType» «ah.getterName»() const override;
			«ENDFOR»
			
			«FOR a : clazz.getAllEReference»
				«val ah = CppHelper::getAssociationHelper(a)»
				void «ah.setterName»(«ah.cppType» newVal) override;
				«ah.returnType» «ah.getterName»() const override;
			«ENDFOR»
		};
	'''
	
	static def compileLocalClassCode(EClass clazz) '''		
		class «clazz.genLocalName» : 
			public virtual Viatra::Query::Model::LocalElement, 
			public «clazz.genInterfaceName»
		{
		private:
			static std::list<«clazz.genInterfaceName»*> «instanceVariable»;
					
			«FOR a : clazz.getAllEAttribute»
				«val ah = CppHelper::getAttributeHelper(a)»
				«ah.declaration»
			«ENDFOR»
			
			«FOR a : clazz.getAllEReference»
				«val ah = CppHelper::getAssociationHelper(a)»
				«ah.declaration»
			«ENDFOR»
			
		public:
			«clazz.genLocalName»(Viatra::Query::Model::id_t id);
			
			unsigned short get_type_id() override {
				return «clazz.genInterfaceName»::type_id;
			}

						
			virtual ~«clazz.genLocalName»();
			inline static std::list<«clazz.genInterfaceName»*>& Instances()
			{
				return «instanceVariable»;				
			}
		
			«FOR a : clazz.getAllEAttribute»
				«val ah = CppHelper::getAttributeHelper(a)»
				void «ah.setterName»(«ah.cppType» newVal) override;
				«ah.returnType» «ah.getterName»() const override;

			«ENDFOR»
			
			«FOR a : clazz.getAllEReference»
				«val ah = CppHelper::getAssociationHelper(a)»
				void «ah.setterName»(«ah.cppType» newVal) override;
				«ah.returnType» «ah.getterName»() const override;
				
			«ENDFOR»
		};
	'''
	
	static def compileSource(EClass clazz) '''
		#include "«clazz.name».h"
		
		«val ns = NamespaceHelper::getNamespaceHelper(clazz)»
		«val assoc = clazz.getEReferences»
		«FOR includedClass : assoc.map[getEReferenceType].toSet»
			««« TODO this does not work with if there are multiple Ecore files referenced in model
			#include "«NamespaceHelper.getNamespaceHelper(includedClass).toString("/")»/«includedClass.name».h"
		«ENDFOR»
		
		#include <algorithm>
		
		«FOR namespaceFragment : ns»
			namespace «namespaceFragment» {
		«ENDFOR»	
		
		std::list<«clazz.genInterfaceName»*> «clazz.genLocalName»::«instanceVariable»;
		
		
		
		«/* Local Class implementation */»
		
		«clazz.genLocalName»::«clazz.genLocalName»(Viatra::Query::Model::id_t id)
			: Viatra::Query::Model::ModelElement(id, true)
			, Viatra::Query::Model::LocalElement(id)
			«FOR base : clazz.getESuperTypes»
				, «base.genInterfaceName»(id, true)
			«ENDFOR»
			, «clazz.genInterfaceName»(id, true)
		{
			«instanceVariable».push_back(this);
		}
		
		«clazz.genLocalName»::~«clazz.genLocalName»() {
			«instanceVariable».remove(this);
		}
				
		«FOR a : clazz.getAllEAttribute»
			«val ah = CppHelper::getAttributeHelper(a)»
			void «clazz.genLocalName»::«ah.setterName»(«ah.cppType» newVal) {
				«ah.memberName» = newVal;				
			}
			«ah.returnType» «clazz.genLocalName»::«ah.getterName»() const {
				return «ah.memberName»;
			}

		«ENDFOR»
		
		«FOR a : clazz.getAllEReference»
			«val ah = CppHelper::getAssociationHelper(a)»
			void «clazz.genLocalName»::«ah.setterName»(«ah.cppType» newVal) {
				«ah.memberName» = newVal;				
			}
			«ah.returnType» «clazz.genLocalName»::«ah.getterName»() const  {
				return «ah.memberName»;
			}
			
		«ENDFOR»
		
		«/* Remote Class implementation */»

		«clazz.genRemoteName»::«clazz.genRemoteName»(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
		: Viatra::Query::Model::ModelElement(id, false)
		, Viatra::Query::Model::RemoteElement(id)
		«FOR base : clazz.getESuperTypes»
			, «base.genInterfaceName»(id, false)
		«ENDFOR»
		, «clazz.genInterfaceName»(id, true)
		{
			//«instanceVariable».push_back(this);
		}
		
		«clazz.genRemoteName»::~«clazz.genRemoteName»() {
			//«instanceVariable».remove(this);
		}

		«FOR a : clazz.getAllEAttribute»
			«val ah = CppHelper::getAttributeHelper(a)»
			void «clazz.genRemoteName»::«ah.setterName»(«ah.cppType» newVal) {
				throw "Unimplemented feature of Remote Class";			
			}
			«ah.returnType» «clazz.genRemoteName»::«ah.getterName»() const {
				throw "Unimplemented feature of Remote Class";	
			}

		«ENDFOR»
		
		«FOR a : clazz.getAllEReference»
			«val ah = CppHelper::getAssociationHelper(a)»
			void «clazz.genRemoteName»::«ah.setterName»(«ah.cppType» newVal) {
				throw "Unimplemented feature of Remote Class";			
			}
			«ah.returnType» «clazz.genRemoteName»::«ah.getterName»() const {
				throw "Unimplemented feature of Remote Class";	
			}
			
		«ENDFOR»		
		
		
		«FOR namespaceFragment : ns»
			} /* namespace «namespaceFragment» */
		«ENDFOR»
	'''
}
