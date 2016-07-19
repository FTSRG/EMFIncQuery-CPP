#pragma once

#include <list>
#include <iostream>
#include <typeinfo>

namespace Viatra {
namespace Query {

template<class Class, class ModelRoot>
struct ModelIndex {

	static const std::list<Class*>& instances(const ModelRoot* modelroot) {
		//static_assert(false, "Please specialize a model indexer for this type!");
		std::cout << "Model Indexer static assertion" << std::endl;
		std::cout << typeid(modelroot).name() << std::endl;
		std::cout << typeid(Class{}).name() << std::endl;
	}
};

}  /* namespace Query*/
}  /* namespace Viatra*/
