
#ifndef _VIATRA_QUERY_UTIL_CONVERT_H_54725_4
#define _VIATRA_QUERY_UTIL_CONVERT_H_54725_4

#include<string>
#include<string.h>

namespace Viatra {
	namespace Query {
		namespace Util {
			struct Convert {

				static inline std::string ToString(int i)
				{
					static constexpr int n = 20;
					std::string ret;
					ret.resize(n);

					return ret.substr(0, snprintf(&ret[0], n-1, "%d", i));
				}

			};
		}
	}
}




#endif
