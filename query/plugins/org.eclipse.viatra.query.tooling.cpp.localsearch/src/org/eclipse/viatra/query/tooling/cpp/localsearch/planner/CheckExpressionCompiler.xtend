package org.eclipse.viatra.query.tooling.cpp.localsearch.planner

import org.eclipse.viatra.query.patternlanguage.emf.specification.XBaseEvaluator
import org.eclipse.viatra.query.runtime.matchers.psystem.IExpressionEvaluator
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.ExpressionEvaluation
import org.eclipse.xtext.xbase.XExpression
import org.eclipse.xtext.xbase.impl.XBinaryOperationImplCustom
import org.eclipse.xtext.xbase.impl.XFeatureCallImplCustom
import org.eclipse.xtext.xbase.impl.XMemberFeatureCallImplCustom
import org.eclipse.xtext.xbase.impl.XNumberLiteralImpl
import org.eclipse.xtext.xbase.impl.XUnaryOperationImplCustom

class CheckExpressionCompiler {
		
	val XExpression expression;
		
	new(ExpressionEvaluation evaluation) {
		expression = obtainExpression(evaluation);
	}
	
	public def compileLambdaInner()
		'''
		// check(«expression.toString»);
		«returnOrAssert»
		'''
			
	
	
	
	public def String returnOrAssert()
	{
		try{
			return '''return «expression.compile»;''' 
		}	
		catch(Exception ex)
		{
			System.out.println(ex.message);
			return '''
				static_assert(false, "The check expression was failed to compile to C++. Please implement it manually.");
			'''
		}		
	}
	
	
	private static dispatch def String compile(XExpression exp){
		inspect(exp);
	}	
	
	private static dispatch def String compile(XBinaryOperationImplCustom exp){
		return '''(«exp.leftOperand.compile»«exp.getConcreteSyntaxFeatureName»«exp.rightOperand.compile»)'''
	}	
	
	private static dispatch def String compile(XUnaryOperationImplCustom exp){
		return '''(«exp.getConcreteSyntaxFeatureName»«exp.operand.compile»)'''
	}	
	
	private static dispatch def String compile(XNumberLiteralImpl exp){
		return exp.value.toString;
	}	
	private static dispatch def String compile(XFeatureCallImplCustom exp){
		return exp.feature.identifier;
	}	
	private static dispatch def String compile(XMemberFeatureCallImplCustom exp){
		val compiledArguments = exp.memberCallArguments.map[it.compile].join(", ");
					
		if(exp.staticWithDeclaringType)
			return '''«exp.feature.simpleName»(«compiledArguments»)'''
		else
			return '''«exp.memberCallTarget.compile»«exp.feature.simpleName»(«compiledArguments»)'''
	}	
		
	/*private static dispatch def String compile(XMemberFeatureCallImplCustom exp){
		return exp.featureCallArguments.map[feature|feature.compile].join(".");
	}	*/
		
	
	private static def String inspect(XExpression exp){
		throw new Exception("XExpression type ("+ exp.class.name +") cannot be compiled to c++");
	}
	
	private static def XExpression obtainExpression(ExpressionEvaluation ev){
		return reflectExpression(ev.evaluator);
	}
	
	private static dispatch def XExpression reflectExpression(XBaseEvaluator evaluator){	
		return evaluator.expression;
	}
	
	private static dispatch def XExpression reflectExpression(IExpressionEvaluator evaluator){
		val c = evaluator.getClass();

		val wrapped = c.getDeclaredField("wrapped");
		wrapped.setAccessible(true);
		val ev = wrapped.get(evaluator) as IExpressionEvaluator;
		return reflectExpression(ev);		
	}
}
	