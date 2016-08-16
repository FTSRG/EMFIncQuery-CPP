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

import java.util.List
import java.util.Map
import java.util.Set
import javax.activation.UnsupportedDataTypeException
import org.eclipse.viatra.query.runtime.emf.types.EClassTransitiveInstancesKey
import org.eclipse.viatra.query.runtime.emf.types.EDataTypeInSlotsKey
import org.eclipse.viatra.query.runtime.emf.types.EStructuralFeatureInstancesKey
import org.eclipse.viatra.query.runtime.matchers.planning.SubPlan
import org.eclipse.viatra.query.runtime.matchers.planning.SubPlanFactory
import org.eclipse.viatra.query.runtime.matchers.planning.operations.PApply
import org.eclipse.viatra.query.runtime.matchers.planning.operations.POperation
import org.eclipse.viatra.query.runtime.matchers.planning.operations.PProject
import org.eclipse.viatra.query.runtime.matchers.planning.operations.PStart
import org.eclipse.viatra.query.runtime.matchers.psystem.PBody
import org.eclipse.viatra.query.runtime.matchers.psystem.PConstraint
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.ExportedParameter
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.Inequality
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.NegativePatternCall
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.PatternMatchCounter
import org.eclipse.viatra.query.runtime.matchers.psystem.basicenumerables.BinaryTransitiveClosure
import org.eclipse.viatra.query.runtime.matchers.psystem.basicenumerables.ConstantValue
import org.eclipse.viatra.query.runtime.matchers.psystem.basicenumerables.TypeConstraint
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PQuery.PQueryStatus
import org.eclipse.viatra.query.runtime.matchers.tuple.FlatTuple
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.TypeInfo
import org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util.CompilerHelper
import org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util.SupplementTypeConstraint
import org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util.TypeUtil
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.ExpressionEvaluation

/**
 * @author Robert Doczi
 */
class POperationCompiler {


	var Map<PVariable, Integer> variableMapping
	var Map<PConstraint, Set<Integer>> variableBindings
	var Map<PVariable, TypeInfo> typeMapping
	
	

	def void compile(SubPlan plan, PBody pBody, Set<PVariable> boundVariables, ISearchOperationAcceptor acceptor) {
		var newOperationList = injectSupplementTypeConstraints(plan)
		val newPlan = reAssemblePlan(newOperationList, pBody)
		variableMapping = CompilerHelper::createVariableMapping(newPlan)
		typeMapping = CompilerHelper::createTypeMapping(newPlan)
		variableBindings = CompilerHelper::cacheVariableBindings(newPlan, variableMapping, boundVariables.map[variableMapping.get(it)].toSet)

		acceptor.initialize(newPlan, variableMapping, variableBindings)

		CompilerHelper::createOperationsList(newPlan).forEach[compile(acceptor)]
	}
	

	
	def reAssemblePlan(List<POperation> operations, PBody pBody) {
		var i = 0
		val subPlanFactory = new SubPlanFactory(pBody)
		var op = operations.get(i) 
		var plan = subPlanFactory.createSubPlan(op)
		var allConstraints = newArrayList
		i++
		while(i < operations.size){
			op = operations.get(i)
			switch (op) {
				PStart: {
					plan = subPlanFactory.createSubPlan(operations.get(i))
				}
				PProject: {
					plan = subPlanFactory.createSubPlan(operations.get(i), plan)
				}
				PApply: {
					if(!allConstraints.contains(op.PConstraint)){
						allConstraints.add(op.PConstraint) 
						plan = subPlanFactory.createSubPlan(operations.get(i), plan)
					}
			
				}
			}
			i++	
		}
		return plan
	}
	
	def injectSupplementTypeConstraints(SubPlan plan) {
		var operationList = CompilerHelper::createOperationsList(plan)
		var i = 0;
		while(operationList.size > i){
			var pOperation = operationList.get(i)
			switch(pOperation){
				PApply: {
					val pConstraint = pOperation.getPConstraint
					switch(pConstraint){
						PatternMatchCounter: {
							var dataType = TypeUtil::EIntDataType
							pConstraint.PSystem.status = PQueryStatus.UNINITIALIZED
							var supTypeConst = new SupplementTypeConstraint(pConstraint.PSystem,new FlatTuple(pConstraint.resultVariable), dataType)
							//The operationList.size - 1 is the position of last PConstraint: PProject, it has to be the last.
							operationList.add(operationList.size-1,new PApply(supTypeConst))
						}
						ConstantValue: {
							val constraints = pConstraint.affectedVariables.get(0).referringConstraints
							val isTypeConst = constraints.map[it instanceof TypeConstraint].toSet
							if(!isTypeConst.contains(Boolean.TRUE)){
								val dataType = TypeUtil::getDataType(pConstraint.supplierKey)
								pConstraint.PSystem.status = PQueryStatus.UNINITIALIZED
								var supTypeConst = new SupplementTypeConstraint(pConstraint.PSystem,pConstraint.variablesTuple, dataType)
								//The operationList.size - 1 is the position of last PConstraint: PProject, it has to be the last.
								operationList.add(operationList.size-1,new PApply(supTypeConst))
							}
						}
					}
				}
				default:{
					
				}
			}
			i++
		}
		return operationList
	}

