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
package org.eclipse.viatra.query.tooling.cpp.localsearch.planner

import com.google.common.collect.Multimaps
import java.util.HashMap
import java.util.List
import java.util.Map
import java.util.Set
import org.eclipse.emf.ecore.EClassifier
import org.eclipse.emf.ecore.EReference
import org.eclipse.emf.ecore.EStructuralFeature
import org.eclipse.viatra.query.runtime.emf.types.EClassTransitiveInstancesKey
import org.eclipse.viatra.query.runtime.emf.types.EStructuralFeatureInstancesKey
import org.eclipse.viatra.query.runtime.matchers.context.IInputKey
import org.eclipse.viatra.query.runtime.matchers.planning.SubPlan
import org.eclipse.viatra.query.runtime.matchers.psystem.PBody
import org.eclipse.viatra.query.runtime.matchers.psystem.PConstraint
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PParameter
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PQuery
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
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.MatchingFrameDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.NACOperationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternBodyDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternMatchCounterCheckDescription
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternMatchCounterExtendDescription
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.TypeInfo
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.VariableInfo
import org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util.CompilerHelper

/**
 * @author Robert Doczi
 */
class CPPSearchOperationAcceptor implements ISearchOperationAcceptor {

	val MatchingFrameRegistry matchingFrameRegistry
	val List<ISearchOperationDescriptor> searchOperations
	val List<MatcherReference> dependencies
	val int id

	var Map<PVariable, TypeInfo> typeMapping
	var Map<PVariable, Integer> variableMapping
	var PBody pBody

	var MatchingFrameDescriptor matchingFrame

	new (int id, MatchingFrameRegistry frameRegistry) {
		this.matchingFrameRegistry = frameRegistry
		this.searchOperations = newArrayList
		this.dependencies = newArrayList
		this.id = id
	}

	override initialize(SubPlan plan, Map<PVariable, Integer> variableMapping, Map<PConstraint, Set<Integer>> variableBindings) {
		this.typeMapping = CompilerHelper::createTypeMapping(plan)
		this.variableMapping = variableMapping
		this.pBody = plan.body
		this.matchingFrame = getMatchingFrame(pBody)
	}

	override acceptContainmentCheck(PVariable sourceVariable, PVariable targetVariable, IInputKey inputKey) {
		val structrualFeature = (inputKey as EStructuralFeatureInstancesKey).wrappedKey

		// one to one
		if(structrualFeature.upperBound == 1)
			searchOperations += new CheckSingleNavigationDescriptor(matchingFrame, sourceVariable, targetVariable, structrualFeature)
		else
			searchOperations += new CheckMultiNavigationDescriptor(matchingFrame, sourceVariable, targetVariable, structrualFeature)
	}

	override acceptInstanceOfClassCheck(PVariable checkedVariable, IInputKey inputKey) {
		val eClass = (inputKey as EClassTransitiveInstancesKey).wrappedKey

		searchOperations += new CheckInstanceOfDescriptor(matchingFrame, checkedVariable, eClass)
	}

	override acceptExtendToAssociationSource(PVariable sourceVariable, PVariable targetVariable, IInputKey inputKey) {
		val structrualFeature = (inputKey as EStructuralFeatureInstancesKey).wrappedKey

		createNavigationOperation(sourceVariable, targetVariable, structrualFeature)
	}

	override acceptExtendToAssociationTarget(PVariable sourceVariable, PVariable targetVariable, IInputKey inputKey) {
		val structrualFeature = (inputKey as EStructuralFeatureInstancesKey).wrappedKey

		createNavigationOperation(targetVariable, sourceVariable, (structrualFeature as EReference).EOpposite)
	}

	private def createNavigationOperation(PVariable sourceVariable, PVariable targetVariable, EStructuralFeature structrualFeature) {
		// one to one
		if(structrualFeature.upperBound == 1)
			searchOperations += new ExtendSingleNavigationDescriptor(matchingFrame, sourceVariable, targetVariable, structrualFeature)
		else
			searchOperations += new ExtendMultiNavigationDescriptor(matchingFrame, sourceVariable, targetVariable, structrualFeature)
	}

	override acceptIterateOverClassInstances(PVariable location, IInputKey inputKey) {
		val eClass = (inputKey as EClassTransitiveInstancesKey).wrappedKey

		searchOperations += new ExtendInstanceOfDescriptor(matchingFrame, location, eClass)
	}

