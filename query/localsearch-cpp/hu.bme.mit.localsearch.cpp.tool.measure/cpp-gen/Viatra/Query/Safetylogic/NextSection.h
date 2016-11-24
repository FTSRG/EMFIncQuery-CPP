#ifndef VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_H_
#define VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/NextSectionMatch.h"
#include "Viatra/Query/Safetylogic/NextSectionMatcher.h"
#include "Viatra/Query/Safetylogic/NextSectionQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedNextSection;

	class NextSection {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedNextSection<ModelRoot>;
		
		using Match = NextSectionMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = NextSection;
			static constexpr int queryID = 10;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					NextSectionFrame_0 frame;
					NextSectionFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_1 frame;
					NextSectionFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_2 frame;
					NextSectionFrame_2Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[2] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_3 frame;
					NextSectionFrame_3Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[3] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_4 frame;
					NextSectionFrame_4Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[4] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_5 frame;
					NextSectionFrame_5Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[5] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_6 frame;
					NextSectionFrame_6Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[6] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_7 frame;
					NextSectionFrame_7Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[7] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_8 frame;
					NextSectionFrame_8Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[8] = frameVector.SerializeAsString();
				}
				{
					NextSectionFrame_9 frame;
					NextSectionFrame_9Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[9] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedNextSection {
	public:
		using BindInfo = NextSection::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = NextSectionMatcher<ModelRoot>;
		using QuerySpecification = NextSectionQuerySpecification<ModelRoot>;
		using Match = NextSectionMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_H_ */
