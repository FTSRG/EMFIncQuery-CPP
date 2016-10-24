package org.eclipse.viatra.query.tooling.cpp.localsearch.proto

abstract class ProtoCompiler {
	
	protected val String unitName
	
	abstract def CharSequence compile()
	
	new(String name){
		unitName = name
	}
	

	override hashCode() {
		val prime = 31;
		var result = 1;
		if(unitName == null) result = prime * result
		else result = prime * result + unitName.hashCode()
		return result;
	}
	
	override equals(Object obj) {
		var ProtoCompiler other =  obj as ProtoCompiler;
		if (unitName == null) {
			if (other.unitName != null)
				return false;
		} else if (!unitName.equals(other.unitName))
			return false;
		return true;
	}
	
}