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
package org.eclipse.viatra.query.tooling.cpp.rete.ui.handler;

import com.google.inject.Injector;
import java.util.HashMap;
import java.util.List;
import java.util.Set;
import java.util.function.Consumer;
import javax.inject.Inject;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IWorkspace;
import org.eclipse.core.resources.IWorkspaceRoot;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.NullProgressMonitor;
import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.ecore.resource.ResourceSet;
import org.eclipse.emf.ecore.util.EcoreUtil;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.ui.handlers.HandlerUtil;
import org.eclipse.viatra.query.patternlanguage.emf.eMFPatternLanguage.PatternModel;
import org.eclipse.viatra.query.patternlanguage.emf.specification.SpecificationBuilder;
import org.eclipse.viatra.query.patternlanguage.patternLanguage.Pattern;
import org.eclipse.viatra.query.runtime.api.IPatternMatch;
import org.eclipse.viatra.query.runtime.api.IQuerySpecification;
import org.eclipse.viatra.query.runtime.api.ViatraQueryMatcher;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PQuery;
import org.eclipse.viatra.query.tooling.cpp.localsearch.LocalSearchCppGenerator;
import org.eclipse.viatra.query.tooling.cpp.localsearch.api.IGeneratorOutputProvider;
import org.eclipse.viatra.query.tooling.cpp.localsearch.api.ILocalsearchGeneratorOutputProvider;
import org.eclipse.viatra.query.tooling.cpp.localsearch.serializer.DefaultSerializer;
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.fs.FileSystemAccess;
import org.eclipse.viatra.query.tooling.cpp.rete.ui.XTextFileAccessor;
import org.eclipse.xtend2.lib.StringConcatenation;
import org.eclipse.xtext.builder.EclipseResourceFileSystemAccess2;
import org.eclipse.xtext.generator.IContextualOutputConfigurationProvider;
import org.eclipse.xtext.generator.OutputConfiguration;
import org.eclipse.xtext.resource.XtextResourceSet;
import org.eclipse.xtext.xbase.lib.CollectionLiterals;
import org.eclipse.xtext.xbase.lib.Exceptions;
import org.eclipse.xtext.xbase.lib.Functions.Function1;
import org.eclipse.xtext.xbase.lib.IterableExtensions;
import org.eclipse.xtext.xbase.lib.ListExtensions;

/**
 * This class is a generic generate command handler called by both {@link IteratorGeneratorHandler} and {@link RuntimeGeneratorHandler}.
 * It returns the .vql resource based on the current selection, creates the code generator and it also sets up the Xtext based {@link FileSystemAccess}.
 * 
 * @author Robert Doczi
 */
@SuppressWarnings("all")
public class GeneratorHandler {
  @Inject
  private Injector injector;
  
  @Inject
  private IContextualOutputConfigurationProvider outputConfigurationProvider;
  
  public Object generate(final ExecutionEvent event, final Class<? extends ILocalsearchGeneratorOutputProvider> generatorClass) {
    final ISelection selection = HandlerUtil.getCurrentSelection(event);
    if ((selection instanceof IStructuredSelection)) {
      final XtextResourceSet xtextResourceSet = new XtextResourceSet();
      final Resource patternDefinitionResource = this.getPatternDefinitionResource(((IStructuredSelection)selection), xtextResourceSet);
      EList<EObject> _contents = patternDefinitionResource.getContents();
      final Consumer<EObject> _function = (EObject it) -> {
        EcoreUtil.resolveAll(it);
      };
      _contents.forEach(_function);
      URI _uRI = patternDefinitionResource.getURI();
      final String patternDefinitionResourceUri = _uRI.toString();
      int _lastIndexOf = patternDefinitionResourceUri.lastIndexOf(".");
      final String extensionlessUri = patternDefinitionResourceUri.substring(0, _lastIndexOf);
      int _lastIndexOf_1 = extensionlessUri.lastIndexOf("/");
      int _plus = (_lastIndexOf_1 + 1);
      final String fileName = extensionlessUri.substring(_plus);
      EList<EObject> _contents_1 = patternDefinitionResource.getContents();
      EObject _get = _contents_1.get(0);
      final PatternModel ast = ((PatternModel) _get);
      final EclipseResourceFileSystemAccess2 fileSystemAccess = this.getFileSystemAccess(patternDefinitionResource);
      final LocalSearchCppGenerator generator = new LocalSearchCppGenerator(generatorClass);
      final List<PQuery> pQueries = GeneratorHandler.astToPQueries(ast);
      final IGeneratorOutputProvider outputProvider = generator.generate(fileName, patternDefinitionResource, pQueries);
      final DefaultSerializer serializer = new DefaultSerializer();
      XTextFileAccessor _xTextFileAccessor = new XTextFileAccessor(fileSystemAccess);
      serializer.serialize("", outputProvider, _xTextFileAccessor);
    }
    return null;
  }
  
