#ifndef VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/IdIsNotUniqueMatch.h"
#include "Viatra/Query/Cpsquery/IdIsNotUniqueQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class IdIsNotUniqueMatcher {
public:
	IdIsNotUniqueMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<IdIsNotUniqueMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<IdIsNotUniqueMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& identifiableId_0__identifiable : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::Identifiable>::type, ModelRoot>::instances(_model))) {
				if(!::Viatra::Query::Util::IsNull<decltype(identifiableId_0__identifiable->identifier)>::check(identifiableId_0__identifiable->identifier)) {
					auto identifiableId_0__id = identifiableId_0__identifiable->identifier;
					if(_classHelper->is_super_type(identifiableId_0__identifiable->get_type_id(), ::cyberPhysicalSystem::Identifiable::type_id)) {
						auto identifiableId_0__identifiable_0 = identifiableId_0__identifiable;
						for(auto&& identifiableId_1__identifiable : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::Identifiable>::type, ModelRoot>::instances(_model))) {
							if(identifiableId_1__identifiable->identifier == identifiableId_0__id) {
								if(identifiableId_1__identifiable != identifiableId_0__identifiable_0){
									::Viatra::Query::Cpsquery::IdIsNotUniqueMatch match;
									match.identifiable = static_cast<::cyberPhysicalSystem::Identifiable*>(identifiableId_1__identifiable);
									
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


#endif /*  VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCHER_H_ */
