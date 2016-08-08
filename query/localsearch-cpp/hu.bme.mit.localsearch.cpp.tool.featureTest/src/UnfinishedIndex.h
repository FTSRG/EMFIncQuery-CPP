#include "Viatra/Query/Matcher/ModelIndex.h"
#include "unfinished_def.h"

namespace Viatra {
	namespace Query {

		template<>
		struct ModelIndex<::unfinished::Item, ::unfinished::Item> {
			static const std::list<::unfinished::Item*>& instances(const ::unfinished::Item* modelroot) {
				return ::unfinished::Item::_instances;
			}
		};

	}
}
