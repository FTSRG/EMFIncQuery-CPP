/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.ReachableAppInstanceMatch;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.ReachableAppInstanceQuerySpecification;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;
import org.apache.log4j.Logger;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationInstance;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationType;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;
import org.eclipse.viatra.query.runtime.api.IQuerySpecification;
import org.eclipse.viatra.query.runtime.api.ViatraQueryEngine;
import org.eclipse.viatra.query.runtime.api.impl.BaseMatcher;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;
import org.eclipse.viatra.query.runtime.matchers.tuple.Tuple;
import org.eclipse.viatra.query.runtime.util.ViatraQueryLoggingUtil;

/**
 * Generated pattern matcher API of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.reachableAppInstance pattern,
 * providing pattern-specific query methods.
 * 
 * <p>Use the pattern matcher on a given model via {@link #on(ViatraQueryEngine)},
 * e.g. in conjunction with {@link ViatraQueryEngine#on(Notifier)}.
 * 
 * <p>Matches of the pattern will be represented as {@link ReachableAppInstanceMatch}.
 * 
 * <p>Original source:
 * <code><pre>
 * pattern reachableAppInstance(sourceHostInstance, app, appInstance) {
 * 	find appTypeInstanceAndHost(app, appInstance, targetHostInstance);
 * 	// there is a source hostInstance that could communicate with either hostInstance
 * 	find reachableHosts(sourceHostInstance, targetHostInstance);
 * }
 * </pre></code>
 * 
 * @see ReachableAppInstanceMatch
 * @see ReachableAppInstanceProcessor
 * @see ReachableAppInstanceQuerySpecification
 * 
 */
@SuppressWarnings("all")
public class ReachableAppInstanceMatcher extends BaseMatcher<ReachableAppInstanceMatch> {
  /**
   * Initializes the pattern matcher within an existing VIATRA Query engine.
   * If the pattern matcher is already constructed in the engine, only a light-weight reference is returned.
   * The match set will be incrementally refreshed upon updates.
   * @param engine the existing VIATRA Query engine in which this matcher will be created.
   * @throws ViatraQueryException if an error occurs during pattern matcher creation
   * 
   */
  public static ReachableAppInstanceMatcher on(final ViatraQueryEngine engine) throws ViatraQueryException {
    // check if matcher already exists
    ReachableAppInstanceMatcher matcher = engine.getExistingMatcher(querySpecification());
    if (matcher == null) {
    	matcher = new ReachableAppInstanceMatcher(engine);
    	// do not have to "put" it into engine.matchers, reportMatcherInitialized() will take care of it
    }
    return matcher;
  }
  
  private final static int POSITION_SOURCEHOSTINSTANCE = 0;
  
  private final static int POSITION_APP = 1;
  
  private final static int POSITION_APPINSTANCE = 2;
  
  private final static Logger LOGGER = ViatraQueryLoggingUtil.getLogger(ReachableAppInstanceMatcher.class);
  
  /**
   * Initializes the pattern matcher within an existing VIATRA Query engine.
   * If the pattern matcher is already constructed in the engine, only a light-weight reference is returned.
   * The match set will be incrementally refreshed upon updates.
   * @param engine the existing VIATRA Query engine in which this matcher will be created.
   * @throws ViatraQueryException if an error occurs during pattern matcher creation
   * 
   */
  private ReachableAppInstanceMatcher(final ViatraQueryEngine engine) throws ViatraQueryException {
    super(engine, querySpecification());
  }
  
  /**
   * Returns the set of all matches of the pattern that conform to the given fixed values of some parameters.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @return matches represented as a ReachableAppInstanceMatch object.
   * 
   */
  public Collection<ReachableAppInstanceMatch> getAllMatches(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return rawGetAllMatches(new Object[]{pSourceHostInstance, pApp, pAppInstance});
  }
  
  /**
   * Returns an arbitrarily chosen match of the pattern that conforms to the given fixed values of some parameters.
   * Neither determinism nor randomness of selection is guaranteed.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @return a match represented as a ReachableAppInstanceMatch object, or null if no match is found.
   * 
   */
  public ReachableAppInstanceMatch getOneArbitraryMatch(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return rawGetOneArbitraryMatch(new Object[]{pSourceHostInstance, pApp, pAppInstance});
  }
  
  /**
   * Indicates whether the given combination of specified pattern parameters constitute a valid pattern match,
   * under any possible substitution of the unspecified parameters (if any).
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @return true if the input is a valid (partial) match of the pattern.
   * 
   */
  public boolean hasMatch(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return rawHasMatch(new Object[]{pSourceHostInstance, pApp, pAppInstance});
  }
  
  /**
   * Returns the number of all matches of the pattern that conform to the given fixed values of some parameters.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @return the number of pattern matches found.
   * 
   */
  public int countMatches(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return rawCountMatches(new Object[]{pSourceHostInstance, pApp, pAppInstance});
  }
  
  /**
   * Executes the given processor on each match of the pattern that conforms to the given fixed values of some parameters.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param processor the action that will process each pattern match.
   * 
   */
  public void forEachMatch(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance, final IMatchProcessor<? super ReachableAppInstanceMatch> processor) {
    rawForEachMatch(new Object[]{pSourceHostInstance, pApp, pAppInstance}, processor);
  }
  
