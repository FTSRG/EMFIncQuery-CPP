#pragma once

#define BUFFER_SIZE 20

#include<google/protobuf/repeated_field.h>
#include<vector>

namespace Viatra {
	namespace Query {
		namespace Util {

			template<typename T>
			class HierarchicalID : private std::vector<T>
			{
			public:
				using std::vector<T>::begin;
				using std::vector<T>::end;
				using std::vector<T>::empty;

				HierarchicalID() = default;
				HierarchicalID(HierarchicalID&&) = default;
				HierarchicalID(const HierarchicalID&) = default;
				~HierarchicalID() = default;

				HierarchicalID(google::protobuf::RepeatedField<int> pbfield)
					: std::vector<T>(pbfield.begin(), pbfield.end())
				{}


				HierarchicalID<T> parent()const {
					auto ret(*this);
					if (ret.begin() == ret.end())
						throw std::logic_error("Empty Hierarchical ID does not have a parent");
					ret.resize(ret.size() - 1);
					return ret;
				}
				
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
