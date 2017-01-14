#include "engine.h"
#include "interface_out.h"
// Variables
// Events
Event sig(0);
Event turnOn(1);
Event turnOff(2);
Event clk(3);
Event slow(4);
Event stc_t(5);

// Event name mappings:
char const* events[] = { "default", "turnOn", "turnOff", "clk", "slow", "stc_t" };
int eventsNo = 6;

// States
State normal(0);
State close(1);
State stop(2);

// State name mappings:
char const* states[] = { "normal", "close", "stop" };
int statesNo = 3;

// List of error states
State* errorStateList[] = {  };
PList<State, maxNumOfActiveStates> errorStates(errorStateList, 0);// Creating the initially active states' list.
State* nullStateList[0];
PList<State, maxNumOfActiveStates> activeStatesCopy(nullStateList, 0);
State* startingStates[] = { &normal };
PList<State, maxNumOfActiveStates> activeStates(startingStates, 1);

// Transitions
// t1 transition:
State* t1_from[] = { &normal, nullptr };
State* t1_to[] = { &close, nullptr };
void t1_ac() {
  setTimeout(events[4]);
  setTimeout(events[5], 20);
}
bool t1_en() {
  return isClose();
}
Transition t1(t1_from, t1_to, Event(3), t1_en, t1_ac);
// t2 transition:
State* t2_from[] = { &close, nullptr };
State* t2_to[] = { &normal, nullptr };
bool t2_en() {
  return isFar();
}
Transition t2(t2_from, t2_to, Event(3), t2_en, defaultAction);
// t3 transition:
State* t3_from[] = { &close, nullptr };
State* t3_to[] = { &stop, nullptr };
void t3_ac() {
  setTimeout(events[4]);
  setTimeout(events[5], 20);
}
bool t3_en() {
  return isVeryClose();
}
Transition t3(t3_from, t3_to, Event(3), t3_en, t3_ac);
// t4 transition:
State* t4_from[] = { &stop, nullptr };
State* t4_to[] = { &normal, nullptr };
bool t4_en() {
  return isFar();
}
Transition t4(t4_from, t4_to, Event(3), t4_en, defaultAction);
// t5 transition:
State* t5_from[] = { &close, nullptr };
State* t5_to[] = { &normal, nullptr };
Transition t5(t5_from, t5_to, Event(2), defaultEnabled, defaultAction);
// t6 transition:
State* t6_from[] = { &stop, nullptr };
State* t6_to[] = { &normal, nullptr };
Transition t6(t6_from, t6_to, Event(2), defaultEnabled, defaultAction);

// States' transitions lists
Transition* normal_trans[] = { &t1, nullptr };
Transition* stop_trans[] = { &t4, &t6, nullptr };
Transition* close_trans[] = { &t2, &t3, &t5, nullptr };

// Adding transition lists to states
void init_statechart() {
  normal.transitions = normal_trans;
  stop.transitions = stop_trans;
  close.transitions = close_trans;
}
