#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Arch/arch_def.h"

namespace Viatra {
	namespace Query {

		template<>
		struct ModelIndex<::arch::Node, ::arch::SN> {
			static const std::list<::arch::Node*>& instances(const ::arch::SN* modelroot) {
				return ::arch::Node::_instances;
			}
		};

		template<>
		struct ModelIndex<::arch::CL, ::arch::SN> {
			static const std::list<::arch::CL*>& instances(const ::arch::SN* modelroot) {
				return ::arch::CL::_instances;
			}
		};

		template<>
		struct ModelIndex<::arch::SN, ::arch::SN> {
			static const std::list<::arch::SN*>& instances(const ::arch::SN* modelroot) {
				return ::arch::SN::_instances;
			}
		};

	}
}
