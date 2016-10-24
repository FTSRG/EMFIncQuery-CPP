#pragma once


namespace Viatra {
namespace Query {
namespace Operations {
namespace Extend {


	/**
	* @brief Global Instance iteration.
	*
	* This extend operation binds a frame variable to an instance of a specified type.
	*
	* @tparam SrcType The type of the variable to be bound.
	* @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
	*/
	template<class MatchingFrame>
	class GlobalIterateOverInstances : public Check::CheckOperation<MatchingFrame> {

	private:
		int _operationIndex;
		std::map<int, typename MatchingFrame::FrameVector> *_subFrames;

	public:
		/**
		* Creates a new instance of an GlobalIterateOverInstances operation.
		*
		* @param bind The function used to bind the variable in a frame.
		* @param clazz The id of the type to be iterated.
		*/
		GlobalIterateOverInstances(int operationIndex, std::map<int, typename MatchingFrame::FrameVector> *subFrames)
			: _operationIndex(operationIndex)
			, _subFrames(subFrames)
		{}

		virtual bool check(MatchingFrame& frame, const Matcher::ISearchContext& context) override
		{
			if (_subFrames != nullptr)
				(*_subFrames)[_operationIndex].push_back(frame);
			return true;	// querying simply continues locally too
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