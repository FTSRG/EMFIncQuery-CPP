/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.ReachableAppInstanceQuerySpecification;
import java.util.Arrays;
import java.util.List;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationInstance;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationType;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IPatternMatch;
import org.eclipse.viatra.query.runtime.api.impl.BasePatternMatch;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;

/**
 * Pattern-specific match representation of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.reachableAppInstance pattern,
 * to be used in conjunction with {@link ReachableAppInstanceMatcher}.
 * 
 * <p>Class fields correspond to parameters of the pattern. Fields with value null are considered unassigned.
 * Each instance is a (possibly partial) substitution of pattern parameters,
 * usable to represent a match of the pattern in the result of a query,
 * or to specify the bound (fixed) input parameters when issuing a query.
 * 
 * @see ReachableAppInstanceMatcher
 * @see ReachableAppInstanceProcessor
 * 
 */
@SuppressWarnings("all")
public abstract class ReachableAppInstanceMatch extends BasePatternMatch {
  private HostInstance fSourceHostInstance;
  
  private ApplicationType fApp;
  
  private ApplicationInstance fAppInstance;
  
  private static List<String> parameterNames = makeImmutableList("sourceHostInstance", "app", "appInstance");
  
  private ReachableAppInstanceMatch(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    this.fSourceHostInstance = pSourceHostInstance;
    this.fApp = pApp;
    this.fAppInstance = pAppInstance;
  }
  
  @Override
  public Object get(final String parameterName) {
    if ("sourceHostInstance".equals(parameterName)) return this.fSourceHostInstance;
    if ("app".equals(parameterName)) return this.fApp;
    if ("appInstance".equals(parameterName)) return this.fAppInstance;
    return null;
  }
  
  public HostInstance getSourceHostInstance() {
    return this.fSourceHostInstance;
  }
  
  public ApplicationType getApp() {
    return this.fApp;
  }
  
  public ApplicationInstance getAppInstance() {
    return this.fAppInstance;
  }
  
  @Override
  public boolean set(final String parameterName, final Object newValue) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    if ("sourceHostInstance".equals(parameterName) ) {
    	this.fSourceHostInstance = (HostInstance) newValue;
    	return true;
    }
    if ("app".equals(parameterName) ) {
    	this.fApp = (ApplicationType) newValue;
    	return true;
    }
    if ("appInstance".equals(parameterName) ) {
    	this.fAppInstance = (ApplicationInstance) newValue;
    	return true;
    }
    return false;
  }
  
  public void setSourceHostInstance(final HostInstance pSourceHostInstance) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fSourceHostInstance = pSourceHostInstance;
  }
  
  public void setApp(final ApplicationType pApp) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fApp = pApp;
  }
  
  public void setAppInstance(final ApplicationInstance pAppInstance) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fAppInstance = pAppInstance;
  }
  
  @Override
  public String patternName() {
    return "hu.bme.mit.localsearch.cpp.tool.cpstest.query.reachableAppInstance";
  }
  
  @Override
  public List<String> parameterNames() {
    return ReachableAppInstanceMatch.parameterNames;
  }
  
  @Override
  public Object[] toArray() {
    return new Object[]{fSourceHostInstance, fApp, fAppInstance};
  }
  
  @Override
  public ReachableAppInstanceMatch toImmutable() {
    return isMutable() ? newMatch(fSourceHostInstance, fApp, fAppInstance) : this;
  }
  
  @Override
  public String prettyPrint() {
    StringBuilder result = new StringBuilder();
    result.append("\"sourceHostInstance\"=" + prettyPrintValue(fSourceHostInstance) + ", ");
    
    result.append("\"app\"=" + prettyPrintValue(fApp) + ", ");
    
    result.append("\"appInstance\"=" + prettyPrintValue(fAppInstance)
    );
    return result.toString();
  }
  
  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((fSourceHostInstance == null) ? 0 : fSourceHostInstance.hashCode());
    result = prime * result + ((fApp == null) ? 0 : fApp.hashCode());
    result = prime * result + ((fAppInstance == null) ? 0 : fAppInstance.hashCode());
    return result;
  }
  
  @Override
  public boolean equals(final Object obj) {
    if (this == obj)
    	return true;
    if (!(obj instanceof ReachableAppInstanceMatch)) { // this should be infrequent
    	if (obj == null) {
    		return false;
    	}
    	if (!(obj instanceof IPatternMatch)) {
    		return false;
    	}
    	IPatternMatch otherSig  = (IPatternMatch) obj;
    	if (!specification().equals(otherSig.specification()))
    		return false;
    	return Arrays.deepEquals(toArray(), otherSig.toArray());
    }
    ReachableAppInstanceMatch other = (ReachableAppInstanceMatch) obj;
    if (fSourceHostInstance == null) {if (other.fSourceHostInstance != null) return false;}
    else if (!fSourceHostInstance.equals(other.fSourceHostInstance)) return false;
    if (fApp == null) {if (other.fApp != null) return false;}
    else if (!fApp.equals(other.fApp)) return false;
    if (fAppInstance == null) {if (other.fAppInstance != null) return false;}
    else if (!fAppInstance.equals(other.fAppInstance)) return false;
    return true;
  }
  
  @Override
  public ReachableAppInstanceQuerySpecification specification() {
    try {
    	return ReachableAppInstanceQuerySpecification.instance();
    } catch (ViatraQueryException ex) {
     	// This cannot happen, as the match object can only be instantiated if the query specification exists
     	throw new IllegalStateException (ex);
    }
  }
  
  /**
   * Returns an empty, mutable match.
   * Fields of the mutable match can be filled to create a partial match, usable as matcher input.
   * 
   * @return the empty match.
   * 
   */
  public static ReachableAppInstanceMatch newEmptyMatch() {
    return new Mutable(null, null, null);
  }
  
  /**
   * Returns a mutable (partial) match.
   * Fields of the mutable match can be filled to create a partial match, usable as matcher input.
   * 
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @return the new, mutable (partial) match object.
   * 
   */
  public static ReachableAppInstanceMatch newMutableMatch(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return new Mutable(pSourceHostInstance, pApp, pAppInstance);
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
  public static ReachableAppInstanceMatch newMatch(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
    return new Immutable(pSourceHostInstance, pApp, pAppInstance);
  }
  
  private static final class Mutable extends ReachableAppInstanceMatch {
    Mutable(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
      super(pSourceHostInstance, pApp, pAppInstance);
    }
    
    @Override
    public boolean isMutable() {
      return true;
    }
  }
  
  private static final class Immutable extends ReachableAppInstanceMatch {
    Immutable(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance) {
      super(pSourceHostInstance, pApp, pAppInstance);
    }
    
    @Override
    public boolean isMutable() {
      return false;
    }
  }
}
