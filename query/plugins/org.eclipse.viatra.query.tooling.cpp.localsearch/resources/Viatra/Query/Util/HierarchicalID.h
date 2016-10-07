#pragma once

#define BUFFER_SIZE 20

#include<vector>

namespace Viatra {
	namespace Query {
		namespace Util {

			template<typename T>
			class HierarchicalID : private std::vector<T>
			{
				using std::vector<T>::begin;
				using std::vector<T>::end;
			};

		}
	}
}

namespace std {

	template<typename T> 
	struct hash<::Viatra::Query::Util::HierarchicalID<T>> 
	{
		std::hash<T> hashT;
		size_t operator()(const ::Viatra::Query::Util::HierarchicalID<T>& hID) const 
		{
			size_t h = 0;
			for (auto && x : hID)
			{
				h *= 31; 
				h += hashT(x);
			}
			return h;
		}
	};

}
