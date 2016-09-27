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
 * @brief Constant value equality checking with a frame member.
 *
 * Checks whether the frame member's value is the specified. This is used when the result calculated and the
 * expected value is predefined in query pattern.
 *
 * @tparam TrgType The type of the attribute
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 */
template<class TrgType, class MatchingFrame>
class ConstantValueCheck: public CheckOperation<MatchingFrame> {
    typedef TrgType MatchingFrame::* TrgGetter; /** @typedef The type of the member pointer for getting the target from the frame. */
public:
    ConstantValueCheck(TrgGetter trg, TrgType checkValue);

protected:
    bool check(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:
    TrgType _checkValue;
    TrgGetter _trg;
};

template<class TrgType, class MatchingFrame>
inline ConstantValueCheck<TrgType, MatchingFrame>::ConstantValueCheck(TrgGetter trg, TrgType checkValue) :
        _checkValue(checkValue), _trg(trg) {
}

template<class TrgType, class MatchingFrame>
inline bool ConstantValueCheck<TrgType, MatchingFrame>::check(MatchingFrame& frame,
        const Matcher::ISearchContext&) {
    TrgType trg = frame.*_trg;
    return trg == _checkValue;
}
template<class TrgType, class MatchingFrame>
inline ConstantValueCheck<TrgType, MatchingFrame>* create_ConstantValueCheck(TrgType MatchingFrame::* trg, TrgType checkValue){
	return new ConstantValueCheck<TrgType, MatchingFrame>(trg, checkValue);
}
} /* namespace Operations */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
