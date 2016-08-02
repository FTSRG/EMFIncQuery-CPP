/*******************************************************************************
 * Copyright (c) 2014-2016 Robert Doczi, IncQuery Labs Ltd.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Robert Doczi - initial API and implementation
 *******************************************************************************/
#pragma once

#include <string>
#include <list>
#include <tuple>

#include "ExtendOperation.h"

namespace Viatra {
namespace Query {
namespace Operations {
namespace Extend {

/**
 * @brief Extend operation for counting the results of a matcher given the bind variables.
 *
 * This extends operations takes the given variables of a matching frame, give it as a parameter
 * to the required matcher, and binds the result variable to the count of the required matcher'sb_type
 * result set.
 *
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 * @tparam RequiredMatcher The matcher for the expression which needs to be counted.
 * @tparam CountResultT The type of the variable to be bind as count (integral type)
 * @tparam Mp The arbitrary list of member pointers to access the proper field of the frame (to pass them to the matcher).
 */
template<class MatchingFrame, class RequiredMatcher, class CountResultT, class ...Mp>
class PatternMatchCounterExtend : public ExtendOperation<CountResultT, std::list<CountResultT>, MatchingFrame> {
	using CountResultMp = CountResultT MatchingFrame::*;
public:
	
	inline PatternMatchCounterExtend(const RequiredMatcher& matcher, CountResultMp countResultMp, Mp... memberPointers)
	  :	ExtendOperation<CountResultT, std::list<CountResultT>, MatchingFrame>(countResultMp)
	  , _matcher(matcher)
	  , _countResultMp(countResultMp)
	  , _memberPointers(memberPointers...)  
	{
	}

	void on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context);
	
	
	template<size_t... index>
	CountResultT invoke_helper(MatchingFrame& frame, std::index_sequence<index...>);

private:
	const RequiredMatcher _matcher;
	CountResultMp _countResultMp;
	std::tuple<Mp...> _memberPointers;
    std::list<CountResultT> _objectHolder;
};


template<class MatchingFrame, class RequiredMatcher, class CountResultT, class ...Mp>
inline void PatternMatchCounterExtend<MatchingFrame, RequiredMatcher, CountResultT, Mp...>
			::on_initialize(MatchingFrame& frame, const Matcher::ISearchContext&) 
{
    _objectHolder.clear();
	
	constexpr auto VariableCount = std::tuple_size<typename std::decay<std::tuple<Mp...>>::type>::value;
	CountResultT countResult = invoke_helper(frame, std::make_index_sequence<VariableCount>{});
	
	_objectHolder.push_back(countResult);
	
    ExtendOperation<TrgType, std::list<TrgType>, MatchingFrame>::set_data(_objectHolder.begin(), _objectHolder.end());
}

template<class MatchingFrame, class RequiredMatcher, class CountResultT, class ...Mp>
template<size_t ...index>
inline CountResultT PatternMatchCounterExtend<MatchingFrame, RequiredMatcher, CountResultT, Mp...>
		::invoke_helper(MatchingFrame& frame, std::index_sequence<index...>) 
{
	auto matches = _matcher.matches((frame.*std::get<index>(std::forward<std::tuple<Mp...>>(_memberPointers)))...);
	return matches.size();
}


template<class MatchingFrame, class RequiredMatcher, class CountResultT, class ...Mp>
PatternMatchCounterExtend<MatchingFrame, RequiredMatcher, CountResultT, Mp...>* 
	create_PatternMatchCounterExtend(
		const RequiredMatcher& matcher, 
		CountResultT MatchingFrame::*countResultMp,
		Mp... memberPointers) 
{
	return new PatternMatchCounterExtend<MatchingFrame, RequiredMatcher, CountResultT, Mp...>(matcher, countResultMp, memberPointers...);
}


} /* namespace Extend */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
