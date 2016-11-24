#ifndef VIATRA__QUERY__SAFETYLOGIC__SAFETYLOGIC_QUERY_GROUP_H_
#define VIATRA__QUERY__SAFETYLOGIC__SAFETYLOGIC_QUERY_GROUP_H_

		
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
#include "railRoadModel/Frozen.h"
#include "railRoadModel/Operational.h"
#include "railRoadModel/Path.h"
#include "railRoadModel/Point.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/RailRoadModel.h"
#include "railRoadModel/Robot.h"
#include "railRoadModel/RobotElement.h"
#include "railRoadModel/RobotModel.h"
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Segment.h"
#include "railRoadModel/State.h"
#include "railRoadModel/Train.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

class SafetylogicQueryGroup{
public:
	static SafetylogicQueryGroup* instance() {
		static SafetylogicQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	SafetylogicQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::railRoadModel::ITrain::type_id).noSuper()
					.forClass(::railRoadModel::IRailRoadElement::type_id).noSuper()
					.forClass(::railRoadModel::ITurnout::type_id).setSuper(::railRoadModel::IRailRoadElement::type_id)
					.forClass(::railRoadModel::IPoint::type_id).noSuper()
					.forClass(::railRoadModel::IRailRoadModel::type_id).noSuper()
					.forClass(::railRoadModel::ISegment::type_id).setSuper(::railRoadModel::IRailRoadElement::type_id)
					.forClass(::railRoadModel::IPath::type_id).noSuper()
					.forClass(::railRoadModel::IRobotPart::type_id).setSuper(::railRoadModel::IRobotElement::type_id)
					.forClass(::railRoadModel::IRobotElement::type_id).noSuper()
					.forClass(::railRoadModel::IState::type_id).noSuper()
					.forClass(::railRoadModel::IFrozen::type_id).setSuper(::railRoadModel::IState::type_id)
					.forClass(::railRoadModel::IOperational::type_id).setSuper(::railRoadModel::IState::type_id)
					.forClass(::railRoadModel::IRobot::type_id).noSuper()
					.forClass(::railRoadModel::IRobotModel::type_id).noSuper()
					.forClass(::ecore::IEAttribute::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id).setSuper(::ecore::IETypedElement::type_id).setSuper(::ecore::IEStructuralFeature::type_id)
					.forClass(::ecore::IEAnnotation::type_id).setSuper(::ecore::IEModelElement::type_id)
					.forClass(::ecore::IEClass::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id).setSuper(::ecore::IEClassifier::type_id)
					.forClass(::ecore::IEClassifier::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id)
					.forClass(::ecore::IEDataType::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id).setSuper(::ecore::IEClassifier::type_id)
					.forClass(::ecore::IEEnum::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id).setSuper(::ecore::IEClassifier::type_id).setSuper(::ecore::IEDataType::type_id)
					.forClass(::ecore::IEEnumLiteral::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id)
					.forClass(::ecore::IEFactory::type_id).setSuper(::ecore::IEModelElement::type_id)
					.forClass(::ecore::IEModelElement::type_id).noSuper()
					.forClass(::ecore::IENamedElement::type_id).setSuper(::ecore::IEModelElement::type_id)
					.forClass(::ecore::IEObject::type_id).noSuper()
					.forClass(::ecore::IEOperation::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id).setSuper(::ecore::IETypedElement::type_id)
					.forClass(::ecore::IEPackage::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id)
					.forClass(::ecore::IEParameter::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id).setSuper(::ecore::IETypedElement::type_id)
					.forClass(::ecore::IEReference::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id).setSuper(::ecore::IETypedElement::type_id).setSuper(::ecore::IEStructuralFeature::type_id)
					.forClass(::ecore::IEStructuralFeature::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id).setSuper(::ecore::IETypedElement::type_id)
					.forClass(::ecore::IETypedElement::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id)
					.forClass(::ecore::IEStringToStringMapEntry::type_id).noSuper()
					.forClass(::ecore::IEGenericType::type_id).noSuper()
					.forClass(::ecore::IETypeParameter::type_id).setSuper(::ecore::IEModelElement::type_id).setSuper(::ecore::IENamedElement::type_id)
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__SAFETYLOGIC_QUERY_GROUP_H_ */
