package org.eclipse.viatra.query.tooling.cpp.rete;

import java.util.List;
import org.eclipse.emf.common.notify.Notifier;
import org.eclipse.emf.common.notify.impl.BasicNotifierImpl;
import org.eclipse.viatra.query.runtime.api.ViatraQueryEngine;
import org.eclipse.viatra.query.runtime.api.ViatraQueryEngineManager;
import org.eclipse.viatra.query.runtime.emf.EMFScope;
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PQuery;
import org.eclipse.viatra.query.tooling.cpp.localsearch.serializer.IFileAccessor;
import org.eclipse.xtext.xbase.lib.Exceptions;

@SuppressWarnings("all")
public class ReteGeneratorEntryPoint {
  public static ViatraQueryEngine generate(final List<PQuery> queries, final IFileAccessor fsa) {
    try {
      ViatraQueryEngine _xblockexpression = null;
      {
        final Notifier notif = new BasicNotifierImpl();
        ViatraQueryEngineManager _instance = ViatraQueryEngineManager.getInstance();
        EMFScope _eMFScope = new EMFScope(notif);
        _xblockexpression = _instance.getQueryEngine(_eMFScope);
      }
      return _xblockexpression;
    } catch (Throwable _e) {
      throw Exceptions.sneakyThrow(_e);
    }
  }
}
