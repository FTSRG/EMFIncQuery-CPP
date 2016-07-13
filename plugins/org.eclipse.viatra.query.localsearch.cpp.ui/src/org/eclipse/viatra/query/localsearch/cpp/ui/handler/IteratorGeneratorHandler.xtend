/*******************************************************************************
 * Copyright (c) 2014-2016 Robert Doczi, IncQuery Labs Ltd.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Robert Doczi - initial API and implementation
 *******************************************************************************/
package org.eclipse.viatra.query.localsearch.cpp.ui.handler

import com.google.inject.Inject
import com.google.inject.Injector
import org.eclipse.viatra.query.localsearch.cpp.generator.internal.IteratorGeneratorContext
import org.eclipse.core.commands.AbstractHandler
import org.eclipse.core.commands.ExecutionEvent
import org.eclipse.core.commands.ExecutionException

/**
 * @author Robert Doczi
 */
class IteratorGeneratorHandler extends AbstractHandler {
	
	@Inject Injector injector	
	
	override execute(ExecutionEvent event) throws ExecutionException {
		val generatorHandler = new GeneratorHandler
		injector.injectMembers(generatorHandler)
		generatorHandler.generate(event, IteratorGeneratorContext)
		return null
	}

}
