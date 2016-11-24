#ifndef VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_C_L_H_
#define VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_C_L_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/IsolatedCLMatch.h"
#include "Viatra/Query/Sncl_runtime/IsolatedCLMatcher.h"
#include "Viatra/Query/Sncl_runtime/IsolatedCLQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedIsolatedCL;

	class IsolatedCL {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedIsolatedCL<ModelRoot>;
		
		using Match = IsolatedCLMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = IsolatedCL;
			static constexpr int queryID = 17;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					IsolatedCLFrame_0 frame;
					IsolatedCLFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedIsolatedCL {
	public:
		using BindInfo = IsolatedCL::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = IsolatedCLMatcher<ModelRoot>;
		using QuerySpecification = IsolatedCLQuerySpecification<ModelRoot>;
		using Match = IsolatedCLMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_C_L_H_ */