  public EclipseResourceFileSystemAccess2 getFileSystemAccess(final Resource resource) {
    final EclipseResourceFileSystemAccess2 fileSystemAccess = new EclipseResourceFileSystemAccess2();
    this.injector.injectMembers(fileSystemAccess);
    IWorkspace _workspace = ResourcesPlugin.getWorkspace();
    final IWorkspaceRoot workspaceRoot = _workspace.getRoot();
    URI _uRI = resource.getURI();
    String _segment = _uRI.segment(1);
    final IProject project = workspaceRoot.getProject(_segment);
    fileSystemAccess.setProject(project);
    NullProgressMonitor _nullProgressMonitor = new NullProgressMonitor();
    fileSystemAccess.setMonitor(_nullProgressMonitor);
    final Set<OutputConfiguration> outputConfigurations = this.outputConfigurationProvider.getOutputConfigurations(resource);
    final HashMap<String, OutputConfiguration> outputConfigurationsMap = CollectionLiterals.<String, OutputConfiguration>newHashMap();
    final Consumer<OutputConfiguration> _function = (OutputConfiguration it) -> {
      StringConcatenation _builder = new StringConcatenation();
      _builder.append("./cpp-gen");
      it.setOutputDirectory(_builder.toString());
      String _name = it.getName();
      outputConfigurationsMap.put(_name, it);
    };
    outputConfigurations.forEach(_function);
    fileSystemAccess.setOutputConfigurations(outputConfigurationsMap);
    return fileSystemAccess;
  }
  
  public Resource getPatternDefinitionResource(final IStructuredSelection selection, final ResourceSet loader) {
    Object _firstElement = selection.getFirstElement();
    IPath _fullPath = ((IFile) _firstElement).getFullPath();
    String _portableString = _fullPath.toPortableString();
    URI _createPlatformResourceURI = URI.createPlatformResourceURI(_portableString, true);
    return loader.getResource(_createPlatformResourceURI, 
      true);
  }
  
  public static List<PQuery> astToPQueries(final PatternModel ast) {
    final SpecificationBuilder specBuilder = new SpecificationBuilder();
    EList<Pattern> _patterns = ast.getPatterns();
    final Function1<Pattern, PQuery> _function = (Pattern pattern) -> {
      PQuery _xtrycatchfinallyexpression = null;
      try {
        IQuerySpecification<? extends ViatraQueryMatcher<? extends IPatternMatch>> _orCreateSpecification = specBuilder.getOrCreateSpecification(pattern);
        _xtrycatchfinallyexpression = _orCreateSpecification.getInternalQueryRepresentation();
      } catch (final Throwable _t) {
        if (_t instanceof ViatraQueryException) {
          final ViatraQueryException ex = (ViatraQueryException)_t;
          _xtrycatchfinallyexpression = null;
        } else {
          throw Exceptions.sneakyThrow(_t);
        }
      }
      return _xtrycatchfinallyexpression;
    };
    List<PQuery> _map = ListExtensions.<Pattern, PQuery>map(_patterns, _function);
    Iterable<PQuery> _filterNull = IterableExtensions.<PQuery>filterNull(_map);
    return IterableExtensions.<PQuery>toList(_filterNull);
  }
}
