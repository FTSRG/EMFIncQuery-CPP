/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.NodeIpIsNotUniqueMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.nodeIpIsNotUnique pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class NodeIpIsNotUniqueProcessor implements IMatchProcessor<NodeIpIsNotUniqueMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pHost the value of pattern parameter host in the currently processed match
   * 
   */
  public abstract void process(final HostInstance pHost);
  
  @Override
  public void process(final NodeIpIsNotUniqueMatch match) {
    process(match.getHost());
  }
}
