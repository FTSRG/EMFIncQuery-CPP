/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.HostCommunicationMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.hostCommunication pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class HostCommunicationProcessor implements IMatchProcessor<HostCommunicationMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pFromHost the value of pattern parameter fromHost in the currently processed match
   * @param pToHost the value of pattern parameter toHost in the currently processed match
   * 
   */
  public abstract void process(final HostInstance pFromHost, final HostInstance pToHost);
  
  @Override
  public void process(final HostCommunicationMatch match) {
    process(match.getFromHost(), match.getToHost());
  }
}
