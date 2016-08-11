/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query.util;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.IdIsNotUniqueMatch;
import org.eclipse.viatra.examples.cps.cyberPhysicalSystem.Identifiable;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;

/**
 * A match processor tailored for the hu.bme.mit.localsearch.cpp.tool.cpstest.query.idIsNotUnique pattern.
 * 
 * Clients should derive an (anonymous) class that implements the abstract process().
 * 
 */
@SuppressWarnings("all")
public abstract class IdIsNotUniqueProcessor implements IMatchProcessor<IdIsNotUniqueMatch> {
  /**
   * Defines the action that is to be executed on each match.
   * @param pIdentifiable the value of pattern parameter identifiable in the currently processed match
   * 
   */
  public abstract void process(final Identifiable pIdentifiable);
  
  @Override
  public void process(final IdIsNotUniqueMatch match) {
    process(match.getIdentifiable());
  }
}
