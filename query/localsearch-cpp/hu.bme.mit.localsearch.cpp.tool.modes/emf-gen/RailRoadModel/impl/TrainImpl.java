/**
 */
package RailRoadModel.impl;

import RailRoadModel.Point;
import RailRoadModel.RailRoadElement;
import RailRoadModel.RailRoadModelPackage;
import RailRoadModel.Train;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.MinimalEObjectImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Train</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.impl.TrainImpl#getCurrentlyOn <em>Currently On</em>}</li>
 *   <li>{@link RailRoadModel.impl.TrainImpl#getId <em>Id</em>}</li>
 *   <li>{@link RailRoadModel.impl.TrainImpl#getPreviouslyOn <em>Previously On</em>}</li>
 *   <li>{@link RailRoadModel.impl.TrainImpl#getPoint <em>Point</em>}</li>
 * </ul>
 *
 * @generated
 */
public class TrainImpl extends MinimalEObjectImpl.Container implements Train {
	/**
	 * The cached value of the '{@link #getCurrentlyOn() <em>Currently On</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getCurrentlyOn()
	 * @generated
	 * @ordered
	 */
	protected RailRoadElement currentlyOn;

	/**
	 * The default value of the '{@link #getId() <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getId()
	 * @generated
	 * @ordered
	 */
	protected static final int ID_EDEFAULT = 0;

	/**
	 * The cached value of the '{@link #getId() <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getId()
	 * @generated
	 * @ordered
	 */
	protected int id = ID_EDEFAULT;

	/**
	 * The cached value of the '{@link #getPreviouslyOn() <em>Previously On</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPreviouslyOn()
	 * @generated
	 * @ordered
	 */
	protected RailRoadElement previouslyOn;

	/**
	 * The cached value of the '{@link #getPoint() <em>Point</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPoint()
	 * @generated
	 * @ordered
	 */
	protected Point point;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected TrainImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return RailRoadModelPackage.Literals.TRAIN;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RailRoadElement getCurrentlyOn() {
		if (currentlyOn != null && currentlyOn.eIsProxy()) {
			InternalEObject oldCurrentlyOn = (InternalEObject)currentlyOn;
			currentlyOn = (RailRoadElement)eResolveProxy(oldCurrentlyOn);
			if (currentlyOn != oldCurrentlyOn) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, RailRoadModelPackage.TRAIN__CURRENTLY_ON, oldCurrentlyOn, currentlyOn));
			}
		}
		return currentlyOn;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RailRoadElement basicGetCurrentlyOn() {
		return currentlyOn;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setCurrentlyOn(RailRoadElement newCurrentlyOn) {
		RailRoadElement oldCurrentlyOn = currentlyOn;
		currentlyOn = newCurrentlyOn;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, RailRoadModelPackage.TRAIN__CURRENTLY_ON, oldCurrentlyOn, currentlyOn));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getId() {
		return id;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setId(int newId) {
		int oldId = id;
		id = newId;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, RailRoadModelPackage.TRAIN__ID, oldId, id));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RailRoadElement getPreviouslyOn() {
		if (previouslyOn != null && previouslyOn.eIsProxy()) {
			InternalEObject oldPreviouslyOn = (InternalEObject)previouslyOn;
			previouslyOn = (RailRoadElement)eResolveProxy(oldPreviouslyOn);
			if (previouslyOn != oldPreviouslyOn) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, RailRoadModelPackage.TRAIN__PREVIOUSLY_ON, oldPreviouslyOn, previouslyOn));
			}
		}
		return previouslyOn;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RailRoadElement basicGetPreviouslyOn() {
		return previouslyOn;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPreviouslyOn(RailRoadElement newPreviouslyOn) {
		RailRoadElement oldPreviouslyOn = previouslyOn;
		previouslyOn = newPreviouslyOn;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, RailRoadModelPackage.TRAIN__PREVIOUSLY_ON, oldPreviouslyOn, previouslyOn));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Point getPoint() {
		return point;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetPoint(Point newPoint, NotificationChain msgs) {
		Point oldPoint = point;
		point = newPoint;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, RailRoadModelPackage.TRAIN__POINT, oldPoint, newPoint);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPoint(Point newPoint) {
		if (newPoint != point) {
			NotificationChain msgs = null;
			if (point != null)
				msgs = ((InternalEObject)point).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - RailRoadModelPackage.TRAIN__POINT, null, msgs);
			if (newPoint != null)
				msgs = ((InternalEObject)newPoint).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - RailRoadModelPackage.TRAIN__POINT, null, msgs);
			msgs = basicSetPoint(newPoint, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, RailRoadModelPackage.TRAIN__POINT, newPoint, newPoint));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case RailRoadModelPackage.TRAIN__POINT:
				return basicSetPoint(null, msgs);
		}
		return super.eInverseRemove(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case RailRoadModelPackage.TRAIN__CURRENTLY_ON:
				if (resolve) return getCurrentlyOn();
				return basicGetCurrentlyOn();
			case RailRoadModelPackage.TRAIN__ID:
				return getId();
			case RailRoadModelPackage.TRAIN__PREVIOUSLY_ON:
				if (resolve) return getPreviouslyOn();
				return basicGetPreviouslyOn();
			case RailRoadModelPackage.TRAIN__POINT:
				return getPoint();
		}
		return super.eGet(featureID, resolve, coreType);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void eSet(int featureID, Object newValue) {
		switch (featureID) {
			case RailRoadModelPackage.TRAIN__CURRENTLY_ON:
				setCurrentlyOn((RailRoadElement)newValue);
				return;
			case RailRoadModelPackage.TRAIN__ID:
				setId((Integer)newValue);
				return;
			case RailRoadModelPackage.TRAIN__PREVIOUSLY_ON:
				setPreviouslyOn((RailRoadElement)newValue);
				return;
			case RailRoadModelPackage.TRAIN__POINT:
				setPoint((Point)newValue);
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
			case RailRoadModelPackage.TRAIN__CURRENTLY_ON:
				setCurrentlyOn((RailRoadElement)null);
				return;
			case RailRoadModelPackage.TRAIN__ID:
				setId(ID_EDEFAULT);
				return;
			case RailRoadModelPackage.TRAIN__PREVIOUSLY_ON:
				setPreviouslyOn((RailRoadElement)null);
				return;
			case RailRoadModelPackage.TRAIN__POINT:
				setPoint((Point)null);
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
			case RailRoadModelPackage.TRAIN__CURRENTLY_ON:
				return currentlyOn != null;
			case RailRoadModelPackage.TRAIN__ID:
				return id != ID_EDEFAULT;
			case RailRoadModelPackage.TRAIN__PREVIOUSLY_ON:
				return previouslyOn != null;
			case RailRoadModelPackage.TRAIN__POINT:
				return point != null;
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
		result.append(" (id: ");
		result.append(id);
		result.append(')');
		return result.toString();
	}

} //TrainImpl
