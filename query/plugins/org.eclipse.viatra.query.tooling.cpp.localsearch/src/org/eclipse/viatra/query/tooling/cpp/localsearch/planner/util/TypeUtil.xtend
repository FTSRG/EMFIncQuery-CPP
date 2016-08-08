package org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util

class TypeUtil {
	static def getCppValue(Object o){
		switch(o){
			String:{
				return '''std::string("«o»")'''
			}
			Float:{
				return '''«o.floatValue»f'''
			}
			Double:{
				return o.doubleValue
			}
			Boolean:{
				return o.toString
			}
			default:{
				return o.toString
			}
		}
	}
}