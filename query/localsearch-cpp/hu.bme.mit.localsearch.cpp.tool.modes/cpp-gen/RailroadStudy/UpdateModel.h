
#include<model/ModelRoot.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<Viatra\Query\DerivedInput\FrozenStateAPIInputUpdater.h> 
#include<map>
#include"Viatra\Query\Util\Logger.h"


using namespace Viatra::Query::DerivedInput;
using Viatra::Query::Util::Logger;
/*
*  Befagyott váltók esettanulmány beégetett értékei, függvényei
*/
static const int nodeAfrozenID = 1000001;
static const int nodeAoperationalID = 2000001;

static const int nodeBfrozenID = 1000002;
static const int nodeBoperationalID = 2000002;

std::string executesTurnoutNodeA[] = { "T4", "T5", "T1" };
std::string executesTurnoutNodeB[] = { "T6", "T3", "T2", "T7" };
static std::map<std::string, int> turnoutToID = { { "T1", 14 },{ "T2", 28 },{ "T3", 25 },{ "T4", 3 },{ "T5", 9 },{ "T6", 21 }, {"T7", 32} };

static int pullTempCounter = 0;

std::string GetTempInfo(const char * nodeName) {
	if (pullTempCounter > 30) pullTempCounter = 0;

	if (std::string(nodeName) == std::string("nodeA")) {
		std::string temp = executesTurnoutNodeA[pullTempCounter % 3];
		return std::to_string(turnoutToID[temp]) + std::string(";") + std::to_string((pullTempCounter++) * 3 - 27.3);
	}
	if (std::string(nodeName) == std::string("nodeB")) {
		std::string temp = executesTurnoutNodeB[pullTempCounter % 4];
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
	int turnoutId;
	double turnoutTemp;
	std::string info = GetTempInfo(nodeName);
	Logger::Log("Message arrived: ", info);
	ParseTempInfo(info, turnoutId, turnoutTemp);
	if (std::string(nodeName) == std::string("nodeA")) {
		Logger::Log("std::string(nodeName) == std::string(\"nodeA\")");
		FrozenStateAPIInputUpdater::update(modelRoot, turnoutId, nodeAfrozenID, turnoutTemp);
		Logger::Log("std::string(nodeName) == std::string(\"nodeA\") ---- second");
		FrozenStateAPIInputUpdater::update(modelRoot, turnoutId, nodeAoperationalID, turnoutTemp);
	}
	
	else if (std::string(nodeName) == std::string("nodeB")) {
		Logger::Log("std::string(nodeName) == std::string(\"nodeB\") ---- second");
		FrozenStateAPIInputUpdater::update(modelRoot, turnoutId, nodeBfrozenID, turnoutTemp);
		FrozenStateAPIInputUpdater::update(modelRoot, turnoutId, nodeBoperationalID, turnoutTemp);
	}
	Logger::Log("Update done");
}

/*
*  Robotkarok és vonatok kooperációja esettanulmány
*/
/*
static const std::string executesRobotPartNodeA[] = { {"RP1"}, {"RP2"}, {"RP3"} };
static const std::string executesSegmentNodeA[] = { "S06", "S18", "S31" };
static const std::map<std::string, int> segmentToID = { {"S06", 21}, {"S18", 22}, {"S31", 23} };
static const std::map<std::string, int> robotPartToID = { {"RP1", 31}, {"RP2", 32}, {"RP3", 33} };

static int pullCameraCounter = 0;

std::string GetCameraInfo(const char * nodeName) {
if (pullCameraCounter > 30) pullCameraCounter = 0;

if(nodeName == "nodeA") return
}

void ParseCameraInfo(std::string& info, int& robotId, double& robX, double& robY, double& robZ, int& trainId, double& trX, double& trY, double& trZ) // "robotartID;x;y;z;trainID;x;y;z"
{
sscanf_s(info.c_str(), "%d;%lf;%lf;%lf;%d;%lf;%lf;%lf", &robotId, &robX, &robY, &robZ, &trainId, &trX, &trY, &trZ);
}*/