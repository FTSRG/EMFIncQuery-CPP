
#ifndef _MODELROOT__H__
#define _MODELROOT__H__

#include<map>
#include"Viatra/Query/Model/ModelElement.h"
#include"Viatra/Query/Matcher/ModelIndex.h"


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

				Viatra::Query::Model::ModelElement* findModelElementByID(int32_t id)
				{
					return modelElements.at(id);
				}

			private:
				void FreeAllModelElement();
				std::map<int, Viatra::Query::Model::ModelElement*> modelElements;

			};

		};

		template<typename T>
		struct ModelIndex<T, Viatra::Query::Model::ModelRoot> {
			static const std::list<T*>& instances(const Viatra::Query::Model::ModelRoot* modelRoot)
			{
				return T::LocalImplementation::_instances__x__x__x__x__x__x__x;
			}
		};
	}
}



#endif