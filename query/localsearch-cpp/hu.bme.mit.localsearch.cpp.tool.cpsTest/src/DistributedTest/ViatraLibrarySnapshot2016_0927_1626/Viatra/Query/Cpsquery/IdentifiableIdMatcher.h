#ifndef VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/IdentifiableIdMatch.h"
#include "Viatra/Query/Cpsquery/IdentifiableIdQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class IdentifiableIdMatcher {
public:
	IdentifiableIdMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<IdentifiableIdMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<IdentifiableIdMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& identifiable : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::Identifiable>::type, ModelRoot>::instances(_model))) {
				if(!::Viatra::Query::Util::IsNull<decltype(identifiable->identifier)>::check(identifiable->identifier)) {
					auto id = identifiable->identifier;
					if(_classHelper->is_super_type(identifiable->get_type_id(), ::cyberPhysicalSystem::Identifiable::type_id)) {
						auto identifiable_0 = identifiable;
						::Viatra::Query::Cpsquery::IdentifiableIdMatch match;
						match.identifiable = static_cast<::cyberPhysicalSystem::Identifiable*>(identifiable_0);
						match.id = static_cast<::std::string>(id);
						
						matches.insert(match);
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


#endif /*  VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_MATCHER_H_ */
