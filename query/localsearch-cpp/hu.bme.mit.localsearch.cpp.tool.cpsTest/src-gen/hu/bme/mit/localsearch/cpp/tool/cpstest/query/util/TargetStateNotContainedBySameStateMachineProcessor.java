/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.TargetStateNotContainedBySameStateMachineMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.State;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.Transition;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.targetStateNotContainedBySameStateMachine pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class TargetStateNotContainedBySameStateMachineProcessor implements IMatchProcessor<TargetStateNotContainedBySameStateMachineMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pTransition the value of pattern parameter transition in the currently processed match
   * @param pTarget the value of pattern parameter target in the currently processed match
   * 
   */
  public abstract void process(final Transition pTransition, final State pTarget);
  
  @Override
  public void process(final TargetStateNotContainedBySameStateMachineMatch match) {
    process(match.getTransition(), match.getTarget());
  }
}
