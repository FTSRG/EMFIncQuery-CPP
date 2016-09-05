// **************************************
//
// COPY ME NEXT TO GENERATED MAKEFILE
//
// **************************************

#include "NearByUpdaterTest.h"
#include "gtest/gtest.h"

//RobotParts 4->6
//Train 1->3

TEST_F(NearByUpdaterTest, InputGenerating){
	auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
	auto matcher = engine.matcher<NearByQuerySpecification>();
	
	robotX = trainX = 3;
	robotY = 2;
	trainY = 5;
	robotZ = trainZ = 4;
	
	for(auto tr = 1; tr <= 3; tr++)
		for(auto rob = 4; rob <= 6; rob++){
			auto matches = matcher.matches(rob, tr, robotX, robotY, robotZ, trainX, trainY, trainZ);
			ASSERT_EQ(matches.size(),1);
			for(auto match : matches) ASSERT_TRUE(match.robotPart->id == rob && match.train->id == tr);
		}
		
	auto robotPartID = 0;
	auto srcIDPredicate = [robotPartID](const ::RailRoadModel::RobotPart* src){
		return src->id == robotPartID;
	};
	auto trainID = 0;
	auto trgIDPredicate = [trainID](const ::RailRoadModel::Train* trg){
		return trg->id == trainID;
	};
	
	for(auto tr = 1; tr <= 3; tr++)
		for(auto rob = 4; rob <= 6; rob++){
			ASSERT_NO_THROW(NearByUpdate<ModelRoot>::update(modelRoot, rob, tr, robotX, robotY, robotZ, trainX, trainY, trainZ));
			
			auto robotPartID = rob;
			auto srcIDPredicate = [robotPartID](const ::RailRoadModel::RobotPart* src){
				return src->id == robotPartID;
			};
			
			auto srcIt = std::find_if(robotparts.begin(), robotparts.end(), srcIDPredicate);
			ASSERT_NE(srcIt, robotparts.end());
			auto trainID = tr;
			auto trgIDPredicate = [trainID](const ::RailRoadModel::Train* trg){
				return trg->id == trainID;
			};
			auto trgIt = std::find_if((*srcIt)->nearBy.begin(), (*srcIt)->nearBy.end(), trgIDPredicate);
			ASSERT_NE(trgIt, (*srcIt)->nearBy.end());
		}
	
	robotY = 2;
	trainY = 10;
	trainID = 1;
	for(auto rob = 4; rob <= 6; rob++){
		ASSERT_NO_THROW(NearByUpdate<ModelRoot>::update(modelRoot, rob, trainID, robotX, robotY, robotZ, trainX, trainY, trainZ));		
		auto robotPartID = rob;
		auto srcIDPredicate = [robotPartID](const ::RailRoadModel::RobotPart* src){
			return src->id == robotPartID;
		};
		auto srcIt = std::find_if(robotparts.begin(), robotparts.end(), srcIDPredicate);
		ASSERT_NE(srcIt, robotparts.end());
		
		auto trgIDPredicate = [trainID](const ::RailRoadModel::Train* trg){
			return trg->id == trainID;
		};
		
		auto trgIt = std::find_if((*srcIt)->nearBy.begin(), (*srcIt)->nearBy.end(), trgIDPredicate);
		ASSERT_EQ(trgIt, (*srcIt)->nearBy.end());
	}
}

TEST_F(NearByUpdaterTest, NotExistingIDs){
	ASSERT_THROW(NearByUpdate<ModelRoot>::update(modelRoot, 4, 10, robotX, robotY, robotZ, trainX, trainY, trainZ), std::invalid_argument*);
	ASSERT_THROW(NearByUpdate<ModelRoot>::update(modelRoot, 10, 1, robotX, robotY, robotZ, trainX, trainY, trainZ), std::invalid_argument*);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}