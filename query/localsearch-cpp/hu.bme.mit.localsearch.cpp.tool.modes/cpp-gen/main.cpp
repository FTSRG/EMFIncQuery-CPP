#include "sys/types.h"
#include "sys/sysinfo.h"

#include "Viatra/Query/IteratorQuery/RobotCollideWithTrainMatcher.h"
#include "Viatra/Query/IteratorQuery/DeadEndMatcher.h"
#include "Viatra/Query/IteratorQuery/GoToDivergentMatcher.h"
#include "Viatra/Query/IteratorQuery/IsDangerousMatcher.h"
#include "Viatra/Query/IteratorQuery/OnSamePositionMatcher.h"
#include "Viatra/Query/IteratorQuery/PathMatcher.h"

#include "railRoadModel/Segment.h"
#include "railRoadModel/State.h"

#include "Viatra/Query/QueryEngine.h"

#include <cstdlib>
#include "string.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <thread>

using namespace railRoadModel;
using namespace Viatra::Query;
using namespace Viatra::Query::IteratorQuery;
using ModelRoot = Viatra::Query::ModelRoot;

constexpr int test_count = 20;

struct Record{
	double checkTime;
};

struct Storage{
	std::vector<Segment*> segments;
	std::vector<Turnout*> turnouts;
	std::vector<RobotPart*> robotparts;
	std::vector<Robot*> robots;
	std::vector<Train*> trains;
	//Frozen* frozen;
	//Operational* operational;
};

Storage model;
std::vector<Record> data;

QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::empty();
DeadEndQuerySpecification<ModelRoot>::Matcher deadEndMatcher = engine.matcher<DeadEndQuerySpecification>();
GoToDivergentQuerySpecification<ModelRoot>::Matcher divergentMatcher = engine.matcher<GoToDivergentQuerySpecification>();
IsDangerousQuerySpecification<ModelRoot>::Matcher dangerousMatcher = engine.matcher<IsDangerousQuerySpecification>();
OnSamePositionQuerySpecification<ModelRoot>::Matcher samePosMatcher = engine.matcher<OnSamePositionQuerySpecification>();
PathQuerySpecification<ModelRoot>::Matcher pathMatcher = engine.matcher<PathQuerySpecification>();
RobotCollideWithTrainQuerySpecification<ModelRoot>::Matcher collideMatcher = engine.matcher<RobotCollideWithTrainQuerySpecification>();

auto start_time = std::chrono::high_resolution_clock::now();

long long nanos() {
	auto end_time = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
}

double seconds() {
	return nanos() / (1000 * 1000 * 1000 * 1.0);
}

void CheckSystemState(int i)
{
	//std::cout << "Dangerous: " << dangerousMatcher.matches().size() << " #." <<std::endl;
	//std::cout << "Collide: " << collideMatcher.matches().size() << " #." <<std::endl;
	//std::cout << "DeadEnd: " << deadEndMatcher.matches().size() << " #." <<std::endl;
	//std::cout << "Divergent: " << divergentMatcher.matches().size() << " #." <<std::endl;
	//std::cout << "SamePos: " << samePosMatcher.matches().size() << " #." <<std::endl;
	//std::cout << "Path: " << pathMatcher.matches().size() << " #." <<std::endl;
	switch(i){
		case 1: dangerousMatcher.matches();break;
		case 2: collideMatcher.matches();break;
		case 3: deadEndMatcher.matches();break;
		case 4: divergentMatcher.matches();break;
		case 5: samePosMatcher.matches();break;
		case 6: pathMatcher.matches();break;
		default: break;
	}
}

void runCheckingThread(int counter) {
	switch(counter){
		//case 1: std::cout << "isDangerous;";break;
		//case 2: std::cout << "robotCollideWithTrain;";break;
		//case 3: std::cout << "deadEnd;";break;
		//case 4: std::cout << "goToDivergent;";break;
		//case 5: std::cout << "onSamePosition;";break;
		//case 6: std::cout << "path;";break;
		default: break;
	}
	//double lastT = seconds();
	//for (int i = 0; i < test_count; ++i)
	{
		CheckSystemState(counter);

		//auto time = seconds();
		//data.push_back({time - lastT});
		//lastT = time;
	}
}

