/**
 */
package PlatformModel.impl;

import PlatformModel.Node;
import PlatformModel.PlatformModelPackage;

import RailRoadModel.Segment;
import RailRoadModel.Train;

import java.util.Collection;

import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.MinimalEObjectImpl;

import org.eclipse.emf.ecore.util.EObjectResolvingEList;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Node</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * </p>
 * <ul>
 *   <li>{@link PlatformModel.impl.NodeImpl#getExecutes <em>Executes</em>}</li>
 *   <li>{@link PlatformModel.impl.NodeImpl#getDerivedExecutes <em>Derived Executes</em>}</li>
 *   <li>{@link PlatformModel.impl.NodeImpl#getId <em>Id</em>}</li>
 *   <li>{@link PlatformModel.impl.NodeImpl#getResponsibleFor <em>Responsible For</em>}</li>
 * </ul>
 *
 * @generated
 */
public class NodeImpl extends MinimalEObjectImpl.Container implements Node {
	/**
	 * The cached value of the '{@link #getExecutes() <em>Executes</em>}' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getExecutes()
	 * @generated
	 * @ordered
	 */
	protected EList<Segment> executes;

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
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected NodeImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return PlatformModelPackage.Literals.NODE;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Segment> getExecutes() {
		if (executes == null) {
			executes = new EObjectResolvingEList<Segment>(Segment.class, this, PlatformModelPackage.NODE__EXECUTES);
		}
		return executes;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Train> getDerivedExecutes() {
		// TODO: implement this method to return the 'Derived Executes' reference list
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
			eNotify(new ENotificationImpl(this, Notification.SET, PlatformModelPackage.NODE__ID, oldId, id));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Integer> getResponsibleFor() {
		// TODO: implement this method to return the 'Responsible For' attribute list
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
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case PlatformModelPackage.NODE__EXECUTES:
				return getExecutes();
			case PlatformModelPackage.NODE__DERIVED_EXECUTES:
				return getDerivedExecutes();
			case PlatformModelPackage.NODE__ID:
				return getId();
			case PlatformModelPackage.NODE__RESPONSIBLE_FOR:
				return getResponsibleFor();
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
			case PlatformModelPackage.NODE__EXECUTES:
				getExecutes().clear();
				getExecutes().addAll((Collection<? extends Segment>)newValue);
				return;
			case PlatformModelPackage.NODE__DERIVED_EXECUTES:
				getDerivedExecutes().clear();
				getDerivedExecutes().addAll((Collection<? extends Train>)newValue);
				return;
			case PlatformModelPackage.NODE__ID:
				setId((Integer)newValue);
				return;
			case PlatformModelPackage.NODE__RESPONSIBLE_FOR:
				getResponsibleFor().clear();
				getResponsibleFor().addAll((Collection<? extends Integer>)newValue);
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
			case PlatformModelPackage.NODE__EXECUTES:
				getExecutes().clear();
				return;
			case PlatformModelPackage.NODE__DERIVED_EXECUTES:
				getDerivedExecutes().clear();
				return;
			case PlatformModelPackage.NODE__ID:
				setId(ID_EDEFAULT);
				return;
			case PlatformModelPackage.NODE__RESPONSIBLE_FOR:
				getResponsibleFor().clear();
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
			case PlatformModelPackage.NODE__EXECUTES:
				return executes != null && !executes.isEmpty();
			case PlatformModelPackage.NODE__DERIVED_EXECUTES:
				return !getDerivedExecutes().isEmpty();
			case PlatformModelPackage.NODE__ID:
				return id != ID_EDEFAULT;
			case PlatformModelPackage.NODE__RESPONSIBLE_FOR:
				return !getResponsibleFor().isEmpty();
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

} //NodeImpl
