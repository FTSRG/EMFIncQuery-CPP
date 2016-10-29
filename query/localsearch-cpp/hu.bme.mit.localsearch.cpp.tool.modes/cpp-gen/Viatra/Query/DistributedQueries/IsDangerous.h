#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_H_

#include <map>
#include <string>
		
#include "Viatra/Query/DistributedQueries/IsDangerousMatch.h"
#include "Viatra/Query/DistributedQueries/IsDangerousMatcher.h"
#include "Viatra/Query/DistributedQueries/IsDangerousQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {


	template<class ModelRootParam>
	class RootedIsDangerous;

	class IsDangerous {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedIsDangerous<ModelRoot>;
		
		using Match = IsDangerousMatch;
		using QueryGroup = DistributedQueriesQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = IsDangerous;
			static constexpr int queryID = 2;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					IsDangerousFrame_0 frame;
					IsDangerousFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedIsDangerous {
	public:
		using BindInfo = IsDangerous::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = IsDangerousMatcher<ModelRoot>;
		using QuerySpecification = IsDangerousQuerySpecification<ModelRoot>;
		using Match = IsDangerousMatch;
		using QueryGroup = DistributedQueriesQueryGroup;
	};
			

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_H_ */
