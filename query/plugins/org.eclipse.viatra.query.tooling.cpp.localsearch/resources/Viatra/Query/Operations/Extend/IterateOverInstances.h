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

#include "../../Util/Defs.h"
#include "ExtendOperation.h"

#include <list>
#include <type_traits>

namespace Viatra {
namespace Query {
namespace Operations {
namespace Extend {

/**
 * @brief Local Instance iteration.
 *
 * This extend operation binds a frame variable to an instance of a specified type.
 *
 * @tparam SrcType The type of the variable to be bound.
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 */
template<class SrcType, class MatchingFrame, class ModelRoot>
class LocalIterateOverInstances: public ExtendOperation<SrcType, std::list<SrcType>, MatchingFrame> {
    typedef SrcType MatchingFrame::* BindPoint;
public:
    /**
     * Creates a new instance of an LocalIterateOverInstances operation.
     *
     * @param bind The function used to bind the variable in a frame.
     * @param clazz The id of the type to be iterated.
     */
    LocalIterateOverInstances(BindPoint bind, EClass clazz, const ModelRoot* model);
    void on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context);
private:
    EClass _clazz;
	const ModelRoot* _model;

};

template<class SrcType, class MatchingFrame, class ModelRoot>
inline LocalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>::LocalIterateOverInstances(BindPoint bind, EClass clazz, const ModelRoot* model)
	: ExtendOperation<SrcType, std::list<SrcType>, MatchingFrame>(bind), _clazz(clazz), _model(model) {
}

template<class SrcType, class MatchingFrame, class ModelRoot>
inline void LocalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>::on_initialize(MatchingFrame&, const Matcher::ISearchContext&) {
	auto& data = ModelIndex<typename std::remove_pointer<SrcType>::type, ModelRoot>::instances(_model);
	ExtendOperation<SrcType, std::list<SrcType>, MatchingFrame>::set_data(std::cbegin(data), std::cend(data));
}

template<class SrcType, class MatchingFrame, class ModelRoot>
inline LocalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>* create_LocalIterateOverInstances(SrcType MatchingFrame::* bind, EClass clazz, const ModelRoot* model) {
	return new LocalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>(bind, clazz, model);
}

/**
 * @brief Global Instance iteration.
 *
 * This extend operation binds a frame variable to an instance of a specified type.
 *
 * @tparam SrcType The type of the variable to be bound.
 * @tparam MatchingFrame Describes the structure of the *MatchingFrame* the operation is executed on.
 */
template<class SrcType, class MatchingFrame, class ModelRoot>
class GlobalIterateOverInstances: public ExtendOperation<SrcType, std::list<SrcType>, MatchingFrame> {
    typedef SrcType MatchingFrame::* BindPoint;
public:
    /**
     * Creates a new instance of an GlobalIterateOverInstances operation.
     *
     * @param bind The function used to bind the variable in a frame.
     * @param clazz The id of the type to be iterated.
     */
    GlobalIterateOverInstances(BindPoint bind, EClass clazz, const ModelRoot* model);
    void on_initialize(MatchingFrame&, const Matcher::ISearchContext& ) override;
    void on_backtrack(MatchingFrame&, const Matcher::ISearchContext& ) override;

    bool execute(MatchingFrame&, const Matcher::ISearchContext&) override;
private:
    bool _executed;
    EClass _clazz;
  	const ModelRoot* _model;
};

template<class SrcType, class MatchingFrame, class ModelRoot>
inline GlobalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>::GlobalIterateOverInstances(BindPoint bind, EClass clazz, const ModelRoot* model)
	: ExtendOperation<SrcType, std::list<SrcType>, MatchingFrame>(bind), _executed(false), _clazz(clazz), _model(model) {
}

template<class SrcType, class MatchingFrame, class ModelRoot>
inline void GlobalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>::on_initialize(MatchingFrame& frame, const Matcher::ISearchContext& context) {
  return;
}

template<class SrcType, class MatchingFrame, class ModelRoot>
inline void GlobalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>::on_backtrack(MatchingFrame& frame, const Matcher::ISearchContext& context) {
  _executed = false;
  return;
}

template<class SrcType, class MatchingFrame, class ModelRoot>
inline bool GlobalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>::execute(MatchingFrame& frame, const Matcher::ISearchContext& context) {
  if(_executed) return false;
  _executed = true;
  return _executed;
}

template<class SrcType, class MatchingFrame, class ModelRoot>
inline GlobalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>* create_GlobalIterateOverInstances(SrcType MatchingFrame::* bind, EClass clazz, const ModelRoot* model) {
	return new GlobalIterateOverInstances<SrcType, MatchingFrame, ModelRoot>(bind, clazz, model);
}

} /* namespace Extend */
} /* namespace Operations */
} /* namespace Query */
} /* namespace Viatra */
