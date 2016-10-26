#ifndef VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_H_
#define VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_H_

#include <map>
#include <string>
		
#include "Viatra/Query/DerivedInput/OperationalStateAPIMatch.h"
#include "Viatra/Query/DerivedInput/OperationalStateAPIMatcher.h"
#include "Viatra/Query/DerivedInput/OperationalStateAPIQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {


	template<class ModelRootParam>
	class RootedOperationalStateAPI;

	class OperationalStateAPI {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedOperationalStateAPI<ModelRoot>;
		
		using Match = OperationalStateAPIMatch;
		using QueryGroup = DerivedInputQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
			struct turnoutID_stateID_turnoutTemp{
				using QueryClass = OperationalStateAPI;
				static constexpr int queryID = 6;
				static BindInfo BuildFrames(int turnoutID, int stateID, double turnoutTemp){
					std::map<int, std::string> encodedFrames;
					
					{
						OperationalStateAPIFrame_0 frame;
						OperationalStateAPIFrame_0Vector frameVector;
						frame._1 = turnoutID;
						frame._3 = stateID;
						frame._4 = turnoutTemp;
						frameVector.push_back(frame);
						encodedFrames[0] = frameVector.SerializeAsString();
					}
					
					return BindInfo{std::move(encodedFrames)};
				}
			};
		};
		
		struct NoBind{
			using QueryClass = OperationalStateAPI;
			static constexpr int queryID = 5;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					OperationalStateAPIFrame_0 frame;
					OperationalStateAPIFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedOperationalStateAPI {
	public:
		using BindInfo = OperationalStateAPI::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = OperationalStateAPIMatcher<ModelRoot>;
		using QuerySpecification = OperationalStateAPIQuerySpecification<ModelRoot>;
		using Match = OperationalStateAPIMatch;
		using QueryGroup = DerivedInputQueryGroup;
	};
			

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_H_ */
