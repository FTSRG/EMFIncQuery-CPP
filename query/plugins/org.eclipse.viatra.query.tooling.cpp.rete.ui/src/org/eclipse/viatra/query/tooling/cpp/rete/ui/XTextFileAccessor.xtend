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
package org.eclipse.viatra.query.tooling.cpp.rete.ui

import org.eclipse.viatra.query.tooling.cpp.localsearch.serializer.IFileAccessor
import java.io.File
import org.eclipse.xtext.generator.IFileSystemAccess
import org.eclipse.xtext.builder.EclipseResourceFileSystemAccess2
import org.eclipse.core.resources.ResourcesPlugin
import org.eclipse.core.runtime.Path

/**
 * @author Robert Doczi
 */
public class XTextFileAccessor implements IFileAccessor {
	
	val IFileSystemAccess fsa
	
	new (IFileSystemAccess fsa) {
		this.fsa = fsa
	}
	
	override createFile(String folderPath, String fileName, CharSequence contents) {
		val path = '''«folderPath»«File.separator»«fileName»'''
		fsa.generateFile(path, contents)
	}
	
	override deleteFile(String folderPath, String fileName) {
		fsa.deleteFile('''«folderPath»«File.separator»«fileName»''')
	}
	
	override createFolder(String folderPath, String folderName) {
		throw new UnsupportedOperationException("XText IFileSystemAccess does not support folder creation")
	}
	
	override localURI(String folder) {
		if((fsa as EclipseResourceFileSystemAccess2) == null)
			throw new UnsupportedOperationException(
			"Only EclipseResourceFileSystemAccess2 can be used to determine");
		
		var str = ResourcesPlugin.workspace.root.getFile(
			new Path((fsa as EclipseResourceFileSystemAccess2)
				.getURI(folder)
				.toPlatformString(true)
			)
		).locationURI.path
		
		// Windows -> no need for starting /
		if(System.getProperty ("os.name").toLowerCase().contains("windows"))
			str = str.substring(1);
		
		return str;
	}
	
}
