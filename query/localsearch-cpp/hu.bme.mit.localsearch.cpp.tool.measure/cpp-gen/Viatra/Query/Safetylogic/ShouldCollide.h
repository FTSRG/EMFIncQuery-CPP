#ifndef VIATRA__QUERY__SAFETYLOGIC__SHOULD_COLLIDE_H_
#define VIATRA__QUERY__SAFETYLOGIC__SHOULD_COLLIDE_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/ShouldCollideMatch.h"
#include "Viatra/Query/Safetylogic/ShouldCollideMatcher.h"
#include "Viatra/Query/Safetylogic/ShouldCollideQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedShouldCollide;

	class ShouldCollide {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedShouldCollide<ModelRoot>;
		
		using Match = ShouldCollideMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = ShouldCollide;
			static constexpr int queryID = 19;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					ShouldCollideFrame_0 frame;
					ShouldCollideFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedShouldCollide {
	public:
		using BindInfo = ShouldCollide::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = ShouldCollideMatcher<ModelRoot>;
		using QuerySpecification = ShouldCollideQuerySpecification<ModelRoot>;
		using Match = ShouldCollideMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__SHOULD_COLLIDE_H_ */
