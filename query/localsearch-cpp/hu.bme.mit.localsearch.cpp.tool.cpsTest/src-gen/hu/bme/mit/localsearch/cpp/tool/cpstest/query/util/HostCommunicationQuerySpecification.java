/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import com.google.common.collect.Sets;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.HostCommunicationMatch;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.HostCommunicationMatcher;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.viatra.query.runtime.api.ViatraQueryEngine;
import org.eclipse.viatra.query.runtime.api.impl.BaseGeneratedEMFPQuery;
import org.eclipse.viatra.query.runtime.api.impl.BaseGeneratedEMFQuerySpecification;
import org.eclipse.viatra.query.runtime.emf.types.EClassTransitiveInstancesKey;
import org.eclipse.viatra.query.runtime.emf.types.EStructuralFeatureInstancesKey;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;
import org.eclipse.viatra.query.runtime.matchers.psystem.PBody;
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable;
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.Equality;
import org.eclipse.viatra.query.runtime.matchers.psystem.basicdeferred.ExportedParameter;
import org.eclipse.viatra.query.runtime.matchers.psystem.basicenumerables.TypeConstraint;
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PParameter;
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.QueryInitializationException;
import org.eclipse.viatra.query.runtime.matchers.tuple.FlatTuple;

/**
 * A pattern-specific query specification that can instantiate HostCommunicationMatcher in a type-safe way.
 * 
 * @see HostCommunicationMatcher
 * @see HostCommunicationMatch
 * 
 */
@SuppressWarnings("all")
public final class HostCommunicationQuerySpecification extends BaseGeneratedEMFQuerySpecification<HostCommunicationMatcher> {
  private HostCommunicationQuerySpecification() {
    super(GeneratedPQuery.INSTANCE);
  }
  
  /**
   * @return the singleton instance of the query specification
   * @throws ViatraQueryException if the pattern definition could not be loaded
   * 
   */
  public static HostCommunicationQuerySpecification instance() throws ViatraQueryException {
    try{
    	return LazyHolder.INSTANCE;
    } catch (ExceptionInInitializerError err) {
    	throw processInitializerError(err);
    }
  }
  
  @Override
  protected HostCommunicationMatcher instantiate(final ViatraQueryEngine engine) throws ViatraQueryException {
    return HostCommunicationMatcher.on(engine);
  }
  
  @Override
  public HostCommunicationMatch newEmptyMatch() {
    return HostCommunicationMatch.newEmptyMatch();
  }
  
  @Override
  public HostCommunicationMatch newMatch(final Object... parameters) {
    return HostCommunicationMatch.newMatch((org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance) parameters[0], (org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance) parameters[1]);
  }
  
  /**
   * Inner class allowing the singleton instance of {@link HostCommunicationQuerySpecification} to be created 
   * 	<b>not</b> at the class load time of the outer class, 
   * 	but rather at the first call to {@link HostCommunicationQuerySpecification#instance()}.
   * 
   * <p> This workaround is required e.g. to support recursion.
   * 
   */
  private static class LazyHolder {
    private final static HostCommunicationQuerySpecification INSTANCE = new HostCommunicationQuerySpecification();
    
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
    private final static HostCommunicationQuerySpecification.GeneratedPQuery INSTANCE = new GeneratedPQuery();
    
    @Override
    public String getFullyQualifiedName() {
      return "hu.bme.mit.localsearch.cpp.tool.cpstest.query.hostCommunication";
    }
    
    @Override
    public List<String> getParameterNames() {
      return Arrays.asList("fromHost","toHost");
    }
    
    @Override
    public List<PParameter> getParameters() {
      return Arrays.asList(
      			 new PParameter("fromHost", "org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance"),
      			 new PParameter("toHost", "org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance")
      			);
    }
    
    @Override
    public Set<PBody> doGetContainedBodies() throws QueryInitializationException {
      Set<PBody> bodies = Sets.newLinkedHashSet();
      try {
      	{
      		PBody body = new PBody(this);
      		PVariable var_fromHost = body.getOrCreateVariableByName("fromHost");
      		PVariable var_toHost = body.getOrCreateVariableByName("toHost");
      		body.setSymbolicParameters(Arrays.<ExportedParameter>asList(
      		   new ExportedParameter(body, var_fromHost, "fromHost"),
      		   new ExportedParameter(body, var_toHost, "toHost")
      		));
      		// 	HostInstance.communicateWith(fromHost, toHost)
      		new TypeConstraint(body, new FlatTuple(var_fromHost), new EClassTransitiveInstancesKey((EClass)getClassifierLiteral("http://org.eclipse.viatra/model/cps", "HostInstance")));
      		PVariable var__virtual_0_ = body.getOrCreateVariableByName(".virtual{0}");
      		new TypeConstraint(body, new FlatTuple(var_fromHost, var__virtual_0_), new EStructuralFeatureInstancesKey(getFeatureLiteral("http://org.eclipse.viatra/model/cps", "HostInstance", "communicateWith")));
      		new Equality(body, var__virtual_0_, var_toHost);
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
