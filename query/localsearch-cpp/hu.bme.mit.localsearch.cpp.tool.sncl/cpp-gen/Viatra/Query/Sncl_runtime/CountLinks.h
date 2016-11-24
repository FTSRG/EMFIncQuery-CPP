#ifndef VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_H_
#define VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/CountLinksMatch.h"
#include "Viatra/Query/Sncl_runtime/CountLinksMatcher.h"
#include "Viatra/Query/Sncl_runtime/CountLinksQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedCountLinks;

	class CountLinks {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedCountLinks<ModelRoot>;
		
		using Match = CountLinksMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = CountLinks;
			static constexpr int queryID = 1;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					CountLinksFrame_0 frame;
					CountLinksFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedCountLinks {
	public:
		using BindInfo = CountLinks::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = CountLinksMatcher<ModelRoot>;
		using QuerySpecification = CountLinksQuerySpecification<ModelRoot>;
		using Match = CountLinksMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_H_ */
