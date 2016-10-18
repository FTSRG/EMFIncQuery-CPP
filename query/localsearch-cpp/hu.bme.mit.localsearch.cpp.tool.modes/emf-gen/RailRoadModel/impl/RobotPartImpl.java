/**
 */
package RailRoadModel.impl;

import RailRoadModel.RailRoadModelPackage;
import RailRoadModel.RobotPart;
import RailRoadModel.Segment;
import RailRoadModel.Train;

import java.util.Collection;

import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Robot Part</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.impl.RobotPartImpl#getNearBy <em>Near By</em>}</li>
 *   <li>{@link RailRoadModel.impl.RobotPartImpl#isIsOperational <em>Is Operational</em>}</li>
 *   <li>{@link RailRoadModel.impl.RobotPartImpl#getRefSegment <em>Ref Segment</em>}</li>
 * </ul>
 *
 * @generated
 */
public class RobotPartImpl extends RobotElementImpl implements RobotPart {
	/**
	 * The default value of the '{@link #isIsOperational() <em>Is Operational</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isIsOperational()
	 * @generated
	 * @ordered
	 */
	protected static final boolean IS_OPERATIONAL_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isIsOperational() <em>Is Operational</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isIsOperational()
	 * @generated
	 * @ordered
	 */
	protected boolean isOperational = IS_OPERATIONAL_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected RobotPartImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return RailRoadModelPackage.Literals.ROBOT_PART;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Train> getNearBy() {
		// TODO: implement this method to return the 'Near By' reference list
		// Ensure that you remove @generated or mark it @generated NOT
		// The list is expected to implement org.eclipse.emf.ecore.util.InternalEList and org.eclipse.emf.ecore.EStructuralFeature.Setting
		// so it's likely that an appropriate subclass of org.eclipse.emf.ecore.util.EcoreEList should be used.
		throw new UnsupportedOperationException();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isIsOperational() {
		return isOperational;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setIsOperational(boolean newIsOperational) {
		boolean oldIsOperational = isOperational;
		isOperational = newIsOperational;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, RailRoadModelPackage.ROBOT_PART__IS_OPERATIONAL, oldIsOperational, isOperational));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Segment getRefSegment() {
		Segment refSegment = basicGetRefSegment();
		return refSegment != null && refSegment.eIsProxy() ? (Segment)eResolveProxy((InternalEObject)refSegment) : refSegment;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Segment basicGetRefSegment() {
		// TODO: implement this method to return the 'Ref Segment' reference
		// -> do not perform proxy resolution
		// Ensure that you remove @generated or mark it @generated NOT
		throw new UnsupportedOperationException();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setRefSegment(Segment newRefSegment) {
		// TODO: implement this method to set the 'Ref Segment' reference
		// Ensure that you remove @generated or mark it @generated NOT
		throw new UnsupportedOperationException();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case RailRoadModelPackage.ROBOT_PART__NEAR_BY:
				return getNearBy();
			case RailRoadModelPackage.ROBOT_PART__IS_OPERATIONAL:
				return isIsOperational();
			case RailRoadModelPackage.ROBOT_PART__REF_SEGMENT:
				if (resolve) return getRefSegment();
				return basicGetRefSegment();
		}
		return super.eGet(featureID, resolve, coreType);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void eSet(int featureID, Object newValue) {
		switch (featureID) {
			case RailRoadModelPackage.ROBOT_PART__NEAR_BY:
				getNearBy().clear();
				getNearBy().addAll((Collection<? extends Train>)newValue);
				return;
			case RailRoadModelPackage.ROBOT_PART__IS_OPERATIONAL:
				setIsOperational((Boolean)newValue);
				return;
			case RailRoadModelPackage.ROBOT_PART__REF_SEGMENT:
				setRefSegment((Segment)newValue);
				return;
		}
		super.eSet(featureID, newValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void eUnset(int featureID) {
		switch (featureID) {
			case RailRoadModelPackage.ROBOT_PART__NEAR_BY:
				getNearBy().clear();
				return;
			case RailRoadModelPackage.ROBOT_PART__IS_OPERATIONAL:
				setIsOperational(IS_OPERATIONAL_EDEFAULT);
				return;
			case RailRoadModelPackage.ROBOT_PART__REF_SEGMENT:
				setRefSegment((Segment)null);
				return;
		}
		super.eUnset(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public boolean eIsSet(int featureID) {
		switch (featureID) {
			case RailRoadModelPackage.ROBOT_PART__NEAR_BY:
				return !getNearBy().isEmpty();
			case RailRoadModelPackage.ROBOT_PART__IS_OPERATIONAL:
				return isOperational != IS_OPERATIONAL_EDEFAULT;
			case RailRoadModelPackage.ROBOT_PART__REF_SEGMENT:
				return basicGetRefSegment() != null;
		}
		return super.eIsSet(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String toString() {
		if (eIsProxy()) return super.toString();

		StringBuffer result = new StringBuffer(super.toString());
		result.append(" (isOperational: ");
		result.append(isOperational);
		result.append(')');
		return result.toString();
	}

} //RobotPartImpl
