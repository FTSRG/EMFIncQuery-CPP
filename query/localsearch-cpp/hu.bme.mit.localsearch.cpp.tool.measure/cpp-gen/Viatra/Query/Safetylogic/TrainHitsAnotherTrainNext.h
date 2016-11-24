#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextMatch.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextMatcher.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedTrainHitsAnotherTrainNext;

	class TrainHitsAnotherTrainNext {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedTrainHitsAnotherTrainNext<ModelRoot>;
		
		using Match = TrainHitsAnotherTrainNextMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = TrainHitsAnotherTrainNext;
			static constexpr int queryID = 15;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					TrainHitsAnotherTrainNextFrame_0 frame;
					TrainHitsAnotherTrainNextFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_1 frame;
					TrainHitsAnotherTrainNextFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_2 frame;
					TrainHitsAnotherTrainNextFrame_2Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[2] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_3 frame;
					TrainHitsAnotherTrainNextFrame_3Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[3] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_4 frame;
					TrainHitsAnotherTrainNextFrame_4Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[4] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_5 frame;
					TrainHitsAnotherTrainNextFrame_5Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[5] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_6 frame;
					TrainHitsAnotherTrainNextFrame_6Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[6] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_7 frame;
					TrainHitsAnotherTrainNextFrame_7Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[7] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_8 frame;
					TrainHitsAnotherTrainNextFrame_8Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[8] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextFrame_9 frame;
					TrainHitsAnotherTrainNextFrame_9Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[9] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedTrainHitsAnotherTrainNext {
	public:
		using BindInfo = TrainHitsAnotherTrainNext::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = TrainHitsAnotherTrainNextMatcher<ModelRoot>;
		using QuerySpecification = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>;
		using Match = TrainHitsAnotherTrainNextMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_H_ */
