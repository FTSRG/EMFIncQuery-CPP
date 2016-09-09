#ifndef VIATRA__QUERY__DERIVED_FEATURES__DERIVED_FEATURES_QUERY_GROUP_H_
#define VIATRA__QUERY__DERIVED_FEATURES__DERIVED_FEATURES_QUERY_GROUP_H_

		
#include "PlatformModel/Camera.h"
#include "RailRoadModel/Point.h"
#include "RailRoadModel/RailRoadElement.h"
#include "RailRoadModel/RailRoadModel.h"
#include "RailRoadModel/Robot.h"
#include "RailRoadModel/RobotElement.h"
#include "RailRoadModel/RobotModel.h"
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Segment.h"
#include "RailRoadModel/Train.h"
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

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

class DerivedFeaturesQueryGroup{
public:
	static DerivedFeaturesQueryGroup* instance() {
		static DerivedFeaturesQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	DerivedFeaturesQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::RailRoadModel::Train::type_id).noSuper()
					.forClass(::RailRoadModel::RailRoadElement::type_id).noSuper()
					.forClass(::RailRoadModel::Point::type_id).noSuper()
					.forClass(::RailRoadModel::RailRoadModel::type_id).noSuper()
					.forClass(::RailRoadModel::Segment::type_id).setSuper(::RailRoadModel::RailRoadElement::type_id)
					.forClass(::RailRoadModel::RobotElement::type_id).noSuper()
					.forClass(::RailRoadModel::Robot::type_id).setSuper(::RailRoadModel::RobotElement::type_id)
					.forClass(::RailRoadModel::RobotPart::type_id).setSuper(::RailRoadModel::RobotElement::type_id)
					.forClass(::RailRoadModel::RobotModel::type_id).noSuper()
					.forClass(::PlatformModel::Camera::type_id).noSuper()
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

} /* namespace DerivedFeatures */
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

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__DERIVED_FEATURES_QUERY_GROUP_H_ */