	override acceptNACOperation(PQuery calledPQuery, Set<PVariable> boundVariables, Set<PParameter> boundParameters) {
		val matcherName = '''«calledPQuery.fullyQualifiedName.substring(calledPQuery.fullyQualifiedName.lastIndexOf('.')+1).toFirstUpper»Matcher'''
		val dependency = new MatcherReference(calledPQuery, boundParameters)
		dependencies += dependency
		searchOperations += new NACOperationDescriptor(matchingFrame, #{dependency}, matcherName, boundVariables)
	}

	override acceptBinaryTransitiveClosureOperation(PQuery calledPQuery, Set<PVariable> boundVariables, Set<PParameter> boundParameters, PVariable source, PVariable target, CharSequence matchMemberName){
		val matcherName = '''«calledPQuery.fullyQualifiedName.substring(calledPQuery.fullyQualifiedName.lastIndexOf('.')+1).toFirstUpper»Matcher'''
		val matchName = '''«calledPQuery.fullyQualifiedName.substring(calledPQuery.fullyQualifiedName.lastIndexOf('.')+1).toFirstUpper»Match'''
		val dependency = new MatcherReference(calledPQuery, boundParameters)
		dependencies += dependency
		searchOperations += new BinaryTransitiveClosureDescriptor(matchingFrame, #{dependency}, matcherName, matchName, boundVariables, source, target, matchMemberName)
		println('''WARNING: You must ensure there is a binded version of called pattern: @Bind(parameters={source})pattern «calledPQuery.fullyQualifiedName»(source, target){...}''')
	}

	override acceptPatternMatchCounterCheck(PQuery calledPQuery, Set<PVariable> boundVariables, Set<PParameter> boundParameters, PVariable resultVariable){
		val matcherName = '''«calledPQuery.fullyQualifiedName.substring(calledPQuery.fullyQualifiedName.lastIndexOf('.')+1).toFirstUpper»Matcher'''
		val dependency = new MatcherReference(calledPQuery, boundParameters)
		dependencies += dependency
		searchOperations += new PatternMatchCounterCheckDescription(matchingFrame, #{dependency}, matcherName, boundVariables, resultVariable )
	}
	
	override acceptPatternMatchCounterExtend(PQuery calledPQuery, Set<PVariable> boundVariables, Set<PParameter> boundParameters, PVariable resultVariable){
		val matcherName = '''«calledPQuery.fullyQualifiedName.substring(calledPQuery.fullyQualifiedName.lastIndexOf('.')+1).toFirstUpper»Matcher'''
		val dependency = new MatcherReference(calledPQuery, boundParameters)
		dependencies += dependency
		searchOperations += new PatternMatchCounterExtendDescription(matchingFrame, #{dependency}, matcherName, boundVariables, resultVariable)
	}
	
	override acceptConstantValueCheck(PVariable variable, Object value) {
		searchOperations += new CheckConstantValueDescriptor(matchingFrame, variable, value)
	}
	
	override acceptConstantValueExtend(PVariable variable, Object value) {
		searchOperations += new ExtendConstantValueDescriptor(matchingFrame, variable, value)
				
	}
	
	override acceptInequalityCheck(PVariable who, PVariable withWhom) {
		searchOperations += new CheckInequalityDescriptor(matchingFrame, who, withWhom)
	}
	
	
	override acceptCheckExpression(Set<PVariable> variables, CharSequence expressionAsStr) {
		var map = new HashMap<PVariable, EClassifier>();
		for( v : variables )
			map.put(v, typeMapping.get(v).looseType)
			
		searchOperations += new CheckExpressionDescriptor(matchingFrame, variables, map, expressionAsStr);
	}	
	


	def getPatternBodyStub() {
		return new PatternBodyDescriptor(pBody, id, matchingFrame, searchOperations);
	}

	def getDependencies() {
		return dependencies.unmodifiableView
	}

	private def getMatchingFrame(PBody pBody) {
		matchingFrameRegistry.getMatchingFrame(pBody).or[
			val variableToParameterMap = Multimaps::index(pBody.pattern.parameters) [pBody.getVariableByNameChecked(it.name)]
			// don't pass this to anything else or evaluate it! (Lazy evaluation!!)
			val variableInfos = pBody.uniqueVariables.map[
				val type = typeMapping.get(it)
				if(type == null)
					return null
				return new VariableInfo(variableToParameterMap.get(it), it, type, variableMapping.get(it))
			].filterNull.toList
			val frame = new MatchingFrameDescriptor(variableInfos)
			matchingFrameRegistry.putMatchingFrame(pBody, frame)
			return frame
		]
	}
	

	
}
