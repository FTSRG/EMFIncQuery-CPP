#ifndef stc_interface_out_h
#define stc_interface_out_h

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <string>
#include <vector>

#include "Viatra/Query/IteratorQuery/RobotCollideWithTrainMatcher.h"
#include "Viatra/Query/IteratorQuery/RobotIsSafeMatcher.h"
#include "Viatra/Query/IteratorQuery/RobotNearTrainMatcher.h"

struct sig {
	std::chrono::time_point<std::chrono::system_clock> time;
	std::string sigName;
	bool operator==(const sig&) const;
	bool operator==(const std::string&) const;
};

extern std::vector<sig> timeoutQueue;
extern std::mutex signalMutex;

void setTimeout(const char* eventName, int timeoutLength = 0);

void cancelTimeout(const char* eventName);

void errorAction(const char* current, const char* lastAccepted);

void logItem(const char* c);

void logEnd();

void customInitializer();

using namespace Viatra::Query::IteratorQuery;

std::unordered_set<RobotNearTrainMatch> getCloseMatches();
std::unordered_set<RobotIsSafeMatch> getSafeMatches();
std::unordered_set<RobotCollideWithTrainMatch> getCollideMatches();

//ROS communication
void sendStopMessage(int trainID, bool stop);
void sendSlowDownMessage(int trainID, bool slowDown);

//Custom guard functions
bool isClose();
bool isFar();
bool isVeryClose();


#endif
