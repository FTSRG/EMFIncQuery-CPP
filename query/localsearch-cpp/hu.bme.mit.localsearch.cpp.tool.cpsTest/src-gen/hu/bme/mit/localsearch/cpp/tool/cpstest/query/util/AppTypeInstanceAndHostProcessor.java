/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.AppTypeInstanceAndHostMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationInstance;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.ApplicationType;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.HostInstance;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.appTypeInstanceAndHost pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class AppTypeInstanceAndHostProcessor implements IMatchProcessor<AppTypeInstanceAndHostMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pApp the value of pattern parameter app in the currently processed match
   * @param pAppInstance the value of pattern parameter appInstance in the currently processed match
   * @param pHostInstance the value of pattern parameter hostInstance in the currently processed match
   * 
   */
  public abstract void process(final ApplicationType pApp, final ApplicationInstance pAppInstance, final HostInstance pHostInstance);
  
  @Override
  public void process(final AppTypeInstanceAndHostMatch match) {
    process(match.getApp(), match.getAppInstance(), match.getHostInstance());
  }
}
