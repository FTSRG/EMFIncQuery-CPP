#include <vector>
#include <mutex>
#include "interface_out.h"
#include "Viatra/Query/IteratorQuery/RobotCollideWithTrainMatcher.h"
#include "Viatra/Query/IteratorQuery/RobotIsSafeMatcher.h"
#include "Viatra/Query/IteratorQuery/RobotNearTrainMatcher.h"

std::vector<sig> timeoutQueue;
std::mutex signalMutex;

bool sig::operator==(const sig& s) const {
	return sigName == s.sigName;
}

bool sig::operator==(const std::string& sName) const {
	return sigName == sName;
}

void logItem(const char* c) {
	std::cout << c << ",";
}

void logEnd() {
	std::cout << std::endl;
}

void setTimeout(const char* eventName, int timeoutLength) {
	auto now = std::chrono::system_clock::now();
	now += std::chrono::milliseconds(timeoutLength);
	sig newSig;
	newSig.time = now;
	newSig.sigName = std::string(eventName);
	std::lock_guard<std::mutex> guard(signalMutex);
	timeoutQueue.push_back(newSig);
}

void cancelTimeout(const char* eventName) {
	std::lock_guard<std::mutex> guard(signalMutex);
	auto tbd = timeoutQueue.end();
	for(auto i = timeoutQueue.begin(); i != timeoutQueue.end(); ++i) {
		if((*i).sigName == eventName) {
			tbd = i;
		}
	}
	if(tbd != timeoutQueue.end()) {
		timeoutQueue.erase(tbd);
	}
}

void errorAction(const char* current, const char* lastAccepted) {
	std::cout << "Error action called! Curr: " << current << ", prev: " << lastAccepted << std::endl;
}

void customInitializer() {
	return;
}


//Custom guard functions
bool isClose(){
	std::cout << "---isClose called" << std::endl;
	return true;
}
bool isFar(){
	std::cout << "---isFar called" << std::endl;
	return true;
}
bool isVeryClose(){
	std::cout << "---isVeryClose called" << std::endl;
	return false;
}
