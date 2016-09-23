
#ifndef _MODELROOT__H__
#define _MODELROOT__H__

#include<map>
#include"Viatra/Query/Model/ModelElement.h"


namespace Viatra {
	namespace Query {
		namespace Model {
			class ModelRoot
			{
			public:
				ModelRoot(const char * configjson);
				~ModelRoot()
				{
					FreeAllModelElement();
				}

			private:
				void FreeAllModelElement();
				std::map<int, Viatra::Query::Model::ModelElement*> modelElements;

			};

		};

		template<typename T>
		struct ModelIndex<T, ModelRoot> {
			static const std::list<T*>& instances(const ModelRoot* modelRoot)
			{
				return T::LocalImplementation::_instances__x__x__x__x__x__x__x;
			}
		};
	}
}



#endif