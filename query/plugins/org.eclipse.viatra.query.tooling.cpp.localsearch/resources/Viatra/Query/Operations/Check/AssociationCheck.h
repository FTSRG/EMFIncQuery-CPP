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
 * @brief Association check for [0, 1] multiplicity.
 *
 * Checks whether the two end of the association are those that are defined in the frame.
 * This is only usable, if the multiplicity of the association end is [0, 1], since this check
 * presumes the target is single value.
 *
 * @tparam SrcType The type of the source object.
 * @tparam TrgType The type of the target object.
 * @tparam Member The type the src has to be so the navigation can happen.
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 */
template<class SrcType, class TrgType, class Member, class MatchingFrame>
class SingleAssociationCheck: public CheckOperation<MatchingFrame> {
    typedef SrcType MatchingFrame::* SrcGetter; /** @typedef The type of the member pointer for getting the source from the frame. */
    typedef TrgType MatchingFrame::* TrgGetter; /** @typedef The type of the member pointer for getting the target from the frame. */
    typedef TrgType (Member::*Navigator)() const; /** @typedef The type of the member pointer for navigating from source to target. */
public:
    SingleAssociationCheck(SrcGetter src, TrgGetter trg, Navigator navigate);

protected:
    bool check(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:
    SrcGetter _src;
    TrgGetter _trg;
    Navigator _navigate;
};

/**
 * @brief Association check for [0, *] multiplicity.
 *
 * Checks whether the end of the association from source contains the target specified in the frame.
 * This is only usable iff the multiplicity of the association end is [0, *], since this check
 * presumes the target is a collection of values.
 *
 * @tparam SrcType The type of the source object.
 * @tparam TrgType The type of the target object.
 * @tparam Collection The type of the collection containing the instances of targets.
 * @tparam Member The type the src has to be so the navigation can happen.
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 */
template<class SrcType, class TrgType, class Collection, class Member, class MatchingFrame>
class MultiAssociationCheck: public CheckOperation<MatchingFrame> {
	typedef SrcType MatchingFrame::* SrcGetter; /** @typedef The type of the member pointer for getting the source from the frame. */
	typedef TrgType MatchingFrame::* TrgGetter; /** @typedef The type of the member pointer for getting the target from the frame. */
	typedef const Collection& (Member::*Navigator)() const; /** @typedef The type of the member pointer for navigating from source to target. */
public:
    MultiAssociationCheck(SrcGetter getSrc, TrgGetter getTrg, Navigator navigate);

protected:
    bool check(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:
    SrcGetter _src;
    TrgGetter _trg;
    Navigator _navigate;
};

template<class SrcType, class TrgType, class Member, class MatchingFrame>
inline SingleAssociationCheck<SrcType, TrgType, Member, MatchingFrame>::SingleAssociationCheck(SrcGetter src,
        TrgGetter trg, Navigator navigate) :
        _src(src), _trg(trg), _navigate(navigate) {
}

template<class SrcType, class TrgType, class Member, class MatchingFrame>
inline bool SingleAssociationCheck<SrcType, TrgType, Member, MatchingFrame>::check(MatchingFrame& frame,
        const Matcher::ISearchContext&) {
	if (!(frame.*_src)->present())
		return false;
    SrcType src = frame.*_src;
    TrgType trg = frame.*_trg;
    return trg == ((static_cast<Member*>(src))->*_navigate)();
}

template<class SrcType, class TrgType, class Collection, class Member, class MatchingFrame>
inline MultiAssociationCheck<SrcType, TrgType, Collection, Member, MatchingFrame>::MultiAssociationCheck(SrcGetter getSrc, TrgGetter getTrg, Navigator navigate) :
        _src(getSrc), _trg(getTrg), _navigate(navigate) {
}

template<class SrcType, class TrgType, class Collection, class Member, class MatchingFrame>
inline bool MultiAssociationCheck<SrcType, TrgType, Collection, Member, MatchingFrame>::check(MatchingFrame& frame, const Matcher::ISearchContext&) {
	if (!(frame.*_src)->present())
		return false;
	auto src = frame.*_src;
    auto trg = frame.*_trg;;
    auto data = ((static_cast<Member*>(src))->*_navigate)();
    return std::find(data.begin(), data.end(), trg) != data.end();
}

template<class SrcType, class TrgType, class Member, class MatchingFrame>
inline SingleAssociationCheck<SrcType, TrgType, Member, MatchingFrame>* create_SingleAssociationCheck(SrcType MatchingFrame::* src, TrgType MatchingFrame::* trg, TrgType (Member::*navigator)() const){
	return new SingleAssociationCheck<SrcType, TrgType, Member, MatchingFrame>(src, trg, navigator);
}

template<class SrcType, class TrgType, class Collection, class Member, class MatchingFrame>
inline MultiAssociationCheck<SrcType, TrgType, Collection, Member, MatchingFrame>* create_MultiAssociationCheck(SrcType MatchingFrame::* src, TrgType MatchingFrame::* trg, const Collection& (Member::*navigator)() const){
	return new MultiAssociationCheck<SrcType, TrgType, Collection, Member, MatchingFrame>(src, trg, navigator);
}

} /* namespace Operations */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
