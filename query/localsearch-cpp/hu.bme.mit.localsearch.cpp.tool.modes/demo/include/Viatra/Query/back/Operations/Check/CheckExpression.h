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
 * @brief This CheckOperation describes a custom check
 *
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 * @tparam T The arbitrary list of member pointers to access the proper field of the frame (to pass them to the matcher).
*/
template<class MatchingFrame, class FUNCTION,  class ...MP>
class CheckExpression : public CheckOperation<MatchingFrame> {
private:
	

	std::tuple<MP...> _memberPointers;
	FUNCTION _checkerFunction;
	
	// Helper method for tuple
	template<size_t... index>
	bool invoke_helper(MatchingFrame& frame, std::index_sequence<index...>);

	
public:

	CheckExpression(FUNCTION checkerFunction, MP... memberPointers )
		: _memberPointers(memberPointers...)
		, _checkerFunction(checkerFunction)
	{}

protected:
	bool check(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:

};

template<class MatchingFrame, class FUNCTION, class ...MP>
inline bool CheckExpression<MatchingFrame, FUNCTION, MP...>::check(MatchingFrame & frame, const Matcher::ISearchContext & context)
{
	constexpr auto Size = std::tuple_size<typename std::decay<std::tuple<MP...>>::type>::value;
	return invoke_helper(frame, std::make_index_sequence<Size>{});
}

template<class MatchingFrame, class FUNCTION, class ...MP>
CheckExpression<MatchingFrame, FUNCTION, MP...>* create_CheckExpression(
		FUNCTION checkerFunction, MP... memberPointers) 
{
	return new CheckExpression<MatchingFrame, FUNCTION, MP...>(checkerFunction, memberPointers...);
}

template<class MatchingFrame, class FUNCTION, class ...MP>
template<size_t ...index>
inline bool CheckExpression<MatchingFrame, FUNCTION, MP...>::invoke_helper(MatchingFrame& frame, std::index_sequence<index...>) 
{
	return _checkerFunction((frame.*std::get<index>(std::forward<std::tuple<MP...>>(_memberPointers)))... );
}

}  /* namespace Check */
}  /* namespace Util */
}  /* namespace Query */
}  /* namespace Viatra */
