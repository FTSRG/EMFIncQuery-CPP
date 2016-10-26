#pragma once

#include<sstream>
#include<algorithm>
#include<thread>
#include<map>
#include<iostream>
#include<functional>
#include<mutex>
#include<string.h>

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

				static constexpr auto ident = "    ";

				static std::map<std::thread::id, std::string>& threadNames();
				static std::map<std::thread::id, std::string>& threadIdents();
				static std::function<void(const std::string&, const std::string)>& loggerFunc();

				static int nextUnnamedID;
				
				static std::recursive_mutex mutex;
				using Lock = std::unique_lock<std::recursive_mutex>;
				
			public:

				struct Identer {
					Identer() {
#ifndef NO_LOG
						Lock lck(mutex);
						auto &identValue = threadIdents()[std::this_thread::get_id()];
						identValue += ident;
#endif
					}

					~Identer() {
#ifndef NO_LOG
						Lock lck(mutex);
						auto &identValue = threadIdents()[std::this_thread::get_id()];
						int ns = identValue.length() - strlen(ident);
						if (ns < 0)
						{
							ns = 0;
						}
						identValue.resize(ns);
						Log("<<");
#endif
					}
				};

				static std::string& getThreadName(std::thread::id id)
				{
#ifndef NO_LOG
					Lock lck(mutex);

					auto & map = threadNames();
					auto it = map.find(id);

					if (it == map.end())
						return map[id] = concat("Unnamed@", nextUnnamedID++);
					else
						return it->second;
#endif
				}

				static void SetThreadName(std::thread& thread, std::string name)
				{
#ifndef NO_LOG
					Lock lck(mutex);
					threadNames()[thread.get_id()] = name;
#endif
				}

				static void SetThisThreadName(std::string name)
				{
#ifndef NO_LOG
					Lock lck(mutex);
					threadNames()[std::this_thread::get_id()] = name;
#endif
				}

				template<typename FUNC_VOID_STR_STR>
				static void SetLoggerFunction(FUNC_VOID_STR_STR func) {
#ifndef NO_LOG
					Lock lck(mutex);
					loggerFunc = param;
#endif
				}


				template<typename... T>
				static void Log(T... args)
				{
#ifndef NO_LOG
					Lock lck(mutex);
					auto threadName = threadNames()[std::this_thread::get_id()];
					try {
						loggerFunc()(
							threadName, 
							concat(threadIdents()[std::this_thread::get_id()], args...)
						);
					}
					catch (...)
					{
						std::cout << concat("LOGGER FUNCTION ERROR(", threadName, ") --- ", args...)  << std::endl;
						throw;
					}
#endif
				}

				template<typename TIME>
				static void ThreadTest(TIME time)
				{
#ifndef NO_LOG
					Log("-------------- THREAD TEST --------------");
					std::this_thread::sleep_for(time);
					Log("------------ THREAD TEST END ------------");
#endif
				}


			};
		}
	}
}