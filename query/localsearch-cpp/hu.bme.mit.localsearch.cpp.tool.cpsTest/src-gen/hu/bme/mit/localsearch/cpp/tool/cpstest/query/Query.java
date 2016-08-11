/**
 * Generated from platform:/resource/hu.bme.mit.localsearch.cpp.tool.cpsTest/src/hu/bme/mit/localsearch/cpp/tool/cpstest/query/query.vql
 */
package hu.bme.mit.localsearch.cpp.tool.cpstest.query;

import hu.bme.mit.localsearch.cpp.tool.cpstest.query.AppTypeInstanceAndHostMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.AvailableGreaterThanTotalCpuMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.AvailableGreaterThanTotalHddMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.AvailableGreaterThanTotalRamMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.HostCommunicationMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.IdIsNotUniqueMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.InitialStateNotContainedByStateMachineMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.MultipleApplicationInstanceInCommunicationGroupMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.MultipleTransitionsWithSameActionMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.NodeIpIsNotUniqueMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.NotAllocatedButRunningMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.ReachableAppInstanceMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.ReachableHostsMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.TargetStateNotContainedBySameStateMachineMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.TransitionWithoutTargetStateMatcher;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.AppTypeInstanceAndHostQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.AvailableGreaterThanTotalCpuQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.AvailableGreaterThanTotalHddQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.AvailableGreaterThanTotalRamQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.HostCommunicationQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.IdIsNotUniqueQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.InitialStateNotContainedByStateMachineQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.MultipleApplicationInstanceInCommunicationGroupQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.MultipleTransitionsWithSameActionQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.NodeIpIsNotUniqueQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.NotAllocatedButRunningQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.ReachableAppInstanceQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.ReachableHostsQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.TargetStateNotContainedBySameStateMachineQuerySpecification;
import hu.bme.mit.localsearch.cpp.tool.cpstest.query.util.TransitionWithoutTargetStateQuerySpecification;
import org.eclipse.viatra.query.runtime.api.ViatraQueryEngine;
import org.eclipse.viatra.query.runtime.api.impl.BaseGeneratedPatternGroup;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;

/**
 * A pattern group formed of all patterns defined in query.vql.
 * 
 * <p>Use the static instance as any {@link org.eclipse.viatra.query.runtime.api.IPatternGroup}, to conveniently prepare
 * a VIATRA Query engine for matching all patterns originally defined in file query.vql,
 * in order to achieve better performance than one-by-one on-demand matcher initialization.
 * 
 * <p> From package hu.bme.mit.localsearch.cpp.tool.cpstest.query, the group contains the definition of the following patterns: <ul>
 * <li>notAllocatedButRunning</li>
 * <li>allocatedApplication</li>
 * <li>availableGreaterThanTotalCpu</li>
 * <li>availableGreaterThanTotalHdd</li>
 * <li>availableGreaterThanTotalRam</li>
 * <li>nodeIpIsNotUnique</li>
 * <li>nodeIpOfHost</li>
 * <li>idIsNotUnique</li>
 * <li>identifiableId</li>
 * <li>initialStateNotContainedByStateMachine</li>
 * <li>statemachineState</li>
 * <li>transitionWithoutTargetState</li>
 * <li>stateTransition</li>
 * <li>targetStateNotContainedBySameStateMachine</li>
 * <li>multipleTransitionsWithSameAction</li>
 * <li>actionOfTransition</li>
 * <li>multipleApplicationInstanceInCommunicationGroup</li>
 * <li>appTypeInstanceAndHost</li>
 * <li>hostCommunication</li>
 * <li>reachableHosts</li>
 * <li>reachableAppInstance</li>
 * </ul>
 * 
 * @see IPatternGroup
 * 
 */
@SuppressWarnings("all")
public final class Query extends BaseGeneratedPatternGroup {
  /**
   * Access the pattern group.
   * 
   * @return the singleton instance of the group
   * @throws ViatraQueryException if there was an error loading the generated code of pattern specifications
   * 
   */
  public static Query instance() throws ViatraQueryException {
    if (INSTANCE == null) {
    	INSTANCE = new Query();
    }
    return INSTANCE;
  }
  
