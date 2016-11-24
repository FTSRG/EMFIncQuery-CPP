#ifndef VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_H_
#define VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/ViablePathsMatch.h"
#include "Viatra/Query/Safetylogic/ViablePathsMatcher.h"
#include "Viatra/Query/Safetylogic/ViablePathsQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedViablePaths;

	class ViablePaths {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedViablePaths<ModelRoot>;
		
		using Match = ViablePathsMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = ViablePaths;
			static constexpr int queryID = 9;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					ViablePathsFrame_0 frame;
					ViablePathsFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					ViablePathsFrame_1 frame;
					ViablePathsFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				{
					ViablePathsFrame_2 frame;
					ViablePathsFrame_2Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[2] = frameVector.SerializeAsString();
				}
				{
					ViablePathsFrame_3 frame;
					ViablePathsFrame_3Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[3] = frameVector.SerializeAsString();
				}
				{
					ViablePathsFrame_4 frame;
					ViablePathsFrame_4Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[4] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedViablePaths {
	public:
		using BindInfo = ViablePaths::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = ViablePathsMatcher<ModelRoot>;
		using QuerySpecification = ViablePathsQuerySpecification<ModelRoot>;
		using Match = ViablePathsMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_H_ */
