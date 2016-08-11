/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.HostCommunicationQuerySpecification;
import java.util.Arrays;
import java.util.List;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IPatternMatch;
import org.eclipse.viatra.query.runtime.api.impl.BasePatternMatch;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;

/**
 * Pattern-specific match representation of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.hostCommunication pattern,
 * to be used in conjunction with {@link HostCommunicationMatcher}.
 * 
 * <p>Class fields correspond to parameters of the pattern. Fields with value null are considered unassigned.
 * Each instance is a (possibly partial) substitution of pattern parameters,
 * usable to represent a match of the pattern in the result of a query,
 * or to specify the bound (fixed) input parameters when issuing a query.
 * 
 * @see HostCommunicationMatcher
 * @see HostCommunicationProcessor
 * 
 */
@SuppressWarnings("all")
public abstract class HostCommunicationMatch extends BasePatternMatch {
  private HostInstance fFromHost;
  
  private HostInstance fToHost;
  
  private static List<String> parameterNames = makeImmutableList("fromHost", "toHost");
  
  private HostCommunicationMatch(final HostInstance pFromHost, final HostInstance pToHost) {
    this.fFromHost = pFromHost;
    this.fToHost = pToHost;
  }
  
  @Override
  public Object get(final String parameterName) {
    if ("fromHost".equals(parameterName)) return this.fFromHost;
    if ("toHost".equals(parameterName)) return this.fToHost;
    return null;
  }
  
  public HostInstance getFromHost() {
    return this.fFromHost;
  }
  
  public HostInstance getToHost() {
    return this.fToHost;
  }
  
  @Override
  public boolean set(final String parameterName, final Object newValue) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    if ("fromHost".equals(parameterName) ) {
    	this.fFromHost = (HostInstance) newValue;
    	return true;
    }
    if ("toHost".equals(parameterName) ) {
    	this.fToHost = (HostInstance) newValue;
    	return true;
    }
    return false;
  }
  
  public void setFromHost(final HostInstance pFromHost) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fFromHost = pFromHost;
  }
  
  public void setToHost(final HostInstance pToHost) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fToHost = pToHost;
  }
  
  @Override
  public String patternName() {
    return "hu.bme.mit.localsearch.cpp.tool.cpstest.query.hostCommunication";
  }
  
  @Override
  public List<String> parameterNames() {
    return HostCommunicationMatch.parameterNames;
  }
  
  @Override
  public Object[] toArray() {
    return new Object[]{fFromHost, fToHost};
  }
  
  @Override
  public HostCommunicationMatch toImmutable() {
    return isMutable() ? newMatch(fFromHost, fToHost) : this;
  }
  
  @Override
  public String prettyPrint() {
    StringBuilder result = new StringBuilder();
    result.append("\"fromHost\"=" + prettyPrintValue(fFromHost) + ", ");
    
    result.append("\"toHost\"=" + prettyPrintValue(fToHost)
    );
    return result.toString();
  }
  
  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((fFromHost == null) ? 0 : fFromHost.hashCode());
    result = prime * result + ((fToHost == null) ? 0 : fToHost.hashCode());
    return result;
  }
  
  @Override
  public boolean equals(final Object obj) {
    if (this == obj)
    	return true;
    if (!(obj instanceof HostCommunicationMatch)) { // this should be infrequent
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
    HostCommunicationMatch other = (HostCommunicationMatch) obj;
    if (fFromHost == null) {if (other.fFromHost != null) return false;}
    else if (!fFromHost.equals(other.fFromHost)) return false;
    if (fToHost == null) {if (other.fToHost != null) return false;}
    else if (!fToHost.equals(other.fToHost)) return false;
    return true;
  }
  
  @Override
  public HostCommunicationQuerySpecification specification() {
    try {
    	return HostCommunicationQuerySpecification.instance();
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
  public static HostCommunicationMatch newEmptyMatch() {
    return new Mutable(null, null);
  }
  
  /**
   * Returns a mutable (partial) match.
   * Fields of the mutable match can be filled to create a partial match, usable as matcher input.
   * 
   * @param pFromHost the fixed value of pattern parameter fromHost, or null if not bound.
   * @param pToHost the fixed value of pattern parameter toHost, or null if not bound.
   * @return the new, mutable (partial) match object.
   * 
   */
  public static HostCommunicationMatch newMutableMatch(final HostInstance pFromHost, final HostInstance pToHost) {
    return new Mutable(pFromHost, pToHost);
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
  public static HostCommunicationMatch newMatch(final HostInstance pFromHost, final HostInstance pToHost) {
    return new Immutable(pFromHost, pToHost);
  }
  
  private static final class Mutable extends HostCommunicationMatch {
    Mutable(final HostInstance pFromHost, final HostInstance pToHost) {
      super(pFromHost, pToHost);
    }
    
    @Override
    public boolean isMutable() {
      return true;
    }
  }
  
  private static final class Immutable extends HostCommunicationMatch {
    Immutable(final HostInstance pFromHost, final HostInstance pToHost) {
      super(pFromHost, pToHost);
    }
    
    @Override
    public boolean isMutable() {
      return false;
    }
  }
}
