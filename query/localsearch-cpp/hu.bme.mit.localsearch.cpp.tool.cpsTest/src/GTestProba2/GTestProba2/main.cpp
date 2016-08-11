// GTestProba2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "gtest/gtest.h"

#include "FactoryFunction.h"

#include"model\cyberPhysicalSystem\HostType.h"
#include"model\cyberPhysicalSystem\HostInstance.h"
#include"model\cyberPhysicalSystem\ApplicationInstance.h"

#include "Viatra\Query\Matcher\ModelIndex.h"
#include "Viatra\Query\QueryEngine.h"

#include "Viatra\Query\CpsModelViewerCommon\AllHostInstancesMatcher.h"
#include "Viatra\Query\CpsModelViewerCommon\AllHostInstancesQuerySpecification.h"

#include "Viatra\Query\CpsModelViewerCommon\AppInstancesNoAllocationMatcher.h"
#include "Viatra\Query\CpsModelViewerCommon\AppInstancesNoAllocationQuerySpecification.h"

#include "Viatra\Query\CpsModelViewerCommon\AppInstancesWithAllocationMatcher.h"
#include "Viatra\Query\CpsModelViewerCommon\AppInstancesWithAllocationQuerySpecification.h"


#include<unordered_set>


using namespace cyberPhysicalSystem;
using namespace Viatra::Query;
using namespace Viatra::Query::CpsModelViewerCommon;

auto CreateHostInstance = CreateBuilderFunction<cyberPhysicalSystem::HostInstance, int, int, int>(
	&cyberPhysicalSystem::HostInstance::availableCpu,
	&cyberPhysicalSystem::HostInstance::availableRam,
	&cyberPhysicalSystem::HostInstance::availableHdd);


std::ostream& operator<<(std::ostream& out, const cyberPhysicalSystem::HostInstance& hi)
{
	return out << "HostInstance("
		<< hi.availableCpu << ", "
		<< hi.availableRam << ", "
		<< hi.availableHdd << ")";

}

auto CreateApplicationInstance = CreateBuilderFunction<ApplicationInstance, std::string, std::string, HostInstance*>(
	&ApplicationInstance::dbUser,
	&ApplicationInstance::dbPassword,
	&ApplicationInstance::allocatedTo
	);


std::ostream& operator<<(std::ostream& out, const cyberPhysicalSystem::ApplicationInstance& ai)
{
	return out << "HostInstance("
		<< ai.dbUser << ", "
		<< ai.dbPassword << ", "
		<< ai.allocatedTo << ")";

}

auto CreateHostType = CreateBuilderFunction<cyberPhysicalSystem::HostType, int, int, int>(
	&cyberPhysicalSystem::HostType::defaultCpu,
	&cyberPhysicalSystem::HostType::defaultRam,
	&cyberPhysicalSystem::HostType::defaultHdd);


struct ModelRoot
{
	std::unordered_set<HostInstance*> hostInstances;
	std::unordered_set<ApplicationInstance*> appInstances;

	ModelRoot()
	{

		auto h1 = CreateHostInstance(3, 4, 1000);
		auto h2 = CreateHostInstance(3, 4, 500);
		auto h3 = CreateHostInstance(4, 8, 240);

		auto a1 = CreateApplicationInstance("User1", "password", h1);
		auto a2 = CreateApplicationInstance("User2", "xyz123", nullptr);
		auto a3 = CreateApplicationInstance("User3", "midtylland", h2);
		auto a4 = CreateApplicationInstance("User4", "krekken", nullptr);
		auto a5 = CreateApplicationInstance("User5", "pass2", h3);

		hostInstances.insert(h1);
		hostInstances.insert(h2);
		hostInstances.insert(h3);

		appInstances.insert(a1);
		appInstances.insert(a2);
		appInstances.insert(a3);
		appInstances.insert(a4);
	}
	~ModelRoot()
	{
		for (auto & x : appInstances)
			delete x;

		for (auto & x : hostInstances)
			delete x;
	}
};

namespace Viatra {
	namespace Query {

		template<>
		struct ModelIndex<HostInstance, ModelRoot> {
			static const std::unordered_set<HostInstance*>& instances(const ModelRoot* modelRoot)
			{
				return modelRoot->hostInstances;
			}
		};

		template<>
		struct ModelIndex<ApplicationInstance, ModelRoot> {
			static const std::unordered_set<ApplicationInstance*>& instances(const ModelRoot* modelRoot)
			{
				return modelRoot->appInstances;
			}
		};
	}
}

TEST(CPS, HostInstance1) {
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);

	AllHostInstancesQuerySpecification<ModelRoot>
		::Matcher matcher = engine.matcher<AllHostInstancesQuerySpecification>();

	auto matches = matcher.matches();

	for (auto & m : matches)
	{
		std::cout << "match found: " << *(m.host) << std::endl;
		ASSERT_NE(modelRoot.hostInstances.count(m.host), 0);
		modelRoot.hostInstances.erase(m.host);
	}
	ASSERT_EQ(modelRoot.hostInstances.size(), 0);

}


TEST(CPS, ApplicationInstanceWithAllocation) {
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);


	auto matcher = engine.matcher<AppInstancesWithAllocationQuerySpecification>();
	auto matches = matcher.matches();

	for (auto & m : matches)
	{
	
		std::cout << "match found: " << *(m.app) << std::endl;
		ASSERT_NE(modelRoot.appInstances.count(m.app), 0);
		modelRoot.appInstances.erase(m.app);
	}
	ASSERT_EQ(modelRoot.appInstances.size(), 2);

}


TEST(CPS, ApplicationInstanceWithNoAllocation) {
	ModelRoot modelRoot;

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::of(&modelRoot);
	
	auto matcher = engine.matcher<AppInstancesNoAllocationQuerySpecification>();
	auto matches = matcher.matches();

	for (auto & m : matches)
	{

		std::cout << "match found: " << *(m.app) << std::endl;
		ASSERT_NE(modelRoot.appInstances.count(m.app), 0);
		modelRoot.appInstances.erase(m.app);
	}
	ASSERT_EQ(modelRoot.appInstances.size(), 2);

}



int main(int argc, char **argv) {

	::testing::InitGoogleTest(&argc, argv);
	auto rat = RUN_ALL_TESTS();
	system("pause");
	return rat;
}
