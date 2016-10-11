package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import java.util.Set
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PParameter
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.MatchingFrameDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternGroupDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper

class QueryIncludeGenerator extends ViatraQueryHeaderGenerator {
	
	protected val PatternGroupDescriptor patternGroup;
	protected val String queryGroupName
	protected val String patternName	
	
	new(String queryGroupName, PatternGroupDescriptor patternGroup) {
		super(#{queryGroupName.toFirstUpper}, '''«patternGroup.name.toFirstUpper»''')

		this.queryGroupName = queryGroupName.toFirstUpper
		this.patternGroup = patternGroup
		this.patternName = patternGroup.name.toFirstUpper
	}
	
	override initialize() {
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»QuerySpecification.h''')
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»Matcher.h''')
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»Match.h''')		
	}

	// TODO: Iterating over the bodies giving them indices makes the generated code nondeterministic
	override compileInner() '''
	
		template<class ModelRootParam>
		class Rooted«unitName» {
		public:
			using ModelRoot = ModelRootParam;
			using Matcher = «patternName»Matcher<ModelRoot>;
			using QuerySpecification = «patternName»QuerySpecification<ModelRoot>;
			using Match = «patternName»Match;
			using QueryGroup = «queryGroupName»QueryGroup;
			
			static constexpr int queryID = «patternName»QuerySpecification<ModelRoot>::queryID;
		};
		

		class «unitName» {
		public:
			template<typename ModelRoot>
			using RootedQuery = Rooted«unitName»<ModelRoot>;
		
			struct BindInfo{
				const std::map<int, std::string> encodedFrames;
			}
			
			class Bind{
				«FOR boundedPattern : patternGroup.boundedPatterns»
					class «boundedPattern.cppBoundName.toUpperCase»{
						«val randomMatchingFrame = boundedPattern.patternBodies.head.matchingFrame»
						static BindInfo BuildFrames(«boundedPattern.boundParameters.BuildFramesParamList(randomMatchingFrame)»){
							std::map<int, std::string> encodedFrames;
							
							«FOR body : boundedPattern.patternBodies»
								{
									«val frame = body.matchingFrame»
									«val frameType = '''«patternGroup.name.toFirstUpper»Frame_«body.index»'''»
									
									«frameType» frame;
									«frameType»Vector frameVector;
									
									«FOR param : boundedPattern.boundParameters»
										«val variable = body.matchingFrame.getVariableFromParameter(param)»
										frame._«body.matchingFrame.getVariablePosition(variable)» = param.name;
									«ENDFOR»
																		
									frameVector.push_back(frame);
									encodedFrames[«body.index»] = frameVector.SerializeAsString();
								}
							«ENDFOR»				
							
							return {std::move(encodedFrames)};
						}
					};
				«ENDFOR»
			}
			
			template<typename ModelRoot>
			using RootedQuery = Rooted«unitName»<ModelRoot>
			using ModelRoot = ModelRootParam;
			using Matcher = «patternName»Matcher<ModelRoot>;
			using QuerySpecification = «patternName»QuerySpecification<ModelRoot>;
			using Match = «patternName»Match;
			using QueryGroup = «queryGroupName»QueryGroup;
			
			static constexpr int queryID = «patternName»QuerySpecification<ModelRoot>::queryID;
		};
	
	'''
	
	def BuildFramesParamList(Set<PParameter> parameters, MatchingFrameDescriptor aMatchingFrame){
		return '''«FOR param:parameters»«param.cppForwardType(aMatchingFrame)» «param.name»«ENDFOR»'''
	}
	
	def cppForwardType(PParameter parameter, MatchingFrameDescriptor aMatchingFrame) 
	{
		val type = aMatchingFrame.getVariableLooseType(aMatchingFrame.getVariableFromParameter(parameter));
		val helper = CppHelper::getTypeHelper(type)
		return helper.declareType;
	}
	
}