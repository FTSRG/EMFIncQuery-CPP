#pragma once
#define maxNumOfParams 1
#define maxNumOfActiveStates 10

#define nullptr 0

#include "plist.hpp"

struct Event {
  int id;
  int numOfParams;
  int params[maxNumOfParams];
  Event();
  Event(int id);
  Event(int id, int paramNum, int* _params);
  bool operator==(const Event& rhs);
  bool operator!=(const Event& rhs);
};

struct Transition;

struct State {
  int id;
  Transition** transitions;
  State(int id);
};

extern PList<State, maxNumOfActiveStates> activeStates;
extern PList<State, maxNumOfActiveStates> activeStatesCopy;
extern PList<State, maxNumOfActiveStates> errorStates;
extern const char* events[];
extern int eventsNo;
extern const char* states[];
extern int statesNo;
void init_statechart();

bool defaultEnabled();
void defaultAction();

struct Transition {
  State** from;
  State** to;
  Event trigger;
  bool (*enabled)();
  void (*action)();
  Transition(State** from, State** to, Event trigger,
    bool (*enabled)() = defaultEnabled, void (*action)() = defaultAction);
};
