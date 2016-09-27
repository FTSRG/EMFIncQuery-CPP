#ifndef VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_RAM_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_RAM_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/AvailableGreaterThanTotalRamMatch.h"
#include "Viatra/Query/Cpsquery/AvailableGreaterThanTotalRamQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AvailableGreaterThanTotalRamMatcher {
public:
	AvailableGreaterThanTotalRamMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<AvailableGreaterThanTotalRamMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AvailableGreaterThanTotalRamMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& host : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(host->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto host_0 = host;
					if(_classHelper->is_super_type(host_0->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto host_1 = host_0;
						if(!::Viatra::Query::Util::IsNull<decltype(host_1->availableRam)>::check(host_1->availableRam)) {
							auto aRam = host_1->availableRam;
							if(!::Viatra::Query::Util::IsNull<decltype(host_1->totalRam)>::check(host_1->totalRam)) {
								auto tRam = host_1->totalRam;
								if(
									//
									//  *****************  CHECK EXPRESSION IMPLEMENTATION
									//		
									[](int aRam, int tRam){
										// Please implement the following 
										// <XFeatureCallImplCustom> > <XFeatureCallImplCustom>
										//
										
										static_assert(false, "Please implement the Check expression");	
									}
									//	***************************************************
									
									  (aRam, tRam)){
										::Viatra::Query::Cpsquery::AvailableGreaterThanTotalRamMatch match;
										match.host = static_cast<::cyberPhysicalSystem::HostInstance*>(host_1);
										
										matches.insert(match);
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

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_RAM_MATCHER_H_ */
