/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.MultipleApplicationInstanceInCommunicationGroupQuerySpecification;
import java.util.Arrays;
import java.util.List;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationType;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IPatternMatch;
import org.eclipse.viatra.query.runtime.api.impl.BasePatternMatch;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;

/**
 * Pattern-specific match representation of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.multipleApplicationInstanceInCommunicationGroup pattern,
 * to be used in conjunction with {@link MultipleApplicationInstanceInCommunicationGroupMatcher}.
 * 
 * <p>Class fields correspond to parameters of the pattern. Fields with value null are considered unassigned.
 * Each instance is a (possibly partial) substitution of pattern parameters,
 * usable to represent a match of the pattern in the result of a query,
 * or to specify the bound (fixed) input parameters when issuing a query.
 * 
 * @see MultipleApplicationInstanceInCommunicationGroupMatcher
 * @see MultipleApplicationInstanceInCommunicationGroupProcessor
 * 
 */
@SuppressWarnings("all")
public abstract class MultipleApplicationInstanceInCommunicationGroupMatch extends BasePatternMatch {
  private Object fSourceHostInstance;
  
  private Object fApp;
  
  private static List<String> parameterNames = makeImmutableList("sourceHostInstance", "app");
  
  private MultipleApplicationInstanceInCommunicationGroupMatch(final Object pSourceHostInstance, final Object pApp) {
    this.fSourceHostInstance = pSourceHostInstance;
    this.fApp = pApp;
  }
  
  @Override
  public Object get(final String parameterName) {
    if ("sourceHostInstance".equals(parameterName)) return this.fSourceHostInstance;
    if ("app".equals(parameterName)) return this.fApp;
    return null;
  }
  
  public Object getSourceHostInstance() {
    return this.fSourceHostInstance;
  }
  
  public Object getApp() {
    return this.fApp;
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
    return false;
  }
  
  public void setSourceHostInstance(final Object pSourceHostInstance) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fSourceHostInstance = pSourceHostInstance;
  }
  
  public void setApp(final Object pApp) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fApp = pApp;
  }
  
  @Override
  public String patternName() {
    return "hu.bme.mit.localsearch.cpp.tool.cpstest.query.multipleApplicationInstanceInCommunicationGroup";
  }
  
  @Override
  public List<String> parameterNames() {
    return MultipleApplicationInstanceInCommunicationGroupMatch.parameterNames;
  }
  
  @Override
  public Object[] toArray() {
    return new Object[]{fSourceHostInstance, fApp};
  }
  
  @Override
  public MultipleApplicationInstanceInCommunicationGroupMatch toImmutable() {
    return isMutable() ? newMatch(fSourceHostInstance, fApp) : this;
  }
  
  @Override
  public String prettyPrint() {
    StringBuilder result = new StringBuilder();
    result.append("\"sourceHostInstance\"=" + prettyPrintValue(fSourceHostInstance) + ", ");
    
    result.append("\"app\"=" + prettyPrintValue(fApp)
    );
    return result.toString();
  }
  
  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((fSourceHostInstance == null) ? 0 : fSourceHostInstance.hashCode());
    result = prime * result + ((fApp == null) ? 0 : fApp.hashCode());
    return result;
  }
  
  @Override
  public boolean equals(final Object obj) {
    if (this == obj)
    	return true;
    if (!(obj instanceof MultipleApplicationInstanceInCommunicationGroupMatch)) { // this should be infrequent
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
    MultipleApplicationInstanceInCommunicationGroupMatch other = (MultipleApplicationInstanceInCommunicationGroupMatch) obj;
    if (fSourceHostInstance == null) {if (other.fSourceHostInstance != null) return false;}
    else if (!fSourceHostInstance.equals(other.fSourceHostInstance)) return false;
    if (fApp == null) {if (other.fApp != null) return false;}
    else if (!fApp.equals(other.fApp)) return false;
    return true;
  }
  
  @Override
  public MultipleApplicationInstanceInCommunicationGroupQuerySpecification specification() {
    try {
    	return MultipleApplicationInstanceInCommunicationGroupQuerySpecification.instance();
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
  public static MultipleApplicationInstanceInCommunicationGroupMatch newEmptyMatch() {
    return new Mutable(null, null);
  }
  
  /**
   * Returns a mutable (partial) match.
   * Fields of the mutable match can be filled to create a partial match, usable as matcher input.
   * 
   * @param pSourceHostInstance the fixed value of pattern parameter sourceHostInstance, or null if not bound.
   * @param pApp the fixed value of pattern parameter app, or null if not bound.
   * @return the new, mutable (partial) match object.
   * 
   */
  public static MultipleApplicationInstanceInCommunicationGroupMatch newMutableMatch(final Object pSourceHostInstance, final Object pApp) {
    return new Mutable(pSourceHostInstance, pApp);
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
  public static MultipleApplicationInstanceInCommunicationGroupMatch newMatch(final Object pSourceHostInstance, final Object pApp) {
    return new Immutable(pSourceHostInstance, pApp);
  }
  
  private static final class Mutable extends MultipleApplicationInstanceInCommunicationGroupMatch {
    Mutable(final Object pSourceHostInstance, final Object pApp) {
      super(pSourceHostInstance, pApp);
    }
    
    @Override
    public boolean isMutable() {
      return true;
    }
  }
  
  private static final class Immutable extends MultipleApplicationInstanceInCommunicationGroupMatch {
    Immutable(final Object pSourceHostInstance, final Object pApp) {
      super(pSourceHostInstance, pApp);
    }
    
    @Override
    public boolean isMutable() {
      return false;
    }
  }
}
