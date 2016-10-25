
#include<model/ModelRoot.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<Viatra\Query\DerivedInput\FrozenStateAPIInputUpdater.h> 
#include<map>


using namespace Viatra::Query::DerivedInput;

/*
*  Befagyott váltók esettanulmány beégetett értékei, függvényei
*/
static const int frozenID = 100;
static const int operationalID = 101;

std::string executesTurnoutNodeA[] = { "T4", "T5", "T1" };
std::string executesTurnoutNodeB[] = { "T6", "T3", "T2", "T7" };
static std::map<std::string, int> turnoutToID = { { "T1", 14 },{ "T2", 28 },{ "T3", 25 },{ "T4", 3 },{ "T5", 9 },{ "T6", 21 }, {"T7", 32} };

static int pullTempCounter = 0;

std::string GetTempInfo(const char * nodeName) {
	if (pullTempCounter > 30) pullTempCounter = 0;

	if (nodeName ==std::string("nodeA")) {
		std::string temp = executesTurnoutNodeA[pullTempCounter % 3];
		return std::to_string(turnoutToID[temp]) + std::string(";") + std::to_string((pullTempCounter++) * 3 - 27.3);
	}
	if (nodeName == std::string("nodeB")) {
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
	auto lck = modelRoot->acquireLock();
	int turnoutId;
	double turnoutTemp;
	std::string info = GetTempInfo(nodeName);
	std::cout << "Message arrived: " << info << std::endl;
	ParseTempInfo(info, turnoutId, turnoutTemp);
	FrozenStateAPIInputUpdater::update(modelRoot, turnoutId, frozenID, turnoutTemp);
	FrozenStateAPIInputUpdater::update(modelRoot, turnoutId, operationalID, turnoutTemp);
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