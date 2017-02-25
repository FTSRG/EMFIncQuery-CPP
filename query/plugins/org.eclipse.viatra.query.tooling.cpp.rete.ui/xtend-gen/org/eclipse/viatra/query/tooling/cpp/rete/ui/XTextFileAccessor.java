/**
 * Copyright (c) 2014-2016 Robert Doczi, IncQuery Labs Ltd.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Contributors:
 *     Robert Doczi - initial API and implementation
 */
package org.eclipse.viatra.query.tooling.cpp.rete.ui;

import com.google.common.base.Objects;
import java.io.File;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IWorkspace;
import org.eclipse.core.resources.IWorkspaceRoot;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.Path;
import org.eclipse.emf.common.util.URI;
import org.eclipse.viatra.query.tooling.cpp.localsearch.serializer.IFileAccessor;
import org.eclipse.xtend2.lib.StringConcatenation;
import org.eclipse.xtext.builder.EclipseResourceFileSystemAccess2;
import org.eclipse.xtext.generator.IFileSystemAccess;

/**
 * @author Robert Doczi
 */
@SuppressWarnings("all")
public class XTextFileAccessor implements IFileAccessor {
  private final IFileSystemAccess fsa;
  
  public XTextFileAccessor(final IFileSystemAccess fsa) {
    this.fsa = fsa;
  }
  
  @Override
  public void createFile(final String folderPath, final String fileName, final CharSequence contents) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append(folderPath, "");
    _builder.append(File.separator, "");
    _builder.append(fileName, "");
    final String path = _builder.toString();
    this.fsa.generateFile(path, contents);
  }
  
  @Override
  public void deleteFile(final String folderPath, final String fileName) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append(folderPath, "");
    _builder.append(File.separator, "");
    _builder.append(fileName, "");
    this.fsa.deleteFile(_builder.toString());
  }
  
  @Override
  public void createFolder(final String folderPath, final String folderName) {
    throw new UnsupportedOperationException("XText IFileSystemAccess does not support folder creation");
  }
  
  @Override
  public String localURI(final String folder) {
    boolean _equals = Objects.equal(((EclipseResourceFileSystemAccess2) this.fsa), null);
    if (_equals) {
      throw new UnsupportedOperationException(
        "Only EclipseResourceFileSystemAccess2 can be used to determine");
    }
    IWorkspace _workspace = ResourcesPlugin.getWorkspace();
    IWorkspaceRoot _root = _workspace.getRoot();
    URI _uRI = ((EclipseResourceFileSystemAccess2) this.fsa).getURI(folder);
    String _platformString = _uRI.toPlatformString(true);
    Path _path = new Path(_platformString);
    IFile _file = _root.getFile(_path);
    java.net.URI _locationURI = _file.getLocationURI();
    String str = _locationURI.getPath();
    String _property = System.getProperty("os.name");
    String _lowerCase = _property.toLowerCase();
    boolean _contains = _lowerCase.contains("windows");
    if (_contains) {
      String _substring = str.substring(1);
      str = _substring;
    }
    return str;
  }
}
