package org.eclipse.viatra.query.tooling.cpp.rete

import java.util.List
import org.eclipse.emf.common.notify.Notifier
import org.eclipse.viatra.query.runtime.api.ViatraQueryEngineManager
import org.eclipse.viatra.query.runtime.emf.EMFScope
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PQuery
import org.eclipse.viatra.query.tooling.cpp.localsearch.serializer.IFileAccessor
import org.eclipse.emf.common.notify.impl.BasicNotifierImpl

class ReteGeneratorEntryPoint {

	static def generate(List<PQuery> queries, IFileAccessor fsa)
	{
		val Notifier notif = new BasicNotifierImpl();
		
		ViatraQueryEngineManager::instance.getQueryEngine(new EMFScope(notif))
		
		
	}
}
