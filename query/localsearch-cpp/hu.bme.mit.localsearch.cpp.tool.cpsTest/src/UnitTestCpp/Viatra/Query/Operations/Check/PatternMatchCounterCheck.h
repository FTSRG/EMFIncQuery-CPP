/*******************************************************************************
 * Copyright (c) 2014-2016 Robert Doczi, IncQuery Labs Ltd.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Robert Doczi - initial API and implementation
 *     Gabor Szilagyi - Additional features implementation
 *     Krisztian Toth - Additional features implementation
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
class PatternMatchCounterCheck : public CheckOperation<MatchingFrame> {
public:
	PatternMatchCounterCheck(const RequiredMatcher& matcher, CountResultMp countResultMp, Mp... memberPointers);

protected:
	bool check(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:

	template<size_t... index>
	bool invoke_helper(MatchingFrame& frame, std::index_sequence<index...>);

	const RequiredMatcher _matcher;
	CountResultMp _countResultMp;
	std::tuple<Mp...> _memberPointers;
};

template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
inline PatternMatchCounterCheck<MatchingFrame, RequiredMatcher, CountResultMp, Mp...>::PatternMatchCounterCheck(const RequiredMatcher& matcher, CountResultMp countResultMp, Mp ...memberPointers) :
	_matcher(matcher), _countResultMp(countResultMp), _memberPointers(memberPointers...)  {
}

template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
inline bool PatternMatchCounterCheck<MatchingFrame, RequiredMatcher, CountResultMp, Mp...>::check(MatchingFrame & frame, const Matcher::ISearchContext & context) {
	constexpr size_t Size = std::tuple_size<typename std::decay<std::tuple<Mp...>>::type>::value;
	return invoke_helper(frame, std::make_index_sequence<Size>{});
}

template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
PatternMatchCounterCheck<MatchingFrame, RequiredMatcher, CountResultMp, Mp...>* create_PatternMatchCounterCheck(const RequiredMatcher& matcher, CountResultMp countResultMp, Mp... memberPointers) {
	return new PatternMatchCounterCheck<MatchingFrame, RequiredMatcher, CountResultMp, Mp...>(matcher, countResultMp, memberPointers...);
}

template<class MatchingFrame, class RequiredMatcher, class CountResultMp, class ...Mp>
template<size_t...index>
inline bool PatternMatchCounterCheck<MatchingFrame, RequiredMatcher, CountResultMp, Mp...>::invoke_helper(MatchingFrame& frame, std::index_sequence<index...>) {
	auto matches = _matcher.matches((frame.*std::get<index>(std::forward<std::tuple<Mp...>>(_memberPointers)))...);
	return matches.size() == frame.*_countResultMp;
}

}  /* namespace Check */
}  /* namespace Util */
}  /* namespace Query */
}  /* namespace Viatra */
