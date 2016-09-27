#pragma once

#pragma once

#include "ModelElement.h"

namespace Viatra {
	namespace Query {
		namespace Model {
			
			class RemoteElement : public virtual ModelElement
			{
			private:

			protected:
				RemoteElement(id_t id)
					: ModelElement(id, false)
				{}
			};
		}
	}
}
