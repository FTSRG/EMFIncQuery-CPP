/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.HostCommunicationMatch;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.HostCommunicationQuerySpecification;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;
import org.apache.log4j.Logger;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;
import org.eclipse.viatra.query.runtime.api.IQuerySpecification;
import org.eclipse.viatra.query.runtime.api.ViatraQueryEngine;
import org.eclipse.viatra.query.runtime.api.impl.BaseMatcher;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;
import org.eclipse.viatra.query.runtime.matchers.tuple.Tuple;
import org.eclipse.viatra.query.runtime.util.ViatraQueryLoggingUtil;

/**
 * Generated pattern matcher API of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.hostCommunication pattern,
 * providing pattern-specific query methods.
 * 
 * <p>Use the pattern matcher on a given model via {@link #on(ViatraQueryEngine)},
 * e.g. in conjunction with {@link ViatraQueryEngine#on(Notifier)}.
 * 
 * <p>Matches of the pattern will be represented as {@link HostCommunicationMatch}.
 * 
 * <p>Original source:
 * <code><pre>
 * pattern hostCommunication(fromHost, toHost) {
 * 	HostInstance.communicateWith(fromHost, toHost);
 * }
 * </pre></code>
 * 
 * @see HostCommunicationMatch
 * @see HostCommunicationProcessor
 * @see HostCommunicationQuerySpecification
 * 
 */
@SuppressWarnings("all")
public class HostCommunicationMatcher extends BaseMatcher<HostCommunicationMatch> {
  /**
   * Initializes the pattern matcher within an existing VIATRA Query engine.
   * If the pattern matcher is already constructed in the engine, only a light-weight reference is returned.
   * The match set will be incrementally refreshed upon updates.
   * @param engine the existing VIATRA Query engine in which this matcher will be created.
   * @throws ViatraQueryException if an error occurs during pattern matcher creation
   * 
   */
  public static HostCommunicationMatcher on(final ViatraQueryEngine engine) throws ViatraQueryException {
    // check if matcher already exists
    HostCommunicationMatcher matcher = engine.getExistingMatcher(querySpecification());
    if (matcher == null) {
    	matcher = new HostCommunicationMatcher(engine);
    	// do not have to "put" it into engine.matchers, reportMatcherInitialized() will take care of it
    }
    return matcher;
  }
  
  private final static int POSITION_FROMHOST = 0;
  
  private final static int POSITION_TOHOST = 1;
  
  private final static Logger LOGGER = ViatraQueryLoggingUtil.getLogger(HostCommunicationMatcher.class);
  
  /**
   * Initializes the pattern matcher within an existing VIATRA Query engine.
   * If the pattern matcher is already constructed in the engine, only a light-weight reference is returned.
   * The match set will be incrementally refreshed upon updates.
   * @param engine the existing VIATRA Query engine in which this matcher will be created.
   * @throws ViatraQueryException if an error occurs during pattern matcher creation
   * 
   */
  private HostCommunicationMatcher(final ViatraQueryEngine engine) throws ViatraQueryException {
    super(engine, querySpecification());
  }
  
  /**
   * Returns the set of all matches of the pattern that conform to the given fixed values of some parameters.
   * @param pFromHost the fixed value of pattern parameter fromHost, or null if not bound.
   * @param pToHost the fixed value of pattern parameter toHost, or null if not bound.
   * @return matches represented as a HostCommunicationMatch object.
   * 
   */
  public Collection<HostCommunicationMatch> getAllMatches(final HostInstance pFromHost, final HostInstance pToHost) {
    return rawGetAllMatches(new Object[]{pFromHost, pToHost});
  }
  
  /**
   * Returns an arbitrarily chosen match of the pattern that conforms to the given fixed values of some parameters.
   * Neither determinism nor randomness of selection is guaranteed.
   * @param pFromHost the fixed value of pattern parameter fromHost, or null if not bound.
   * @param pToHost the fixed value of pattern parameter toHost, or null if not bound.
   * @return a match represented as a HostCommunicationMatch object, or null if no match is found.
   * 
   */
  public HostCommunicationMatch getOneArbitraryMatch(final HostInstance pFromHost, final HostInstance pToHost) {
    return rawGetOneArbitraryMatch(new Object[]{pFromHost, pToHost});
  }
  
  /**
   * Indicates whether the given combination of specified pattern parameters constitute a valid pattern match,
   * under any possible substitution of the unspecified parameters (if any).
   * @param pFromHost the fixed value of pattern parameter fromHost, or null if not bound.
   * @param pToHost the fixed value of pattern parameter toHost, or null if not bound.
   * @return true if the input is a valid (partial) match of the pattern.
   * 
   */
  public boolean hasMatch(final HostInstance pFromHost, final HostInstance pToHost) {
    return rawHasMatch(new Object[]{pFromHost, pToHost});
  }
  
  /**
   * Returns the number of all matches of the pattern that conform to the given fixed values of some parameters.
   * @param pFromHost the fixed value of pattern parameter fromHost, or null if not bound.
   * @param pToHost the fixed value of pattern parameter toHost, or null if not bound.
   * @return the number of pattern matches found.
   * 
   */
  public int countMatches(final HostInstance pFromHost, final HostInstance pToHost) {
    return rawCountMatches(new Object[]{pFromHost, pToHost});
  }
  
