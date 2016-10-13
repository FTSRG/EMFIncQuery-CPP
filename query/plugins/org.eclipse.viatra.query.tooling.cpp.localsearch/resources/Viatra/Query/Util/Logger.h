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
						Lock lck(mutex);
						auto &identValue = threadIdents()[std::this_thread::get_id()];
						identValue += ident;
					}

					~Identer() {
						Lock lck(mutex);
						auto &identValue = threadIdents()[std::this_thread::get_id()];
						int ns = identValue.length() - strlen(ident);
						if (ns < 0)
						{
							ns = 0;
						}
						identValue.resize(ns);
						Log("<<");
					}
				};

				static std::string& getThreadName(std::thread::id id)
				{
					Lock lck(mutex);

					auto & map = threadNames();
					auto it = map.find(id);

					if (it == map.end())
						return map[id] = concat("Unnamed@", nextUnnamedID++);
					else
						return it->second;
					
				}

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
					std::cout << "<<<";
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
					std::cout << ">>>";
				}
			};
		}
	}
}