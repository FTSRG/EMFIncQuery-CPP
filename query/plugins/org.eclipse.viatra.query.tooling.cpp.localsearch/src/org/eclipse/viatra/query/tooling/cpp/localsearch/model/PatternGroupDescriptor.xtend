package org.eclipse.viatra.query.tooling.cpp.localsearch.model

import java.util.Set
import org.eclipse.xtend.lib.annotations.Accessors

class PatternGroupDescriptor {
	
	@Accessors
	String name;
	@Accessors
	Set<BoundedPatternDescriptor> boundedPatterns;
	
	
	new(String name, Iterable<BoundedPatternDescriptor> boundedPatterns)
	{
		this.name = name;
		this.boundedPatterns = boundedPatterns.toSet;
	}
	
}