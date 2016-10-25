
#ifndef _MODELROOT__H__
#define _MODELROOT__H__

#include<map>
#include<mutex>
#include"Viatra/Query/Model/ModelElement.h"
#include"Viatra/Query/Matcher/ModelIndex.h"


namespace Viatra {
	namespace Query {
		namespace Model {
			class ModelRoot
			{
			public:
				ModelRoot();
				ModelRoot(const char * configjson, const char * localNodeName);
				~ModelRoot()
				{
					FreeAllModelElement();
				}

				Viatra::Query::Model::ModelElement* findModelElementByID(int32_t id) const
				{
					return modelElements.at(id);
				}

				std::unique_lock<std::mutex> acquireLock()
				{
					return std::unique_lock<std::mutex>(lock);
				}

			private:
				void FreeAllModelElement();
				std::map<int32_t, Viatra::Query::Model::ModelElement*> modelElements;

				std::mutex lock;

			};

		};

		template<typename T>
		struct ModelIndex<T, Viatra::Query::Model::ModelRoot> {
			static const std::list<T*>& instances(const Viatra::Query::Model::ModelRoot* modelRoot)
			{
				return T::LocalImplementation::Instances();
			}
		};
	}
}

#endif

