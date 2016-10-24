#ifndef _VIATRA_QUERY_DISTRIBUTED_TASKID_5475634658_
#define _VIATRA_QUERY_DISTRIBUTED_TASKID_5475634658_

#include"../Util/HierarchicalID.h"
#include<ostream>
#include<algorithm>

namespace Viatra {
	namespace Query {
		namespace Distributed {
			using TaskID = Util::HierarchicalID<int>;
		}
	}
}


inline std::ostream& operator<<(std::ostream& os, const Viatra::Query::Distributed::TaskID& taskID)
{
	if (taskID.empty())
	{
		return os << "TaskID.empty";
	}

	auto it = taskID.begin();
	os << *it;
	++it;

	for (; it != taskID.end(); ++it)
		os << "." << *it;
	return os;
}

#endif _VIATRA_QUERY_DISTRIBUTED_TASKID_5475634658_
