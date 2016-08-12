#ifndef CYBERPHYSICALSYSTEM_ENUMHELPER_H___H_
#define CYBERPHYSICALSYSTEM_ENUMHELPER_H___H_

template<typename T>
struct EnumHelper{
	static std::string ToString(T t)
	{
		throw "To String method undefined for type";
	}
};

#include"AppState.h"
template<>
struct EnumHelper< ::cyberPhysicalSystem::AppState> {
	static std::string ToString(::cyberPhysicalSystem::AppState x)
	{
		switch (x)
		{
			case ::cyberPhysicalSystem::AppState::Running: return "Running";
			case ::cyberPhysicalSystem::AppState::Stopped: return "Stopped";
			
			default:
				throw "To String method undefined for enum";
		}
	}
};

#endif /*  CYBERPHYSICALSYSTEM_ENUMHELPER_H___H_ */
