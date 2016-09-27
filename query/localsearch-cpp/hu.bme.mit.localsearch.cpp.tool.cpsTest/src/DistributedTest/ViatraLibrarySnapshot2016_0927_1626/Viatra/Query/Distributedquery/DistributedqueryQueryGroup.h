#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__DISTRIBUTEDQUERY_QUERY_GROUP_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__DISTRIBUTEDQUERY_QUERY_GROUP_H_

		
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
namespace Distributedquery {

class DistributedqueryQueryGroup{
public:
	static DistributedqueryQueryGroup* instance() {
		static DistributedqueryQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	DistributedqueryQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::cyberPhysicalSystem::IIdentifiable::type_id).noSuper()
					.forClass(::cyberPhysicalSystem::ICyberPhysicalSystem::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IApplicationType::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IHostType::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IResourceRequirement::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IHostInstance::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IApplicationInstance::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IRequest::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IRequirement::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IStateMachine::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::IState::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.forClass(::cyberPhysicalSystem::ITransition::type_id).setSuper(::cyberPhysicalSystem::IIdentifiable::type_id)
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace Distributedquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__DISTRIBUTEDQUERY_QUERY_GROUP_H_ */
