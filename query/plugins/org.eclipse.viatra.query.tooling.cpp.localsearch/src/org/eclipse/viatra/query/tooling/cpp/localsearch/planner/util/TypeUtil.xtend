package org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util

import org.eclipse.emf.ecore.EcorePackage
import org.eclipse.emf.ecore.impl.EEnumImpl
import org.eclipse.emf.ecore.impl.EEnumLiteralImpl
import org.eclipse.viatra.query.runtime.emf.types.EDataTypeInSlotsKey
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper

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
			Integer:{
				return o.toString
			}
			EEnumLiteralImpl: {
				val eEnumImpl = o.eContainer as EEnumImpl
				return '''«CppHelper::getTypeHelper(eEnumImpl).FQN»::«o.toString»'''
			}
			default:{
				println("Unidentified constant value's type of " + o.toString)
				return o.toString
			}
		}
	}
	
	static def getDataType(Object o){
		switch(o){
			Integer:{
				return new EDataTypeInSlotsKey(EcorePackage.Literals.EINT)
			}
			Boolean:{
				return new EDataTypeInSlotsKey(EcorePackage.Literals.EBOOLEAN)
			}
			Double:{
				return new EDataTypeInSlotsKey(EcorePackage.Literals.EDOUBLE)
			}
			String:{
				return new EDataTypeInSlotsKey(EcorePackage.Literals.ESTRING)
			}
			Float:{
				return new EDataTypeInSlotsKey(EcorePackage.Literals.EFLOAT)
			}
			EEnumLiteralImpl: {
				return new EDataTypeInSlotsKey((o.eContainer as EEnumImpl))
			}
			default:{
				println("Unidentified constant value's type: " + o.toString)
				return new EDataTypeInSlotsKey(EcorePackage.Literals.EINT)
			}
		}
	}
	
	static def getEIntDataType(){
		return new EDataTypeInSlotsKey(EcorePackage.Literals.EINT)
	}
}