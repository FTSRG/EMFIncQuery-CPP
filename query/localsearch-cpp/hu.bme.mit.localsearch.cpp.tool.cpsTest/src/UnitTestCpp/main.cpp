// GTestProba2.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"

#include "FactoryFunction.h"

#include"model\cyberPhysicalSystem\EnumHelper.h"
#include"model\cyberPhysicalSystem\HostType.h"
#include"model\cyberPhysicalSystem\HostInstance.h"
#include"model\cyberPhysicalSystem\ApplicationInstance.h"

#include "Viatra\Query\Matcher\ModelIndex.h"
#include "Viatra\Query\QueryEngine.h"


#include "Viatra\Query\CpsQuery\NotAllocatedButRunningMatcher.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalCpuMatcher.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalRamMatcher.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalHddMatcher.h"
#include "Viatra\Query\CpsQuery\TargetStateNotContainedBySameStateMachineMatcher.h"
#include "Viatra\Query\CpsQuery\ReachableHostsMatcher.h"

#include<unordered_set>


using namespace cyberPhysicalSystem;
using namespace Viatra::Query;
using namespace Viatra::Query::Cpsquery;

auto CreateHostInstance = CreateBuilderFunction<cyberPhysicalSystem::HostInstance, int, int, int, int, int, int>(
	&cyberPhysicalSystem::HostInstance::availableCpu,
	&cyberPhysicalSystem::HostInstance::availableRam,
	&cyberPhysicalSystem::HostInstance::availableHdd,
	&cyberPhysicalSystem::HostInstance::totalCpu,
	&cyberPhysicalSystem::HostInstance::totalRam,
	&cyberPhysicalSystem::HostInstance::totalHdd
	);

auto CreateHostInstanceByComm = CreateBuilderFunction<cyberPhysicalSystem::HostInstance, int, std::vector<HostInstance*>>(
	&cyberPhysicalSystem::HostInstance::availableCpu,
	&cyberPhysicalSystem::HostInstance::communicateWith
	);

auto CreateTransition = CreateBuilderFunction<Transition, State*>(
	&Transition::targetState
	);

std::ostream& operator<<(std::ostream& out, const cyberPhysicalSystem::HostInstance& hi)
{
	return out << "HostInstance - CPU/RAM/HDD:\n \tavailable("
		<< hi.availableCpu << ", "
		<< hi.availableRam << ", "
		<< hi.availableHdd << "),\n \ttotal:("

		<< hi.totalCpu << ", "
		<< hi.totalRam << ", "
		<< hi.totalHdd << ")";
}

auto CreateApplicationInstance = CreateBuilderFunction<ApplicationInstance, std::string, std::string, HostInstance*, AppState>(
	&ApplicationInstance::dbUser,
	&ApplicationInstance::dbPassword,
	&ApplicationInstance::allocatedTo,
	&ApplicationInstance::state
	);


std::ostream& operator<<(std::ostream& out, const cyberPhysicalSystem::ApplicationInstance& ai)
{
	return out << "HostInstance("
		<< ai.dbUser << ", "
		<< ai.dbPassword << ", "
		<< ai.allocatedTo << ", "
		<< EnumHelper<AppState>::ToString(ai.state) << ")";

}

auto CreateHostType = CreateBuilderFunction<cyberPhysicalSystem::HostType, int, int, int>(
	&cyberPhysicalSystem::HostType::defaultCpu,
	&cyberPhysicalSystem::HostType::defaultRam,
	&cyberPhysicalSystem::HostType::defaultHdd);


std::map<void*, std::string>& nameMap()
{
	static std::map<void*, std::string> map; return map;
}

void Name(void * ptr, std::string name)
{
	nameMap()[ptr] = name;
}

std::string& Name(void * ptr)
{
	return nameMap()[ptr];
}



