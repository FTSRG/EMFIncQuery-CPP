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
template<class MatchingFrame, class ...T>
class CustomCheck : public CheckOperation<MatchingFrame> {
private:
	// Helper struct, so simple variadic type can be expanded into member pointer list
	template<typename CLASS, typename FIELD> 
	struct ToMemberPointer {
		using type = FIELD CLASS::*;		
	};
	

	std::tuple<typename ToMemberPointer<MatchingFrame, T>...> _memberPointers;
	std::function<bool(T...)> _checkerFunction;
	
	// Helper method for tuple
	template<size_t... index>
	bool invoke_helper(MatchingFrame& frame, std::index_sequence<index...>);

	
public:

	CustomCheck(std::function<bool(T...)> checkerFunction, typename ToMemberPointer<MatchingFrame, T>... memberPointers )
		: _memberPointers(memberPointers...)
		, _checkerFunction(checkerFunction)
	{}

protected:
	bool check(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:

};

template<class MatchingFrame, class ...T>
inline bool CustomCheck<MatchingFrame, T...>::check(MatchingFrame & frame, const Matcher::ISearchContext & context) {
	constexpr auto Size = std::tuple_size<typename std::decay<std::tuple<T...>>::type>::value;
	return invoke_helper(frame, std::make_index_sequence<Size>{});
}

template<class MatchingFrame, class ...T>
CustomCheck<MatchingFrame, T...>* create_CustomCheck( std::function<bool(T...)> checkerFunction, typename ToMemberPointer<MatchingFrame, T>... memberPointers) {
	return new CustomCheck<MatchingFrame, T...>(checkerFunction, memberPointers...);
}

template<class MatchingFrame, class ...T>
template<size_t ...index>
inline bool CustomCheck<MatchingFrame, T...>::invoke_helper(MatchingFrame& frame, std::index_sequence<index...>) {
	return _checkerFunction((frame.*std::get<index>(std::forward<std::tuple<typename ToMemberPointer<MatchingFrame, T>...>>(_memberPointers)))... );

}

}  /* namespace Check */
}  /* namespace Util */
}  /* namespace Query */
}  /* namespace Viatra */
