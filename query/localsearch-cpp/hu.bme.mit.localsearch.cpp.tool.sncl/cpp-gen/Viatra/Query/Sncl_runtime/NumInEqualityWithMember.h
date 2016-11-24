#ifndef VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/NumInEqualityWithMemberMatch.h"
#include "Viatra/Query/Sncl_runtime/NumInEqualityWithMemberMatcher.h"
#include "Viatra/Query/Sncl_runtime/NumInEqualityWithMemberQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedNumInEqualityWithMember;

	class NumInEqualityWithMember {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedNumInEqualityWithMember<ModelRoot>;
		
		using Match = NumInEqualityWithMemberMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = NumInEqualityWithMember;
			static constexpr int queryID = 13;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					NumInEqualityWithMemberFrame_0 frame;
					NumInEqualityWithMemberFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedNumInEqualityWithMember {
	public:
		using BindInfo = NumInEqualityWithMember::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = NumInEqualityWithMemberMatcher<ModelRoot>;
		using QuerySpecification = NumInEqualityWithMemberQuerySpecification<ModelRoot>;
		using Match = NumInEqualityWithMemberMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_H_ */
