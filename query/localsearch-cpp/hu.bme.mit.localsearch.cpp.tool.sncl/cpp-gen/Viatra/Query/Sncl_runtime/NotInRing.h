#ifndef VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/NotInRingMatch.h"
#include "Viatra/Query/Sncl_runtime/NotInRingMatcher.h"
#include "Viatra/Query/Sncl_runtime/NotInRingQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedNotInRing;

	class NotInRing {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedNotInRing<ModelRoot>;
		
		using Match = NotInRingMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = NotInRing;
			static constexpr int queryID = 9;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					NotInRingFrame_0 frame;
					NotInRingFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedNotInRing {
	public:
		using BindInfo = NotInRing::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = NotInRingMatcher<ModelRoot>;
		using QuerySpecification = NotInRingQuerySpecification<ModelRoot>;
		using Match = NotInRingMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_H_ */
