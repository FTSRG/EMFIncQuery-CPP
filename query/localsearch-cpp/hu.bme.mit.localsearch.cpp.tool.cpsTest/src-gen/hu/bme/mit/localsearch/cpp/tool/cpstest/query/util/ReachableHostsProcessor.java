/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.ReachableHostsMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.reachableHosts pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class ReachableHostsProcessor implements IMatchProcessor<ReachableHostsMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pSource the value of pattern parameter source in the currently processed match
   * @param pTarget the value of pattern parameter target in the currently processed match
   * 
   */
  public abstract void process(final HostInstance pSource, final HostInstance pTarget);
  
  @Override
  public void process(final ReachableHostsMatch match) {
    process(match.getSource(), match.getTarget());
  }
}
