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
#include "Viatra\Query\CpsQuery\NotAllocatedButRunningQuerySpecification.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalCpuMatcher.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalCpuQuerySpecification.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalRamMatcher.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalRamQuerySpecification.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalHddMatcher.h"
#include "Viatra\Query\CpsQuery\AvailableGreaterThanTotalHddQuerySpecification.h"

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

		auto a1 = CreateApplicationInstance("User1", "password", h1,	 AppState::Running);
		auto a2 = CreateApplicationInstance("User2", "xyz123", nullptr,  AppState::Running);
		auto a3 = CreateApplicationInstance("User3", "midtylland", h2,   AppState::Stopped);
		auto a4 = CreateApplicationInstance("User4", "krekken", nullptr, AppState::Stopped);
		auto a5 = CreateApplicationInstance("User5", "pass2", h3,		 AppState::Stopped);
		
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




int main(int argc, char **argv) {

	::testing::InitGoogleTest(&argc, argv);
	auto rat = RUN_ALL_TESTS();
	system("pause");
	return rat;
}
