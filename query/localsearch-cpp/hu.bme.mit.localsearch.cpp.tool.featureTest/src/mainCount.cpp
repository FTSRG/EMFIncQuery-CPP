#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "robot_def.h"
#include "unfinished_def.h"
#include "Viatra/Query/UnfinishedQuery/EqualityIntMatcher.h"

#include <cmath>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

namespace Viatra {
	namespace Query {

		template<>
		struct ModelIndex<::robot::Robot, ::unfinished::Item> {
			static const std::list<::robot::Robot*>& instances(const ::unfinished::Item* modelroot) {
				return ::robot::Robot::_instances;
			}
		};

		template<>
		struct ModelIndex<::unfinished::Item, ::unfinished::Item> {
			static const std::list<::unfinished::Item*>& instances(const ::unfinished::Item* modelroot) {
				return ::unfinished::Item::_instances;
			}
		};

	}
}

using namespace robot;
using namespace unfinished;
using namespace Viatra::Query;
using namespace Viatra::Query::UnfinishedQuery;

int main(){
	//Init
	auto rob = new Robot(); rob->name="Robot1";
	auto rob_part1 = new RobotPart(); rob_part1->name = "RobPart_1"; rob->parts.push_back(rob_part1);
	auto rob_part2 = new RobotPart(); rob_part1->name = "RobPart_2"; rob->parts.push_back(rob_part2);
	auto rob_part3 = new RobotPart(); rob_part1->name = "RobPart_3"; rob->parts.push_back(rob_part3);
	auto rob_part4 = new RobotPart(); rob_part1->name = "RobPart_4"; rob->parts.push_back(rob_part4);
	auto rob_part5 = new RobotPart(); rob_part1->name = "RobPart_5"; rob->parts.push_back(rob_part5);
	auto rob_part6 = new RobotPart(); rob_part1->name = "RobPart_6"; rob->parts.push_back(rob_part6);
	auto rob_part7 = new RobotPart(); rob_part1->name = "RobPart_7"; rob->parts.push_back(rob_part7);
	auto rob_part8 = new RobotPart(); rob_part1->name = "RobPart_8"; rob->parts.push_back(rob_part8);

	auto item1 = new Item(); item1->count = 8; item1->status = 1;
	auto item2 = new Item(); item2->count = 8; item2->status = 2;
	auto item3 = new Item(); item3->count = 2; item3->status = 3;

	//Query
	auto engine = QueryEngine<Item>::empty();
  auto matcher = engine.matcher<EqualityIntQuerySpecification>();

	for(auto match : matcher.matches()){
		std::cout << match.robot->name << " -- Item_" << match.item->status << std::endl;
	}

	//GC
	delete rob;
	delete rob_part1; delete rob_part2; delete rob_part3; delete rob_part4;
	delete rob_part5; delete rob_part6; delete rob_part7; delete rob_part8;
	delete item1; delete item2; delete item3;
}
