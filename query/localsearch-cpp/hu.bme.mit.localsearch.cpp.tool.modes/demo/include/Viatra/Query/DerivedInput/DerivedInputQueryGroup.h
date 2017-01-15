#ifndef VIATRA__QUERY__DERIVED_INPUT__DERIVED_INPUT_QUERY_GROUP_H_
#define VIATRA__QUERY__DERIVED_INPUT__DERIVED_INPUT_QUERY_GROUP_H_

		
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
#include "railRoadModel/Path.h"
#include "railRoadModel/Point.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/RailRoadModel.h"
#include "railRoadModel/Robot.h"
#include "railRoadModel/RobotElement.h"
#include "railRoadModel/RobotModel.h"
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Segment.h"
#include "railRoadModel/Train.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

class DerivedInputQueryGroup{
public:
	static DerivedInputQueryGroup* instance() {
		static DerivedInputQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	DerivedInputQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::railRoadModel::Train::type_id).noSuper()
					.forClass(::railRoadModel::RailRoadElement::type_id).noSuper()
					.forClass(::railRoadModel::Turnout::type_id).setSuper(::railRoadModel::RailRoadElement::type_id)
					.forClass(::railRoadModel::Point::type_id).noSuper()
					.forClass(::railRoadModel::RailRoadModel::type_id).noSuper()
					.forClass(::railRoadModel::Segment::type_id).setSuper(::railRoadModel::RailRoadElement::type_id)
					.forClass(::railRoadModel::Path::type_id).noSuper()
					.forClass(::railRoadModel::RobotPart::type_id).setSuper(::railRoadModel::RobotElement::type_id)
					.forClass(::railRoadModel::RobotElement::type_id).noSuper()
					.forClass(::railRoadModel::Robot::type_id).noSuper()
					.forClass(::railRoadModel::RobotModel::type_id).noSuper()
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

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */

namespace Viatra {
	namespace Query {

    struct ModelRoot
  	{
  		ModelRoot(){}

  		~ModelRoot(){}
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

#endif /*  VIATRA__QUERY__DERIVED_INPUT__DERIVED_INPUT_QUERY_GROUP_H_ */
