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
package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.iterator

import com.google.common.base.Function
import java.util.Collection
import java.util.LinkedList
import java.util.Map
import java.util.regex.Pattern
import org.eclipse.emf.ecore.EClass
import org.eclipse.emf.ecore.EClassifier
import org.eclipse.emf.ecore.EStructuralFeature
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.BaseGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.MatchGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.NameUtils
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.AbstractSearchOperationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BinaryTransitiveClosureDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.CheckConstantValueDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.CheckExpressionDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.CheckInequalityDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.CheckInstanceOfDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.CheckMultiNavigationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.CheckSingleNavigationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.ExtendConstantValueDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.ExtendInstanceOfDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.ExtendMultiNavigationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.ExtendSingleNavigationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.ISearchOperationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.NACOperationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternMatchCounterCheckDescription
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternMatchCounterExtendDescription
import org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util.TypeUtil
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper
import org.eclipse.xtend.lib.annotations.Accessors
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.MatchingFrameDescriptor

/**
 * @author Robert Doczi
 */
class IteratorSearchOperationGenerator extends BaseGenerator {

	val Collection<ISearchOperationDescriptor> operations;
	val MatchGenerator matchGenerator

	@Accessors(PUBLIC_SETTER)
	Function<CharSequence, CharSequence> matchFoundHandler

	val LinkedList<ISearchOperationDescriptor> operationsQueue
	val Map<String, String> variablePurgedNameCache
	val Map<String, String> variableNameCache
	val Map<String, Integer> variableNameCounter
	
	val MatchingFrameDescriptor matchingFrame

	new(Collection<ISearchOperationDescriptor> operations, MatchGenerator matchGenerator, MatchingFrameDescriptor matchingFrame) {
		this.operations = operations;
		this.matchGenerator = matchGenerator
		this.matchingFrame = matchingFrame

		this.operationsQueue = newLinkedList
		this.variablePurgedNameCache = newHashMap
		this.variableNameCache = newHashMap
		this.variableNameCounter = newHashMap
	}

	override initialize() {
		operationsQueue.clear
		operationsQueue.addAll(operations)
	}

	override compile(StringBuilder setupCode) {
		variableNameCache.clear
		variableNameCounter.clear
		compileNext(setupCode)
	}

