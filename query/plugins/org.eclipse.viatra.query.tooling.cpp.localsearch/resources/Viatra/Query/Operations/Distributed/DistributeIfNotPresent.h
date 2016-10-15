#pragma once

#include"../Check/CheckOperation.h"

namespace Viatra {
namespace Query {
namespace Operations {
namespace Extend {


	/**
	* @brief Distribute to nodes id a frame field is not present on the local node
	*
	* @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
	*/
	template<class MatchingFrame, class Type>
	class DistributeIfNotPresent : public Check::CheckOperation<MatchingFrame> {
		typedef Type MatchingFrame::* Getter; /** @typedef The type of the member pointer for getting the source from the frame. */

	private:
		int _operationIndex;
		std::map<int, typename MatchingFrame::FrameVector> *_subFrames;
		Getter _getter;

	public:
		/**
		* Creates a new instance of an GlobalIterateOverInstances operation.
		*
		* @param bind The function used to bind the variable in a frame.
		* @param clazz The id of the type to be iterated.
		*/
		GlobalIterateOverInstances(int operationIndex, std::map<int, typename MatchingFrame::FrameVector> *subFrames, Getter getter)
			: _operationIndex(operationIndex)
			, _subFrames(subFrames)
			, _getter(getter)
		{}

		virtual bool check(MatchingFrame& frame, const Matcher::ISearchContext& context) override
		{
			if (frame.*_getter.present())
			{
				return true;	// Simply continue
			}
			else
			{
				if (_subFrames != nullptr)
					(*_subFrames)[_operationIndex].push_back(frame);
				return false;	// Stop querying locally, we can only continue it remotely
			}
		}

	};

	template<typename MatchingFrame>
	GlobalIterateOverInstances<MatchingFrame>* create_GlobalIterateOverInstances(int _operationIndex, std::map<int, typename MatchingFrame::FrameVector> *_subFrames)
	{
		return new GlobalIterateOverInstances<MatchingFrame>(_operationIndex, _subFrames);
	}



}
}
}
}