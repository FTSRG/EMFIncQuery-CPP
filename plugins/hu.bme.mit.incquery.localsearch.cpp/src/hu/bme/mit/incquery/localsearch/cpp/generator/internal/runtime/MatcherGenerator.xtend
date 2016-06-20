package hu.bme.mit.incquery.localsearch.cpp.generator.internal.runtime

import hu.bme.mit.incquery.localsearch.cpp.generator.internal.ViatraQueryHeaderGenerator
import hu.bme.mit.incquery.localsearch.cpp.generator.model.MatchingFrameStub
import hu.bme.mit.incquery.localsearch.cpp.generator.model.PatternStub
import java.util.List
import hu.bme.mit.incquery.localsearch.cpp.generator.internal.common.NameUtils
import org.eclipse.emf.ecore.EClassifier
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable

class MatcherGenerator extends ViatraQueryHeaderGenerator {
	
	val String name
	List<PatternStub> patterns
	
	MatchingFrameStub matchingFrame

	new(String patternName, List<PatternStub> patterns, MatchingFrameStub frame) {
		super(#{patternName}, '''«patternName»Matcher''')
		this.name = patternName
		this.patterns = patterns
		this.matchingFrame = frame
	}
	
	override compileInner() '''
		template<class ModelRoot>
		class «name»Matcher {
		public:
			friend class ::Viatra::Query::QueryEngine<ModelRoot>;
		
			«FOR pattern : patterns»
				«compileGetter(pattern)»
			«ENDFOR»
		
		private:
			SchoolMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
				: _model(model), _context(context) {
			}
		
			const ModelRoot* _model;
			const ::Viatra::Query::Matcher::ISearchContext* _context;
		};
	'''
	
	private def compileGetter(PatternStub pattern) '''
		std::unordered_set<«name»Match> matches(«getParamList(pattern)») const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::SearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			std::unordered_set<«name»Match> matches;
		
			auto sp = «name»QuerySpec<ModelRoot>::get_plan_«NameUtils::getPlanName(pattern)»(_model);
			
			SearchPlanExecutor<«name»Frame> exec(sp, *_context);
		
			for (auto&& frame : exec) {
				«name»Match match;
				
				«fillMatch»
				
				matches.insert(match);
			}
		
			return matches;
		}
	'''
	
	private def fillMatch() '''
		«FOR keyVariable : matchingFrame.keyVariables»
			match.«keyVariable.name» = static_cast<«keyVariable.type»>
		«ENDFOR»
	'''
	
	private def getParamList(PatternStub pattern) {
		pattern.boundVariables.map['''«it.type» «it.name»'''].join(", ")		
	}
	
	private def toTypeName(EClassifier clazz) {
		NameUtils::toTypeName(clazz)		
	}
	
	private def type(PVariable variable) {
		matchingFrame.getVariableStrictType(variable).toTypeName
	}
}