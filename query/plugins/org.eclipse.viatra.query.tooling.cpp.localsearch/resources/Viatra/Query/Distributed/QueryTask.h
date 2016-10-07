
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
			*/
			template<typename RootedQuery>
			struct QueryTask {
				
				// Unique Id for the task of a QuerySession
				TaskID id;

				// Index of the body to run on
				int bodyIndex;	
				// Index of the operation to be continued
				int operationIndex;
				// The matching frame encoded in a string
				std::string EncodedMatchingFrame;
				// The result collector for the matches
				QueryResultCollector<RootedQuery>* collector;

				template<typename MatchingFrame>
				QueryTask(	const MatchingFrame& frame, 
							int bodyIndex, 
							int operationIndex,
							QueryResultCollector<RootedQuery>* collector)
					: bodyIndex(bodyIndex)
					, operationIndex(operationIndex)
					, EncodedMatchingFrame(frame.SerializeAsString())
					, collector(collector)
					, bodyIndex (bodyIndex)
				{}

				QueryTask(	std::string encodedFrame,
							int bodyIndex,
							int operationIndex,
							QueryResultCollector<RootedQuery>* collector)
					: bodyIndex(bodyIndex)
					, operationIndex(operationIndex)
					, EncodedMatchingFrame(encodedFrame)
					, collector(collector)
					, bodyIndex(bodyIndex)
				{}

				QueryTask(QueryTask<RootedQuery> &&) = default;

			};
		}
	}
}



#endif