struct ModelRoot
{
	ModelRoot()
	{

		auto h1 = CreateHostInstance(
				3, 4, 1000,	// Available
				4, 8, 999	// Total
			);
		auto h2 = CreateHostInstance(
			3, 5, 500,
			3, 4, 500
			);
		auto h3 = CreateHostInstance(
			4, 8, 240,
			3, 16, 560
			);

		auto h4 = CreateHostInstance(
			4, 16, 240,
			3, 16, 560
			);

		auto h5 = CreateHostInstance(105, 1, 1, 1, 1, 1);
		auto h6 = CreateHostInstance(106, 1, 1, 1, 1, 1);
		auto h7 = CreateHostInstance(107, 1, 1, 1, 1, 1);
		auto h8 = CreateHostInstance(108, 1, 1, 1, 1, 1);
		auto h9 = CreateHostInstance(109, 1, 1, 1, 1, 1);
		auto h10 = CreateHostInstance(110, 1, 1, 1, 1, 1);

		Name(h1, "h1");
		Name(h2, "h2");
		Name(h3, "h3");
		Name(h4, "h4");
		Name(h5, "h5");
		Name(h6, "h6");
		Name(h7, "h7");
		Name(h8, "h8");
		Name(h9, "h9");
		Name(h10, "h10");


		h5->communicateWith = { h6, h7 };
		h7->communicateWith = { h8 };
		h9->communicateWith = { h5 };


		auto a1 = CreateApplicationInstance("User1", "password", h1,	 AppState::Running);
		auto a2 = CreateApplicationInstance("User2", "xyz123", nullptr,  AppState::Running);
		auto a3 = CreateApplicationInstance("User3", "midtylland", h2,   AppState::Stopped);
		auto a4 = CreateApplicationInstance("User4", "krekken", nullptr, AppState::Stopped);
		auto a5 = CreateApplicationInstance("User5", "pass2", h3,		 AppState::Stopped);
		

		auto s0 = new State();	Name(s0, "s0");
		auto s1 = new State();	Name(s1, "s1");
		auto s2 = new State();	Name(s2, "s2");
		auto s3 = new State();	Name(s3, "s3");

		auto s4 = new State();	Name(s4, "s4");
		auto s5 = new State();	Name(s5, "s5");
		auto s6 = new State();	Name(s6, "s6");
		auto s7 = new State();	Name(s7, "s7");
		
		s0->outgoingTransitions.push_back(CreateTransition(s1));
		s1->outgoingTransitions.push_back(CreateTransition(s2));
		s2->outgoingTransitions.push_back(CreateTransition(s3));

		s4->outgoingTransitions.push_back(CreateTransition(s5));
		s5->outgoingTransitions.push_back(CreateTransition(s6));
		s6->outgoingTransitions.push_back(CreateTransition(s7));


		auto sm1 = new StateMachine();
		sm1->states = { s0, s1, s2 };

		auto sm2 = new StateMachine();
		sm2->states = { s4, s5, s7 };



	}

	template<typename T> 
	void DeleteInstances()
	{	
		while (T::_instances.size() != 0)
			delete (*(T::_instances.begin()));
	}


	~ModelRoot()
	{
		DeleteInstances<ApplicationInstance>(); 
		DeleteInstances<HostInstance>();
		DeleteInstances<StateMachine>();
		DeleteInstances<State>();
		DeleteInstances<Transition>();
	}
};

namespace Viatra {
	namespace Query {

		template<typename T>
		struct ModelIndex<T, ModelRoot> {
			static const std::list<T*>& instances(const ModelRoot* modelRoot)
			{
				return T::_instances;
			}
		};
	}
}

TEST(CPS, NotAllocatedButRunningTest) {
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);

	NotAllocatedButRunningQuerySpecification<ModelRoot>::Matcher matcher = engine.matcher<NotAllocatedButRunningQuerySpecification>();

	auto matches = matcher.matches();

	auto allApp = ApplicationInstance::_instances;

	for (auto & m : matches)
	{
		std::cout << "matching app: " << *(m.app) << std::endl;
		ASSERT_EQ(m.app->allocatedTo, nullptr);
		ASSERT_EQ(m.app->state, AppState::Running);
		allApp.remove(m.app);
	}

	for (auto & app : allApp)
	{
		std::cout << "not matching app:" << *(app) << std::endl;
		ASSERT_TRUE(app->allocatedTo != nullptr || app->state != AppState::Running);
	}

}

