#ifndef VIATRA__QUERY__SNCL_RUNTIME__SNCL_RUNTIME_QUERY_GROUP_H_
#define VIATRA__QUERY__SNCL_RUNTIME__SNCL_RUNTIME_QUERY_GROUP_H_

		
#include "Viatra/Query/Matcher/ClassHelper.h"
#include "Viatra/Query/Matcher/ISearchContext.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "arch/CL.h"
#include "arch/Node.h"
#include "arch/SN.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

class Sncl_runtimeQueryGroup{
public:
	static Sncl_runtimeQueryGroup* instance() {
		static Sncl_runtimeQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	Sncl_runtimeQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::arch::INode::type_id).noSuper()
					.forClass(::arch::ISN::type_id).setSuper(::arch::INode::type_id)
					.forClass(::arch::ICL::type_id).setSuper(::arch::INode::type_id)
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__SNCL_RUNTIME_QUERY_GROUP_H_ */
