#ifndef VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberMatch.h"
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberMatcher.h"
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedNumEqualityWithMember;

	class NumEqualityWithMember {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedNumEqualityWithMember<ModelRoot>;
		
		using Match = NumEqualityWithMemberMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = NumEqualityWithMember;
			static constexpr int queryID = 11;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					NumEqualityWithMemberFrame_0 frame;
					NumEqualityWithMemberFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedNumEqualityWithMember {
	public:
		using BindInfo = NumEqualityWithMember::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = NumEqualityWithMemberMatcher<ModelRoot>;
		using QuerySpecification = NumEqualityWithMemberQuerySpecification<ModelRoot>;
		using Match = NumEqualityWithMemberMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_H_ */
