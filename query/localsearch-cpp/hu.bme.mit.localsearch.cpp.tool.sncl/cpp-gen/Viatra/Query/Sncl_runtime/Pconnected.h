#ifndef VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_H_
#define VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/PconnectedMatch.h"
#include "Viatra/Query/Sncl_runtime/PconnectedMatcher.h"
#include "Viatra/Query/Sncl_runtime/PconnectedQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedPconnected;

	class Pconnected {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedPconnected<ModelRoot>;
		
		using Match = PconnectedMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
			struct C1{
				using QueryClass = Pconnected;
				static constexpr int queryID = 3;
				static BindInfo BuildFrames(::arch::ICL* C1){
					std::map<int, std::string> encodedFrames;
					
					{
						PconnectedFrame_0 frame;
						PconnectedFrame_0Vector frameVector;
						frame._0 = C1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						PconnectedFrame_1 frame;
						PconnectedFrame_1Vector frameVector;
						frame._0 = C1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct C1{
				using QueryClass = Pconnected;
				static constexpr int queryID = 6;
				static BindInfo BuildFrames(::arch::ICL* C1){
					std::map<int, std::string> encodedFrames;
					
					{
						PconnectedFrame_0 frame;
						PconnectedFrame_0Vector frameVector;
						frame._0 = C1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						PconnectedFrame_1 frame;
						PconnectedFrame_1Vector frameVector;
						frame._0 = C1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct C1{
				using QueryClass = Pconnected;
				static constexpr int queryID = 10;
				static BindInfo BuildFrames(::arch::ICL* C1){
					std::map<int, std::string> encodedFrames;
					
					{
						PconnectedFrame_0 frame;
						PconnectedFrame_0Vector frameVector;
						frame._0 = C1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						PconnectedFrame_1 frame;
						PconnectedFrame_1Vector frameVector;
						frame._0 = C1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct C1{
				using QueryClass = Pconnected;
				static constexpr int queryID = 18;
				static BindInfo BuildFrames(::arch::ICL* C1){
					std::map<int, std::string> encodedFrames;
					
					{
						PconnectedFrame_0 frame;
						PconnectedFrame_0Vector frameVector;
						frame._0 = C1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						PconnectedFrame_1 frame;
						PconnectedFrame_1Vector frameVector;
						frame._0 = C1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
		};
		
		struct NoBind{
			using QueryClass = Pconnected;
			static constexpr int queryID = 20;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					PconnectedFrame_0 frame;
					PconnectedFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					PconnectedFrame_1 frame;
					PconnectedFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedPconnected {
	public:
		using BindInfo = Pconnected::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = PconnectedMatcher<ModelRoot>;
		using QuerySpecification = PconnectedQuerySpecification<ModelRoot>;
		using Match = PconnectedMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_H_ */
