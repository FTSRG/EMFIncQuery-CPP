/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.AppTypeInstanceAndHostQuerySpecification;
import java.util.Arrays;
import java.util.List;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationInstance;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationType;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IPatternMatch;
import org.eclipse.viatra.query.runtime.api.impl.BasePatternMatch;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;

/**
 * Pattern-specific match representation of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.appTypeInstanceAndHost pattern,
 * to be used in conjunction with {@link AppTypeInstanceAndHostMatcher}.
 * 
 * <p>Class fields correspond to parameters of the pattern. Fields with value null are considered unassigned.
 * Each instance is a (possibly partial) substitution of pattern parameters,
 * usable to represent a match of the pattern in the result of a query,
 * or to specify the bound (fixed) input parameters when issuing a query.
 * 
 * @see AppTypeInstanceAndHostMatcher
 * @see AppTypeInstanceAndHostProcessor
 * 
 */
@SuppressWarnings("all")
public abstract class AppTypeInstanceAndHostMatch extends BasePatternMatch {
  private ApplicationType fApp;
  
  private ApplicationInstance fAppInstance;
  
  private HostInstance fHostInstance;
  
  private static List<String> parameterNames = makeImmutableList("app", "appInstance", "hostInstance");
  
  private AppTypeInstanceAndHostMatch(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    this.fApp = pApp;
    this.fAppInstance = pAppInstance;
    this.fHostInstance = pHostInstance;
  }
  
  @Override
  public Object get(final String parameterName) {
    if ("app".equals(parameterName)) return this.fApp;
    if ("appInstance".equals(parameterName)) return this.fAppInstance;
    if ("hostInstance".equals(parameterName)) return this.fHostInstance;
    return null;
  }
  
  public ApplicationType getApp() {
    return this.fApp;
  }
  
  public ApplicationInstance getAppInstance() {
    return this.fAppInstance;
  }
  
  public HostInstance getHostInstance() {
    return this.fHostInstance;
  }
  
  @Override
  public boolean set(final String parameterName, final Object newValue) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    if ("app".equals(parameterName) ) {
    	this.fApp = (ApplicationType) newValue;
    	return true;
    }
    if ("appInstance".equals(parameterName) ) {
    	this.fAppInstance = (ApplicationInstance) newValue;
    	return true;
    }
    if ("hostInstance".equals(parameterName) ) {
    	this.fHostInstance = (HostInstance) newValue;
    	return true;
    }
    return false;
  }
  
  public void setApp(final ApplicationType pApp) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fApp = pApp;
  }
  
  public void setAppInstance(final ApplicationInstance pAppInstance) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fAppInstance = pAppInstance;
  }
  
  public void setHostInstance(final HostInstance pHostInstance) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fHostInstance = pHostInstance;
  }
  
  @Override
  public String patternName() {
    return "hu.bme.mit.localsearch.cpp.tool.cpstest.query.appTypeInstanceAndHost";
  }
  
  @Override
  public List<String> parameterNames() {
    return AppTypeInstanceAndHostMatch.parameterNames;
  }
  
  @Override
  public Object[] toArray() {
    return new Object[]{fApp, fAppInstance, fHostInstance};
  }
  
  @Override
  public AppTypeInstanceAndHostMatch toImmutable() {
    return isMutable() ? newMatch(fApp, fAppInstance, fHostInstance) : this;
  }
  
  @Override
  public String prettyPrint() {
    StringBuilder result = new StringBuilder();
    result.append("\"app\"=" + prettyPrintValue(fApp) + ", ");
    
    result.append("\"appInstance\"=" + prettyPrintValue(fAppInstance) + ", ");
    
    result.append("\"hostInstance\"=" + prettyPrintValue(fHostInstance)
    );
    return result.toString();
  }
  
  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((fApp == null) ? 0 : fApp.hashCode());
    result = prime * result + ((fAppInstance == null) ? 0 : fAppInstance.hashCode());
    result = prime * result + ((fHostInstance == null) ? 0 : fHostInstance.hashCode());
    return result;
  }
  
  @Override
  public boolean equals(final Object obj) {
    if (this == obj)
    	return true;
    if (!(obj instanceof AppTypeInstanceAndHostMatch)) { // this should be infrequent
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
    AppTypeInstanceAndHostMatch other = (AppTypeInstanceAndHostMatch) obj;
    if (fApp == null) {if (other.fApp != null) return false;}
    else if (!fApp.equals(other.fApp)) return false;
    if (fAppInstance == null) {if (other.fAppInstance != null) return false;}
    else if (!fAppInstance.equals(other.fAppInstance)) return false;
    if (fHostInstance == null) {if (other.fHostInstance != null) return false;}
    else if (!fHostInstance.equals(other.fHostInstance)) return false;
    return true;
  }
  
  @Override
  public AppTypeInstanceAndHostQuerySpecification specification() {
    try {
    	return AppTypeInstanceAndHostQuerySpecification.instance();
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
  public static AppTypeInstanceAndHostMatch newEmptyMatch() {
    return new Mutable(null, null, null);
  }
  
  /**
   * Returns a mutable (partial) match.
   * Fields of the mutable match can be filled to create a partial match, usable as matcher input.
   * 
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @param pAppInstance the fixed value of pattern parameter appInstance, or null if not bound.
   * @param pHostInstance the fixed value of pattern parameter hostInstance, or null if not bound.
   * @return the new, mutable (partial) match object.
   * 
   */
  public static AppTypeInstanceAndHostMatch newMutableMatch(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    return new Mutable(pApp, pAppInstance, pHostInstance);
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
  public static AppTypeInstanceAndHostMatch newMatch(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
    return new Immutable(pApp, pAppInstance, pHostInstance);
  }
  
  private static final class Mutable extends AppTypeInstanceAndHostMatch {
    Mutable(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
      super(pApp, pAppInstance, pHostInstance);
    }
    
    @Override
    public boolean isMutable() {
      return true;
    }
  }
  
  private static final class Immutable extends AppTypeInstanceAndHostMatch {
    Immutable(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance) {
      super(pApp, pAppInstance, pHostInstance);
    }
    
    @Override
    public boolean isMutable() {
      return false;
    }
  }
}
