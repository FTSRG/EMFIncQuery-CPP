/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.TransitionWithoutTargetStateMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.Transition;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.transitionWithoutTargetState pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class TransitionWithoutTargetStateProcessor implements IMatchProcessor<TransitionWithoutTargetStateMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pTransition the value of pattern parameter transition in the currently processed match
   * 
   */
  public abstract void process(final Transition pTransition);
  
  @Override
  public void process(final TransitionWithoutTargetStateMatch match) {
    process(match.getTransition());
  }
}
