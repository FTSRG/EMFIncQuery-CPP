#ifndef VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_H_
#define VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/CurrentlyConnectedMatch.h"
#include "Viatra/Query/Safetylogic/CurrentlyConnectedMatcher.h"
#include "Viatra/Query/Safetylogic/CurrentlyConnectedQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedCurrentlyConnected;

	class CurrentlyConnected {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedCurrentlyConnected<ModelRoot>;
		
		using Match = CurrentlyConnectedMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = CurrentlyConnected;
			static constexpr int queryID = 7;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					CurrentlyConnectedFrame_0 frame;
					CurrentlyConnectedFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					CurrentlyConnectedFrame_1 frame;
					CurrentlyConnectedFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				{
					CurrentlyConnectedFrame_2 frame;
					CurrentlyConnectedFrame_2Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[2] = frameVector.SerializeAsString();
				}
				{
					CurrentlyConnectedFrame_3 frame;
					CurrentlyConnectedFrame_3Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[3] = frameVector.SerializeAsString();
				}
				{
					CurrentlyConnectedFrame_4 frame;
					CurrentlyConnectedFrame_4Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[4] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedCurrentlyConnected {
	public:
		using BindInfo = CurrentlyConnected::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = CurrentlyConnectedMatcher<ModelRoot>;
		using QuerySpecification = CurrentlyConnectedQuerySpecification<ModelRoot>;
		using Match = CurrentlyConnectedMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_H_ */
