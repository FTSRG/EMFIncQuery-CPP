#ifndef VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionMatch.h"
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionMatcher.h"
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedGreaterThanOneSNConnection;

	class GreaterThanOneSNConnection {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedGreaterThanOneSNConnection<ModelRoot>;
		
		using Match = GreaterThanOneSNConnectionMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = GreaterThanOneSNConnection;
			static constexpr int queryID = 7;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					GreaterThanOneSNConnectionFrame_0 frame;
					GreaterThanOneSNConnectionFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedGreaterThanOneSNConnection {
	public:
		using BindInfo = GreaterThanOneSNConnection::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = GreaterThanOneSNConnectionMatcher<ModelRoot>;
		using QuerySpecification = GreaterThanOneSNConnectionQuerySpecification<ModelRoot>;
		using Match = GreaterThanOneSNConnectionMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_H_ */
