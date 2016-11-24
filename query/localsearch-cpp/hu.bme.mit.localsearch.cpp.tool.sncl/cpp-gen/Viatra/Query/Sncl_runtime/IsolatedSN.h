#ifndef VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_H_
#define VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/IsolatedSNMatch.h"
#include "Viatra/Query/Sncl_runtime/IsolatedSNMatcher.h"
#include "Viatra/Query/Sncl_runtime/IsolatedSNQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedIsolatedSN;

	class IsolatedSN {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedIsolatedSN<ModelRoot>;
		
		using Match = IsolatedSNMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = IsolatedSN;
			static constexpr int queryID = 15;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					IsolatedSNFrame_0 frame;
					IsolatedSNFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedIsolatedSN {
	public:
		using BindInfo = IsolatedSN::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = IsolatedSNMatcher<ModelRoot>;
		using QuerySpecification = IsolatedSNQuerySpecification<ModelRoot>;
		using Match = IsolatedSNMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_H_ */