	def compile(POperation pOperation, ISearchOperationAcceptor acceptor) {
		switch (pOperation) {
			PApply: {
				val pConstraint = pOperation.getPConstraint

				if(pConstraint.allBound)
					return createCheck(pConstraint, acceptor)
				else
					return createExtend(pConstraint, acceptor)
			}
			PStart: {
			}
			PProject: {
			}
			default: { // TODO: throw an error
			}
		}
		return #[]
	}

	def dispatch createCheck(TypeConstraint constraint, ISearchOperationAcceptor acceptor) {
		val inputKey = constraint.supplierKey

		switch (inputKey) {
			EClassTransitiveInstancesKey: {
				val variable = constraint.getVariableInTuple(0)
				acceptor.acceptInstanceOfClassCheck(variable, inputKey)
			}
			EStructuralFeatureInstancesKey: {
				val src = constraint.getVariableInTuple(0)
				val trg = constraint.getVariableInTuple(1)

				acceptor.acceptContainmentCheck(src, trg, inputKey)
			}
			EDataTypeInSlotsKey: {
				throw new UnsupportedDataTypeException("Cannot interpret TypeConstraint with primitiveType.")
			}
		}
	}
	
	def dispatch createCheck(SupplementTypeConstraint constraint, ISearchOperationAcceptor acceptor) {
		//nop
	}

	def dispatch createCheck(NegativePatternCall constraint, ISearchOperationAcceptor acceptor) {
		val bindings = variableBindings.get(constraint)
		val adornment = constraint.actualParametersTuple.elements.filter(PVariable).filter[
			bindings.contains(variableMapping.get(it))
		].toSet

		val keySize = constraint.actualParametersTuple.size

		val params = constraint.referredQuery.parameters
		val boundParams = newHashSet

		for(i : 0..<keySize) {
			val pVariable = constraint.actualParametersTuple.get(i) as PVariable
			if(bindings.contains(variableMapping.get(pVariable))) {
				boundParams += params.get(i)
			}
		}

		acceptor.acceptNACOperation(constraint.referredQuery, adornment, boundParams)
	}

	def dispatch createCheck(BinaryTransitiveClosure constraint, ISearchOperationAcceptor acceptor){

		val bindings = variableBindings.get(constraint)
		val adornment = constraint.variablesTuple.elements.filter(PVariable).filter[
			bindings.contains(variableMapping.get(it))
		].toSet

		val keySize = constraint.variablesTuple.size

		//It has two elements, because its a binary trans. closure.
		val params = constraint.referredQuery.parameters
		val boundParams = newHashSet

		for(i : 0..<keySize) {
			val pVariable = constraint.variablesTuple.get(i) as PVariable
			if(bindings.contains(variableMapping.get(pVariable))) {
				boundParams += params.get(i)
			}
		}
		val inputVariables = constraint.variablesTuple.elements.filter(PVariable).toList
		val source = inputVariables.get(0)
		val target = inputVariables.get(1)
		acceptor.acceptBinaryTransitiveClosureOperation(constraint.referredQuery, adornment, boundParams, source, target, params.get(1).name)
		acceptor.hashCode
	}

	def dispatch createCheck(PatternMatchCounter constraint, ISearchOperationAcceptor acceptor){
		val bindings = variableBindings.get(constraint)
		val adornment = constraint.actualParametersTuple.elements.filter(PVariable).filter[
			bindings.contains(variableMapping.get(it))
		].toSet
		
		val keySize = constraint.actualParametersTuple.size
		
		val params = constraint.referredQuery.parameters
		val boundParams = newHashSet
		
		for(i : 0..<keySize) {
			val pVariable = constraint.actualParametersTuple.get(i) as PVariable
		if(bindings.contains(variableMapping.get(pVariable))) {
				boundParams += params.get(i)
			}
		}
		val resultVar = constraint.resultVariable
		acceptor.acceptPatternMatchCounterCheck(constraint.referredQuery, adornment, boundParams, resultVar)
	}
	
