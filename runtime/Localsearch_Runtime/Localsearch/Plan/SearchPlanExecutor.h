/*
 * SearchPlanExecutor.h
 *
 *  Created on: Apr 19, 2015
 *      Author: doczir
 */

#ifndef LOCALSEARCH_PLAN_SEARCHPLANEXECUTOR_H_
#define LOCALSEARCH_PLAN_SEARCHPLANEXECUTOR_H_

#include <vector>
#include <cstddef>

#include "../Operations/ISearchOperation.h"
#include "SearchPlan.h"

namespace Localsearch {
namespace Plan {

/**
 * @brief Search plan executor.
 *
 * This executor's job is to execute a search plan.
 *
 * @tparam MatchingFrame The frame the operations will be executed on.
 */
template<typename MatchingFrame>
class SearchPlanExecutor {
public:
    /**
     * Creates a new executor instance.
     *
     * @param plan The search plan to be executed.
     * @param context The search context.
     */
    SearchPlanExecutor(const SearchPlan<MatchingFrame>& plan, const Matcher::ISearchContext& context);

    /**
     * Iterator for iterating over the matches.
     */
    class iterator {
    public:
        /**
         * Creates a new iterator instance.
         */
        iterator();

        /**
         * Creates a new iterator instance.
         * @param exec A pointer to the parent executor.
         * @param isEnd Indicates whether the iterator is at the end, meaning there are no more matches.
         */
        iterator(SearchPlanExecutor* exec, bool isEnd);

        /**
         * Compares two iterators. It only checks if both iterators are of the same executor
         * and if they are both at the end. This means it will only give accurate answer when comparing
         * to the end iterator, otherwise it will return true if the two iterators are of the same executor,
         * no matter where they are pointing to.
         *
         * @param other The iterator to be compared to.
         *
         * @return **True** if both iterator are of the same executor and if their state is the same, **False** otherwise.
         */
        bool operator==(const iterator& other);

        /**
         * Compares two iterators. It only checks if both iterators are of the same executor
         * and if they are both at the end. This means it will only give accurate answer when comparing
         * to the end iterator, otherwise it will return true if the two iterators are of the same executor,
         * no matter where they are pointing to.
         *
         * @param other The iterator to be compared to.
         *
         * @return **True** if both iterator are of the same executor and if their state is the same, **False** otherwise.
         */
        bool operator!=(const iterator& other);

        /**
         * Retrieves the current frame state.
         *
         * @return The current frame.
         */
        const MatchingFrame& operator*();

        /**
         * Advances the iterator to the next match.
         *
         * (this is the pre operator)
         */
        void operator++();

        /**
         * Advances the iterator to the next match.
         *
         * (this is the post operator)
         */
        void operator++(int);
    private:
        SearchPlanExecutor* _exec;

        MatchingFrame _frame;

        bool _atEnd;
        int _nrOfMatches;
    };

    bool execute(MatchingFrame& frame);
    void reset_plan();

    iterator begin();
    iterator& end();

private:
    void init(MatchingFrame& frame);

    const SearchPlan<MatchingFrame>& _plan;
    const std::vector<Operations::ISearchOperation<MatchingFrame>*>& _operations;
    const Matcher::ISearchContext& _context;

    int _currentOperation;
    int _operationCount;

    iterator _endIterator;
};

template<typename MatchingFrame>
inline SearchPlanExecutor<MatchingFrame>::SearchPlanExecutor(const SearchPlan<MatchingFrame>& plan,
        const Matcher::ISearchContext& context) :
        _plan(plan), _operations(_plan.get_operations()), _context(context), _currentOperation(-1), _operationCount(-1), _endIterator(
                iterator(this, true)) {
}

template<typename MatchingFrame>
inline bool SearchPlanExecutor<MatchingFrame>::execute(MatchingFrame& frame) {
    int upperBound = _operations.size() - 1;
    init(frame);
    while (_currentOperation >= 0 && _currentOperation <= upperBound) {
        if (_operations[_currentOperation]->execute(frame, _context)) {
            _currentOperation++;
            if (_currentOperation <= upperBound)
                _operations[_currentOperation]->on_initialize(frame, _context);
        } else {
            _operations[_currentOperation]->on_backtrack(frame, _context);
            _currentOperation--;
        }
    }
    return _currentOperation > upperBound; // if true, match found
}

template<typename MatchingFrame>
inline void SearchPlanExecutor<MatchingFrame>::reset_plan() {
    _currentOperation = -1;
}

template<typename MatchingFrame>
inline typename SearchPlanExecutor<MatchingFrame>::iterator SearchPlanExecutor<MatchingFrame>::begin() {
    return iterator(this, false);
}

template<typename MatchingFrame>
inline typename SearchPlanExecutor<MatchingFrame>::iterator& SearchPlanExecutor<MatchingFrame>::end() {
    return _endIterator;
}

template<typename MatchingFrame>
inline void SearchPlanExecutor<MatchingFrame>::init(MatchingFrame& frame) {
    if (_operationCount == -1) {
        _operationCount = _operations.size();
    }
    if (_currentOperation == -1) {
        _currentOperation++;
        _operations[_currentOperation]->on_initialize(frame, _context);
    } else if (_currentOperation == _operationCount) {
        _currentOperation--;
    } else {
        // TODO: Error handling
    }
}

template<typename MatchingFrame>
inline SearchPlanExecutor<MatchingFrame>::iterator::iterator() :
        _exec(NULL), _atEnd(true), _nrOfMatches(0) {
}

template<typename MatchingFrame>
inline SearchPlanExecutor<MatchingFrame>::iterator::iterator(SearchPlanExecutor* exec, bool isEnd) :
        _exec(exec), _atEnd(isEnd), _nrOfMatches(0) {
    if (!_atEnd) {
        operator++();
    }
}

template<typename MatchingFrame>
inline bool SearchPlanExecutor<MatchingFrame>::iterator::operator ==(const iterator& other) {
    if (_exec != other._exec)
        return false;
    if (_atEnd != other._atEnd && _nrOfMatches != other._nrOfMatches)
        return false;

    return true;
}

template<typename MatchingFrame>
inline bool SearchPlanExecutor<MatchingFrame>::iterator::operator !=(const iterator& other) {
    return !((*this) == other);
}

template<typename MatchingFrame>
inline const MatchingFrame& SearchPlanExecutor<MatchingFrame>::iterator::operator *() {
    return _frame;
}

template<typename MatchingFrame>
inline void SearchPlanExecutor<MatchingFrame>::iterator::operator ++() {
    if (!_atEnd) {
        _atEnd = !_exec->execute(_frame);
        if (!_atEnd) {
            _nrOfMatches++;
        }
    }
}

template<typename MatchingFrame>
inline void SearchPlanExecutor<MatchingFrame>::iterator::operator ++(int) {
    operator++();
}

} /* namespace Plan */
} /* namespace Localsearch */

#endif /* LOCALSEARCH_PLAN_SEARCHPLANEXECUTOR_H_ */