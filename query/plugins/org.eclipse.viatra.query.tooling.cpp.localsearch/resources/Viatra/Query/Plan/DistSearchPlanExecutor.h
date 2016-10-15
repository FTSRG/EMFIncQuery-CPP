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

#include <vector>
#include <cstddef>

#include "../Operations/ISearchOperation.h"
#include "SearchPlan.h"

namespace Viatra {
	namespace Query {
		namespace Plan {

			template<class MatchingFrame>
			class DistSearchPlanExecutor {
				class PreparedDistSearchPlanExecutor;
			public:
				/**
				* Creates a new executor instance.
				*
				* @param plan The search plan to be executed.
				* @param context The search context.
				*/
				DistSearchPlanExecutor(SearchPlan<MatchingFrame> plan, Matcher::ISearchContext context, int bodyIndex, int startOpIndex);

				/**
				* Iterator for iterating over the matches.
				*/
				class iterator {
				public:

					/**
					* Creates a new iterator instance prepared with an initial frame.
					* @param exec A pointer to the parent executor.
					* @param isEnd Indicates whether the iterator is at the end, meaning there are no more matches.
					* @param frame The initial frame to use.
					*/
					iterator(DistSearchPlanExecutor* exec, bool isEnd, const MatchingFrame& frame = {});

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
					DistSearchPlanExecutor* _exec;

					MatchingFrame _frame;

					bool _atEnd;
					int _nrOfMatches;
				};

				PreparedDistSearchPlanExecutor prepare(const MatchingFrame& frame);

				bool execute(MatchingFrame& frame);
				void reset_plan();

				iterator begin();
				iterator end();
			private:

				class PreparedDistSearchPlanExecutor {
				public:
					PreparedDistSearchPlanExecutor(const DistSearchPlanExecutor& exec, const MatchingFrame& frame);

					bool execute();

					iterator begin();
					iterator end();

				private:
					DistSearchPlanExecutor _exec;
					MatchingFrame _frame;
				};

				void init(MatchingFrame& frame);

				const SearchPlan<MatchingFrame> _plan;
				const Matcher::ISearchContext _context;

				int _startOperationIndex;
				int _bodyIndex;
				int _currentOperation;
				int _operationCount;
			};

			template<class MatchingFrame>
			inline DistSearchPlanExecutor<MatchingFrame>::DistSearchPlanExecutor(SearchPlan<MatchingFrame> plan, Matcher::ISearchContext context, int bodyIndex, int startOpIndex)
				: _plan(plan), _context(context), _startOperationIndex(startOpIndex), _bodyIndex(bodyIndex), _currentOperation(-1), _operationCount(-1) {

			}

			template<class MatchingFrame>
			inline typename DistSearchPlanExecutor<MatchingFrame>::PreparedDistSearchPlanExecutor DistSearchPlanExecutor<MatchingFrame>::prepare(const MatchingFrame & frame)
			{
				return PreparedDistSearchPlanExecutor(*this, frame);
			}

			template<class MatchingFrame>
			inline bool DistSearchPlanExecutor<MatchingFrame>::execute(MatchingFrame& frame) {
				auto& operations = _plan.get_operations();
				int upperBound = operations.size() - 1;
				init(frame);
				while (_currentOperation >= _startOperationIndex && _currentOperation <= upperBound) {
					if (operations[_currentOperation]->execute(frame, _context)) {
						_currentOperation++;
						if (_currentOperation <= upperBound)
							operations[_currentOperation]->on_initialize(frame, _context);
					}
					else {
						operations[_currentOperation]->on_backtrack(frame, _context);
						_currentOperation--;
					}
				}
				return _currentOperation > upperBound; // if true, match found
			}

			template<class MatchingFrame>
			inline void DistSearchPlanExecutor<MatchingFrame>::reset_plan() {
				_currentOperation = _startOperationIndex;
			}

			template<class MatchingFrame>
			inline typename DistSearchPlanExecutor<MatchingFrame>::iterator DistSearchPlanExecutor<MatchingFrame>::begin() {
				return iterator(this, false);
			}

			template<class MatchingFrame>
			inline typename DistSearchPlanExecutor<MatchingFrame>::iterator DistSearchPlanExecutor<MatchingFrame>::end() {
				return iterator(this, true);
			}

			template<class MatchingFrame>
			inline void DistSearchPlanExecutor<MatchingFrame>::init(MatchingFrame& frame) {
				auto& operations = _plan.get_operations();
				if (_operationCount == -1) {
					_operationCount = operations.size();
				}
				if (_currentOperation == -1) {
					_currentOperation = _startOperationIndex;
					operations[_currentOperation]->on_initialize(frame, _context);
				}
				else if (_currentOperation == _operationCount) {
					_currentOperation--;
				}
				else {
					// TODO: Error handling
				}
			}

			template<class MatchingFrame>
			inline DistSearchPlanExecutor<MatchingFrame>::iterator::iterator(DistSearchPlanExecutor * exec, bool isEnd, const MatchingFrame & frame)
				: _exec(exec), _frame(frame), _atEnd(isEnd), _nrOfMatches(0) {
				if (!_atEnd) {
					operator++();
				}
			}

			template<class MatchingFrame>
			inline bool DistSearchPlanExecutor<MatchingFrame>::iterator::operator ==(const iterator& other) {
				if (_exec != other._exec)
					return false;
				if (_atEnd != other._atEnd && _nrOfMatches != other._nrOfMatches)
					return false;

				return true;
			}

			template<class MatchingFrame>
			inline bool DistSearchPlanExecutor<MatchingFrame>::iterator::operator !=(const iterator& other) {
				return !((*this) == other);
			}

			template<class MatchingFrame>
			inline const MatchingFrame& DistSearchPlanExecutor<MatchingFrame>::iterator::operator *() {
				return _frame;
			}

			template<class MatchingFrame>
			inline void DistSearchPlanExecutor<MatchingFrame>::iterator::operator ++() {
				if (!_atEnd) {
					_atEnd = !_exec->execute(_frame);
					if (!_atEnd) {
						_nrOfMatches++;
					}
				}
			}

			template<class MatchingFrame>
			inline void DistSearchPlanExecutor<MatchingFrame>::iterator::operator ++(int) {
				operator++();
			}

			template<class MatchingFrame>
			inline DistSearchPlanExecutor<MatchingFrame>::PreparedDistSearchPlanExecutor::PreparedDistSearchPlanExecutor(const DistSearchPlanExecutor& exec, const MatchingFrame& frame)
				: _exec(exec), _frame(frame) {
			}

			template<class MatchingFrame>
			inline bool DistSearchPlanExecutor<MatchingFrame>::PreparedDistSearchPlanExecutor::execute() {
				return _exec.execute(_frame);
			}

			template<class MatchingFrame>
			inline typename DistSearchPlanExecutor<MatchingFrame>::iterator DistSearchPlanExecutor<MatchingFrame>::PreparedDistSearchPlanExecutor::begin() {
				return iterator(&_exec, false, _frame);
			}

			template<class MatchingFrame>
			inline typename DistSearchPlanExecutor<MatchingFrame>::iterator DistSearchPlanExecutor<MatchingFrame>::PreparedDistSearchPlanExecutor::end() {
				return _exec.end();
			}

		} /* namespace Plan */
	} /* namespace Query */
} /* namespace Viatra */
