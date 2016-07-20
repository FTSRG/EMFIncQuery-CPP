#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Arch/arch_def.h"
#include "Viatra/Query/Query_clos/PconnectedMatcher.h"

#include <cmath>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

namespace Viatra {
	namespace Query {

		template<>
		struct ModelIndex<::arch::Node, ::arch::SN> {
			static const std::list<::arch::Node*>& instances(const ::arch::SN* modelroot) {
				//std::cout << "OK1" << std::endl;
				return ::arch::Node::_instances;
			}
		};

		template<>
		struct ModelIndex<::arch::CL, ::arch::SN> {
			static const std::list<::arch::CL*>& instances(const ::arch::SN* modelroot) {
				//std::cout << "OK2" << std::endl;
				return ::arch::CL::_instances;
			}
		};

		template<>
		struct ModelIndex<::arch::SN, ::arch::SN> {
			static const std::list<::arch::SN*>& instances(const ::arch::SN* modelroot) {
				//std::cout << "OK3" << std::endl;
				return ::arch::SN::_instances;
			}
		};

	}
}

std::vector<::arch::SN*> sns;

int main(){
	std::cout << "Start" << std::endl;
	/*std::cout << "C1--(cnn)--S1" << std::endl;
	std::cout << "C2--(cnn)--S2" << std::endl;
	std::cout << "S1--(link)--S2" << std::endl;
  auto c1 = new arch::CL(); c1->name = "C1";
  auto c2 = new arch::CL(); c2->name = "C2";

  auto s1 = new arch::SN(); s1->name = "S1";
  auto s2 = new arch::SN(); s2->name = "S2";

	s1->link.push_back(s2);
  c1->cnn=s1; c2->cnn=s2;

  auto engine = ::Viatra::Query::QueryEngine<::arch::SN>::of(s1);
  auto matcher = engine.matcher<::Viatra::Query::Query_clos::PconnectedQuerySpecification>();
	//std::cout << "Matcher created" << std::endl;
  auto matches = matcher.matches();
  int i = 0;
	//std::cout << "Matches queried, Size:"<< matches.size() << std::endl;
	try{
	  for (auto&& m : matches){
	    std::cout << "Match cathed " << ++i << ":" << m.C1->name << " -- " << m.C2->name << std::endl;
	  }
	}catch(...){
		std::cout << "Exception occured." << std::endl;
	}
	//std::cout << "Ended" << std::endl;
	delete c1; delete c2; delete s1; delete s2;*/

  auto c1 = new arch::CL(); c1->name = "C1";
	auto c2 = new arch::CL(); c2->name = "C2";
	auto c3 = new arch::CL(); c3->name = "C3";
	auto c4 = new arch::CL(); c4->name = "C4";
	auto c5 = new arch::CL(); c5->name = "C5";
	auto c6 = new arch::CL(); c6->name = "C6";

  auto s1 = new arch::SN(); s1->name = "S1";
  auto s2 = new arch::SN(); s2->name = "S2";
	auto s3 = new arch::SN(); s3->name = "S3";
	auto s4 = new arch::SN(); s4->name = "S4";
	auto s5 = new arch::SN(); s5->name = "S5";

	s1->link.push_back(s2);
	s2->link.push_back(s3);
	s4->link.push_back(s3);
	s4->link.push_back(s1);
	s1->link.push_back(s4);
  c1->cnn=s1; c2->cnn=s2; c3->cnn=s3; c4->cnn=s4;

	c5->cnn=s5; c6->cnn=s5;

  auto engine = ::Viatra::Query::QueryEngine<::arch::SN>::of(s1);
  auto matcher = engine.matcher<::Viatra::Query::Query_clos::PconnectedQuerySpecification>();
	//std::cout << "Matcher created" << std::endl;
  auto matches = matcher.matches();
  int i = 0;
	//std::cout << "Matches queried, Size:"<< matches.size() << std::endl;
	try{
	  for (auto&& m : matches){
	    std::cout << "Match cathed " << ++i << ": " << m.C1->name << " -- " << m.C2->name << std::endl;
	  }
	}catch(...){
		std::cout << "Exception occured." << std::endl;
	}
	//std::cout << "Ended" << std::endl;
	delete c1; delete c2; delete s1; delete s2;
}
