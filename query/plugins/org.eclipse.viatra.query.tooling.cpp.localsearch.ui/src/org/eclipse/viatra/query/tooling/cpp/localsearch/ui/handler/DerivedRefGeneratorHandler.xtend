package org.eclipse.viatra.query.tooling.cpp.localsearch.ui.handler

import com.google.inject.Inject
import com.google.inject.Injector
import org.eclipse.core.commands.AbstractHandler
import org.eclipse.core.commands.ExecutionEvent
import org.eclipse.core.commands.ExecutionException
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.DerivedRefGeneratorContext

class DerivedRefGeneratorHandler extends AbstractHandler {
	
	@Inject Injector injector	
	
	override execute(ExecutionEvent event) throws ExecutionException {
		val generatorHandler = injector.getInstance(GeneratorHandler)
		generatorHandler.generate(event, DerivedRefGeneratorContext)
		return null
	}

}