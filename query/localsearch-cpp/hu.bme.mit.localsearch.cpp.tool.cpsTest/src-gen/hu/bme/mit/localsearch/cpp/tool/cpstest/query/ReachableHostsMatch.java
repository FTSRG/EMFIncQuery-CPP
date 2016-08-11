/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.ReachableHostsQuerySpecification;
import java.util.Arrays;
import java.util.List;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IPatternMatch;
import org.eclipse.viatra.query.runtime.api.impl.BasePatternMatch;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;

/**
 * Pattern-specific match representation of the hu.bme.mit.localsearch.cpp.tool.cpstest.query.reachableHosts pattern,
 * to be used in conjunction with {@link ReachableHostsMatcher}.
 * 
 * <p>Class fields correspond to parameters of the pattern. Fields with value null are considered unassigned.
 * Each instance is a (possibly partial) substitution of pattern parameters,
 * usable to represent a match of the pattern in the result of a query,
 * or to specify the bound (fixed) input parameters when issuing a query.
 * 
 * @see ReachableHostsMatcher
 * @see ReachableHostsProcessor
 * 
 */
@SuppressWarnings("all")
public abstract class ReachableHostsMatch extends BasePatternMatch {
  private HostInstance fSource;
  
  private HostInstance fTarget;
  
  private static List<String> parameterNames = makeImmutableList("source", "target");
  
  private ReachableHostsMatch(final HostInstance pSource, final HostInstance pTarget) {
    this.fSource = pSource;
    this.fTarget = pTarget;
  }
  
  @Override
  public Object get(final String parameterName) {
    if ("source".equals(parameterName)) return this.fSource;
    if ("target".equals(parameterName)) return this.fTarget;
    return null;
  }
  
  public HostInstance getSource() {
    return this.fSource;
  }
  
  public HostInstance getTarget() {
    return this.fTarget;
  }
  
  @Override
  public boolean set(final String parameterName, final Object newValue) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    if ("source".equals(parameterName) ) {
    	this.fSource = (HostInstance) newValue;
    	return true;
    }
    if ("target".equals(parameterName) ) {
    	this.fTarget = (HostInstance) newValue;
    	return true;
    }
    return false;
  }
  
  public void setSource(final HostInstance pSource) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fSource = pSource;
  }
  
  public void setTarget(final HostInstance pTarget) {
    if (!isMutable()) throw new java.lang.UnsupportedOperationException();
    this.fTarget = pTarget;
  }
  
  @Override
  public String patternName() {
    return "hu.bme.mit.localsearch.cpp.tool.cpstest.query.reachableHosts";
  }
  
  @Override
  public List<String> parameterNames() {
    return ReachableHostsMatch.parameterNames;
  }
  
  @Override
  public Object[] toArray() {
    return new Object[]{fSource, fTarget};
  }
  
  @Override
  public ReachableHostsMatch toImmutable() {
    return isMutable() ? newMatch(fSource, fTarget) : this;
  }
  
  @Override
  public String prettyPrint() {
    StringBuilder result = new StringBuilder();
    result.append("\"source\"=" + prettyPrintValue(fSource) + ", ");
    
    result.append("\"target\"=" + prettyPrintValue(fTarget)
    );
    return result.toString();
  }
  
  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((fSource == null) ? 0 : fSource.hashCode());
    result = prime * result + ((fTarget == null) ? 0 : fTarget.hashCode());
    return result;
  }
  
  @Override
  public boolean equals(final Object obj) {
    if (this == obj)
    	return true;
    if (!(obj instanceof ReachableHostsMatch)) { // this should be infrequent
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
    ReachableHostsMatch other = (ReachableHostsMatch) obj;
    if (fSource == null) {if (other.fSource != null) return false;}
    else if (!fSource.equals(other.fSource)) return false;
    if (fTarget == null) {if (other.fTarget != null) return false;}
    else if (!fTarget.equals(other.fTarget)) return false;
    return true;
  }
  
  @Override
  public ReachableHostsQuerySpecification specification() {
    try {
    	return ReachableHostsQuerySpecification.instance();
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
  public static ReachableHostsMatch newEmptyMatch() {
    return new Mutable(null, null);
  }
  
  /**
   * Returns a mutable (partial) match.
   * Fields of the mutable match can be filled to create a partial match, usable as matcher input.
   * 
   * @param pSource the fixed value of pattern parameter source, or null if not bound.
   * @param pTarget the fixed value of pattern parameter target, or null if not bound.
   * @return the new, mutable (partial) match object.
   * 
   */
  public static ReachableHostsMatch newMutableMatch(final HostInstance pSource, final HostInstance pTarget) {
    return new Mutable(pSource, pTarget);
  }
  
  /**
   * Returns a new (partial) match.
   * This can be used e.g. to call the matcher with a partial match.
   * <p>The returned match will be immutable. Use {@link #newEmptyMatch()} to obtain a mutable match object.
   * @param pSource the fixed value of pattern parameter source, or null if not bound.
   * @param pTarget the fixed value of pattern parameter target, or null if not bound.
   * @return the (partial) match object.
   * 
   */
  public static ReachableHostsMatch newMatch(final HostInstance pSource, final HostInstance pTarget) {
    return new Immutable(pSource, pTarget);
  }
  
  private static final class Mutable extends ReachableHostsMatch {
    Mutable(final HostInstance pSource, final HostInstance pTarget) {
      super(pSource, pTarget);
    }
    
    @Override
    public boolean isMutable() {
      return true;
    }
  }
  
  private static final class Immutable extends ReachableHostsMatch {
    Immutable(final HostInstance pSource, final HostInstance pTarget) {
      super(pSource, pTarget);
    }
    
    @Override
    public boolean isMutable() {
      return false;
    }
  }
}
