#ifndef VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_H_
#define VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_H_

#include <map>
#include <string>
		
#include "Viatra/Query/DerivedInput/FrozenStateAPIMatch.h"
#include "Viatra/Query/DerivedInput/FrozenStateAPIMatcher.h"
#include "Viatra/Query/DerivedInput/FrozenStateAPIQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {


	template<class ModelRootParam>
	class RootedFrozenStateAPI;

	class FrozenStateAPI {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedFrozenStateAPI<ModelRoot>;
		
		using Match = FrozenStateAPIMatch;
		using QueryGroup = DerivedInputQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
			struct turnoutID_stateID_turnoutTemp{
				using QueryClass = FrozenStateAPI;
				static constexpr int queryID = 4;
				static BindInfo BuildFrames(int turnoutIDint stateIDdouble turnoutTemp){
					std::map<int, std::string> encodedFrames;
					
					{
						FrozenStateAPIFrame_0 frame;
						FrozenStateAPIFrame_0Vector frameVector;
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
			using QueryClass = FrozenStateAPI;
			static constexpr int queryID = 3;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					FrozenStateAPIFrame_0 frame;
					FrozenStateAPIFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedFrozenStateAPI {
	public:
		using BindInfo = FrozenStateAPI::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = FrozenStateAPIMatcher<ModelRoot>;
		using QuerySpecification = FrozenStateAPIQuerySpecification<ModelRoot>;
		using Match = FrozenStateAPIMatch;
		using QueryGroup = DerivedInputQueryGroup;
	};
			

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_H_ */
