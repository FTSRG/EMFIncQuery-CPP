#pragma once

#include "CheckOperation.h"

#include <algorithm>
#include <string>
#include <list>
#include <type_traits>
#include <utility>

namespace Viatra {
namespace Query {
namespace Operations {
namespace Check {

/**
 * @brief Transitive closure on an association of [0, 1] multiplicity.
 *
 * Checks whether the second variable can be reached from the first via a series of association with the same type.
 * This is only usable, iff the multiplicity of the association end is [0, 1], since this check
 * presumes the target is single value.
 *
 * @tparam Type The type of the source and target object.
 * @tparam Member The type the src has to be so the navigation can happen.
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 */
template<class SrcType, class TrgType, class NavigatingTrgType, class NavigatingMatcher, class NavigatingMatch, class MatchingFrame >
class TransitiveClosureCheck: public CheckOperation<MatchingFrame> {
public:
  typedef SrcType MatchingFrame::* SrcGetter; /** @typedef The type of the member pointer for getting the source from the frame. */
  typedef TrgType MatchingFrame::* TrgGetter; /** @typedef The type of the member pointer for getting the target from the frame. */
  typedef NavigatingTrgType NavigatingMatch::* NavigatingTrgGetter; /** @typedef The type of the member pointer for getting the target from the match. */
  TransitiveClosureCheck(NavigatingMatcher matcherObj, SrcGetter src, TrgGetter trg, NavigatingTrgGetter trgMatch);

protected:
    bool check(MatchingFrame& frame, const Matcher::ISearchContext& context);

private:
    SrcGetter _src;
    TrgGetter _trg;
    NavigatingTrgGetter _trgMatch;
    NavigatingMatcher _matcher;
};


template<class SrcType, class TrgType, class TrgMatchType, class NavigatingMatcher, class MatchingFrame, class NavigatingMatch>
inline TransitiveClosureCheck<SrcType, TrgType, TrgMatchType, NavigatingMatcher, MatchingFrame, NavigatingMatch>::TransitiveClosureCheck(
  NavigatingMatcher matcherObj, SrcGetter src, TrgGetter trg, NavigatingTrgGetter trgMatch)
  : _src(src), _trg(trg), _trgMatch(trgMatch), _matcher(matcherObj) {
}

template<class SrcType, class TrgType, class TrgMatchType, class NavigatingMatcher, class NavigatingMatch, class MatchingFrame>
inline bool TransitiveClosureCheck<SrcType, TrgType, TrgMatchType, NavigatingMatcher, NavigatingMatch, MatchingFrame>::check(MatchingFrame& frame,
        const Matcher::ISearchContext&) {

    SrcType src = frame.*_src;
    TrgType trg = frame.*_trg;

	std::unordered_set<SrcType> sourcesToEvaluate;
  sourcesToEvaluate.insert(src);
	std::unordered_set<SrcType> sourceEvaluated;

	do {
		// Evaluate an element, moving to evaluated set
		auto it = sourcesToEvaluate.begin();
		auto currentValue = *it;
		sourcesToEvaluate.erase(it);
		sourceEvaluated.insert(currentValue);

		// Finding elements that are reachable via the matcher
		auto matches = _matcher.matches(currentValue);
		for( auto & match : matches )
		{
			auto foundTarget = match.*_trgMatch;

			if( trg == foundTarget )
				return true;
			else if( sourceEvaluated.count(foundTarget) == 0 )
				sourcesToEvaluate.insert(foundTarget);
		}

	}	while(!sourcesToEvaluate.empty());
	return false;

	/*	Java implementation of transitive closue;

		Object targetValue = frame.get(targetPosition);
        Set<Object> sourcesToEvaluate = Sets.newLinkedHashSet();
        sourcesToEvaluate.add(frame.get(sourcePosition));
        Set<Object> sourceEvaluated = Sets.newHashSet();

        do {
            Object currentValue = sourcesToEvaluate.iterator().next();
            sourcesToEvaluate.remove(currentValue);
            sourceEvaluated.add(currentValue);
            final MatchingFrame mappedFrame = matcher.editableMatchingFrame();
            mappedFrame.setParameterValues(new Object[]{currentValue, null});
            for (Tuple match : matcher.getAllMatches(mappedFrame)) {
                Object foundTarget = match.get(1);
                if (targetValue.equals(foundTarget)) {
                    return true;
                } else if (!sourceEvaluated.contains(foundTarget)) {
                    sourcesToEvaluate.add(foundTarget);
                }
            }
        } while (!sourcesToEvaluate.isEmpty());
        return false;
	*/

}

// sp.add_operation(create_TransitiveClosureCheck<PconnectedFrame_1>(matcher_1634608591, &PconnectedFrame_1::_2, &PconnectedFrame_1::_3, &LinkedMatch::S2));

template<class SrcType, class TrgType, class NavMatchType, class NavigatingMatcher, class MatchingFrame, class NavigatingMatch>

inline TransitiveClosureCheck<SrcType, TrgType, NavMatchType, NavigatingMatcher, NavigatingMatch, MatchingFrame>*
		create_TransitiveClosureCheck(NavigatingMatcher matcherObj, SrcType MatchingFrame::*src, TrgType MatchingFrame::* trg, NavMatchType NavigatingMatch::*trgMatch){

	return new TransitiveClosureCheck<SrcType, TrgType, NavMatchType, NavigatingMatcher, NavigatingMatch, MatchingFrame>(matcherObj, src, trg, trgMatch);
}

} /* namespace Operations */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
