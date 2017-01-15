#include "engine.h"

Event::Event() : id(0), numOfParams(0) {}

Event::Event(int id) : id(id), numOfParams(0) {}

Event::Event(int id, int paramNum, int* _params) : id(id), numOfParams(paramNum) {
  for(int i = 0; i < paramNum; ++i) {
    params[i] = _params[i];
  }
}

bool Event::operator==(const Event& rhs) {
  if(id != rhs.id || numOfParams != rhs.numOfParams) {
    return false;
  }
  for(int i = 0; i < numOfParams && i < rhs.numOfParams; ++i) {
    if(params[i] != rhs.params[i]) {
      return false;
    }
  }
  return true;
}

bool Event::operator!=(const Event& rhs) {
  return !(*this == rhs);
}

State::State(int id) : id(id) {}

bool defaultEnabled() {
	return true;
}
void defaultAction() {
	return;
}

Transition::Transition(State** from, State** to, Event trigger,
    bool (*enabled)(), void (*action)())
    : from(from), to(to), trigger(trigger), enabled(enabled), action(action) {}
