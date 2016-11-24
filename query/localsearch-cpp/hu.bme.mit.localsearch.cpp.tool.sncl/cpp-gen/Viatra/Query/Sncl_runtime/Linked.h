#ifndef VIATRA__QUERY__SNCL_RUNTIME__LINKED_H_
#define VIATRA__QUERY__SNCL_RUNTIME__LINKED_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Sncl_runtime/LinkedMatch.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/LinkedQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


	template<class ModelRootParam>
	class RootedLinked;

	class Linked {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedLinked<ModelRoot>;
		
		using Match = LinkedMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
			struct S1{
				using QueryClass = Linked;
				static constexpr int queryID = 2;
				static BindInfo BuildFrames(::arch::ISN* S1){
					std::map<int, std::string> encodedFrames;
					
					{
						LinkedFrame_0 frame;
						LinkedFrame_0Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						LinkedFrame_1 frame;
						LinkedFrame_1Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct S1{
				using QueryClass = Linked;
				static constexpr int queryID = 5;
				static BindInfo BuildFrames(::arch::ISN* S1){
					std::map<int, std::string> encodedFrames;
					
					{
						LinkedFrame_0 frame;
						LinkedFrame_0Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						LinkedFrame_1 frame;
						LinkedFrame_1Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct S1{
				using QueryClass = Linked;
				static constexpr int queryID = 8;
				static BindInfo BuildFrames(::arch::ISN* S1){
					std::map<int, std::string> encodedFrames;
					
					{
						LinkedFrame_0 frame;
						LinkedFrame_0Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						LinkedFrame_1 frame;
						LinkedFrame_1Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct S1{
				using QueryClass = Linked;
				static constexpr int queryID = 12;
				static BindInfo BuildFrames(::arch::ISN* S1){
					std::map<int, std::string> encodedFrames;
					
					{
						LinkedFrame_0 frame;
						LinkedFrame_0Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						LinkedFrame_1 frame;
						LinkedFrame_1Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct S1{
				using QueryClass = Linked;
				static constexpr int queryID = 14;
				static BindInfo BuildFrames(::arch::ISN* S1){
					std::map<int, std::string> encodedFrames;
					
					{
						LinkedFrame_0 frame;
						LinkedFrame_0Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						LinkedFrame_1 frame;
						LinkedFrame_1Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct S1{
				using QueryClass = Linked;
				static constexpr int queryID = 16;
				static BindInfo BuildFrames(::arch::ISN* S1){
					std::map<int, std::string> encodedFrames;
					
					{
						LinkedFrame_0 frame;
						LinkedFrame_0Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						LinkedFrame_1 frame;
						LinkedFrame_1Vector frameVector;
						frame._0 = S1;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct S1_S2{
				using QueryClass = Linked;
				static constexpr int queryID = 21;
				static BindInfo BuildFrames(::arch::ISN* S1, ::arch::ISN* S2){
					std::map<int, std::string> encodedFrames;
					
					{
						LinkedFrame_0 frame;
						LinkedFrame_0Vector frameVector;
						frame._0 = S1;
						frame._1 = S2;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					{
						LinkedFrame_1 frame;
						LinkedFrame_1Vector frameVector;
						frame._0 = S1;
						frame._1 = S2;
						frameVector.push_back(frame);
						encodedFrames[1] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
		};
		
		struct NoBind{
			using QueryClass = Linked;
			static constexpr int queryID = 19;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					LinkedFrame_0 frame;
					LinkedFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					LinkedFrame_1 frame;
					LinkedFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedLinked {
	public:
		using BindInfo = Linked::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = LinkedMatcher<ModelRoot>;
		using QuerySpecification = LinkedQuerySpecification<ModelRoot>;
		using Match = LinkedMatch;
		using QueryGroup = Sncl_runtimeQueryGroup;
	};
			

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__LINKED_H_ */
