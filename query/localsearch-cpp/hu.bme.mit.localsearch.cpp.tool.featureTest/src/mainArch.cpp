#include "Viatra/Query/QueryEngine.h"
#include "ArchIndex.h"
#include "Arch/arch_def.h"
#include "Viatra/Query/Sncl_runtime/CountLinksMatcher.h"
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionMatcher.h"
#include "Viatra/Query/Sncl_runtime/IsolatedCLMatcher.h"
#include "Viatra/Query/Sncl_runtime/IsolatedSNMatcher.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/NotInRingMatcher.h"
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberMatcher.h"
#include "Viatra/Query/Sncl_runtime/NumInEqualityWithMemberMatcher.h"
#include "Viatra/Query/Sncl_runtime/PconnectedMatcher.h"
#include "Viatra/Query/Sncl_runtime/RingMembersMatcher.h"

#include <cmath>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

using namespace ::arch;
using namespace ::Viatra::Query;

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
  auto matcher1 = engine.matcher<Sncl_runtime::CountLinksQuerySpecification>();

	auto matches1 = matcher1.matches();
  int i = 0;
	std::cout << "CountLinks Matches queried, Size:"<< matches1.size() << std::endl;

  for (auto&& m : matches1){
    std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn = " << m.C1->cnn->name << "(numOfSN,numOfCL) - ( " << m.numOfSN << ", " << m.numOfCL << ")" << std::endl;
  }

	auto matcher2 = engine.matcher<Sncl_runtime::GreaterThanOneSNConnectionQuerySpecification>();

	auto matches2 = matcher2.matches();
	 i = 0;
	std::cout << "GreaterThanOneSNConnection Matches queried, Size:"<< matches2.size() << std::endl;

	for (auto&& m : matches2){
		std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn <=> " << m.C1->cnn->name << std::endl;
	}

	auto matcher3 = engine.matcher<Sncl_runtime::IsolatedCLQuerySpecification>();

	auto matches3 = matcher3.matches();
	 i = 0;
	std::cout << "IsolatedCL Matches queried, Size:"<< matches3.size() << std::endl;

	for (auto&& m : matches3){
		std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn <=> " << m.C1->cnn->name << std::endl;
	}
	auto matcher4 = engine.matcher<Sncl_runtime::IsolatedSNQuerySpecification>();

	auto matches4 = matcher4.matches();
	 i = 0;
	std::cout << "IsolatedSN Matches queried, Size:"<< matches4.size() << std::endl;

	for (auto&& m : matches4){
		std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn <=> " << m.C1->cnn->name << std::endl;
	}
	auto matcher5 = engine.matcher<Sncl_runtime::LinkedQuerySpecification>();

	auto matches5 = matcher5.matches();
	 i = 0;
	std::cout << "Linked Matches queried, Size:"<< matches5.size() << std::endl;

	for (auto&& m : matches5){
		std::cout << "Match cathed " << ++i << ": (" << m.S1->name << " <=> " << m.S2->name << ")" << std::endl;
	}

	auto matcher6 = engine.matcher<Sncl_runtime::NotInRingQuerySpecification>();

	auto matches6 = matcher6.matches();
	 i = 0;
	std::cout << "NotInRing Matches queried, Size:"<< matches6.size() << std::endl;

	for (auto&& m : matches6){
		std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn <=> " << m.C1->cnn->name << std::endl;
	}

	auto matcher7 = engine.matcher<Sncl_runtime::NumEqualityWithMemberQuerySpecification>();

	auto matches7 = matcher7.matches();
	 i = 0;
	std::cout << "NumEqualityWithMember Matches queried, Size:"<< matches7.size() << std::endl;

	for (auto&& m : matches7){
		std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn <=> " << m.C1->cnn->name << std::endl;
	}
	auto matcher8 = engine.matcher<Sncl_runtime::NumInEqualityWithMemberQuerySpecification>();

	auto matches8 = matcher8.matches();
	 i = 0;
	std::cout << "NumInEqualityWithMember Matches queried, Size:"<< matches8.size() << std::endl;

	for (auto&& m : matches8){
		std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn <=> " << m.C1->cnn->name << std::endl;
	}
	auto matcher9 = engine.matcher<Sncl_runtime::PconnectedQuerySpecification>();

	auto matches9 = matcher9.matches();
	 i = 0;
	std::cout << "Pconnected Matches queried, Size:"<< matches9.size() << std::endl;

	for (auto&& m : matches9){
		std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn <=> " << m.C1->cnn->name << "\t" << m.C2->name << "->cnn <=> " << m.C2->cnn->name << std::endl;
	}
	auto matcher10 = engine.matcher<Sncl_runtime::RingMembersQuerySpecification>();

	auto matches10 = matcher10.matches();
	 i = 0;
	std::cout << "RingMembers Matches queried, Size:"<< matches10.size() << std::endl;

	for (auto&& m : matches10){
		std::cout << "Match cathed " << ++i << ": " << m.C1->name << "->cnn <=> " << m.C1->cnn->name << std::endl;
	}

	//std::cout << "Ended" << std::endl;
	delete c1; delete c2; delete c3; delete c4; delete c5; delete c6;
	delete s1; delete s2; delete s3; delete s4; delete s5;
}
