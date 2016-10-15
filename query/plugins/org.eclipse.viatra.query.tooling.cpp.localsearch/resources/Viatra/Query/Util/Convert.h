
#ifndef _VIATRA_QUERY_UTIL_CONVERT_H_54725_4
#define _VIATRA_QUERY_UTIL_CONVERT_H_54725_4

#include<string>
#include<string.h>
#include"Viatra/Query/Util/Logger.h"

namespace Viatra {
	namespace Query {
		namespace Util {
			struct Convert {

				static inline std::string ToString(int i)
				{
					Util::Logger::Log("inner ToString begin");
					const int n = 100;
					char buffer[n];
					char *ptr = buffer;

					std::string ret(ptr, snprintf(ptr, n-1, "%d", i));
					Util::Logger::Log("inner ToString end");
					return ret;
				}

				static inline std::string ToString(double f, int width = -1, int prec = 3)
				{
					const int n = 100;
					char buffer[n];
					char *ptr = buffer;

					if(width > 0)
						return std::string(ptr, snprintf(ptr, n - 1, "%*.*F", width, prec, f));
					else
						return std::string(ptr, snprintf(ptr, n - 1, "%.*F", prec, f));
				}

				static inline std::string ToString(float f, int width = -1, int prec = 3)
				{
					return ToString((double)f, width, prec);
				}


			};
		}
	}
}




#endif
