#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseMatch.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseMatcher.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedTrainsAreTooClose;

	class TrainsAreTooClose {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedTrainsAreTooClose<ModelRoot>;
		
		using Match = TrainsAreTooCloseMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = TrainsAreTooClose;
			static constexpr int queryID = 12;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					TrainsAreTooCloseFrame_0 frame;
					TrainsAreTooCloseFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					TrainsAreTooCloseFrame_1 frame;
					TrainsAreTooCloseFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				{
					TrainsAreTooCloseFrame_2 frame;
					TrainsAreTooCloseFrame_2Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[2] = frameVector.SerializeAsString();
				}
				{
					TrainsAreTooCloseFrame_3 frame;
					TrainsAreTooCloseFrame_3Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[3] = frameVector.SerializeAsString();
				}
				{
					TrainsAreTooCloseFrame_4 frame;
					TrainsAreTooCloseFrame_4Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[4] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedTrainsAreTooClose {
	public:
		using BindInfo = TrainsAreTooClose::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = TrainsAreTooCloseMatcher<ModelRoot>;
		using QuerySpecification = TrainsAreTooCloseQuerySpecification<ModelRoot>;
		using Match = TrainsAreTooCloseMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_H_ */
