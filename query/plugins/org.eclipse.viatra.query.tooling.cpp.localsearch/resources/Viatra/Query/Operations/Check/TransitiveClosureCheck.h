/*******************************************************************************
 * Copyright (c) 2014-2016 Robert Doczi, IncQuery Labs Ltd.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Robert Doczi - initial API and implementation
 *     Szilagyi Gabor - Implementation
 *     Toth Krisztian David - Implementation
 *******************************************************************************/
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
 * @brief Transitive closure
 *
 * Checks whether the second variable can be reached from the first via a series of association with the same type.
 *
 * @tparam SrcType The type of the source object.
 * @tparam TrgType The type of the target object.
 * @tparam NavigatingTrgType The type of the transitive closure searching's target. In general same as the TrgType, but pointer in Match structure, not in Frame.
 * @tparam NavigatingMatcher The type of the matcher object, which helps find the next associated object.
 * @tparam NavigatingMatch The type of the matcher returned object.
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
inline bool TransitiveClosureCheck<SrcType, TrgType, TrgMatchType, NavigatingMatcher, NavigatingMatch, MatchingFrame>::check(
  MatchingFrame& frame, const Matcher::ISearchContext&) {

  SrcType src = frame.*_src;
  TrgType trg = frame.*_trg;

  std::unordered_set<SrcType> sourcesToEvaluate;
  sourcesToEvaluate.insert(src);
  std::unordered_set<SrcType> sourceEvaluated;

  do {
    // Evaluate an element, moving to evaluated set
    auto it = sourcesToEvaluate.begin();
    auto currentSrc = *it;
    sourcesToEvaluate.erase(it);
    sourceEvaluated.insert(currentSrc);

    // Finding elements that are reachable via the matcher
    auto matches = _matcher.matches(currentSrc);
    for( auto & match : matches ){
      auto foundTarget = match.*_trgMatch;

      if( trg == foundTarget )
        return true;
      else if( sourceEvaluated.count(foundTarget) == 0 )
        sourcesToEvaluate.insert(foundTarget);
    }

  }	while(!sourcesToEvaluate.empty());
  return false;
}

template<class SrcType, class TrgType, class NavMatchType, class NavigatingMatcher, class MatchingFrame, class NavigatingMatch>
inline TransitiveClosureCheck<SrcType, TrgType, NavMatchType, NavigatingMatcher, NavigatingMatch, MatchingFrame>*
  create_TransitiveClosureCheck(NavigatingMatcher matcherObj, SrcType MatchingFrame::*src, TrgType MatchingFrame::* trg, NavMatchType NavigatingMatch::*trgMatch){
	   return new TransitiveClosureCheck<SrcType, TrgType, NavMatchType, NavigatingMatcher, NavigatingMatch, MatchingFrame>(matcherObj, src, trg, trgMatch);
}

} /* namespace Check */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
