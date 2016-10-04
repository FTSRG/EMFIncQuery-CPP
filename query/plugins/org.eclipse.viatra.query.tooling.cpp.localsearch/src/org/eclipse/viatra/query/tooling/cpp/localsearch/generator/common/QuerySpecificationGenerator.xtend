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
package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import java.util.Set
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternBodyDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BoundedPatternDescriptor

/**
 * @author Robert Doczi
 */
abstract class QuerySpecificationGenerator extends ViatraQueryHeaderGenerator {
	
	protected val Set<BoundedPatternDescriptor> patternGroup
	protected val String queryGroupName

	protected val String patternName
	protected val String querySpecificationName
	
	
	new(String queryGroupName, Set<BoundedPatternDescriptor> patternGroup) {
		super(#{queryGroupName.toFirstUpper}, '''«patternGroup.head.name.toFirstUpper»QuerySpecification''')
		this.patternGroup = patternGroup
		this.queryGroupName = queryGroupName.toFirstUpper
		
		this.patternName = patternGroup.head.name.toFirstUpper
		this.querySpecificationName = '''«patternName.toFirstUpper»QuerySpecification'''
	}
	
	override initialize() {
		includes += new Include('''Viatra/Query/«queryGroupName»/«queryGroupName»QueryGroup.h''')
		
		includes += new Include("Viatra/Query/Util/Optional.h")
		includes += new Include("Viatra/Query/Operations/AllOperations.h")
		includes += new Include("Viatra/Query/Plan/SearchPlan.h")
		includes += new Include("cmath", true)
	}

	// TODO: Iterating over the bodies giving them indices makes the generated code nondeterministic
	override compileInner() '''
		template<class ModelRoot>
		class «patternName»Matcher;
		
		template<class ModelRoot>
		class «unitName» {
		public:
			using Matcher = «patternName»Matcher<ModelRoot>;
			using Match = «patternName»Matcher<ModelRoot>;
			using QueryGroup = «queryGroupName»QueryGroup;
			
			static constexpr int queryID = «patternGroup.head.queryID»;
					
			«FOR pattern : patternGroup»
				// queryID = «pattern.queryID»
				«FOR body : pattern.patternBodies»
					«generatePlan(pattern, body)»
				«ENDFOR»
			«ENDFOR»
		
		};
	'''
	
	abstract def String generatePlan(BoundedPatternDescriptor pattern, PatternBodyDescriptor patternBody) 
	
}
