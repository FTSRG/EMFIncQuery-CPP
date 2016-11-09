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

	template<typename T>
	class ContainerOfPointers{
		using const_iterator = const T*;		
	};

	/**
	* @brief Constant value bounding to frame member.
	*
	* This extend operation bounds an attribute in the frame. This is used when the result or the
	* value is predefined in query pattern.
	*
	* @tparam TrgType The type of the attribute
	* @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
	*/
	template<class MatchingFrame, class TrgType>
	class SingleValueExtend: public ExtendOperation<TrgType, ContainerOfPointers<TrgType>, MatchingFrame> {
		public:
			typedef TrgType MatchingFrame::* FrameMember; /** @typedef The type of the member pointer used to bind a value in a frame */

			SingleValueExtend(FrameMember targetFrameElement)
				: ExtendOperation<TrgType, SingleValueContainer<TrgType>, MatchingFrame>(targetFrameElement)
			{}

		protected:
			inline void set_data(TrgType value)
			{
				_value = value;
				ExtendOperation<TrgType, ContainerOfPointers<TrgType>::set_data(&_value, &value+1);
			}

		private:
			TrgType _value;
	};


} /* namespace Extend */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