void init(){
	//Logikai modell elemek
	//model.frozen = new Frozen(); model.frozen->id = 1003;
	//model.operational = new Operational(); model.operational->id = 1004;
	
	//Modell elemek - Szegmensek
	auto s15 = new Segment(); s15->id = 15; model.segments.push_back(s15);
	auto s24 = new Segment(); s24->id = 24; model.segments.push_back(s24);
	auto s29 = new Segment(); s29->id = 29; model.segments.push_back(s29);
	auto s12 = new Segment(); s12->id = 12; model.segments.push_back(s12);

	auto s1 = new Segment(); s1->id = 1; model.segments.push_back(s1);
	auto s2 = new Segment(); s2->id = 2; model.segments.push_back(s2);
	auto s4 = new Segment(); s4->id = 4; model.segments.push_back(s4);
	auto s6 = new Segment(); s6->id = 6; model.segments.push_back(s6);

	auto s10 = new Segment(); s10->id = 10; model.segments.push_back(s10);
	auto s18 = new Segment(); s18->id = 18; model.segments.push_back(s18);
	auto s31 = new Segment(); s31->id = 31; model.segments.push_back(s31);
	auto s17 = new Segment(); s17->id = 17; model.segments.push_back(s17);

	auto s22 = new Segment(); s22->id = 22; model.segments.push_back(s22);
	auto s23 = new Segment(); s23->id = 23; model.segments.push_back(s23);
	auto s27 = new Segment(); s27->id = 27; model.segments.push_back(s27);
	auto s26 = new Segment(); s26->id = 26; model.segments.push_back(s26);

	auto s20 = new Segment(); s20->id = 20; model.segments.push_back(s20);
	auto s13 = new Segment(); s13->id = 13; model.segments.push_back(s13);
	auto s8 = new Segment(); s8->id = 8; model.segments.push_back(s8);
	auto s5 = new Segment(); s5->id = 5; model.segments.push_back(s5);

	auto s7 = new Segment(); s7->id = 7;model.segments.push_back(s7);
	auto s19 = new Segment(); s19->id = 19; model.segments.push_back(s19);
	auto s30 = new Segment(); s30->id = 30; model.segments.push_back(s30);
	auto s11 = new Segment(); s11->id = 11; model.segments.push_back(s11);

	//Modell elemek - Váltók
	auto turn14 = new Turnout(); turn14->id = 14; turn14->currentlyDivergent = true; turn14->currentState = ::railRoadModel::State::Operational; model.turnouts.push_back(turn14);
	auto turn21 = new Turnout(); turn21->id = 21; turn21->currentlyDivergent = true; turn21->currentState = ::railRoadModel::State::Operational; model.turnouts.push_back(turn21);
	auto turn9 = new Turnout(); turn9->id = 9; turn9->currentlyDivergent = true; turn9->currentState = ::railRoadModel::State::Operational; model.turnouts.push_back(turn9);

	auto turn3 = new Turnout(); turn3->id = 3; turn3->currentlyDivergent = false; turn3->currentState = ::railRoadModel::State::Frozen; model.turnouts.push_back(turn3);
	auto turn25 = new Turnout(); turn25->id = 25; turn25->currentlyDivergent = false; turn25->currentState = ::railRoadModel::State::Frozen; model.turnouts.push_back(turn25);
	auto turn32 = new Turnout(); turn32->id = 32; turn32->currentlyDivergent = false; turn32->currentState = ::railRoadModel::State::Frozen; model.turnouts.push_back(turn32);
	auto turn28 = new Turnout(); turn28->id = 28; turn28->currentlyDivergent = false; turn28->currentState = ::railRoadModel::State::Frozen; model.turnouts.push_back(turn28);

		//Modell elemek - Vonatok
	auto t1001 = new Train(); t1001->id = 1001; t1001->currentlyOn = s4; model.trains.push_back(t1001);
	auto t1002 = new Train(); t1002->id = 1002; t1002->currentlyOn = s15; model.trains.push_back(t1002);
	auto t1003 = new Train(); t1003->id = 1003; t1003->currentlyOn = turn14; model.trains.push_back(t1003);
	auto t1004 = new Train(); t1004->id = 1004; t1004->currentlyOn = turn9; model.trains.push_back(t1004);
	auto t1005 = new Train(); t1005->id = 1005; t1005->currentlyOn = turn28; model.trains.push_back(t1005);
	auto t1006 = new Train(); t1006->id = 1006; t1006->currentlyOn = s15; model.trains.push_back(t1006);
	auto t1007 = new Train(); t1007->id = 1006; t1007->currentlyOn = turn14; model.trains.push_back(t1007);

	//Modell elemek - Robotok
	auto rp3011 = new RobotPart(); rp3011->id = 3011; rp3011->nearBy.push_back(t1001); model.robotparts.push_back(rp3011);
	auto rp3012 = new RobotPart(); rp3012->id = 3012; rp3012->nearBy.push_back(t1001); model.robotparts.push_back(rp3012);
	auto rp3013 = new RobotPart(); rp3013->id = 3013; model.robotparts.push_back(rp3013);

	auto r2001 = new Robot(); r2001->robotParts.push_back(rp3011); r2001->robotParts.push_back(rp3012); r2001->robotParts.push_back(rp3013);
	model.robots.push_back(r2001);

	auto rp3021 = new RobotPart(); rp3021->id = 3021; rp3021->nearBy.push_back(t1002); model.robotparts.push_back(rp3021);
	auto rp3022 = new RobotPart(); rp3022->id = 3022; model.robotparts.push_back(rp3022);
	auto rp3023 = new RobotPart(); rp3023->id = 3023; model.robotparts.push_back(rp3023);

	auto r2002 = new Robot(); r2002->robotParts.push_back(rp3021); r2002->robotParts.push_back(rp3022); r2002->robotParts.push_back(rp3023);
	model.robots.push_back(r2002);

	//Modell asszociációk - váltók
	turn14->top = s15; turn14->straight = s12; turn14->divergent = s11;
	turn21->top = s17; turn21->straight = s23; turn21->divergent = s22;
	turn9->top = s8; turn9->straight = s11; turn9->divergent = s10;

	turn3->top = s2; turn3->straight = s4; turn3->divergent = s5;
	turn25->top = s20; turn25->straight = s26; turn25->divergent = turn32;
	turn32->top = s30; turn32->straight = s19; turn32->divergent = turn25;
	turn28->top = s29; turn28->straight = s31; turn28->divergent = s30;

	//Modell asszociációk - szegmensek
	s15->connectedTo.push_back(s24); s15->connectedTo.push_back(turn14);
	s24->connectedTo.push_back(s29); s24->connectedTo.push_back(s15);
	s29->connectedTo.push_back(s24); s29->connectedTo.push_back(turn28);
	s12->connectedTo.push_back(s1); s12->connectedTo.push_back(turn14);

	s1->connectedTo.push_back(s12); s1->connectedTo.push_back(s2);
	s2->connectedTo.push_back(s1); s2->connectedTo.push_back(turn3);
	s4->connectedTo.push_back(turn3); s4->connectedTo.push_back(s6);
	s6->connectedTo.push_back(s4); s6->connectedTo.push_back(s18);

	s10->connectedTo.push_back(s17); s10->connectedTo.push_back(turn9);
	s18->connectedTo.push_back(s6); s18->connectedTo.push_back(s31);
	s31->connectedTo.push_back(s18); s31->connectedTo.push_back(turn28);
	s17->connectedTo.push_back(turn21); s17->connectedTo.push_back(s10);

	s22->connectedTo.push_back(turn21);
	s23->connectedTo.push_back(s27); s23->connectedTo.push_back(turn21);
	s27->connectedTo.push_back(s23); s27->connectedTo.push_back(s26);
	s26->connectedTo.push_back(s27); s26->connectedTo.push_back(turn25);

	s20->connectedTo.push_back(turn25); s20->connectedTo.push_back(s13);
	s13->connectedTo.push_back(s20); s13->connectedTo.push_back(s8);
	s8->connectedTo.push_back(s13); s8->connectedTo.push_back(turn9);
	s5->connectedTo.push_back(s7); s5->connectedTo.push_back(turn3);

	s7->connectedTo.push_back(s5); s7->connectedTo.push_back(s19);
	s19->connectedTo.push_back(s7); s19->connectedTo.push_back(turn32);
	s30->connectedTo.push_back(turn32); s30->connectedTo.push_back(turn28);
	s11->connectedTo.push_back(turn9); s11->connectedTo.push_back(turn14);
	
	//std::cout << "Model Size: " << model.robotparts.size() + 
	//model.robots.size() + model.segments.size() + model.trains.size() + model.turnouts.size() + 2 << std::endl;

}