	def dispatch createCheck(ExpressionEvaluation constraint, ISearchOperationAcceptor acceptor){
		val variables = constraint.getAffectedVariables();
		val expressionAsStr = constraint.evaluator.shortDescription
		
		acceptor.acceptCheckExpression(variables, expressionAsStr);
	}

	def dispatch createCheck(ExportedParameter constraint, ISearchOperationAcceptor acceptor) {
		// nop
	}
	
	def dispatch createCheck(ConstantValue constraint, ISearchOperationAcceptor acceptor){
		val variable = constraint.affectedVariables.get(0)
		val value = constraint.supplierKey
		
		acceptor.acceptConstantValueExtend(variable, value);
	}
	
	def dispatch createCheck(Inequality constraint, ISearchOperationAcceptor acceptor) {
		val who = constraint.who
		val withWhom = constraint.withWhom
		acceptor.acceptInequalityCheck(who, withWhom)
	}

	def dispatch createCheck(PConstraint constraint, ISearchOperationAcceptor acceptor) {
	}

	def dispatch createExtend(TypeConstraint constraint, ISearchOperationAcceptor acceptor) {
		val inputKey = constraint.supplierKey

		// TODO : this is wasteful
		val paramPositionMap = newHashMap
		variableMapping.forEach [ variable, position |
			paramPositionMap.put(variable.name, position)
		]

		switch (inputKey) {
			EClassTransitiveInstancesKey: {
				val variable = constraint.getVariableInTuple(0)
				acceptor.acceptIterateOverClassInstances(variable, inputKey)
			}
			EStructuralFeatureInstancesKey: {
				var src = constraint.getVariableInTuple(0)
				var trg = constraint.getVariableInTuple(1)

				val fromBound = variableBindings.get(constraint).contains(variableMapping.get(src))
				val toBound = variableBindings.get(constraint).contains(variableMapping.get(trg))

				if (!fromBound && !toBound) {
					acceptor.acceptIterateOverClassInstances(src, new EClassTransitiveInstancesKey(inputKey.wrappedKey.EContainingClass))
				}

				if (toBound) {
					acceptor.acceptExtendToAssociationTarget(src, trg, inputKey)
				} else {
					acceptor.acceptExtendToAssociationSource(src, trg, inputKey)
				}
			}
			EDataTypeInSlotsKey: {
				throw new UnsupportedDataTypeException("Cannot interpret TypeConstraint with primitiveType.")
			}
		}
	}
	
	def dispatch createExtend(SupplementTypeConstraint constraint, ISearchOperationAcceptor acceptor) {
		//nop
	}

	def dispatch createExtend(NegativePatternCall constraint, ISearchOperationAcceptor acceptor) {
		throw new UnsupportedOperationException("Cannot extend through a negative pattern call");
	}

	def dispatch createExtend(PatternMatchCounter constraint, ISearchOperationAcceptor acceptor) {
		val bindings = variableBindings.get(constraint)
		val adornment = constraint.actualParametersTuple.elements.filter(PVariable).filter[
			bindings.contains(variableMapping.get(it))
		].toSet
		
		val keySize = constraint.actualParametersTuple.size
		
		val params = constraint.referredQuery.parameters
		val boundParams = newHashSet
		
		//TODO: ugly, i is used to indexed two different array
		for(i : 0..<keySize) {
			val pVariable = constraint.actualParametersTuple.get(i) as PVariable
		if(bindings.contains(variableMapping.get(pVariable))) {
				boundParams += params.get(i)
			}
		}
		val resultVar = constraint.resultVariable
		acceptor.acceptPatternMatchCounterExtend(constraint.referredQuery, adornment, boundParams, resultVar)
	}

	def dispatch createExtend(ExportedParameter constraint, ISearchOperationAcceptor acceptor) {
		// nop
	}
	
	def dispatch createExtend(ConstantValue constraint, ISearchOperationAcceptor acceptor) {
		val variable = constraint.affectedVariables.get(0)
		val value = constraint.supplierKey
		
		acceptor.acceptConstantValueExtend(variable, value);
	}

	def dispatch createExtend(PConstraint constraint, ISearchOperationAcceptor acceptor) {
		println("Constraint type not yet implemented: " + constraint)
	}

	private def allBound(PConstraint pConstraint) {
		switch (pConstraint) {
			//TODO revision if it's necessary
			NegativePatternCall: return true
			BinaryTransitiveClosure: return true
			PatternMatchCounter: return variableBindings.get(pConstraint).contains(variableMapping.get(pConstraint.resultVariable))
			default: return variableBindings.get(pConstraint).containsAll(
					pConstraint.affectedVariables.map [
						variableMapping.get(it)
					].toSet
				)
		}
	}
}
