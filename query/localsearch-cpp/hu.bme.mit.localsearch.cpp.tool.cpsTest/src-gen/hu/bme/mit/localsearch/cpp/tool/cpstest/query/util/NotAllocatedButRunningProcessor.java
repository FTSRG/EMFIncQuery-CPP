/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.NotAllocatedButRunningMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationInstance;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.notAllocatedButRunning pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class NotAllocatedButRunningProcessor implements IMatchProcessor<NotAllocatedButRunningMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pApp the value of pattern parameter app in the currently processed match
   * 
   */
  public abstract void process(final ApplicationInstance pApp);
  
  @Override
  public void process(final NotAllocatedButRunningMatch match) {
    process(match.getApp());
  }
}
