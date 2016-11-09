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

#include"SingleValueExtend.h"

namespace Viatra {
namespace Query {
namespace Operations {
namespace Extend {
	
/**
 * @brief This CheckOperation describes a custom check
 *
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 * @tparam T The arbitrary list of member pointers to access the proper field of the frame (to pass them to the matcher).
*/
template<class MatchingFrame, class FUNCTION, class TrgType, class ...MP>
class EvalExpression : public SingleValueExtend<MatchingFrame, TrgType> {
private:
	
	TrgType MatchingFrame::*_targetMember;
	std::tuple<MP...> _memberPointers;
	FUNCTION _evalFunction;
	
	// Helper method for tuple
	template<size_t... index>
	TrgType invoke_helper(MatchingFrame& frame, std::index_sequence<index...>)
	{
		return _evalFunction((frame.*std::get<index>(std::forward<std::tuple<MP...>>(_memberPointers)))... );
	}

public:

	EvalExpression(FUNCTION checkerFunction, TrgType MatchingFrame::*_targetMember, MP... memberPointers )
		: _memberPointers(memberPointers...)
		, _evalFunction(checkerFunction)
	{}

	void on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context) override {
		constexpr auto Size = std::tuple_size<typename std::decay<std::tuple<MP...>>::type>::value;
		set_data(invoke_helper(frame, std::make_index_sequence<Size>{}));
	}

};

template<class MatchingFrame, class FUNCTION, class TrgType, class ...MP>
EvalExpression<MatchingFrame, FUNCTION, TrgType MatchingFrame::*, MP...>* create_EvalExpression(
		FUNCTION evalFunction, TrgType MatchingFrame::* target, MP... memberPointers) 
{
	return new EvalExpression<MatchingFrame, FUNCTION, TrgType, MP...>(evalFunction, memberPointers...);
}

}  /* namespace Extend */
}  /* namespace Util */
}  /* namespace Query */
}  /* namespace Viatra */
