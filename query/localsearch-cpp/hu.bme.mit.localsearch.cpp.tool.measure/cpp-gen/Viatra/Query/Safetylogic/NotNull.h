#ifndef VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_H_
#define VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/NotNullMatch.h"
#include "Viatra/Query/Safetylogic/NotNullMatcher.h"
#include "Viatra/Query/Safetylogic/NotNullQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedNotNull;

	class NotNull {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedNotNull<ModelRoot>;
		
		using Match = NotNullMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
			struct Old{
				using QueryClass = NotNull;
				static constexpr int queryID = 11;
				static BindInfo BuildFrames(::railRoadModel::IRailRoadElement* Old){
					std::map<int, std::string> encodedFrames;
					
					{
						NotNullFrame_0 frame;
						NotNullFrame_0Vector frameVector;
						frame._0 = Old;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct Old{
				using QueryClass = NotNull;
				static constexpr int queryID = 14;
				static BindInfo BuildFrames(::railRoadModel::IRailRoadElement* Old){
					std::map<int, std::string> encodedFrames;
					
					{
						NotNullFrame_0 frame;
						NotNullFrame_0Vector frameVector;
						frame._0 = Old;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct Old{
				using QueryClass = NotNull;
				static constexpr int queryID = 16;
				static BindInfo BuildFrames(::railRoadModel::IRailRoadElement* Old){
					std::map<int, std::string> encodedFrames;
					
					{
						NotNullFrame_0 frame;
						NotNullFrame_0Vector frameVector;
						frame._0 = Old;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
			struct Old{
				using QueryClass = NotNull;
				static constexpr int queryID = 18;
				static BindInfo BuildFrames(::railRoadModel::IRailRoadElement* Old){
					std::map<int, std::string> encodedFrames;
					
					{
						NotNullFrame_0 frame;
						NotNullFrame_0Vector frameVector;
						frame._0 = Old;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
		};
		
		struct NoBind{
			using QueryClass = NotNull;
			static constexpr int queryID = 8;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					NotNullFrame_0 frame;
					NotNullFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedNotNull {
	public:
		using BindInfo = NotNull::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = NotNullMatcher<ModelRoot>;
		using QuerySpecification = NotNullQuerySpecification<ModelRoot>;
		using Match = NotNullMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_H_ */
