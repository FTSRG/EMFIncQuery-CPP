/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.AppTypeInstanceAndHostMatch;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.AppTypeInstanceAndHostQuerySpecification;
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
 * Generated pattern matcher API of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.appTypeInstanceAndHost pattern,
 * providing pattern-specific query methods.
 * 
 * <p>Use the pattern matcher on a given model via {@link #on(ViatraQueryEngine)},
 * e.g. in conjunction with {@link ViatraQueryEngine#on(Notifier)}.
 * 
 * <p>Matches of the pattern will be represented as {@link AppTypeInstanceAndHostMatch}.
 * 
 * <p>Original source:
 * <code><pre>
 * pattern appTypeInstanceAndHost(app, appInstance, hostInstance) {
 * 	ApplicationInstance.type(appInstance, app);
 * 	ApplicationInstance.allocatedTo(appInstance, hostInstance);
 * }
 * </pre></code>
 * 
 * @see AppTypeInstanceAndHostMatch
 * @see AppTypeInstanceAndHostProcessor
 * @see AppTypeInstanceAndHostQuerySpecification
 * 
 */
@SuppressWarnings("all")
public class AppTypeInstanceAndHostMatcher extends BaseMatcher<AppTypeInstanceAndHostMatch> {
  /**
   * Initializes the pattern matcher within an existing VIATRA Query engine.
   * If the pattern matcher is already constructed in the engine, only a light-weight reference is returned.
   * The match set will be incrementally refreshed upon updates.
   * @param engine the existing VIATRA Query engine in which this matcher will be created.
   * @throws ViatraQueryException if an error occurs during pattern matcher creation
   * 
   */
  public static AppTypeInstanceAndHostMatcher on(final ViatraQueryEngine engine) throws ViatraQueryException {
    // check if matcher already exists
    AppTypeInstanceAndHostMatcher matcher = engine.getExistingMatcher(querySpecification());
    if (matcher == null) {
    	matcher = new AppTypeInstanceAndHostMatcher(engine);
    	// do not have to "put" it into engine.matchers, reportMatcherInitialized() will take care of it
    }
    return matcher;
  }
  
  private final static int POSITION_APP = 0;
  
  private final static int POSITION_APPINSTANCE = 1;
  
  private final static int POSITION_HOSTINSTANCE = 2;
  
  private final static Logger LOGGER = ViatraQueryLoggingUtil.getLogger(AppTypeInstanceAndHostMatcher.class);
  
  /**
   * Initializes the pattern matcher within an existing VIATRA Query engine.
   * If the pattern matcher is already constructed in the engine, only a light-weight reference is returned.
   * The match set will be incrementally refreshed upon updates.
   * @param engine the existing VIATRA Query engine in which this matcher will be created.
   * @throws ViatraQueryException if an error occurs during pattern matcher creation
   * 
   */
  private AppTypeInstanceAndHostMatcher(final ViatraQueryEngine engine) throws ViatraQueryException {
    super(engine, querySpecification());
  }
  
  /**
   * Returns the set of all matches of the pattern that conform to the given fixed values of some parameters.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param pHostInstance the fixed value of pattern parameter hostInstance, or null if not bound.
   * @return matches represented as a AppTypeInstanceAndHostMatch object.
   * 
   */
  public Collection<AppTypeInstanceAndHostMatch> getAllMatches(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    return rawGetAllMatches(new Object[]{pApp, pAppInstance, pHostInstance});
  }
  
  /**
   * Returns an arbitrarily chosen match of the pattern that conforms to the given fixed values of some parameters.
   * Neither determinism nor randomness of selection is guaranteed.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param pHostInstance the fixed value of pattern parameter hostInstance, or null if not bound.
   * @return a match represented as a AppTypeInstanceAndHostMatch object, or null if no match is found.
   * 
   */
  public AppTypeInstanceAndHostMatch getOneArbitraryMatch(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    return rawGetOneArbitraryMatch(new Object[]{pApp, pAppInstance, pHostInstance});
  }
  
  /**
   * Indicates whether the given combination of specified pattern parameters constitute a valid pattern match,
   * under any possible substitution of the unspecified parameters (if any).
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param pHostInstance the fixed value of pattern parameter hostInstance, or null if not bound.
   * @return true if the input is a valid (partial) match of the pattern.
   * 
   */
  public boolean hasMatch(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    return rawHasMatch(new Object[]{pApp, pAppInstance, pHostInstance});
  }
  
  /**
   * Returns the number of all matches of the pattern that conform to the given fixed values of some parameters.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param pHostInstance the fixed value of pattern parameter hostInstance, or null if not bound.
   * @return the number of pattern matches found.
   * 
   */
  public int countMatches(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    return rawCountMatches(new Object[]{pApp, pAppInstance, pHostInstance});
  }
  
  /**
   * Executes the given processor on each match of the pattern that conforms to the given fixed values of some parameters.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param pHostInstance the fixed value of pattern parameter hostInstance, or null if not bound.
   * @param processor the action that will process each pattern match.
   * 
   */
  public void forEachMatch(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance, final IMatchProcessor<? super AppTypeInstanceAndHostMatch> processor) {
    rawForEachMatch(new Object[]{pApp, pAppInstance, pHostInstance}, processor);
  }
  
  /**
   * Executes the given processor on an arbitrarily chosen match of the pattern that conforms to the given fixed values of some parameters.
   * Neither determinism nor randomness of selection is guaranteed.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param pHostInstance the fixed value of pattern parameter hostInstance, or null if not bound.
   * @param processor the action that will process the selected match.
   * @return true if the pattern has at least one match with the given parameter values, false if the processor was not invoked
   * 
   */
  public boolean forOneArbitraryMatch(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance, final IMatchProcessor<? super AppTypeInstanceAndHostMatch> processor) {
    return rawForOneArbitraryMatch(new Object[]{pApp, pAppInstance, pHostInstance}, processor);
  }
  
  /**
   * Returns a new (partial) match.
   * This can be used e.g. to call the matcher with a partial match.
   * <p>The returned match will be immutable. Use {@link #newEmptyMatch()} to obtain a mutable match object.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param pHostInstance the fixed value of pattern parameter hostInstance, or null if not bound.
   * @return the (partial) match object.
   * 
   */
  public AppTypeInstanceAndHostMatch newMatch(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    return AppTypeInstanceAndHostMatch.newMatch(pApp, pAppInstance, pHostInstance);
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
  public Set<ApplicationType> getAllValuesOfapp(final AppTypeInstanceAndHostMatch partialMatch) {
    return rawAccumulateAllValuesOfapp(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<ApplicationType> getAllValuesOfapp(final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    return rawAccumulateAllValuesOfapp(new Object[]{
    null, 
    pAppInstance, 
    pHostInstance
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
  public Set<ApplicationInstance> getAllValuesOfappInstance(final AppTypeInstanceAndHostMatch partialMatch) {
    return rawAccumulateAllValuesOfappInstance(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for appInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<ApplicationInstance> getAllValuesOfappInstance(final ApplicationType pApp, final HostInstance pHostInstance) {
    return rawAccumulateAllValuesOfappInstance(new Object[]{
    pApp, 
    null, 
    pHostInstance
    });
  }
  
  /**
   * Retrieve the set of values that occur in matches for hostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  protected Set<HostInstance> rawAccumulateAllValuesOfhostInstance(final Object[] parameters) {
    Set<HostInstance> results = new HashSet<HostInstance>();
    rawAccumulateAllValues(POSITION_HOSTINSTANCE, parameters, results);
    return results;
  }
  
  /**
   * Retrieve the set of values that occur in matches for hostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOfhostInstance() {
    return rawAccumulateAllValuesOfhostInstance(emptyArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for hostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOfhostInstance(final AppTypeInstanceAndHostMatch partialMatch) {
    return rawAccumulateAllValuesOfhostInstance(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for hostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOfhostInstance(final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return rawAccumulateAllValuesOfhostInstance(new Object[]{
    pApp, 
    pAppInstance, 
    null
    });
  }
  
  @Override
  protected AppTypeInstanceAndHostMatch tupleToMatch(final Tuple t) {
    try {
    	return AppTypeInstanceAndHostMatch.newMatch((ApplicationType) t.get(POSITION_APP), (ApplicationInstance) t.get(POSITION_APPINSTANCE), (HostInstance) t.get(POSITION_HOSTINSTANCE));
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in tuple not properly typed!",e);
    	return null;
    }
  }
  
  @Override
  protected AppTypeInstanceAndHostMatch arrayToMatch(final Object[] match) {
    try {
    	return AppTypeInstanceAndHostMatch.newMatch((ApplicationType) match[POSITION_APP], (ApplicationInstance) match[POSITION_APPINSTANCE], (HostInstance) match[POSITION_HOSTINSTANCE]);
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in array not properly typed!",e);
    	return null;
    }
  }
  
  @Override
  protected AppTypeInstanceAndHostMatch arrayToMatchMutable(final Object[] match) {
    try {
    	return AppTypeInstanceAndHostMatch.newMutableMatch((ApplicationType) match[POSITION_APP], (ApplicationInstance) match[POSITION_APPINSTANCE], (HostInstance) match[POSITION_HOSTINSTANCE]);
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
  public static IQuerySpecification<AppTypeInstanceAndHostMatcher> querySpecification() throws ViatraQueryException {
    return AppTypeInstanceAndHostQuerySpecification.instance();
  }
}
