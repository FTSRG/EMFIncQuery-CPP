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

import java.util.Map
import java.util.Set
import org.eclipse.emf.ecore.EClass
import org.eclipse.xtend.lib.annotations.Accessors
import java.util.HashMap

/**
 * @author Robert Doczi
 */
class QueryDescriptor {

	@Accessors(PUBLIC_GETTER)
	val String name

	val Set<BoundedPatternDescriptor> everyBoundedPatternInTheFile
	
	@Accessors
	val Map<String, PatternGroupDescriptor> patternGroups
	
	@Accessors
	val Set<EClass> classes

	new(String name, Set<BoundedPatternDescriptor> everyBoundedPatternInTheFile, Set<EClass> classes) {
		this.name = name

		this.everyBoundedPatternInTheFile = everyBoundedPatternInTheFile
		this.classes = classes
		
		patternGroups = new HashMap
		everyBoundedPatternInTheFile.groupBy[it.name].forEach[patternGroupName, set |
			patternGroups.put(patternGroupName, new PatternGroupDescriptor(patternGroupName, set))
		]
	}

	private def getPatternGroupsAsSets() {
		everyBoundedPatternInTheFile.groupBy[it.name].unmodifiableView
	}
	
	override toString() '''
		Query<«name»>:
			«FOR pattern : patterns»
				«pattern»
			«ENDFOR»		
	'''
	
}