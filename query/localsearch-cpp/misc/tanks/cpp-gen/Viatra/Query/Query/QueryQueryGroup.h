#ifndef VIATRA__QUERY__QUERY__QUERY_QUERY_GROUP_H_
#define VIATRA__QUERY__QUERY__QUERY_QUERY_GROUP_H_

		
#include "Viatra/Query/Matcher/ClassHelper.h"
#include "Viatra/Query/Matcher/ISearchContext.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "ecore/EAnnotation.h"
#include "ecore/EAttribute.h"
#include "ecore/EClass.h"
#include "ecore/EClassifier.h"
#include "ecore/EDataType.h"
#include "ecore/EEnum.h"
#include "ecore/EEnumLiteral.h"
#include "ecore/EFactory.h"
#include "ecore/EGenericType.h"
#include "ecore/EModelElement.h"
#include "ecore/ENamedElement.h"
#include "ecore/EObject.h"
#include "ecore/EOperation.h"
#include "ecore/EPackage.h"
#include "ecore/EParameter.h"
#include "ecore/EReference.h"
#include "ecore/EStringToStringMapEntry.h"
#include "ecore/EStructuralFeature.h"
#include "ecore/ETypeParameter.h"
#include "ecore/ETypedElement.h"
#include "factory/Anyag.h"
#include "factory/Folyekony.h"
#include "factory/Goz.h"
#include "factory/Halmazallapot.h"
#include "factory/Szilard.h"
#include "factory/Tartaly.h"
#include "factory/Viz.h"

namespace Viatra {
namespace Query {
namespace Query {

class QueryQueryGroup{
public:
	static QueryQueryGroup* instance() {
		static QueryQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	QueryQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::factory::Tartaly::type_id).noSuper()
					.forClass(::factory::Anyag::type_id).noSuper()
					.forClass(::factory::Viz::type_id).setSuper(::factory::Anyag::type_id)
					.forClass(::factory::Halmazallapot::type_id).noSuper()
					.forClass(::factory::Folyekony::type_id).setSuper(::factory::Halmazallapot::type_id)
					.forClass(::factory::Goz::type_id).setSuper(::factory::Halmazallapot::type_id)
					.forClass(::factory::Szilard::type_id).setSuper(::factory::Halmazallapot::type_id)
					.forClass(::ecore::EAttribute::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id).setSuper(::ecore::ETypedElement::type_id).setSuper(::ecore::EStructuralFeature::type_id)
					.forClass(::ecore::EAnnotation::type_id).setSuper(::ecore::EModelElement::type_id)
					.forClass(::ecore::EClass::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id).setSuper(::ecore::EClassifier::type_id)
					.forClass(::ecore::EClassifier::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id)
					.forClass(::ecore::EDataType::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id).setSuper(::ecore::EClassifier::type_id)
					.forClass(::ecore::EEnum::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id).setSuper(::ecore::EClassifier::type_id).setSuper(::ecore::EDataType::type_id)
					.forClass(::ecore::EEnumLiteral::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id)
					.forClass(::ecore::EFactory::type_id).setSuper(::ecore::EModelElement::type_id)
					.forClass(::ecore::EModelElement::type_id).noSuper()
					.forClass(::ecore::ENamedElement::type_id).setSuper(::ecore::EModelElement::type_id)
					.forClass(::ecore::EObject::type_id).noSuper()
					.forClass(::ecore::EOperation::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id).setSuper(::ecore::ETypedElement::type_id)
					.forClass(::ecore::EPackage::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id)
					.forClass(::ecore::EParameter::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id).setSuper(::ecore::ETypedElement::type_id)
					.forClass(::ecore::EReference::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id).setSuper(::ecore::ETypedElement::type_id).setSuper(::ecore::EStructuralFeature::type_id)
					.forClass(::ecore::EStructuralFeature::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id).setSuper(::ecore::ETypedElement::type_id)
					.forClass(::ecore::ETypedElement::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id)
					.forClass(::ecore::EStringToStringMapEntry::type_id).noSuper()
					.forClass(::ecore::EGenericType::type_id).noSuper()
					.forClass(::ecore::ETypeParameter::type_id).setSuper(::ecore::EModelElement::type_id).setSuper(::ecore::ENamedElement::type_id)
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace Query */
} /* namespace Query */
} /* namespace Viatra */

namespace Viatra {
	namespace Query {
		
	struct ModelRoot{
		
	};

	template<typename T>
	struct ModelIndex<T, ModelRoot> {
		static const std::list<T*>& instances(const ModelRoot* modelRoot)
		{
			return T::_instances;
		}
	};
	}
}

#endif /*  VIATRA__QUERY__QUERY__QUERY_QUERY_GROUP_H_ */
