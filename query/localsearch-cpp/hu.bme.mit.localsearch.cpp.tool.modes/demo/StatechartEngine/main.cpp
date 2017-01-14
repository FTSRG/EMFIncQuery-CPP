#include "interface_in.h"
#include <iostream>

#define nullptr 0

int main() {
  // Queue handler would also come here. Example in timer_tester_main.cpp
  std::cout << "---Start---" << std::endl;
  logStates();
  evaluate("clk");
  evaluate("turnOn");
  logStates();
  evaluate("clk");
  logStates();
  std::cout << "---End---" << std::endl;
  return 0;
}
