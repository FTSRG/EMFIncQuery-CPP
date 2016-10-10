
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYTASK_H__
#define _VIATRA_QUERY_DISTRIBUTED_QUERYTASK_H__

#include"../Util/HierarchicalID.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			template<typename RootedQuery>
			class QueryResultCollector;

			using TaskID = Util::HierarchicalID<int>;
			/**
			* @brief Class for storing a basic task for query processing, ie. continuing a 
			* query of a pattern body from a given operation
			*
			* THREAD SAFETY: Sngle threaded, this object is exclusive to its runner object
			*/
			template<typename RootedQuery>
			struct QueryTask {
				
				// Unique Id for the task of a QuerySession
				TaskID id;
				TaskID nextTask;

				// Index of the body to run on
				int bodyIndex;	
				// Index of the operation to be continued
				int operationIndex;
				// The matching frame encoded in a string
				std::string encodedFrameVector;
				// The result collector for the matches
				QueryResultCollector<RootedQuery>* collector;
				
				QueryTask(	TaskID taskID,
							std::string encodedFrameVector,
							int bodyIndex,
							int operationIndex,
							QueryResultCollector<RootedQuery>* collector)
					: bodyIndex(bodyIndex)
					, operationIndex(operationIndex)
					, encodedFrameVector(encodedFrameVector)
					, collector(collector)
					, id(taskID)
					, nextTask(taskID)
				{
					nextTask.addSubID(1);
				}

				~QueryTask()
				{}

				TaskID nextSubtaskID()
				{
					nextTask.step(1);
					return nextTask;
				}

				QueryTask(const QueryTask<RootedQuery> &) = delete;
				QueryTask(QueryTask<RootedQuery> &&) = default;

			};
		}
	}
}



#endif
