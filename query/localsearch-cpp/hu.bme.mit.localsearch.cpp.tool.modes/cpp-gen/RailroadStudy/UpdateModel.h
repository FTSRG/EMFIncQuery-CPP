
#include<model/ModelRoot.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<Viatra\Query\DerivedInput\FrozenStateAPIInputUpdater.h> 
#include<Viatra\Query\DerivedInput\OperationalStateAPIInputUpdater.h> 
#include<map>
#include"Viatra\Query\Util\Logger.h"


using namespace Viatra::Query::DerivedInput;
using Viatra::Query::Util::Logger;
/*
*  Befagyott váltók esettanulmány beégetett értékei, függvényei
*/
static const int node1frozenID = 1000001;
static const int node1operationalID = 2000001;

static const int node2frozenID = 1000002;
static const int node2operationalID = 2000002;

static const int node3frozenID = 1000003;
static const int node3operationalID = 2000003;

static const int node4frozenID = 1000004;
static const int node4operationalID = 2000004;

std::string executesTurnoutnode1[] = { "T5", "T1" };
std::string executesTurnoutnode2[] = { "T6", "T2", "T7" };

static std::map<std::string, int> turnoutToID = { { "T1", 14 },{ "T2", 28 },{ "T3", 25 },{ "T4", 3 },{ "T5", 9 },{ "T6", 21 }, {"T7", 32} };

static int pullTempCounter = 0;
 
std::vector<int> trainPoints = { 14, 12, 1, 2, 3, 4, 6, 18, 31, 30, 28, 29, 24, 15 };

void moveTrain(std::string nodeName, Viatra::Query::Model::ModelRoot * modelRoot)
{

	railRoadModel::ITrain* train = nullptr;
	
	if (nodeName == "node1") {
		train = dynamic_cast<railRoadModel::ITrain*>(modelRoot->findModelElementByID(9001));
	}

	else if (nodeName == "node2") {
		train = dynamic_cast<railRoadModel::ITrain*>(modelRoot->findModelElementByID(9002));
	}

	else return;

	static int nextElem = [] {
		srand(time(nullptr));
		return rand() % trainPoints.size();
	}();

	nextElem++;
	nextElem %= trainPoints.size();

	train->set_previouslyOn(train->get_currentlyOn());
	train->set_currentlyOn(
		dynamic_cast<railRoadModel::IRailRoadElement*>(modelRoot->findModelElementByID(trainPoints[nextElem]))
			);

}

std::string GetTempInfo(const char * nodeName) {
	if (pullTempCounter > 30) pullTempCounter = 0;

	if (std::string(nodeName) == std::string("node1")) {
		std::string temp = executesTurnoutnode1[pullTempCounter % 2];
		return std::to_string(turnoutToID[temp]) + std::string(";") + std::to_string((pullTempCounter++) * 3 - 37.3);
	}
	if (std::string(nodeName) == std::string("node2")) {
		std::string temp = executesTurnoutnode2[pullTempCounter % 3];
		return std::to_string(turnoutToID[temp]) + std::string(";") + std::to_string((pullTempCounter++) * 3 - 37.3);
	}
	return "-1;0.0";
}


void ParseTempInfo(std::string& info, int& id, double& temp) // "id;doublevalue"
{
	sscanf_s(info.c_str(), "%d;%lf", &id, &temp);
}

void UpdateModel(const char *nodeName, Viatra::Query::Model::ModelRoot * modelRoot)
{
	auto id = Logger::Identer();

	auto lck = modelRoot->acquireLock();

	moveTrain(nodeName, modelRoot);

	int turnoutId;
	double turnoutTemp;
	std::string info = GetTempInfo(nodeName);
	Logger::Log( "Message arrived: ", info);
	ParseTempInfo(info, turnoutId, turnoutTemp);
	if (std::string(nodeName) == std::string("node1")) {
		Logger::Log("std::string(nodeName) == std::string(\"node1\") ---- frozen");
		FrozenStateAPIInputUpdater::update(modelRoot, turnoutId, node1frozenID, turnoutTemp);
		Logger::Log("std::string(nodeName) == std::string(\"node1\") ---- operational");
		OperationalStateAPIInputUpdater::update(modelRoot, turnoutId, node1operationalID, turnoutTemp);
	}
	
	else if (std::string(nodeName) == std::string("node2")) {
		Logger::Log("std::string(nodeName) == std::string(\"node2\") ---- frozen");
		FrozenStateAPIInputUpdater::update(modelRoot, turnoutId, node2frozenID, turnoutTemp);
		Logger::Log("std::string(nodeName) == std::string(\"node2\") ---- operational");
		OperationalStateAPIInputUpdater::update(modelRoot, turnoutId, node2operationalID, turnoutTemp);
	}
	Logger::Log("Update done");
}

/*
*  Robotkarok és vonatok kooperációja esettanulmány
*/
/*
static const std::string executesRobotPartnode1[] = { {"RP1"}, {"RP2"}, {"RP3"} };
static const std::string executesSegmentnode1[] = { "S06", "S18", "S31" };
static const std::map<std::string, int> segmentToID = { {"S06", 21}, {"S18", 22}, {"S31", 23} };
static const std::map<std::string, int> robotPartToID = { {"RP1", 31}, {"RP2", 32}, {"RP3", 33} };

static int pullCameraCounter = 0;

std::string GetCameraInfo(const char * nodeName) {
if (pullCameraCounter > 30) pullCameraCounter = 0;

if(nodeName == "node1") return
}

void ParseCameraInfo(std::string& info, int& robotId, double& robX, double& robY, double& robZ, int& trainId, double& trX, double& trY, double& trZ) // "robotartID;x;y;z;trainID;x;y;z"
{
sscanf_s(info.c_str(), "%d;%lf;%lf;%lf;%d;%lf;%lf;%lf", &robotId, &robX, &robY, &robZ, &trainId, &trX, &trY, &trZ);
}*/