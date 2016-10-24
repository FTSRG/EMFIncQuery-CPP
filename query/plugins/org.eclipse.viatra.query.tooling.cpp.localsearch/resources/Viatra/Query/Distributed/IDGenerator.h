#pragma once

#include<stdint.h>
#include<mutex>

namespace Viatra {
	namespace Query {
		namespace Distributed {
			
			// Threadsafe object to generate id by a given increment from a given start id
			class IDGenerator {
			private:

				int64_t increment, nextID;
				std::mutex id_mutex;
			public:
				IDGenerator(int64_t firstID = 0, int64_t increment = 1)
					: nextID(firstID)
					, increment(increment)
				{
					nextID = firstID;
				}

				void reconfigurate(int64_t firstID, int64_t increment)
				{
					std::unique_lock<std::mutex> lock(id_mutex);
					this->nextID = firstID;
					this->increment = increment;
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