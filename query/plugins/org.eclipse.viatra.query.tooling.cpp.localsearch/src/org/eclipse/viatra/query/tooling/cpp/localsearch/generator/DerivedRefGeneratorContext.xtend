package org.eclipse.viatra.query.tooling.cpp.localsearch.generator

import com.google.common.base.CaseFormat
import java.util.List
import java.util.Set
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.MatchGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.QueryGroupGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.QueryIncludeGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.RefAPIGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime.MatchingFrameGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime.QueryRunnerFactoryGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime.RuntimeMatcherGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime.RuntimeQuerySpecificationGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternGroupDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.QueryDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.proto.ProtoCompiler
import org.eclipse.viatra.query.tooling.cpp.localsearch.proto.ProtoGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.proto.ProtobufMatchCompiler

class DerivedRefGeneratorContext extends LocalsearchGeneratorOutputProvider {

	//WARNING!! This is copied from RuntimeGeneratorContext
	override initializeGenerators(QueryDescriptor query) {
		
		val List<IGenerator> generators = newArrayList
		val Set<ProtoCompiler> protoCompilers = newHashSet
		val Set<PatternGroupDescriptor> patternGroupSet = newHashSet

		query.patternGroups.forEach [ name, patternGroup |
			val frameGenMap = newHashMap
			val patternName = CaseFormat::LOWER_CAMEL.to(CaseFormat::UPPER_CAMEL, name)
			patternGroup.boundedPatterns.forEach[
				patternBodies.forEach[ patternBody |
					val matchingFrameGenerator = new MatchingFrameGenerator(query.name, patternName, patternBody.index, patternBody.matchingFrame)
					frameGenMap.put(patternBody, matchingFrameGenerator)
					generators += matchingFrameGenerator
				]
			]

			val aMatchingFrame = patternGroup.boundedPatterns.head.patternBodies.head.matchingFrame

			val matchGen = new MatchGenerator(query.name, patternName, aMatchingFrame)
			generators += matchGen
			
			// ... I use this hack too hope it still works
			val protoMatchCompiler = new ProtobufMatchCompiler(query.name, patternName, aMatchingFrame)
			protoCompilers += protoMatchCompiler
			
			val querySpec = new RuntimeQuerySpecificationGenerator(query.name, patternGroup, frameGenMap)
			generators += querySpec
			patternGroupSet.add(patternGroup);
			
			val matcherGen = new RuntimeMatcherGenerator(query.name, patternName, patternGroup, frameGenMap, matchGen, querySpec)
			generators += matcherGen
			
			if(patternGroup.boundedPatterns.exists[it | 
				it.patternBodies.exists[it | 
					it.PBody.pattern.allAnnotations.exists[it | it.name == "QueryBasedFeature"]
				]
				
			]){

				val annotations = patternGroup.boundedPatterns.map[patternBodies.map[PBody.pattern.allAnnotations].flatten.filter(it | it.name == "QueryBasedFeature")].flatten
				val featureName = annotations.get(0).getFirstValue("feature") as CharSequence;
				val updaterGen = new RefAPIGenerator(query.name, patternName, featureName, patternGroup, matchGen, matcherGen, querySpec)
				generators += updaterGen
			}
			
			val	includeGen = new QueryIncludeGenerator(query.name, patternGroup)
			generators += includeGen
		]
		
		generators += new ProtoGenerator(protoCompilers)
		
		val queryGroupGenerator = new QueryGroupGenerator(query)
		generators += queryGroupGenerator
		
		generators += new QueryRunnerFactoryGenerator(query);
		

		generators.forEach[initialize]

		return generators

	}

}