package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import java.util.Set
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternDescriptor

class DerivedUpdaterAPIGenerator extends ViatraQueryHeaderGenerator {
	
	protected val String name
	protected val Set<PatternDescriptor> patternGroup
	protected val MatchGenerator matchGenerator
	
	protected val QuerySpecificationGenerator querySpecification

	new(String queryName, String patternName, Set<PatternDescriptor> patternGroup, MatchGenerator matchGenerator, QuerySpecificationGenerator querySpecification) {
		super(#{queryName}, '''«patternName.toFirstUpper»Updater''')
		this.name = patternName.toFirstUpper
		this.patternGroup = patternGroup
		this.matchGenerator = matchGenerator
		this.querySpecification = querySpecification
	}
	
	override initialize() {
		
	}
	
	override compileInner() '''
	
	'''
	
	override compileOuter() '''
	
	'''
	
}