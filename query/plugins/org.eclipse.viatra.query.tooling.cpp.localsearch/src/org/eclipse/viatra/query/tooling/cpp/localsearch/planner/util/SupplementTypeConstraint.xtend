package org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util

import org.eclipse.viatra.query.runtime.matchers.psystem.basicenumerables.TypeConstraint
import org.eclipse.viatra.query.runtime.matchers.psystem.PBody
import org.eclipse.viatra.query.runtime.matchers.tuple.Tuple
import org.eclipse.viatra.query.runtime.matchers.context.IInputKey

class SupplementTypeConstraint extends TypeConstraint {
	
	new(PBody pBody, Tuple variablesTuple, IInputKey inputKey) {
		super(pBody, variablesTuple, inputKey)
	}
	
}