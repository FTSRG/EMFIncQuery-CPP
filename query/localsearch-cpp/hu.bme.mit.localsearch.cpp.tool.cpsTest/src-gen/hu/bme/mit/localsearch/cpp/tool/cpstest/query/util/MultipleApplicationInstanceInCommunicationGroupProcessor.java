/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.MultipleApplicationInstanceInCommunicationGroupMatch;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.multipleApplicationInstanceInCommunicationGroup pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class MultipleApplicationInstanceInCommunicationGroupProcessor implements IMatchProcessor<MultipleApplicationInstanceInCommunicationGroupMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pSourceHostInstance the value of pattern parameter sourceHostInstance in the currently processed match
   * @param pApp the value of pattern parameter app in the currently processed match
   * 
   */
  public abstract void process(final Object pSourceHostInstance, final Object pApp);
  
  @Override
  public void process(final MultipleApplicationInstanceInCommunicationGroupMatch match) {
    process(match.getSourceHostInstance(), match.getApp());
  }
}
