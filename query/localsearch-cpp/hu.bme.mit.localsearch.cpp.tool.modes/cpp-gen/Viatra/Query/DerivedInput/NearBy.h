#ifndef VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_H_
#define VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_H_

#include <map>
#include <string>
		
#include "Viatra/Query/DerivedInput/NearByMatch.h"
#include "Viatra/Query/DerivedInput/NearByMatcher.h"
#include "Viatra/Query/DerivedInput/NearByQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {


	template<class ModelRootParam>
	class RootedNearBy;

	class NearBy {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedNearBy<ModelRoot>;
		
		using Match = NearByMatch;
		using QueryGroup = DerivedInputQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
			struct robotPartID_trainID_segID_robX_robY_robZ_segX_segY_segZ{
				using QueryClass = NearBy;
				static constexpr int queryID = 2;
				static BindInfo BuildFrames(int robotPartID, int trainID, int segID, double robX, double robY, double robZ, double segX, double segY, double segZ){
					std::map<int, std::string> encodedFrames;
					
					{
						NearByFrame_0 frame;
						NearByFrame_0Vector frameVector;
						frame._1 = robotPartID;
						frame._3 = trainID;
						frame._4 = segID;
						frame._5 = robX;
						frame._6 = robY;
						frame._7 = robZ;
						frame._8 = segX;
						frame._9 = segY;
						frame._10 = segZ;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
		};
		
		struct NoBind{
			using QueryClass = NearBy;
			static constexpr int queryID = 1;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					NearByFrame_0 frame;
					NearByFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedNearBy {
	public:
		using BindInfo = NearBy::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = NearByMatcher<ModelRoot>;
		using QuerySpecification = NearByQuerySpecification<ModelRoot>;
		using Match = NearByMatch;
		using QueryGroup = DerivedInputQueryGroup;
	};
			

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_H_ */