  /**
   * Executes the given processor on each match of the pattern that conforms to the given fixed values of some parameters.
   * @param pFromHost the fixed value of pattern parameter fromHost, or null if not bound.
   * @param pToHost the fixed value of pattern parameter toHost, or null if not bound.
   * @param processor the action that will process each pattern match.
   * 
   */
  public void forEachMatch(final HostInstance pFromHost, final HostInstance pToHost, final IMatchProcessor<? super HostCommunicationMatch> processor) {
    rawForEachMatch(new Object[]{pFromHost, pToHost}, processor);
  }
  
  /**
   * Executes the given processor on an arbitrarily chosen match of the pattern that conforms to the given fixed values of some parameters.
   * Neither determinism nor randomness of selection is guaranteed.
   * @param pFromHost the fixed value of pattern parameter fromHost, or null if not bound.
   * @param pToHost the fixed value of pattern parameter toHost, or null if not bound.
   * @param processor the action that will process the selected match.
   * @return true if the pattern has at least one match with the given parameter values, false if the processor was not invoked
   * 
   */
  public boolean forOneArbitraryMatch(final HostInstance pFromHost, final HostInstance pToHost, final IMatchProcessor<? super HostCommunicationMatch> processor) {
    return rawForOneArbitraryMatch(new Object[]{pFromHost, pToHost}, processor);
  }
  
  /**
   * Returns a new (partial) match.
   * This can be used e.g. to call the matcher with a partial match.
   * <p>The returned match will be immutable. Use {@link #newEmptyMatch()} to obtain a mutable match object.
   * @param pFromHost the fixed value of pattern parameter fromHost, or null if not bound.
   * @param pToHost the fixed value of pattern parameter toHost, or null if not bound.
   * @return the (partial) match object.
   * 
   */
  public HostCommunicationMatch newMatch(final HostInstance pFromHost, final HostInstance pToHost) {
    return HostCommunicationMatch.newMatch(pFromHost, pToHost);
  }
  
  /**
   * Retrieve the set of values that occur in matches for fromHost.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  protected Set<HostInstance> rawAccumulateAllValuesOffromHost(final Object[] parameters) {
    Set<HostInstance> results = new HashSet<HostInstance>();
    rawAccumulateAllValues(POSITION_FROMHOST, parameters, results);
    return results;
  }
  
  /**
   * Retrieve the set of values that occur in matches for fromHost.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOffromHost() {
    return rawAccumulateAllValuesOffromHost(emptyArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for fromHost.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOffromHost(final HostCommunicationMatch partialMatch) {
    return rawAccumulateAllValuesOffromHost(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for fromHost.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOffromHost(final HostInstance pToHost) {
    return rawAccumulateAllValuesOffromHost(new Object[]{
    null, 
    pToHost
    });
  }
  
  /**
   * Retrieve the set of values that occur in matches for toHost.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  protected Set<HostInstance> rawAccumulateAllValuesOftoHost(final Object[] parameters) {
    Set<HostInstance> results = new HashSet<HostInstance>();
    rawAccumulateAllValues(POSITION_TOHOST, parameters, results);
    return results;
  }
  
  /**
   * Retrieve the set of values that occur in matches for toHost.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOftoHost() {
    return rawAccumulateAllValuesOftoHost(emptyArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for toHost.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOftoHost(final HostCommunicationMatch partialMatch) {
    return rawAccumulateAllValuesOftoHost(partialMatch.toArray());
  }
  
  /**
   * Retrieve the set of values that occur in matches for toHost.
   * @return the Set of all values, null if no parameter with the given name exists, empty set if there are no matches
   * 
   */
  public Set<HostInstance> getAllValuesOftoHost(final HostInstance pFromHost) {
    return rawAccumulateAllValuesOftoHost(new Object[]{
    pFromHost, 
    null
    });
  }
  
  @Override
  protected HostCommunicationMatch tupleToMatch(final Tuple t) {
    try {
    	return HostCommunicationMatch.newMatch((HostInstance) t.get(POSITION_FROMHOST), (HostInstance) t.get(POSITION_TOHOST));
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in tuple not properly typed!",e);
    	return null;
    }
  }
  
  @Override
  protected HostCommunicationMatch arrayToMatch(final Object[] match) {
    try {
    	return HostCommunicationMatch.newMatch((HostInstance) match[POSITION_FROMHOST], (HostInstance) match[POSITION_TOHOST]);
    } catch(ClassCastException e) {
    	LOGGER.error("Element(s) in array not properly typed!",e);
    	return null;
    }
  }
  
  @Override
  protected HostCommunicationMatch arrayToMatchMutable(final Object[] match) {
    try {
    	return HostCommunicationMatch.newMutableMatch((HostInstance) match[POSITION_FROMHOST], (HostInstance) match[POSITION_TOHOST]);
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
  public static IQuerySpecification<HostCommunicationMatcher> querySpecification() throws ViatraQueryException {
    return HostCommunicationQuerySpecification.instance();
  }
}
