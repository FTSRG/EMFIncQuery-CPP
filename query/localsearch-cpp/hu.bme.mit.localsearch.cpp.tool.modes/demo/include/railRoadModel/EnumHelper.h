#ifndef RAILROADMODEL_ENUMHELPER_H_
#define RAILROADMODEL_ENUMHELPER_H_

#include<string>

template<typename T>
struct EnumHelper{
	static std::string ToString(T t)
	{
		throw "To String method undefined for type";
	}
};

#include "State.h"
template<>
struct EnumHelper< ::railRoadModel::State> {
	static std::string ToString(::railRoadModel::State x)
	{
		switch (x)
		{
			case ::railRoadModel::State::Operational: return "Operational";
			case ::railRoadModel::State::Frozen: return "Frozen";
			
			default:
				throw "To String method undefined for enum";
		}
	}
};

#endif /*  RAILROADMODEL_ENUMHELPER_H_ */
