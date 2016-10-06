
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYTASK_H__
#define _VIATRA_QUERY_DISTRIBUTED_QUERYTASK_H__

#include"QueryResultCollector.h"
#include"../Util/HierarchicalID.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			template<typename Query>
			struct QueryTask {
				
				// Unique Id for the task inside a QuerySession
				Util::HierarchicalID<int> id;

				// Index of the body to run on
				int bodyIndex;	
				int operationIndex;
				
				std::string EncodedMatchingFrame;
				QueryResultCollector collector;

				template<typename MatchingFrame>
				QueryTask(	const MatchingFrame& frame, 
							int bodyIndex, 
							int operationIndex,
							QueryResultCollector collector)
					: bodyIndex(bodyIndex)
					, operationIndex(operationIndex)
					, EncodedMatchingFrame(frame.SerializeAsString())
					, collector(collector)
					, bodyIndex (bodyIndex)
				{}

				QueryTask(QueryTask<Query> &&) = default;

			};
		}
	}
}



#endif
