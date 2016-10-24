#ifndef VIATRA__QUERY__QUERY__SZILARD_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__QUERY__SZILARD_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Query/QueryQueryGroup.h"
#include "Viatra/Query/Query/SzilardFrame_0.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Query {

template<class ModelRoot>
class SzilardMatcher;

template<class ModelRoot>
class SzilardQuerySpecification {
public:
	using Matcher = SzilardMatcher<ModelRoot>;

	using QueryGroup = QueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<SzilardFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<SzilardFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&SzilardFrame_0::_0, ::factory::Tartaly::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&SzilardFrame_0::_0, &SzilardFrame_0::_5, &::factory::Tartaly::tarol));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_0, ::factory::Tartaly::type_id));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_5, ::factory::Viz::type_id));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_0, ::factory::Tartaly::type_id));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_0, ::factory::Tartaly::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&SzilardFrame_0::_0, &SzilardFrame_0::_1, &::factory::Tartaly::ID));
		sp.add_operation(create_CheckExpression<SzilardFrame_0>(
			[](double homerseklet){
				return homerseklet < 0;
			},
			&SzilardFrame_0::_4
		)
		);
		sp.add_operation(create_IterateOverInstances(&SzilardFrame_0::_2, ::factory::Halmazallapot::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&SzilardFrame_0::_2, &SzilardFrame_0::_3, &::factory::Szilard::ID));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_2, ::factory::Szilard::type_id));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_2, ::factory::Szilard::type_id));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<SzilardFrame_0> get_plan_tartalyID_allapotID_homerseklet__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<SzilardFrame_0> sp;
		
		
		sp.add_operation(create_CheckExpression<SzilardFrame_0>(
			[](double homerseklet){
				return homerseklet < 0;
			},
			&SzilardFrame_0::_4
		)
		);
		sp.add_operation(create_IterateOverInstances(&SzilardFrame_0::_2, ::factory::Szilard::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_2, ::factory::Szilard::type_id));
		sp.add_operation(create_SingleAssociationCheck(&SzilardFrame_0::_2, &SzilardFrame_0::_3, &::factory::Szilard::ID));
		sp.add_operation(create_IterateOverInstances(&SzilardFrame_0::_0, ::factory::Tartaly::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&SzilardFrame_0::_0, &SzilardFrame_0::_5, &::factory::Tartaly::tarol));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_0, ::factory::Tartaly::type_id));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_5, ::factory::Viz::type_id));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_0, ::factory::Tartaly::type_id));
		sp.add_operation(create_InstanceOfCheck(&SzilardFrame_0::_0, ::factory::Tartaly::type_id));
		sp.add_operation(create_SingleAssociationCheck(&SzilardFrame_0::_0, &SzilardFrame_0::_1, &::factory::Tartaly::ID));
		
		return sp;
	}

};

} /* namespace Query */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__QUERY__SZILARD_QUERY_SPECIFICATION_H_ */
