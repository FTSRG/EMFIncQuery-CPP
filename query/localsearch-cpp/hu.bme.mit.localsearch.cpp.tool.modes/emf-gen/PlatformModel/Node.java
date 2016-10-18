/**
 */
package PlatformModel;

import RailRoadModel.Segment;
import RailRoadModel.Train;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Node</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link PlatformModel.Node#getExecutes <em>Executes</em>}</li>
 *   <li>{@link PlatformModel.Node#getDerivedExecutes <em>Derived Executes</em>}</li>
 *   <li>{@link PlatformModel.Node#getId <em>Id</em>}</li>
 *   <li>{@link PlatformModel.Node#getResponsibleFor <em>Responsible For</em>}</li>
 * </ul>
 *
 * @see PlatformModel.PlatformModelPackage#getNode()
 * @model
 * @generated
 */
public interface Node extends EObject {
	/**
	 * Returns the value of the '<em><b>Executes</b></em>' reference list.
	 * The list contents are of type {@link RailRoadModel.Segment}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Executes</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Executes</em>' reference list.
	 * @see PlatformModel.PlatformModelPackage#getNode_Executes()
	 * @model
	 * @generated
	 */
	EList<Segment> getExecutes();

	/**
	 * Returns the value of the '<em><b>Derived Executes</b></em>' reference list.
	 * The list contents are of type {@link RailRoadModel.Train}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Derived Executes</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Derived Executes</em>' reference list.
	 * @see PlatformModel.PlatformModelPackage#getNode_DerivedExecutes()
	 * @model transient="true" volatile="true" derived="true"
	 * @generated
	 */
	EList<Train> getDerivedExecutes();

	/**
	 * Returns the value of the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Id</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Id</em>' attribute.
	 * @see #setId(int)
	 * @see PlatformModel.PlatformModelPackage#getNode_Id()
	 * @model required="true"
	 * @generated
	 */
	int getId();

	/**
	 * Sets the value of the '{@link PlatformModel.Node#getId <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Id</em>' attribute.
	 * @see #getId()
	 * @generated
	 */
	void setId(int value);

	/**
	 * Returns the value of the '<em><b>Responsible For</b></em>' attribute list.
	 * The list contents are of type {@link java.lang.Integer}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Responsible For</em>' attribute list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Responsible For</em>' attribute list.
	 * @see PlatformModel.PlatformModelPackage#getNode_ResponsibleFor()
	 * @model transient="true" volatile="true" derived="true"
	 * @generated
	 */
	EList<Integer> getResponsibleFor();

} // Node
