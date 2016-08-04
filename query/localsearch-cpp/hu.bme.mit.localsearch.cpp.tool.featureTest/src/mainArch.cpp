#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Arch/arch_def.h"
#include "Viatra/Query/Sncl_runtime/CountlinksMatcher.h"

#include <cmath>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

using namespace ::arch;
using namespace ::Viatra::Query;

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

std::vector<SN*> sns;

int main(){
	std::cout << "Start" << std::endl;
	auto c1 = new CL(); c1->name = "C1";
	auto c2 = new CL(); c2->name = "C2";
	auto c3 = new CL(); c3->name = "C3";
	auto c4 = new CL(); c4->name = "C4";
	auto c5 = new CL(); c5->name = "C5";
	auto c6 = new CL(); c6->name = "C6";

	//arch::SN::_instances, collection: std::list<...>
	auto s1 = new SN(); s1->name = "S1";
	auto s2 = new SN(); s2->name = "S2";
	auto s3 = new SN(); s3->name = "S3";
	auto s4 = new SN(); s4->name = "S4";
	auto s5 = new SN(); s5->name = "S5";

	//Setting up a ring with four SN and an isolated island.
	s1->link.push_back(s2);
	s2->link.push_back(s3);
	s4->link.push_back(s3);
	s4->link.push_back(s1);
	s1->link.push_back(s4);

	//Set references between objects
	c1->cnn=s1; c2->cnn=s2; c3->cnn=s3; c4->cnn=s4;
	c5->cnn=s5; c6->cnn=s5;

	/*
	pattern countlinks(C1, numOfSN, numOfCL){
		CL.cnn(C1,S1);
		numOfSN == count find linked(S1,_S2);
		numOfCL == count find pconnected(C1, _C2);
	}
	*Expected:
	c1 - numOfSN = 2 (S1-S2,S1-S4) - numOfCL = 4 (C1-S1-S2-C2) (C1-S1-S2-S3-C3) (C1-S1-S4-C4) (C1-S1-C1)
	c2 - numOfSN = 2 (S2-S3,S2-S1) - numOfCL = 4 ...
	c3 - numOfSN = 2 (S3-S2,S3-S4) - numOfCL = 4 ...
	c4 - numOfSN = 2 (S4-S1,S4-S3) - numOfCL = 4 ...
	c5 - numOfSN = 0               - numOfCL = (C5-C6, C5-C5)
	c6 - numOfSN = 0               - numOfCL = (C6-C5, C6-C6)

	@Bind(parameters={S1})
	pattern linked(S1,S2){
		SN(S2);
		SN.link(S1,S2);
	} or {
		SN(S1);
		SN.link(S2,S1);
	}

	pattern pconnected(C1,C2){
		SN(S1);
		CL.cnn(C1,S1);
		CL.cnn(C2,S1);
	} or {
		CL.cnn(C1,S1);
		CL.cnn(C2,S2);
		find linked+(S1,S2);
	}
	*/



  auto engine = QueryEngine<::arch::SN>::of(s1);
  auto mat = engine.matcher<Sncl_runtime::CountlinksQuerySpecification>();
	::arch::CL* C1;
	int numOfSN;
	int numOfCL;

	auto matches = mat.matches();
  int i = 0;
	std::cout << "Matches queried, Size:"<< matches.size() << std::endl;

  for (auto&& m : matches){
    std::cout << "Match cathed " << ++i << ": " << m.C1->name << " -- numOfSN: " << m.numOfSN << "-- numOfCL: " << m.numOfCL << std::endl;
  }

	//std::cout << "Ended" << std::endl;
	delete c1; delete c2; delete c3; delete c4; delete c5; delete c6;
	delete s1; delete s2; delete s3; delete s4; delete s5;
}
