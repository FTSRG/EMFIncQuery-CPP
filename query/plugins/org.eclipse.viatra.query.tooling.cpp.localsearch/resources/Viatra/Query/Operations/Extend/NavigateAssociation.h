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
 template<class SrcType, class MemberTrgType, class NavigatorTrgType, class Member, class MatchingFrame>
 class NavigateSingleAssociation: public ExtendOperation<NavigatorTrgType, std::list<NavigatorTrgType>, MatchingFrame> {
 	typedef SrcType MatchingFrame::* SrcGetter; /** @typedef The type of the member pointer for getting the source from the frame. */
 	typedef MemberTrgType MatchingFrame::* MemberToBind; /** @typedef The type of the member pointer used to bind a value in a frame */
 	typedef NavigatorTrgType (Member::*Navigator)() const; /** @typedef The type of the member pointer for navigating from source to target. */
 public:
 	NavigateSingleAssociation(SrcGetter getSrc, MemberToBind bindMember, Navigator navigate);
 	void on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context);

 private:
 	SrcGetter _getSrc;
 	Navigator _navigate;

 	std::list<TrgType> _objectHolder;
 };


/**
 * @brief Association check for [0, *] multiplicity.
 *
 * This extend operation navigates to the end of an association from the source already bound in the
 * frame and binds the value found there. This is only usable, iff the multiplicity of the association
 * end is [0, *], since this check presumes the target is a collection of values.
 *
 * @tparam SrcType The type of the source object.
 * @tparam TrgType The type of the target object.
 * @tparam Collection The type of the collection containing the instances of targets.
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 */
 template<class SrcType, class MemberTrgType, class Collection, class Member, class MatchingFrame, class NavigatorTrgType=decltype(*std::declval(Collection).begin())>
 class NavigateMultiAssociation: public ExtendOperation<NavigatorTrgType, Collection , MatchingFrame> {
 	typedef SrcType MatchingFrame::* SrcGetter; /** @typedef The type of the member pointer for getting the source from the frame. */
 	typedef MemberTrgType MatchingFrame::* MemberToBind; /** @typedef The type of the member pointer used to bind a value in a frame */
 	typedef const Collection& (Member::*Navigator)() const; /** @typedef The type of the member pointer for navigating from source to target. */
 public:
 	NavigateMultiAssociation(SrcGetter getSrc, MemberToBind bindMember, Navigator navigate);
 	void on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context);

 private:
 	SrcGetter _getSrc;
 	Navigator _navigate;
 };

 template<class SrcType, class MemberTrgType, class NavigatorTrgType, class Member, class MatchingFrame, class NavigatorTrgType>
 inline NavigateSingleAssociation<SrcType, MemberTrgType, NavigatorTrgType, Member, MatchingFrame>::NavigateSingleAssociation(SrcGetter getSrc, MemberToBind bindMember, Navigator navigate ) :
 		ExtendOperation<NavigatorTrgType, std::list<NavigatorTrgType>, MatchingFrame>(bindMember), _getSrc(getSrc), _navigate(navigate) {
 }

template<class SrcType, class MemberTrgType, class NavigatorTrgType, class Member, class MatchingFrame>
inline void NavigateSingleAssociation<SrcType, MemberTrgType, NavigatorTrgType, Member, MatchingFrame>::on_initialize(MatchingFrame& frame,
	const Matcher::ISearchContext&) {
		_objectHolder.clear();
		if ((frame.*_getSrc)->present()) {
			auto target = ((static_cast<Member*>(frame.*_getSrc))->*_navigate)();
			if (!Util::IsNull<decltype(target)>::check(target))
				_objectHolder.push_back(target);
		}
		ExtendOperation<NavigatorTrgType, std::list<NavigatorTrgType>, MatchingFrame>::set_data(_objectHolder.begin(), _objectHolder.end());
}

template<class SrcType, class MemberTrgType, class NavigatorTrgType, class Collection, class Member, class MatchingFrame, class NavigatorTrgType>
inline NavigateMultiAssociation<SrcType, MemberTrgType, NavigatorTrgType, Collection, Member, MatchingFrame, NavigatorTrgType>::NavigateMultiAssociation(SrcGetter getSrc, MemberToBind bindMember, Navigator navigate)
	: ExtendOperation<, Collection, MatchingFrame>(bindMember), _getSrc(getSrc), _navigate(navigate) {
}

template<class SrcType, class MemberTrgType, class Collection, class Member, class MatchingFrame, class NavigatorTrgType>
inline void NavigateMultiAssociation<SrcType, MemberTrgType, Collection, Member, MatchingFrame, NavigatorTrgType>::on_initialize(MatchingFrame& frame, const Matcher::ISearchContext&) {
	if ((frame.*_getSrc)->present())
	{
		auto& data = ((static_cast<Member*>(frame.*_getSrc))->*_navigate)();
		ExtendOperation<NavigatorTrgType, Collection, MatchingFrame>::set_data(std::cbegin(data), std::cend(data));
	}
	else
	{
		ExtendOperation<TrgType, Collection, MatchingFrame>::set_data(Collection::const_iterator{}, Collection::const_iterator{});
	}
	
}


template<class SrcType, class MemberTrgType, class NavigatorTrgType, class Member, class MatchingFrame>
inline NavigateSingleAssociation<SrcType, MemberTrgType, NavigatorTrgType, Member, MatchingFrame>* create_NavigateSingleAssociation(SrcType MatchingFrame::* getSrc, MemberTrgType MatchingFrame::* bindMember, NavigatorTrgType (Member::*navigate)() const) {
	return new NavigateSingleAssociation<SrcType, MemberTrgType, NavigatorTrgType, Member, MatchingFrame>(getSrc, bindMember, navigate);
}

template<class SrcType, class MemberTrgType, class Collection, class Member, class MatchingFrame, class NavigatorTrgType>
inline NavigateMultiAssociation<SrcType, MemberTrgType, Collection, Member, MatchingFrame, NavigatorTrgType>* create_NavigateMultiAssociation(SrcType MatchingFrame::* getSrc, TrgType MatchingFrame::* bindMember, const Collection& (Member::*navigate)() const ) {
	return new NavigateMultiAssociation<SrcType, MemberTrgType, Collection, Member, MatchingFrame, NavigatorTrgType>(getSrc, bindMember, navigate);
}

} /* namespace Extend */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
