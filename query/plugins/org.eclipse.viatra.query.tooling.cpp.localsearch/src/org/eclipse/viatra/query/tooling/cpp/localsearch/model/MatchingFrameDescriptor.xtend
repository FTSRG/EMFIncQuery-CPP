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
package org.eclipse.viatra.query.tooling.cpp.localsearch.model

import java.util.List
import java.util.Map
import org.eclipse.emf.ecore.EClassifier
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PParameter
import org.eclipse.xtend.lib.annotations.Data

import static com.google.common.base.Preconditions.*
import com.google.common.collect.Maps
import com.google.common.collect.ImmutableList
import java.util.ArrayList

/**
 * @author Robert Doczi
 */
class MatchingFrameDescriptor {

	val Map<PVariable, VariableInfo> variableInfoMap
	val Map<String, PVariable> parameterNameToVariableMap 

	new(List<VariableInfo> paramTypes) {
		variableInfoMap = Maps::uniqueIndex(paramTypes) [variable]
		parameterNameToVariableMap = Maps::newHashMap
		// Changed for multiple parameter mapped to one variable
		// paramTypes.filter[parameter.present].forEach[parameterNameToVariableMap.put(parameter.get.name, variable)]
		paramTypes.forEach[paramType | paramType.parameter.forEach[parameterNameToVariableMap.put(it.name, paramType.variable)]]
	}

	def getVariableStrictType(PVariable variable) {
		checkNotNull(variable)
		variableInfoMap.get(variable).type.strictType
	}
	
	def getVariableLooseType(PVariable variable) {
		checkNotNull(variable)
		variableInfoMap.get(variable).type.looseType
	}
	
	def getVariablePosition(PVariable variable) {
		checkNotNull(variable)
		variableInfoMap.get(variable).position
	}
	
	def getVariableFromParameter(PParameter parameter) {
		checkNotNull(parameter)
		parameterNameToVariableMap.get(parameter.name)
	}
	
	def getParameterFromVariable(PVariable variable) {
		checkNotNull(variable)
		variableInfoMap.get(variable).parameter		
	}
	
	def getAllVariables() {
		// copy it to evaluate
		ImmutableList::copyOf(variableInfoMap.values.map[variable])
	}
	
	def getParameters() {
		// copy it to evaluate
		// ImmutableList::copyOf(variableInfoMap.values.filter[parameter.present].map[parameter.get])
		
		var copyList = new ArrayList<PParameter>()
		for( variableInfo: variableInfoMap.values)
			for( param : variableInfo.parameter )
				copyList.add(param)
		return ImmutableList::copyOf(copyList)
	}
	
	def getAllTypes() {
		ImmutableList::copyOf(variableInfoMap.values.map[type].filterNull)
	}
}

@Data
class VariableInfo {
	ImmutableList<PParameter> parameter
	PVariable variable
	TypeInfo type
	int position
	
	def isKey() {
		!parameter.empty
	}
}

@Data
class TypeInfo {
	EClassifier looseType
	EClassifier strictType
}