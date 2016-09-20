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

#include "CheckOperation.h"

#include <algorithm>
#include <string>
#include <list>
#include <type_traits>

namespace Viatra {
namespace Query {
namespace Operations {
namespace Check {

/**
 * @brief Inequality check for two variable in a matching frame
 *
 * Checks whether the two variable in the frame are inequal
 *
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 * @tparam T1 The type of the first variable
 * @tparam T2 The type of the second variable
 */
template< class MatchingFrame, class T1, class T2>
class InequalityCheck: public CheckOperation<MatchingFrame> {
private:
	T1 MatchingFrame::*_var1mp;
	T2 MatchingFrame::*_var2mp;
public:
    InequalityCheck(T1 MatchingFrame::*var1mp, T2 MatchingFrame::*var2mp)
		: _var1mp(var1mp), _var2mp(var2mp){}

protected:
  bool check(MatchingFrame& frame, const Matcher::ISearchContext& context){
		return frame.*_var1mp != frame.*_var2mp;
	}

};

template< class MatchingFrame, class T1, class T2>
inline InequalityCheck<MatchingFrame, T1, T2>* create_InequalityCheck(T1 MatchingFrame::*var1mp, T2 MatchingFrame::*var2mp){
	return new InequalityCheck<MatchingFrame, T1, T2>(var1mp, var2mp);
}

} /* namespace Operations */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
