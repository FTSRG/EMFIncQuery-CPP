#pragma once

#include<sstream>
#include<algorithm>
#include<thread>
#include<map>
#include<functional>
#include<mutex>

namespace Viatra {
	namespace Query {
		namespace Util {

			template<typename T>
			inline static std::string castToStr(T var) {
				std::stringstream ss;
				ss << var;
				return ss.str();
			}

			template<typename... PARAMS>
			inline static std::string concat(PARAMS... params)
			{
				std::string asStr[] = { castToStr(params)... };
				std::string ret = "";
				for (auto & str : asStr)
					ret += str;
				return ret;
			}

			class Logger {

				static std::map<std::thread::id, std::string>& threadNames();
				static std::function<void(const std::string&, const std::string)>& loggerFunc();
				static std::mutex mutex;

				using Lock = std::unique_lock<std::mutex>;
				
			public:
				static void SetThreadName(std::thread& thread, std::string name)
				{
					Lock lck(mutex);
					threadNames()[thread.get_id()] = name;
				}

				static void SetThisThreadName(std::string name)
				{
					Lock lck(mutex);
					threadNames()[std::this_thread::get_id()] = name;
				}

				template<typename FUNC_VOID_STR_STR>
				static void SetLoggerFunction(FUNC_VOID_STR_STR func) {
					Lock lck(mutex);
					loggerFunc = param;
				}


				template<typename... T>
				static void Log(T... args)
				{
					Lock lck(mutex);
					auto threadName = threadNames()[std::this_thread::get_id()];
					loggerFunc()(threadName, concat(args...));
				}
			};
		}
	}
}