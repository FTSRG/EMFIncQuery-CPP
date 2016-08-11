/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.InitialStateNotContainedByStateMachineMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.State;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.StateMachine;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.initialStateNotContainedByStateMachine pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class InitialStateNotContainedByStateMachineProcessor implements IMatchProcessor<InitialStateNotContainedByStateMachineMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pStatemachine the value of pattern parameter statemachine in the currently processed match
   * @param pState the value of pattern parameter state in the currently processed match
   * 
   */
  public abstract void process(final StateMachine pStatemachine, final State pState);
  
  @Override
  public void process(final InitialStateNotContainedByStateMachineMatch match) {
    process(match.getStatemachine(), match.getState());
  }
}
