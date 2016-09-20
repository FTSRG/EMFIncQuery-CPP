#pragma once

template<typename C, typename F>
struct MemberPtrHelper
{
	using type = F C::*;
};


template<typename CLASS, typename... FIELDS>
struct FactoryFunction {};

template<typename CLASS, typename FIELD1, typename... REMFIELDS>
struct FactoryFunction<CLASS, FIELD1, REMFIELDS...>
{
	FIELD1 CLASS::*field1;
	FactoryFunction<CLASS, REMFIELDS...> helperfactory;

	FactoryFunction(FIELD1 CLASS::* field1, typename MemberPtrHelper<CLASS, REMFIELDS>::type... mmbptrs )
		: field1(field1)
		, helperfactory(mmbptrs...)
	{	
	}

	CLASS* operator()(FIELD1 value1, REMFIELDS... values)
	{
		CLASS *ret = helperfactory(values...);
		ret->*field1 = value1;
		return ret;
	}
	
};

template<typename CLASS>
struct FactoryFunction<CLASS>
{
	CLASS* operator()()
	{
		return new CLASS{};
	}
};

template<typename CLASS, typename... FIELDS>
FactoryFunction<CLASS, FIELDS...> CreateBuilderFunction(typename MemberPtrHelper<CLASS, FIELDS>::type... mmbptrs)
{
	return FactoryFunction<CLASS, FIELDS...>(mmbptrs...);
}


