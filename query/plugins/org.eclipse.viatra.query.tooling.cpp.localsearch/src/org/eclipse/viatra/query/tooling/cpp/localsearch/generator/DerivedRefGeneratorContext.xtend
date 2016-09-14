package org.eclipse.viatra.query.tooling.cpp.localsearch.generator

import com.google.common.base.CaseFormat
import java.util.List
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.MatchGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.QueryGroupGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.RefAPIGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime.MatchingFrameGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime.RuntimeMatcherGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime.RuntimeQuerySpecificationGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.QueryDescriptor

class DerivedRefGeneratorContext extends LocalsearchGeneratorOutputProvider {

	override initializeGenerators(QueryDescriptor query) {
		val List<IGenerator> generators = newArrayList


		query.patterns.forEach [ name, patterns |
			val frameGenMap = newHashMap
			val patternName = CaseFormat::LOWER_CAMEL.to(CaseFormat::UPPER_CAMEL, name)
			patterns.forEach[
				patternBodies.forEach[ patternBody |
					val matchingFrameGenerator = new MatchingFrameGenerator(query.name, patternName, patternBody.index, patternBody.matchingFrame)
					frameGenMap.put(patternBody, matchingFrameGenerator)
					generators += matchingFrameGenerator
				]
			]

			// TODO: WARNING! Incredible Hack Inc! works, but ugly...
			val matchGen = new MatchGenerator(query.name, patternName, patterns.head.patternBodies.head.matchingFrame)
			generators += matchGen
			
			val querySpec = new RuntimeQuerySpecificationGenerator(query.name, patterns.toSet, frameGenMap)
			generators += querySpec
			
			val matcherGen = new RuntimeMatcherGenerator(query.name, patternName, patterns.toSet, frameGenMap, matchGen, querySpec)
			generators += matcherGen
			
			if(patterns.exists[it | 
				it.patternBodies.exists[it | 
					it.PBody.pattern.allAnnotations.exists[it | it.name == "QueryBasedFeature"]
				]
				
			]){
				val annotations = patterns.map[patternBodies.map[PBody.pattern.allAnnotations].flatten.filter(it | it.name == "QueryBasedFeature")].flatten
				val featureName = annotations.get(0).getFirstValue("feature") as CharSequence;
				val updaterGen = new RefAPIGenerator(query.name, patternName, featureName, patterns.toSet, matchGen, matcherGen, querySpec)
				generators += updaterGen
			}
		]
		
		val queryGroupGenerator = new QueryGroupGenerator(query)
		generators += queryGroupGenerator

		generators.forEach[initialize]

		return generators

	}

}