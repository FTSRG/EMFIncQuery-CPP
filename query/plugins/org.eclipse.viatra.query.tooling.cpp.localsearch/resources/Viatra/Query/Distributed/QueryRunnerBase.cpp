
#include"QueryRunnerDecl.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			QueryRunnerBase::QueryRunnerBase(uint64_t sessionID, int queryID)
				: sessionID(sessionID)
				, queryID(queryID)
			{}
			QueryRunnerBase::~QueryRunnerBase()
			{
				terminate();
				join();
			}

			void QueryRunnerBase::terminate() {
				terminated = true;
			}

			void QueryRunnerBase::join() {
				if (runnerThread)
					runnerThread->join();
				else
					throw std::logic_error("Join called on a non-running QueryRunner!");
			}

		}
	}
}