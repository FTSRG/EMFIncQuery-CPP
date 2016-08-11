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

#include <tuple>

#include "CheckOperation.h"

namespace Viatra {
namespace Query {
namespace Operations {
namespace Check {

/**
 * @brief InstanceOf check.
 *
 * This type of check examines whether an instance is of the specified type.
 *
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 * @tparam RequiredMatcher The matcher for the expression which needs to be counted.
 * @tparam CountResultMp The member pointer type for the count field of the MatchingFrame 
 * @tparam Mp The arbitrary list of member pointers to access the proper field of the frame (to pass them to the matcher).
*/
template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
class CountCheck : public CheckOperation<MatchingFrame> {
public:
	CountCheck(const RequiredMatcher& matcher, CountResultMp countResultMp, Mp... memberPointers);

protected:
	bool check(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:

	template<unsigned int... index>
	bool invoke_helper(MatchingFrame& frame, std::index_sequence<index...>);

	const RequiredMatcher _matcher;
	CountResultMp _countResultMp;
	std::tuple<Mp...> _memberPointers;
};

template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
inline CountCheck<MatchingFrame, RequiredMatcher, class CountResultMp, Mp...>::CountCheck(const RequiredMatcher& matcher, CountResultMp countResultMp, Mp ...memberPointers) :
	_matcher(matcher), _countResultMp(CountResultMp), _memberPointers(memberPointers...)  {
}

template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
inline bool CountCheck<MatchingFrame, RequiredMatcher, class CountResultMp, Mp...>::check(MatchingFrame & frame, const Matcher::ISearchContext & context) {
	constexpr auto Size = std::tuple_size<typename std::decay<std::tuple<Mp...>>::type>::value;
	return invoke_helper(frame, std::make_index_sequence<Size>{});
}

template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
CountCheck<MatchingFrame, RequiredMatcher, class CountResultMp, Mp...>* create_CountCheck(const RequiredMatcher& matcher, Mp... memberPointers) {
	return new CountCheck<MatchingFrame, RequiredMatcher, Mp...>(matcher, memberPointers...);
}

template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
template<unsigned int ...index>
inline bool CountCheck<MatchingFrame, RequiredMatcher, class CountResultMp, Mp...>::invoke_helper(MatchingFrame& frame, std::index_sequence<index...>) {
	auto matches = _matcher.matches((frame.*std::get<index>(std::forward<std::tuple<Mp...>>(_memberPointers)))...);
	return matches.size() == frame.*countResultMp;
}

}  /* namespace Check */
}  /* namespace Util */
}  /* namespace Query */
}  /* namespace Viatra */