  private static Query INSTANCE;
  
  private Query() throws ViatraQueryException {
    querySpecifications.add(NotAllocatedButRunningQuerySpecification.instance());
    querySpecifications.add(AvailableGreaterThanTotalCpuQuerySpecification.instance());
    querySpecifications.add(AvailableGreaterThanTotalHddQuerySpecification.instance());
    querySpecifications.add(AvailableGreaterThanTotalRamQuerySpecification.instance());
    querySpecifications.add(NodeIpIsNotUniqueQuerySpecification.instance());
    querySpecifications.add(IdIsNotUniqueQuerySpecification.instance());
    querySpecifications.add(InitialStateNotContainedByStateMachineQuerySpecification.instance());
    querySpecifications.add(TransitionWithoutTargetStateQuerySpecification.instance());
    querySpecifications.add(TargetStateNotContainedBySameStateMachineQuerySpecification.instance());
    querySpecifications.add(MultipleTransitionsWithSameActionQuerySpecification.instance());
    querySpecifications.add(MultipleApplicationInstanceInCommunicationGroupQuerySpecification.instance());
    querySpecifications.add(AppTypeInstanceAndHostQuerySpecification.instance());
    querySpecifications.add(HostCommunicationQuerySpecification.instance());
    querySpecifications.add(ReachableHostsQuerySpecification.instance());
    querySpecifications.add(ReachableAppInstanceQuerySpecification.instance());
  }
  
  public NotAllocatedButRunningQuerySpecification getNotAllocatedButRunning() throws ViatraQueryException {
    return NotAllocatedButRunningQuerySpecification.instance();
  }
  
  public NotAllocatedButRunningMatcher getNotAllocatedButRunning(final ViatraQueryEngine engine) throws ViatraQueryException {
    return NotAllocatedButRunningMatcher.on(engine);
  }
  
  public AvailableGreaterThanTotalCpuQuerySpecification getAvailableGreaterThanTotalCpu() throws ViatraQueryException {
    return AvailableGreaterThanTotalCpuQuerySpecification.instance();
  }
  
  public AvailableGreaterThanTotalCpuMatcher getAvailableGreaterThanTotalCpu(final ViatraQueryEngine engine) throws ViatraQueryException {
    return AvailableGreaterThanTotalCpuMatcher.on(engine);
  }
  
  public AvailableGreaterThanTotalHddQuerySpecification getAvailableGreaterThanTotalHdd() throws ViatraQueryException {
    return AvailableGreaterThanTotalHddQuerySpecification.instance();
  }
  
  public AvailableGreaterThanTotalHddMatcher getAvailableGreaterThanTotalHdd(final ViatraQueryEngine engine) throws ViatraQueryException {
    return AvailableGreaterThanTotalHddMatcher.on(engine);
  }
  
  public AvailableGreaterThanTotalRamQuerySpecification getAvailableGreaterThanTotalRam() throws ViatraQueryException {
    return AvailableGreaterThanTotalRamQuerySpecification.instance();
  }
  
  public AvailableGreaterThanTotalRamMatcher getAvailableGreaterThanTotalRam(final ViatraQueryEngine engine) throws ViatraQueryException {
    return AvailableGreaterThanTotalRamMatcher.on(engine);
  }
  
  public NodeIpIsNotUniqueQuerySpecification getNodeIpIsNotUnique() throws ViatraQueryException {
    return NodeIpIsNotUniqueQuerySpecification.instance();
  }
  
  public NodeIpIsNotUniqueMatcher getNodeIpIsNotUnique(final ViatraQueryEngine engine) throws ViatraQueryException {
    return NodeIpIsNotUniqueMatcher.on(engine);
  }
  
  public IdIsNotUniqueQuerySpecification getIdIsNotUnique() throws ViatraQueryException {
    return IdIsNotUniqueQuerySpecification.instance();
  }
  
