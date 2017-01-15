#include <vector>
#include <mutex>
#include <unordered_set>
#include "interface_out.h"
#include "Viatra/Query/IteratorQuery/IteratorQueryQueryGroup.h"

using ModelRoot = Viatra::Query::ModelRoot;

ModelRoot modelRoot;

IteratorQueryQueryGroup* queryGroup = IteratorQueryQueryGroup::instance();

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

std::unordered_set<RobotNearTrainMatch> getCloseMatches(){
	RobotNearTrainMatcher<ModelRoot> matcher(&modelRoot,queryGroup->context());
	return matcher.matches();
}

std::unordered_set<RobotIsSafeMatch> getSafeMatches(){
	RobotIsSafeMatcher<ModelRoot> matcher(&modelRoot,queryGroup->context());
	return matcher.matches();
}

std::unordered_set<RobotCollideWithTrainMatch> getCollideMatches(){
	RobotCollideWithTrainMatcher<ModelRoot> matcher(&modelRoot,queryGroup->context());
	return matcher.matches();
}

//Custom guard functions
bool isClose(){
	//std::cout << "---isClose called -- num = " << num << std::endl;
	return getCloseMatches().size() != 0;
}
bool isFar(){
	//std::cout << "---isFar called -- num = " << num << std::endl;
	return getSafeMatches().size() == 0;
}
bool isVeryClose(){
	//std::cout << "---isVeryClose called -- num = " << num << std::endl;
	return getCollideMatches().size() != 0;
}
