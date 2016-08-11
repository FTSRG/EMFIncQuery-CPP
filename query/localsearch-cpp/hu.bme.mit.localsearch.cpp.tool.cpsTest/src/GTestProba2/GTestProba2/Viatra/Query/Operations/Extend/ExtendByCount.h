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

#include "ExtendOperation.h"
#include "../../Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Operations {
namespace Extend {

/**
 * @brief Association navigation for [0, 1] multiplicity.
 *
 * This extend operation navigates to the end of an association from the source already bound in the
 * frame and binds the value found there. This is only usable, iff the multiplicity of the association
 * end is [0, 1], since this check presumes the target is single value.
 *
 * @tparam SrcType The type of the source object.
 * @tparam TrgType The type of the target object.
 * @tparam Member The type the src has to be so the navigation can happen.
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 */
template<class SrcType, class TrgType, class Member, class MatchingFrame>
class NavigateSingleAssociation: public ExtendOperation<TrgType, std::list<TrgType>, MatchingFrame> {
	typedef SrcType MatchingFrame::* SrcGetter; /** @typedef The type of the member pointer for getting the source from the frame. */
	typedef TrgType MatchingFrame::* MemberToBind; /** @typedef The type of the member pointer used to bind a value in a frame */
	typedef TrgType Member::* Navigator; /** @typedef The type of the member pointer for navigating from source to target. */
public:
    NavigateSingleAssociation(SrcGetter getSrc, MemberToBind bindMember, Navigator navigate);
    void on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:
    SrcGetter _getSrc;
    Navigator _navigate;
    std::list<TrgType> _objectHolder;
};


template<class SrcType, class TrgType, class Member, class MatchingFrame>
inline NavigateSingleAssociation<SrcType, TrgType, Member, MatchingFrame>::NavigateSingleAssociation(SrcGetter getSrc, MemberToBind bindMember, Navigator navigate) :
        ExtendOperation<TrgType, std::list<TrgType>, MatchingFrame>(bindMember), _getSrc(getSrc), _navigate(navigate) {
}

template<class SrcType, class TrgType, class Member, class MatchingFrame>
inline void NavigateSingleAssociation<SrcType, TrgType, Member, MatchingFrame>::on_initialize(MatchingFrame& frame,
        const Matcher::ISearchContext&) {
    _objectHolder.clear();
	auto target = static_cast<Member*>(frame.*_getSrc)->*_navigate;
	if(!Util::IsNull<decltype(target)>::check(target))
		_objectHolder.push_back(target);
    ExtendOperation<TrgType, std::list<TrgType>, MatchingFrame>::set_data(_objectHolder.begin(), _objectHolder.end());
}


template<class SrcType, class TrgType, class Member, class MatchingFrame>
inline NavigateSingleAssociation<SrcType, TrgType, Member, MatchingFrame>* create_NavigateSingleAssociation(SrcType MatchingFrame::* getSrc, TrgType MatchingFrame::* bindMember, TrgType Member::* navigate) {
	return new NavigateSingleAssociation<SrcType, TrgType, Member, MatchingFrame>(getSrc, bindMember, navigate);
}


} /* namespace Extend */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
