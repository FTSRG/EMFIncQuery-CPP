#ifndef VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_H_
#define VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/RingMembersMatch.h"
#include "Viatra/Query/Sncl_runtime/RingMembersMatcher.h"
#include "Viatra/Query/Sncl_runtime/RingMembersQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedRingMembers;

	class RingMembers {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedRingMembers<ModelRoot>;
		
		using Match = RingMembersMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = RingMembers;
			static constexpr int queryID = 4;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					RingMembersFrame_0 frame;
					RingMembersFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedRingMembers {
	public:
		using BindInfo = RingMembers::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = RingMembersMatcher<ModelRoot>;
		using QuerySpecification = RingMembersQuerySpecification<ModelRoot>;
		using Match = RingMembersMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_H_ */
