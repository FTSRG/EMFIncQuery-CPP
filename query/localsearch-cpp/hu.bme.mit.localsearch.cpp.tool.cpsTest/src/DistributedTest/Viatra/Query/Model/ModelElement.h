
#ifndef _VIATRA_QUERY_MODEL_MODELELEMENT_H_
#define _VIATRA_QUERY_MODEL_MODELELEMENT_H_

#include<stdint.h>


namespace Viatra {
	namespace Query {
		namespace Model {

			using id_t = uint64_t;

			class ModelElement
			{
			public:
				bool present() { return _present; }
				id_t id() { return _id; }

			protected:
				id_t _id;
				bool _present;
				ModelElement(id_t id, bool present)
					: _id(id)
					, _present(present)
				{}

				virtual ~ModelElement()
				{}

			};
		}
	}
}




#endif