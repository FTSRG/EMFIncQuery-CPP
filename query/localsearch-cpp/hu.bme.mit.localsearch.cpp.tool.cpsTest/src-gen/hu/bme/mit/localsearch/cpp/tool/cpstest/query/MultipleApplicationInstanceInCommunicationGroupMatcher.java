/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.MultipleApplicationInstanceInCommunicationGroupMatch;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.MultipleApplicationInstanceInCommunicationGroupQuerySpecification;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;
import org.apache.log4j.Logger;
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
 * Generated pattern matcher API of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.multipleApplicationInstanceInCommunicationGroup pattern,
 * providing pattern-specific query methods.
 * 
 * <p>Use the pattern matcher on a given model via {@link #on(ViatraQueryEngine)},
 * e.g. in conjunction with {@link ViatraQueryEngine#on(Notifier)}.
 * 
 * <p>Matches of the pattern will be represented as {@link MultipleApplicationInstanceInCommunicationGroupMatch}.
 * 
 * <p>Original source:
 * <code><pre>
 * pattern multipleApplicationInstanceInCommunicationGroup(sourceHostInstance, app) {
 * 	find reachableAppInstance(sourceHostInstance, app, appInstance);
 * 	find reachableAppInstance(sourceHostInstance, app, otherAppInstance);
 * 	appInstance != otherAppInstance;
 * }
 * </pre></code>
 * 
 * @see MultipleApplicationInstanceInCommunicationGroupMatch
 * @see MultipleApplicationInstanceInCommunicationGroupProcessor
 * @see MultipleApplicationInstanceInCommunicationGroupQuerySpecification
 * 
 */
@SuppressWarnings("all")
public class MultipleApplicationInstanceInCommunicationGroupMatcher extends BaseMatcher<MultipleApplicationInstanceInCommunicationGroupMatch> {
  /**
   * Initializes the pattern matcher within an existing VIATRA Query engine.
   * If the pattern matcher is already constructed in the engine, only a light-weight reference is returned.
   * The match set will be incrementally refreshed upon updates.
   * @param engine the existing VIATRA Query engine in which this matcher will be created.
   * @throws ViatraQueryException if an error occurs during pattern matcher creation
   * 
   */
  public static MultipleApplicationInstanceInCommunicationGroupMatcher on(final ViatraQueryEngine engine) throws ViatraQueryException {
    // check if matcher already exists
    MultipleApplicationInstanceInCommunicationGroupMatcher matcher = engine.getExistingMatcher(querySpecification());
    if (matcher == null) {
    	matcher = new MultipleApplicationInstanceInCommunicationGroupMatcher(engine);
    	// do not have to "put" it into engine.matchers, reportMatcherInitialized() will take care of it
    }
    return matcher;
  }
  
  private final static int POSITION_SOURCEHOSTINSTANCE = 0;
  
  private final static int POSITION_APP = 1;
  
  private final static Logger LOGGER = ViatraQueryLoggingUtil.getLogger(MultipleApplicationInstanceInCommunicationGroupMatcher.class);
  
  /**
   * Initializes the pattern matcher within an existing VIATRA Query engine.
   * If the pattern matcher is already constructed in the engine, only a light-weight reference is returned.
   * The match set will be incrementally refreshed upon updates.
   * @param engine the existing VIATRA Query engine in which this matcher will be created.
   * @throws ViatraQueryException if an error occurs during pattern matcher creation
   * 
   */
  private MultipleApplicationInstanceInCommunicationGroupMatcher(final ViatraQueryEngine engine) throws ViatraQueryException {
    super(engine, querySpecification());
  }
  
  /**
   * Returns the set of all matches of the pattern that conform to the given fixed values of some parameters.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @return matches represented as a MultipleApplicationInstanceInCommunicationGroupMatch object.
   * 
   */
  public Collection<MultipleApplicationInstanceInCommunicationGroupMatch> getAllMatches(final Object pSourceHostInstance, final Object pApp) {
    return rawGetAllMatches(new Object[]{pSourceHostInstance, pApp});
  }
  
  /**
   * Returns an arbitrarily chosen match of the pattern that conforms to the given fixed values of some parameters.
   * Neither determinism nor randomness of selection is guaranteed.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @return a match represented as a MultipleApplicationInstanceInCommunicationGroupMatch object, or null if no match is found.
   * 
   */
  public MultipleApplicationInstanceInCommunicationGroupMatch getOneArbitraryMatch(final Object pSourceHostInstance, final Object pApp) {
    return rawGetOneArbitraryMatch(new Object[]{pSourceHostInstance, pApp});
  }
  
  /**
   * Indicates whether the given combination of specified pattern parameters constitute a valid pattern match,
   * under any possible substitution of the unspecified parameters (if any).
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @return true if the input is a valid (partial) match of the pattern.
   * 
   */
  public boolean hasMatch(final Object pSourceHostInstance, final Object pApp) {
    return rawHasMatch(new Object[]{pSourceHostInstance, pApp});
  }
  
  /**
   * Returns the number of all matches of the pattern that conform to the given fixed values of some parameters.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @return the number of pattern matches found.
   * 
   */
  public int countMatches(final Object pSourceHostInstance, final Object pApp) {
    return rawCountMatches(new Object[]{pSourceHostInstance, pApp});
  }
  
  /**
   * Executes the given processor on each match of the pattern that conforms to the given fixed values of some parameters.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param processor the action that will process each pattern match.
   * 
   */
  public void forEachMatch(final Object pSourceHostInstance, final Object pApp, final IMatchProcessor<? super MultipleApplicationInstanceInCommunicationGroupMatch> processor) {
    rawForEachMatch(new Object[]{pSourceHostInstance, pApp}, processor);
  }
  
  /**
   * Executes the given processor on an arbitrarily chosen match of the pattern that conforms to the given fixed values of some parameters.
   * Neither determinism nor randomness of selection is guaranteed.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param processor the action that will process the selected match.
   * @return true if the pattern has at least one match with the given parameter values, false if the processor was not invoked
   * 
   */
  public boolean forOneArbitraryMatch(final Object pSourceHostInstance, final Object pApp, final IMatchProcessor<? super MultipleApplicationInstanceInCommunicationGroupMatch> processor) {
    return rawForOneArbitraryMatch(new Object[]{pSourceHostInstance, pApp}, processor);
  }
  
  /**
   * Returns a new (partial) match.
   * This can be used e.g. to call the matcher with a partial match.
   * <p>The returned match will be immutable. Use {@link #newEmptyMatch()} to obtain a mutable match object.
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @return the (partial) match object.
   * 
   */
  public MultipleApplicationInstanceInCommunicationGroupMatch newMatch(final Object pSourceHostInstance, final Object pApp) {
    return MultipleApplicationInstanceInCommunicationGroupMatch.newMatch(pSourceHostInstance, pApp);
  }
  
  /**
   * Retrieve the set of values that occur in matches for sourceHostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  protected Set<Object> rawAccumulateAllValuesOfsourceHostInstance(final Object[] parameters) {
    Set<Object> results = new HashSet<Object>();
    rawAccumulateAllValues(POSITION_SOURCEHOSTINSTANCE, parameters, results);
    return results;
  }
  
  /**
   * Retrieve the set of values that occur in matches for sourceHostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<Object> getAllValuesOfsourceHostInstance() {
    return rawAccumulateAllValuesOfsourceHostInstance(emptyArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for sourceHostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<Object> getAllValuesOfsourceHostInstance(final MultipleApplicationInstanceInCommunicationGroupMatch partialMatch) {
    return rawAccumulateAllValuesOfsourceHostInstance(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for sourceHostInstance.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<Object> getAllValuesOfsourceHostInstance(final Object pApp) {
    return rawAccumulateAllValuesOfsourceHostInstance(new Object[]{
    null, 
    pApp
    });
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  protected Set<Object> rawAccumulateAllValuesOfapp(final Object[] parameters) {
    Set<Object> results = new HashSet<Object>();
    rawAccumulateAllValues(POSITION_APP, parameters, results);
    return results;
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<Object> getAllValuesOfapp() {
    return rawAccumulateAllValuesOfapp(emptyArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<Object> getAllValuesOfapp(final MultipleApplicationInstanceInCommunicationGroupMatch partialMatch) {
    return rawAccumulateAllValuesOfapp(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for app.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<Object> getAllValuesOfapp(final Object pSourceHostInstance) {
    return rawAccumulateAllValuesOfapp(new Object[]{
    pSourceHostInstance, 
    null
    });
  }
  
  @Override
  protected MultipleApplicationInstanceInCommunicationGroupMatch tupleToMatch(final Tuple t) {
    try {
    	return MultipleApplicationInstanceInCommunicationGroupMatch.newMatch((HostInstance) t.get(POSITION_SOURCEHOSTINSTANCE), (ApplicationType) t.get(POSITION_APP));
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in tuple not properly typed!",e);
    	return null;
    }
  }
  
  @Override
  protected MultipleApplicationInstanceInCommunicationGroupMatch arrayToMatch(final Object[] match) {
    try {
    	return MultipleApplicationInstanceInCommunicationGroupMatch.newMatch((HostInstance) match[POSITION_SOURCEHOSTINSTANCE], (ApplicationType) match[POSITION_APP]);
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in array not properly typed!",e);
    	return null;
    }
  }
  
  @Override
  protected MultipleApplicationInstanceInCommunicationGroupMatch arrayToMatchMutable(final Object[] match) {
    try {
    	return MultipleApplicationInstanceInCommunicationGroupMatch.newMutableMatch((HostInstance) match[POSITION_SOURCEHOSTINSTANCE], (ApplicationType) match[POSITION_APP]);
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
  public static IQuerySpecification<MultipleApplicationInstanceInCommunicationGroupMatcher> querySpecification() throws ViatraQueryException {
    return MultipleApplicationInstanceInCommunicationGroupQuerySpecification.instance();
  }
}