	def dispatch compileOperation(CheckInstanceOfDescriptor operation, StringBuilder setupCode) '''
		if(_classHelper->is_super_type(«operation.variable.cppName»->get_type_id(), «operation.key.type.typeName»::type_id)) {
			«val typedVar = operation.variable.typedVariable(operation, operation.key)»
			auto «operation.variable.incrementName» = «typedVar»;
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(CheckSingleNavigationDescriptor operation, StringBuilder setupCode) '''
		«val tarName = operation.target.cppName»
		«val srcName = operation.source.cppName»
		«val relName = operation.key.name»
		if(«srcName»->«relName» == «tarName») {
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(CheckMultiNavigationDescriptor operation, StringBuilder setupCode) '''
		«val tarName = operation.target.cppName»
		«val srcName = operation.source.cppName»
		«val relName = operation.key.name»
		auto& data = «srcName»->«relName»;
		if(std::find(data.begin(), data.end(), «tarName») != data.end()) {
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(NACOperationDescriptor operation, StringBuilder setupCode) '''
		«val matcherName = '''matcher_«Math.abs(operation.hashCode)»'''»
		«val youShallNotPrint = setupCode.append('''«operation.matcher»<ModelRoot> «matcherName»(_model,  _context);
		''')»
		if(«matcherName».matches(«operation.bindings.map[cppName].join(", ")»).size() == 0) {
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(BinaryTransitiveClosureDescriptor operation, StringBuilder setupCode) '''
		«val trgName = operation.target.cppName»
		«val srcName = operation.source.cppName»
		«val matcherName = '''matcher_«Math.abs(operation.hashCode)»'''»
		«val youShallNotPrint = setupCode.append('''«operation.matcherName»<ModelRoot> «matcherName»(_model,  _context);
		''')»
		if(transitive_closure_check(«matcherName», &«operation.matchName»::«operation.refferedQueryMatchTargetMemberName», «srcName», «trgName»)) {
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(PatternMatchCounterCheckDescription operation, StringBuilder setupCode) '''
		«val matcherName = '''matcher_«Math.abs(operation.hashCode)»'''»
		«val youShallNotPrint = setupCode.append('''«operation.matcher»<ModelRoot> «matcherName»(_model,  _context);
		''')»
		if(«matcherName».matches(«operation.bindings.map[cppName].join(", ")»).size() == «operation.resultVariable.cppName») {
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(PatternMatchCounterExtendDescription operation, StringBuilder setupCode) '''
		«val matcherName = '''matcher_«Math.abs(operation.hashCode)»'''»
		«val youShallNotPrint = setupCode.append('''«operation.matcher»<ModelRoot> «matcherName»(_model,  _context);
		''')»
		auto «operation.resultVariable.cppName» = «matcherName».matches(«operation.bindings.map[cppName].join(", ")»).size();
		«compileNext(setupCode)»
	'''

	def dispatch compileOperation(CheckConstantValueDescriptor operation, StringBuilder setupCode) '''
		if(«operation.variable.cppName» == «TypeUtil::getCppValue(operation.value)»){
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(CheckInequalityDescriptor operation, StringBuilder setupCode) '''
		if(«operation.who.cppName» != «operation.withWhom.cppName»){
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(ExtendConstantValueDescriptor operation, StringBuilder setupCode) '''
		auto «operation.variable.cppName» = «TypeUtil::getCppValue(operation.value)»;
		«compileNext(setupCode)»
	'''
	
	def dispatch compileOperation(CheckExpressionDescriptor operation, StringBuilder setupCode)'''
		if(
			//
			//  *****************  CHECK EXPRESSION IMPLEMENTATION
			//		
			[](«operation.variables.map[toForwardDef(operation)].join(", ")»){
				// Please implement the following 
				// «operation.expressionAsStr»
				//
				
				static_assert(false, "Please implement the Check expression");	
			}
			//	***************************************************
			
			  («operation.variables.map[it.cppName].join(", ")»)){
				«compileNext(setupCode)»
			}
	'''
	
	private def toForwardDef(PVariable variable, CheckExpressionDescriptor operation) {
		val typeMap = operation.types
		val type = typeMap.get(variable);
		var typeStr = type.toCppName;
		if( type instanceof EClass )
			typeStr = '''const «typeStr»*''' 
			
		return '''«typeStr» «variable.name»'''
	}
	
	private def toCppName(EClassifier type) {
		CppHelper::getTypeHelper(type).FQN
	}
	
	@Deprecated
	def replaceVars(CharSequence expression) {
		var expressionString = expression.toString
		val p = Pattern.compile("\\$([\\w-]*)\\$");
		val m = p.matcher(expression);
		while (m.find()) {
			val variable = m.group(1)
			expressionString = expressionString.replace('''$«variable»$''', '''«variable»''')
		}
		return expressionString
	}

	def dispatch compileOperation(ExtendInstanceOfDescriptor operation, StringBuilder setupCode) '''
		«val type = operation.matchingFrame.getVariableStrictType(operation.variable)»
		«val typeHelper = CppHelper::getTypeHelper(type)»
		«val varName = operation.variable.cppName»
		for(auto&& «varName» : (ModelIndex<std::remove_pointer<«typeHelper.FQN»>::type, ModelRoot>::instances(_model))) {
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(ExtendSingleNavigationDescriptor operation, StringBuilder setupCode) '''
		«val tarName = operation.target.cppName»
		«val srcName = operation.source.cppName»
		«val relName = operation.key.name»
		if(!::Viatra::Query::Util::IsNull<decltype(«srcName»->«relName»)>::check(«srcName»->«relName»)) {
			auto «tarName» = «srcName»->«relName»;
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(ExtendMultiNavigationDescriptor operation, StringBuilder setupCode) '''
		«val tarName = operation.target.cppName»
		«val srcName = operation.source.cppName»
		«val relName = operation.key.name»
		for(auto&& «tarName» : «srcName»->«relName») {
			«compileNext(setupCode)»
		}
	'''

	def dispatch compileOperation(ISearchOperationDescriptor operation, StringBuilder setupCode) '''
		//NYI {
			«compileNext(setupCode)»
		}
	'''

	def createMatch() '''
		«matchGenerator.qualifiedName» match;
		«FOR parameter : matchingFrame.parameters»
			«val keyVariable = matchingFrame.getVariableFromParameter(parameter)»
			«val variableType = matchingFrame.getVariableStrictType(keyVariable)»
			match.«parameter.name» = «keyVariable.cppName.castTo(variableType)»;
		«ENDFOR»

		«matchFoundHandler.apply("match")»
	'''

	def CharSequence compileNext(StringBuilder setupCode) {
		if (!operationsQueue.isEmpty)
			operationsQueue.poll.compileOperation(setupCode)
		else
			createMatch
	}

	def getCppName(PVariable variable) {
		getCachedData(variableNameCache, variable.name) [
			variable.purgedName
		]
	}

	def incrementName(PVariable variable) {
		val name = variable.purgedName
		val count = getCachedData(variableNameCounter, variable.name) [
			0
		]
		val postfixedName = '''«name»_«count»'''
		variableNameCache.put(variable.name, postfixedName)
		variableNameCounter.put(variable.name, count + 1)
		return postfixedName
	}

	def getPurgedName(PVariable variable) {
		getCachedData(variablePurgedNameCache, variable.name) [
			NameUtils::getPurgedName(variable)
		]
	}

	private def <Key, Value> getCachedData(Map<Key, Value> cache, Key key, (Key) => Value supplier) {
		if(!cache.containsKey(key)) {
			val value = supplier.apply(key)
			cache.put(key, value)
			return value
		}
		return cache.get(key)
	}

	private def typeName(EClassifier type) {
		CppHelper::getTypeHelper(type).FQN
	}

	private def castTo(String variable, EClassifier type) {
		'''static_cast<«type.typeName»«IF type instanceof EClass»*«ENDIF»>(«variable»)'''
	}

	private def typedVariable(PVariable variable, AbstractSearchOperationDescriptor operation, EClassifier expectedType) {
		val varType = operation.matchingFrame.getVariableLooseType(variable)
		if (varType != expectedType) {
			variable.cppName.castTo(expectedType)
		} else {
			variable.cppName
		}
	}

	private dispatch def getType(EStructuralFeature key) {
		return key.EType
	}

	private dispatch def getType(EClassifier key) {
		return key
	}
}
