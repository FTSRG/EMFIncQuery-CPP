/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.ReachableAppInstanceMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationInstance;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationType;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.reachableAppInstance pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class ReachableAppInstanceProcessor implements IMatchProcessor<ReachableAppInstanceMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pSourceHostInstance the value of pattern parameter sourceHostInstance in the currently processed match
   * @param pApp the value of pattern parameter app in the currently processed match
   * @param pAppInstance the value of pattern parameter appInstance in the currently processed match
   * 
   */
  public abstract void process(final HostInstance pSourceHostInstance, final ApplicationType pApp, final ApplicationInstance pAppInstance);
  
  @Override
  public void process(final ReachableAppInstanceMatch match) {
    process(match.getSourceHostInstance(), match.getApp(), match.getAppInstance());
  }
}
