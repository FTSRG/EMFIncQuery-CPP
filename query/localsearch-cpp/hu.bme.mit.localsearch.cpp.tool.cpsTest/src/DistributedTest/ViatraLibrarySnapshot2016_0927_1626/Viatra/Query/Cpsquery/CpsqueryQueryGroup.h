#ifndef VIATRA__QUERY__CPSQUERY__CPSQUERY_QUERY_GROUP_H_
#define VIATRA__QUERY__CPSQUERY__CPSQUERY_QUERY_GROUP_H_

		
#include "Viatra/Query/Matcher/ClassHelper.h"
#include "Viatra/Query/Matcher/ISearchContext.h"
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/ApplicationType.h"
#include "cyberPhysicalSystem/CyberPhysicalSystem.h"
#include "cyberPhysicalSystem/HostInstance.h"
#include "cyberPhysicalSystem/HostType.h"
#include "cyberPhysicalSystem/Identifiable.h"
#include "cyberPhysicalSystem/Request.h"
#include "cyberPhysicalSystem/Requirement.h"
#include "cyberPhysicalSystem/ResourceRequirement.h"
#include "cyberPhysicalSystem/State.h"
#include "cyberPhysicalSystem/StateMachine.h"
#include "cyberPhysicalSystem/Transition.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

class CpsqueryQueryGroup{
public:
	static CpsqueryQueryGroup* instance() {
		static CpsqueryQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	CpsqueryQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::cyberPhysicalSystem::Identifiable::type_id).noSuper()
					.forClass(::cyberPhysicalSystem::CyberPhysicalSystem::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::ApplicationType::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::HostType::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::ResourceRequirement::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::HostInstance::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::ApplicationInstance::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::Request::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::Requirement::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::StateMachine::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::State::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.forClass(::cyberPhysicalSystem::Transition::type_id).setSuper(::cyberPhysicalSystem::Identifiable::type_id)
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__CPSQUERY_QUERY_GROUP_H_ */