void destruct(){
	for(auto seg : model.segments) delete seg;
	model.segments.clear();
	for(auto train : model.trains) delete train;
	model.trains.clear();
	for(auto turn : model.turnouts) delete turn;
	model.turnouts.clear();
	for(auto robot : model.robots) delete robot;
	model.robots.clear();
	for(auto rp : model.robotparts) delete rp;
	model.robotparts.clear();
	//delete model.frozen;
	//delete model.operational;
}

int main(int argc, char**argv)
{
	//data.reserve(test_count);
	//std::cout <<"Starting init - done"<< std::endl;
	init();
	//std::cout <<"Ending init - done"<< std::endl;

	//std::cout <<"Starting measure - done"<< std::endl;

	try {
		for(int i = 1; i <= 6; i++){ 
			runCheckingThread(i);
			//for (auto & record : data)
			{
				//std::cout << std::fixed << std::setprecision(12) << record.checkTime << ";";
			}
			//std::cout << std::endl;
			//data.clear();
		}
	}
	catch (const char * c)
	{
		//std::cout << "Exception as const char: " << c << std::endl;
	}
	catch (std::exception& ex)
	{
		//std::cout << "Exception: " << ex.what() << std::endl;
	}
	catch (...)
	{
		//std::cout << "Unexpected exception...." << std::endl;
		throw;
	}

	//destruct();
	return 0;
}
