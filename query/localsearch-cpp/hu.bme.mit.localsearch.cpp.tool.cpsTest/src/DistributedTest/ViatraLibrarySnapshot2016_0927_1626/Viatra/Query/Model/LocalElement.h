#pragma once

#include "ModelElement.h"

namespace Viatra {
	namespace Query {
		namespace Model {
			
			class LocalElement : public virtual ModelElement
			{
			protected:
				LocalElement(id_t id)
					: ModelElement(id, true)
				{}

			private:

			};
		}
	}
}