  /**
   * Executes the given processor on an arbitrarily chosen match of the pattern that conforms to the given fixed values of some parameters.
   * Neither determinism nor randomness of selection is guaranteed.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param processor the action that will process the selected match.
   * @return true if the pattern has at least one match with the given parameter values, false if the processor was not invoked
   * 
   */
  public boolean forOneArbitraryMatch(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance, final IMatchProcessor<? super ReachableAppInstanceMatch> processor) {
    return rawForOneArbitraryMatch(new Object[]{pSourceHostInstance, pApp, pAppInstance}, processor);
  }
  
  /**
   * Returns a new (partial) match.
   * This can be used e.g. to call the matcher with a partial match.
   * <p>The returned match will be immutable. Use {@link #newEmptyMatch()} to obtain a mutable match object.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @return the (partial) match object.
   * 
   */
  public ReachableAppInstanceMatch newMatch(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return ReachableAppInstanceMatch.newMatch(pSourceHostInstance, pApp, pAppInstance);
  }
  
  /**
   * Retrieve the set of values that occur in matches for sourceHostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  protected Set<HostInstance> rawAccumulateAllValuesOfsourceHostInstance(final Object[] parameters) {
    Set<HostInstance> results = new HashSet<HostInstance>();
    rawAccumulateAllValues(POSITION_SOURCEHOSTINSTANCE, parameters, results);
    return results;
  }
  
  /**
   * Retrieve the set of values that occur in matches for sourceHostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOfsourceHostInstance() {
    return rawAccumulateAllValuesOfsourceHostInstance(emptyArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for sourceHostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOfsourceHostInstance(final ReachableAppInstanceMatch partialMatch) {
    return rawAccumulateAllValuesOfsourceHostInstance(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for sourceHostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOfsourceHostInstance(final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return rawAccumulateAllValuesOfsourceHostInstance(new Object[]{
    null, 
    pApp, 
    pAppInstance
    });
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  protected Set<ApplicationType> rawAccumulateAllValuesOfapp(final Object[] parameters) {
    Set<ApplicationType> results = new HashSet<ApplicationType>();
    rawAccumulateAllValues(POSITION_APP, parameters, results);
    return results;
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<ApplicationType> getAllValuesOfapp() {
    return rawAccumulateAllValuesOfapp(emptyArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<ApplicationType> getAllValuesOfapp(final ReachableAppInstanceMatch partialMatch) {
    return rawAccumulateAllValuesOfapp(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<ApplicationType> getAllValuesOfapp(final HostInstance pSourceHostInstance, final ApplicationInstance pAppInstance) {
    return rawAccumulateAllValuesOfapp(new Object[]{
    pSourceHostInstance, 
    null, 
    pAppInstance
    });
  }
  
  /**
   * Retrieve the set of values that occur in matches for appInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  protected Set<ApplicationInstance> rawAccumulateAllValuesOfappInstance(final Object[] parameters) {
    Set<ApplicationInstance> results = new HashSet<ApplicationInstance>();
    rawAccumulateAllValues(POSITION_APPINSTANCE, parameters, results);
    return results;
  }
  
  /**
   * Retrieve the set of values that occur in matches for appInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<ApplicationInstance> getAllValuesOfappInstance() {
    return rawAccumulateAllValuesOfappInstance(emptyArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for appInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<ApplicationInstance> getAllValuesOfappInstance(final ReachableAppInstanceMatch partialMatch) {
    return rawAccumulateAllValuesOfappInstance(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for appInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<ApplicationInstance> getAllValuesOfappInstance(final HostInstance pSourceHostInstance, final ApplicationType pApp) {
    return rawAccumulateAllValuesOfappInstance(new Object[]{
    pSourceHostInstance, 
    pApp, 
    null
    });
  }
  
  @Override
  protected ReachableAppInstanceMatch tupleToMatch(final Tuple t) {
    try {
    	return ReachableAppInstanceMatch.newMatch((HostInstance) t.get(POSITION_SOURCEHOSTINSTANCE), (ApplicationType) t.get(POSITION_APP), (ApplicationInstance) t.get(POSITION_APPINSTANCE));
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in tuple not properly typed!",e);
    	return null;
    }
  }
  
  @Override
  protected ReachableAppInstanceMatch arrayToMatch(final Object[] match) {
    try {
    	return ReachableAppInstanceMatch.newMatch((HostInstance) match[POSITION_SOURCEHOSTINSTANCE], (ApplicationType) match[POSITION_APP], (ApplicationInstance) match[POSITION_APPINSTANCE]);
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in array not properly typed!",e);
    	return null;
    }
  }
  
  @Override
  protected ReachableAppInstanceMatch arrayToMatchMutable(final Object[] match) {
    try {
    	return ReachableAppInstanceMatch.newMutableMatch((HostInstance) match[POSITION_SOURCEHOSTINSTANCE], (ApplicationType) match[POSITION_APP], (ApplicationInstance) match[POSITION_APPINSTANCE]);
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in array not properly typed!",e);
    	return null;
    }
  }
  
  /**
   * @return the singleton instance of the query specification of this pattern
   * @throws ViatraQueryException if the pattern definition could not be loaded
   * 
   */
  public static IQuerySpecification<ReachableAppInstanceMatcher> querySpecification() throws ViatraQueryException {
    return ReachableAppInstanceQuerySpecification.instance();
  }
}
