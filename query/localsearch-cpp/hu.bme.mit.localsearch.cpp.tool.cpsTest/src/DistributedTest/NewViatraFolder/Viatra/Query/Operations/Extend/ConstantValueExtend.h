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

 #include <string>
 #include <list>

 #include "ExtendOperation.h"
 #include "../../Util/IsNull.h"

 namespace Viatra {
 namespace Query {
 namespace Operations {
 namespace Extend {

 /**
  * @brief Constant value bounding to frame member.
  *
  * This extend operation bounds an attribute in the frame. This is used when the result or the
  * value is predefined in query pattern.
  *
  * @tparam TrgType The type of the attribute
  * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
  */
  template<class TrgType, class MatchingFrame>
 class ConstantValueExtend: public ExtendOperation<TrgType, std::list<TrgType>, MatchingFrame> {
 	typedef TrgType MatchingFrame::* MemberToBind; /** @typedef The type of the member pointer used to bind a value in a frame */
 public:
     ConstantValueExtend(MemberToBind bindMember, TrgType extendValue);
     void on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context);

 private:
     TrgType _extendValue;
     std::list<TrgType> _objectHolder;
 };

  template<class TrgType, class MatchingFrame>
 inline ConstantValueExtend<TrgType, MatchingFrame>::ConstantValueExtend(MemberToBind bindMember, TrgType extendValue) :
     ExtendOperation<TrgType, std::list<TrgType>, MatchingFrame>(bindMember), _extendValue(extendValue) {
 }

 template<class TrgType, class MatchingFrame>
 inline void ConstantValueExtend<TrgType, MatchingFrame>::on_initialize(MatchingFrame& frame,
         const Matcher::ISearchContext&) {
     _objectHolder.clear();
     _objectHolder.push_back(_extendValue);
     ExtendOperation<TrgType, std::list<TrgType>, MatchingFrame>::set_data(_objectHolder.begin(), _objectHolder.end());
 }
 template<class TrgType, class MatchingFrame>
 inline ConstantValueExtend<TrgType, MatchingFrame>* create_ConstantValueExtend(TrgType MatchingFrame::* bindMember, TrgType extendValue) {
 	return new ConstantValueExtend<TrgType, MatchingFrame>(bindMember, extendValue);
 }
} /* namespace Extend */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
