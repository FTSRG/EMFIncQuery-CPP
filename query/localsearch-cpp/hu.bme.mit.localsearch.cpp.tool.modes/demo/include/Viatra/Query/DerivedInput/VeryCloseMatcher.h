#ifndef VIATRA__QUERY__DERIVED_INPUT__VERY_CLOSE_MATCHER_H_
#define VIATRA__QUERY__DERIVED_INPUT__VERY_CLOSE_MATCHER_H_

#include <type_traits>
#include <unordered_set>

#include "Viatra/Query/DerivedInput/VeryCloseMatch.h"
#include "Viatra/Query/DerivedInput/VeryCloseQuerySpecification.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

template<class ModelRoot>
class VeryCloseMatcher {
public:
	VeryCloseMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context)
		: _model(model), _context(context) {
	}
	std::unordered_set<VeryCloseMatch> matches(int robotPartID, int trainID, double robX, double robY, double robZ, double trX, double trY, double trZ) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Matcher::ClassHelper;

		std::unordered_set<VeryCloseMatch> matches;

		{
			auto _classHelper = &_context->get_class_helper();
			if(
				//
				//  *****************  CHECK EXPRESSION IMPLEMENTATION
				//
				[](double trX, double robX, double robY, double robZ, double trY, double trZ){
					// check(<XBinaryOperationImplCustom> < <XNumberLiteralImpl>);
					return (((((robX-trX)*(robX-trX))+((robY-trY)*(robY-trY)))+((robZ-trZ)*(robZ-trZ)))<50);
				}
				//	***************************************************

				  (trX, robX, robY, robZ, trY, trZ)){
					for(auto&& robotPart : (ModelIndex<std::remove_pointer<::railRoadModel::RobotPart>::type, ModelRoot>::instances(_model))) {
						if(_classHelper->is_super_type(robotPart->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
							auto robotPart_0 = robotPart;
							if(robotPart_0->id == robotPartID) {
								for(auto&& train : (ModelIndex<std::remove_pointer<::railRoadModel::Train>::type, ModelRoot>::instances(_model))) {
									if(_classHelper->is_super_type(train->get_type_id(), ::railRoadModel::Train::type_id)) {
										auto train_0 = train;
										if(train_0->id == trainID) {
											::Viatra::Query::DerivedInput::VeryCloseMatch match;
											match.robotPart = static_cast<::railRoadModel::RobotPart*>(robotPart_0);
											match.robotPartID = static_cast<int>(robotPartID);
											match.train = static_cast<::railRoadModel::Train*>(train_0);
											match.trainID = static_cast<int>(trainID);
											match.robX = static_cast<double>(robX);
											match.robY = static_cast<double>(robY);
											match.robZ = static_cast<double>(robZ);
											match.trX = static_cast<double>(trX);
											match.trY = static_cast<double>(trY);
											match.trZ = static_cast<double>(trZ);

											matches.insert(match);
										}
									}
								}
							}
						}
					}
				}
		}


		return matches;
	}

private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__VERY_CLOSE_MATCHER_H_ */
