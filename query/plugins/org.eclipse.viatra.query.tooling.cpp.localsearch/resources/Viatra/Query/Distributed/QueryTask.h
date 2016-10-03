
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYTASK_H__
#define _VIATRA_QUERY_DISTRIBUTED_QUERYTASK_H__

#include"QueryResultCollector.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			template<typename QuerySpecification>
			struct QueryTask {
				// Index of the body to run on
				int bodyIndex;	
				int operationIndex;
				
				std::string EncodedMatchingFrame;
				QueryResultCollector collector;
				/*
				template<typename MatchingFrame>
				QueryTask(	const MatchingFrame &f, 
							int bodyIndex, 
							int operationIndex,
							QueryResultCollector<QuerySpecification> collector)
					: bodyIndex(bodyIndex)
					, operationIndex(operationIndex)
					, EncodedMatchingFrame(frame.SerializeAsString())
					, collector(collector)
					, bodyIndex (bodyIndex)
				{}*/

				QueryTask(QueryTask &&) = default;

			};
		}
	}
}



#endif