  public IdIsNotUniqueMatcher getIdIsNotUnique(final ViatraQueryEngine engine) throws ViatraQueryException {
    return IdIsNotUniqueMatcher.on(engine);
  }
  
  public InitialStateNotContainedByStateMachineQuerySpecification getInitialStateNotContainedByStateMachine() throws ViatraQueryException {
    return InitialStateNotContainedByStateMachineQuerySpecification.instance();
  }
  
  public InitialStateNotContainedByStateMachineMatcher getInitialStateNotContainedByStateMachine(final ViatraQueryEngine engine) throws ViatraQueryException {
    return InitialStateNotContainedByStateMachineMatcher.on(engine);
  }
  
  public TransitionWithoutTargetStateQuerySpecification getTransitionWithoutTargetState() throws ViatraQueryException {
    return TransitionWithoutTargetStateQuerySpecification.instance();
  }
  
  public TransitionWithoutTargetStateMatcher getTransitionWithoutTargetState(final ViatraQueryEngine engine) throws ViatraQueryException {
    return TransitionWithoutTargetStateMatcher.on(engine);
  }
  
  public TargetStateNotContainedBySameStateMachineQuerySpecification getTargetStateNotContainedBySameStateMachine() throws ViatraQueryException {
    return TargetStateNotContainedBySameStateMachineQuerySpecification.instance();
  }
  
  public TargetStateNotContainedBySameStateMachineMatcher getTargetStateNotContainedBySameStateMachine(final ViatraQueryEngine engine) throws ViatraQueryException {
    return TargetStateNotContainedBySameStateMachineMatcher.on(engine);
  }
  
  public MultipleTransitionsWithSameActionQuerySpecification getMultipleTransitionsWithSameAction() throws ViatraQueryException {
    return MultipleTransitionsWithSameActionQuerySpecification.instance();
  }
  
  public MultipleTransitionsWithSameActionMatcher getMultipleTransitionsWithSameAction(final ViatraQueryEngine engine) throws ViatraQueryException {
    return MultipleTransitionsWithSameActionMatcher.on(engine);
  }
  
  public MultipleApplicationInstanceInCommunicationGroupQuerySpecification getMultipleApplicationInstanceInCommunicationGroup() throws ViatraQueryException {
    return MultipleApplicationInstanceInCommunicationGroupQuerySpecification.instance();
  }
  
  public MultipleApplicationInstanceInCommunicationGroupMatcher getMultipleApplicationInstanceInCommunicationGroup(final ViatraQueryEngine engine) throws ViatraQueryException {
    return MultipleApplicationInstanceInCommunicationGroupMatcher.on(engine);
  }
  
  public AppTypeInstanceAndHostQuerySpecification getAppTypeInstanceAndHost() throws ViatraQueryException {
    return AppTypeInstanceAndHostQuerySpecification.instance();
  }
  
  public AppTypeInstanceAndHostMatcher getAppTypeInstanceAndHost(final ViatraQueryEngine engine) throws ViatraQueryException {
    return AppTypeInstanceAndHostMatcher.on(engine);
  }
  
  public HostCommunicationQuerySpecification getHostCommunication() throws ViatraQueryException {
    return HostCommunicationQuerySpecification.instance();
  }
  
  public HostCommunicationMatcher getHostCommunication(final ViatraQueryEngine engine) throws ViatraQueryException {
    return HostCommunicationMatcher.on(engine);
  }
  
  public ReachableHostsQuerySpecification getReachableHosts() throws ViatraQueryException {
    return ReachableHostsQuerySpecification.instance();
  }
  
  public ReachableHostsMatcher getReachableHosts(final ViatraQueryEngine engine) throws ViatraQueryException {
    return ReachableHostsMatcher.on(engine);
  }
  
  public ReachableAppInstanceQuerySpecification getReachableAppInstance() throws ViatraQueryException {
    return ReachableAppInstanceQuerySpecification.instance();
  }
  
  public ReachableAppInstanceMatcher getReachableAppInstance(final ViatraQueryEngine engine) throws ViatraQueryException {
    return ReachableAppInstanceMatcher.on(engine);
  }
}
