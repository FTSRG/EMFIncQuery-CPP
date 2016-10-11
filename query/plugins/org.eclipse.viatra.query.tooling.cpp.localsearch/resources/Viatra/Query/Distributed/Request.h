
#ifndef _VIATRA_QUERY_DISTRIBUTED_REQUEST__763465457334_
#define _VIATRA_QUERY_DISTRIBUTED_REQUEST__763465457334_

#include<stdint.h>

namespace Network {
	class Connection;
}

namespace Viatra {
	namespace Query {
		namespace Distributed {

			struct Request {
				Network::Connection * connecton;
				int64_t rqid;
			};

		}
	}
}

#endif // _VIATRA_QUERY_DISTRIBUTED_REQUEST__763465457334_
