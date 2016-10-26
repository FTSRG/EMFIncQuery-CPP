#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_H_

#include <map>
#include <string>
		
#include "Viatra/Query/DistributedQueries/ShouldCollideMatch.h"
#include "Viatra/Query/DistributedQueries/ShouldCollideMatcher.h"
#include "Viatra/Query/DistributedQueries/ShouldCollideQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {


	template<class ModelRootParam>
	class RootedShouldCollide;

	class ShouldCollide {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedShouldCollide<ModelRoot>;
		
		using Match = ShouldCollideMatch;
		using QueryGroup = DistributedQueriesQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = ShouldCollide;
			static constexpr int queryID = 7;
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
		using QueryGroup = DistributedQueriesQueryGroup;
	};
			

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_H_ */
