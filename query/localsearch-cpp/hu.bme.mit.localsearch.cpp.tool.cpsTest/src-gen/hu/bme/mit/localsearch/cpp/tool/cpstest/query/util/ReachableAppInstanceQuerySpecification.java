/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import com.google.common.collect.Sets;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.ReachableAppInstanceMatch;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.ReachableAppInstanceMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.AppTypeInstanceAndHostQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.ReachableHostsQuerySpecification;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import org.eclipse.viatra.query.runtime.api.ViatraQueryEngine;
import org.eclipse.viatra.query.runtime.api.impl.BaseGeneratedEMFPQuery;
import org.eclipse.viatra.query.runtime.api.impl.BaseGeneratedEMFQuerySpecification;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;
import org.eclipse.viatra.query.runtime.matchers.psystem.PBody;
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable;
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.ExportedParameter;
import org.eclipse.viatra.query.runtime.matchers.psystem.basicenumerables.PositivePatternCall;
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PParameter;
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.QueryInitializationException;
import org.eclipse.viatra.query.runtime.matchers.tuple.FlatTuple;

/**
 * A pattern-specific query specification that can instantiate ReachableAppInstanceMatcher in a type-safe way.
 * 
 * @see ReachableAppInstanceMatcher
 * @see ReachableAppInstanceMatch
 * 
 */
@SuppressWarnings("all")
public final class ReachableAppInstanceQuerySpecification extends BaseGeneratedEMFQuerySpecification<ReachableAppInstanceMatcher> {
  private ReachableAppInstanceQuerySpecification() {
    super(GeneratedPQuery.INSTANCE);
  }
  
  /**
   * @return the singleton instance of the query specification
   * @throws ViatraQueryException if the pattern definition could not be loaded
   * 
   */
  public static ReachableAppInstanceQuerySpecification instance() throws ViatraQueryException {
    try{
    	return LazyHolder.INSTANCE;
    } catch (ExceptionInInitializerError err) {
    	throw processInitializerError(err);
    }
  }
  
  @Override
  protected ReachableAppInstanceMatcher instantiate(final ViatraQueryEngine engine) throws ViatraQueryException {
    return ReachableAppInstanceMatcher.on(engine);
  }
  
  @Override
  public ReachableAppInstanceMatch newEmptyMatch() {
    return ReachableAppInstanceMatch.newEmptyMatch();
  }
  
  @Override
  public ReachableAppInstanceMatch newMatch(final Object... parameters) {
    return ReachableAppInstanceMatch.newMatch((org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance) parameters[0], (org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationType) parameters[1], (org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationInstance) parameters[2]);
  }
  
  /**
   * Inner class allowing the singleton instance of {@link ReachableAppInstanceQuerySpecification} to be created 
   * 	<b>not</b> at the class load time of the outer class, 
   * 	but rather at the first call to {@link ReachableAppInstanceQuerySpecification#instance()}.
   * 
   * <p> This workaround is required e.g. to support recursion.
   * 
   */
  private static class LazyHolder {
    private final static ReachableAppInstanceQuerySpecification INSTANCE = new ReachableAppInstanceQuerySpecification();
    
    /**
     * Statically initializes the query specification <b>after</b> the field {@link #INSTANCE} is assigned.
     * This initialization order is required to support indirect recursion.
     * 
     * <p> The static initializer is defined using a helper field to work around limitations of the code generator.
     * 
     */
    private final static Object STATIC_INITIALIZER = ensureInitialized();
    
    public static Object ensureInitialized() {
      INSTANCE.ensureInitializedInternalSneaky();
      return null;
    }
  }
  
  private static class GeneratedPQuery extends BaseGeneratedEMFPQuery {
    private final static ReachableAppInstanceQuerySpecification.GeneratedPQuery INSTANCE = new GeneratedPQuery();
    
    @Override
    public String getFullyQualifiedName() {
      return "hu.bme.mit.localsearch.cpp.tool.cpstest.query.reachableAppInstance";
    }
    
    @Override
    public List<String> getParameterNames() {
      return Arrays.asList("sourceHostInstance","app","appInstance");
    }
    
    @Override
    public List<PParameter> getParameters() {
      return Arrays.asList(
      			 new PParameter("sourceHostInstance", "org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance"),
      			 new PParameter("app", "org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationType"),
      			 new PParameter("appInstance", "org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationInstance")
      			);
    }
    
    @Override
    public Set<PBody> doGetContainedBodies() throws QueryInitializationException {
      Set<PBody> bodies = Sets.newLinkedHashSet();
      try {
      	{
      		PBody body = new PBody(this);
      		PVariable var_sourceHostInstance = body.getOrCreateVariableByName("sourceHostInstance");
      		PVariable var_app = body.getOrCreateVariableByName("app");
      		PVariable var_appInstance = body.getOrCreateVariableByName("appInstance");
      		PVariable var_targetHostInstance = body.getOrCreateVariableByName("targetHostInstance");
      		body.setSymbolicParameters(Arrays.<ExportedParameter>asList(
      		   new ExportedParameter(body, var_sourceHostInstance, "sourceHostInstance"),
      		   new ExportedParameter(body, var_app, "app"),
      		   new ExportedParameter(body, var_appInstance, "appInstance")
      		));
      		// 	find appTypeInstanceAndHost(app, appInstance, targetHostInstance)
      		new PositivePatternCall(body, new FlatTuple(var_app, var_appInstance, var_targetHostInstance), AppTypeInstanceAndHostQuerySpecification.instance().getInternalQueryRepresentation());
      		// 	// there is a source hostInstance that could communicate with either hostInstance	find reachableHosts(sourceHostInstance, targetHostInstance)
      		new PositivePatternCall(body, new FlatTuple(var_sourceHostInstance, var_targetHostInstance), ReachableHostsQuerySpecification.instance().getInternalQueryRepresentation());
      		bodies.add(body);
      	}
      	// to silence compiler error
      	if (false) throw new ViatraQueryException("Never", "happens");
      } catch (ViatraQueryException ex) {
      	throw processDependencyException(ex);
      }
      return bodies;
    }
  }
}
