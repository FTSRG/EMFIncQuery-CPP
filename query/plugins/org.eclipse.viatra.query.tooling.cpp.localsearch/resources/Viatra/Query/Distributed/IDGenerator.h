#pragma once

#include<stdint.h>
#include<mutex>

namespace Viatra {
	namespace Query {
		namespace Distributed {
			
			class IDGenerator {
			private:

				int64_t increment, nextID;
				std::mutex id_mutex;
			public:
				IDGenerator(int64_t firstID, int64_t increment)
				{
					nextID = firstID;
				}

				int64_t generate()
				{
					std::unique_lock<std::mutex> lock(id_mutex);
					auto id = nextID;
					nextID += increment;
					return id;
				}
			};
		}
	}
}