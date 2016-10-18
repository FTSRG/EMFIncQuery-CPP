/**
 */
package RailRoadModel.impl;

import RailRoadModel.RailRoadModelPackage;
import RailRoadModel.Robot;
import RailRoadModel.RobotModel;
import RailRoadModel.RobotPart;

import java.util.Collection;

import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.MinimalEObjectImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentEList;
import org.eclipse.emf.ecore.util.InternalEList;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Robot Model</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.impl.RobotModelImpl#getRobots <em>Robots</em>}</li>
 *   <li>{@link RailRoadModel.impl.RobotModelImpl#getRobotparts <em>Robotparts</em>}</li>
 * </ul>
 *
 * @generated
 */
public class RobotModelImpl extends MinimalEObjectImpl.Container implements RobotModel {
	/**
	 * The cached value of the '{@link #getRobots() <em>Robots</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRobots()
	 * @generated
	 * @ordered
	 */
	protected EList<Robot> robots;

	/**
	 * The cached value of the '{@link #getRobotparts() <em>Robotparts</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRobotparts()
	 * @generated
	 * @ordered
	 */
	protected EList<RobotPart> robotparts;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected RobotModelImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return RailRoadModelPackage.Literals.ROBOT_MODEL;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Robot> getRobots() {
		if (robots == null) {
			robots = new EObjectContainmentEList<Robot>(Robot.class, this, RailRoadModelPackage.ROBOT_MODEL__ROBOTS);
		}
		return robots;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<RobotPart> getRobotparts() {
		if (robotparts == null) {
			robotparts = new EObjectContainmentEList<RobotPart>(RobotPart.class, this, RailRoadModelPackage.ROBOT_MODEL__ROBOTPARTS);
		}
		return robotparts;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTS:
				return ((InternalEList<?>)getRobots()).basicRemove(otherEnd, msgs);
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTPARTS:
				return ((InternalEList<?>)getRobotparts()).basicRemove(otherEnd, msgs);
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
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTS:
				return getRobots();
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTPARTS:
				return getRobotparts();
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
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTS:
				getRobots().clear();
				getRobots().addAll((Collection<? extends Robot>)newValue);
				return;
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTPARTS:
				getRobotparts().clear();
				getRobotparts().addAll((Collection<? extends RobotPart>)newValue);
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
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTS:
				getRobots().clear();
				return;
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTPARTS:
				getRobotparts().clear();
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
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTS:
				return robots != null && !robots.isEmpty();
			case RailRoadModelPackage.ROBOT_MODEL__ROBOTPARTS:
				return robotparts != null && !robotparts.isEmpty();
		}
		return super.eIsSet(featureID);
	}

} //RobotModelImpl
