#pragma once

#define BUFFER_SIZE 20

#include<google/protobuf/repeated_field.h>
#include<vector>

namespace Viatra {
	namespace Query {
		namespace Util {

			template<typename T>
			class HierarchicalID
			{
				std::vector<T> vec;

			private:
				template<typename Iterator>
				HierarchicalID(Iterator begin, Iterator end)
					: vec(begin, end)
				{}

			public:
				// comparator for map
				struct compare {
					bool operator()(const HierarchicalID& a, const HierarchicalID& b) const
					{
						if (a.size() != b.size())
							return a.size() < b.size();

						for (size_t i = 0; i < a.size(); ++i)
						{
							if (a.vec[i] !=b.vec[i])
								return a.vec[i] < b.vec[i];
						}
						return false;
					}
				};

				auto begin()const { return vec.begin();	}
				auto end() const { return vec.end(); }
				auto empty() const { return vec.empty(); }
				auto size() const { return vec.size(); }
								
				HierarchicalID() = default;
				HierarchicalID(HierarchicalID&&) = default;
				HierarchicalID(const HierarchicalID&) = default;
				~HierarchicalID() = default;


				HierarchicalID<T>& operator=(const HierarchicalID&) = default;
				HierarchicalID<T>& operator=(HierarchicalID&&) = default;

				bool operator==(const HierarchicalID& other) const { return vec == other.vec; }

				HierarchicalID(google::protobuf::RepeatedField<int> pbfield)
					: HierarchicalID(pbfield.begin(), pbfield.end())
				{}


				HierarchicalID<T> parent()const {

					if (vec.begin() == vec.end())
						throw std::logic_error("Empty Hierarchical ID does not have a parent");
					
					return HierarchicalID<T>(vec.begin(), vec.end()-1);
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
