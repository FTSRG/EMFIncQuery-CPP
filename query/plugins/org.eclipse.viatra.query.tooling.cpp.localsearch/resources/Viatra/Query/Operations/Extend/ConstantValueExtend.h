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

 #include "SingleValueExtend.h"
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
 class ConstantValueExtend : public SingleValueExtend<TrgType, MatchingFrame> {
 	typedef TrgType MatchingFrame::* MemberToBind; /** @typedef The type of the member pointer used to bind a value in a frame */
 public:
     ConstantValueExtend(MemberToBind bindMember, TrgType extendValue);
     void on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context) override {
		 set_data(_extendValue);
	 }

 private:
     TrgType _extendValue;
 };

  template<class TrgType, class MatchingFrame>
 inline ConstantValueExtend<TrgType, MatchingFrame>::ConstantValueExtend(MemberToBind bindMember, TrgType extendValue) :
     ExtendOperation<TrgType, std::list<TrgType>, MatchingFrame>(bindMember), _extendValue(extendValue) {
 }

 template<class TrgType, class MatchingFrame>
 inline ConstantValueExtend<TrgType, MatchingFrame>* create_ConstantValueExtend(TrgType MatchingFrame::* bindMember, TrgType extendValue) {
 	return new ConstantValueExtend<TrgType, MatchingFrame>(bindMember, extendValue);
 }
} /* namespace Extend */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