TEST(CPS, availableGreaterThanTotalCpu) {
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);

	AvailableGreaterThanTotalCpuQuerySpecification<ModelRoot>::Matcher matcher = engine.matcher<AvailableGreaterThanTotalCpuQuerySpecification>();

	auto matches = matcher.matches();

	// Create copy of all instance
	auto allHostInstance = HostInstance::_instances;

	for (auto & m : matches)
	{
		std::cout << "matching hostinstance: " << *(m.host) << std::endl;
		ASSERT_GT(m.host->availableCpu , m.host->totalCpu);
		allHostInstance.remove(m.host);
	}

	for (auto & host : allHostInstance)
	{
		std::cout << "not matching hostinstance:" << *(host) << std::endl;
		ASSERT_LE(host->availableCpu, host->totalCpu);
	}

}


TEST(CPS, availableGreaterThanTotalHdd) {
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);

	AvailableGreaterThanTotalHddQuerySpecification<ModelRoot>::Matcher matcher = engine.matcher<AvailableGreaterThanTotalHddQuerySpecification>();

	auto matches = matcher.matches();

	// Create copy of all instance
	auto allHostInstance = HostInstance::_instances;

	for (auto & m : matches)
	{
		std::cout << "matching hostinstance: " << *(m.host) << std::endl;
		ASSERT_GT(m.host->availableHdd, m.host->totalHdd);
		allHostInstance.remove(m.host);
	}

	for (auto & host : allHostInstance)
	{
		std::cout << "not matching hostinstance:" << *(host) << std::endl;
		ASSERT_LE(host->availableHdd, host->totalHdd);
	}

}


TEST(CPS, availableGreaterThanTotalRam) {
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);

	AvailableGreaterThanTotalRamQuerySpecification<ModelRoot>::Matcher matcher = engine.matcher<AvailableGreaterThanTotalRamQuerySpecification>();

	auto matches = matcher.matches();

	// Create copy of all instance
	auto allHostInstance = HostInstance::_instances;

	for (auto & m : matches)
	{
		std::cout << "matching hostinstance: " << *(m.host) << std::endl;
		ASSERT_GT(m.host->availableRam, m.host->totalRam);
		allHostInstance.remove(m.host);
	}

	for (auto & host : allHostInstance)
	{
		std::cout << "not matching hostinstance:" << *(host) << std::endl;
		ASSERT_LE(host->availableRam, host->totalRam);
	}

}


TEST(CPS, ReachableHosts) {
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);

	ReachableHostsQuerySpecification<ModelRoot>::Matcher matcher = engine.matcher<ReachableHostsQuerySpecification>();

	auto matches = matcher.matches();

	for (auto & m : matches) {
		std::cout << "match: " << Name(m.source) << ", " << Name(m.target) << std::endl;
	}
}

TEST(CPS, TargetStateNotContainedBySameStateMachine)
{
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);

	TargetStateNotContainedBySameStateMachineMatcher<ModelRoot>
		matcher = engine.matcher<TargetStateNotContainedBySameStateMachineQuerySpecification>();

	auto matches = matcher.matches();

	std::unordered_set<std::string> set = { "s3", "s6" };

	for (auto & m : matches) {
		std::cout << "match: " << Name(m.target) << std::endl;
		ASSERT_TRUE(set.count(Name(m.target))>0);
		set.erase(Name(m.target));
	}

	ASSERT_EQ(set.size() , 0);
}


int main(int argc, char **argv) {

	::testing::InitGoogleTest(&argc, argv);
	auto rat = RUN_ALL_TESTS();
	system("pause");
	return rat;
}
