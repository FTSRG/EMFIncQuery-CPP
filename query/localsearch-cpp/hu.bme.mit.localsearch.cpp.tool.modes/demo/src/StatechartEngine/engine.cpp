#include "engine.h"
#include "interface_in.h"
#include "interface_out.h"

bool initialized = false;
int currentlyProcessed = -1;
int lastProcessed = -1;

bool fireTransition(Transition *transitionPointer) {  // Modifies activeStateCopy
    Transition transition = *(transitionPointer);
    if (transition.from[1] != nullptr) {  // Join state
        bool enabled = true;
        int k = 1;  // First transition is already in the active state list.
        while (transition.from[k] != nullptr) {
            if (!activeStates.contains(transition.from[k])) {
                enabled = false;
            }
            k++;
        }
        if (enabled) {
            k = 0;
            while (transition.from[k] != nullptr) {
                activeStatesCopy.remove(transition.from[k]);
                activeStates.remove(transition.from[k]);
                k++;
            }
            transition.action();
            activeStatesCopy.add(transition.to[0]);
            return true;
        }
    } else {  // Fork and standard states
        activeStatesCopy.remove(transition.from[0]);
        activeStates.remove(transition.from[0]);
        transition.action();
        int k = 0;
        while (transition.to[k] != nullptr) {
            activeStatesCopy.add(transition.to[k]);
            k++;
        }
        return true;
    }
    return false;
}

void errorActionCaller(int curr) {
  if(curr >= 0 && lastProcessed >= 0) {
    errorAction(events[curr], events[lastProcessed]);
  } else if (curr >= 0) {
    errorAction(events[curr], "-no event-");
  } else if (lastProcessed >= 0) {
    errorAction("-unknown-", events[lastProcessed]);
  } else {
    errorAction("-unknown-", "-no event-");
  }
}

void checkErrorState() {
  int i = 0;
  while(activeStates[i] != nullptr) {
    for(int j = 0; j < errorStates.size; j++) {
      if(activeStates[i] == errorStates[j]) {
        errorActionCaller(currentlyProcessed);
      }
    }
    ++i;
  }
}

void takeStep(const Event& e) {
    int eventsUsed = 0;
    activeStatesCopy = activeStates;  // Saving current active states.

    int i = 0;
    while(i < activeStates.size) {
      int stateId = activeStates[i]->id;
      int j = 0;
      while (activeStates[i]->transitions[j] != nullptr) {
          Transition checkedTransition = *(activeStates[i]->transitions[j]);
          if ((checkedTransition.trigger == e && checkedTransition.enabled()) || (checkedTransition.trigger.id == 0 && checkedTransition.enabled())) {
              if (fireTransition(activeStates[i]->transitions[j])) {
                  if(i >= activeStates.size || activeStates[i]->id != stateId) {
                      i--;
                  }
                  break;
              }
          }
          j++;
      }

      i++;
    }

    activeStates = activeStatesCopy;
    checkErrorState();
    lastProcessed = currentlyProcessed;
    currentlyProcessed = e.id;
}

void logStates() {
  int i = 0;
  while(activeStates[i] != nullptr) {
  	logItem(states[activeStates[i]->id]);
    i++;
  }
  logEnd();
}

int getState(){
  return activeStates[0]->id;
}

bool stringCompare(char const* a, char const* b) {
  int i = 0;
  while(a[i] != '\0' && b[i] != '\0') {
    if(a[i] != b[i]) return false;
    ++i;
  }
  return ((a[i] == '\0') && (b[i] == '\0'));
}

void initStatechartEngine() {
  if(!initialized) {
    customInitializer();
    init_statechart();
    initialized = true;
  }
}

void evaluate(char const* event, int param) {
  initStatechartEngine();
  int i = 0;
  while(i < eventsNo) {
    if(stringCompare(event, events[i])) {
      lastProcessed = currentlyProcessed;
      currentlyProcessed = i;
      int params[1] = {param};
      takeStep(Event(i, 1, params));
      return;
    }
    ++i;
  }
  errorActionCaller(-1);
}

void evaluate(char const* event) {
  initStatechartEngine();
  int i = 0;
  while(i < eventsNo) {
    if(stringCompare(event, events[i])) {
      lastProcessed = currentlyProcessed;
      currentlyProcessed = i;
      takeStep(Event(i));
      return;
    }
    ++i;
  }
  errorActionCaller(-1);
}
