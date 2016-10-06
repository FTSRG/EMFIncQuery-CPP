
#ifndef _VIATRA_QUERY_UTIL_CONCURRENT_QUEUE_H_
#define _VIATRA_QUERY_UTIL_CONCURRENT_QUEUE_H_

#include <mutex>
#include <condition_variable>
#include <deque>
#include <stdexcept>

namespace Viatra {
	namespace Query {
		namespace Util {

			class ConcurrentQueueTimeout : public std::exception {

				const char * what() const noexcept override
				{
					return "ConcurrentQueue method failed because of timeout";
				}
			};

			template <typename T>
			class ConcurrentQueue
			{
			private:
				std::mutex              d_mutex;
				std::condition_variable d_condition;
				std::deque<T>           d_queue;
			public:
				void push(T const& value) {
					{
						std::unique_lock<std::mutex> lock(this->d_mutex);
						d_queue.push_front(value);
					}
					this->d_condition.notify_one();
				}
				void push(T && value) {
					{
						std::unique_lock<std::mutex> lock(this->d_mutex);
						d_queue.push_front(std::move(value));
					}
					this->d_condition.notify_one();
				}
				T pop() {
					std::unique_lock<std::mutex> lock(this->d_mutex);
					this->d_condition.wait(lock, [=] { return !this->d_queue.empty(); });
					T rc(std::move(this->d_queue.back()));
					this->d_queue.pop_back();
					return rc;
				}

				template<typename duration_t>
				T pop(duration_t timeout) {
					std::unique_lock<std::mutex> lock(this->d_mutex);
					if (this->d_condition.wait_for(
						lock, timeout,
						[=] { return !this->d_queue.empty(); })
					) {
						T rc(std::move(this->d_queue.back()));
						this->d_queue.pop_back();
						return rc;
					}
					else
						throw ConcurrentQueueTimeout{};
				}
			};


		}
	}
}


#endif
