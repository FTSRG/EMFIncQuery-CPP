/**
 */
package RailRoadModel;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Train</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.Train#getCurrentlyOn <em>Currently On</em>}</li>
 *   <li>{@link RailRoadModel.Train#getId <em>Id</em>}</li>
 *   <li>{@link RailRoadModel.Train#getPreviouslyOn <em>Previously On</em>}</li>
 *   <li>{@link RailRoadModel.Train#getPoint <em>Point</em>}</li>
 * </ul>
 *
 * @see RailRoadModel.RailRoadModelPackage#getTrain()
 * @model
 * @generated
 */
public interface Train extends EObject {
	/**
	 * Returns the value of the '<em><b>Currently On</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Currently On</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Currently On</em>' reference.
	 * @see #setCurrentlyOn(RailRoadElement)
	 * @see RailRoadModel.RailRoadModelPackage#getTrain_CurrentlyOn()
	 * @model required="true"
	 * @generated
	 */
	RailRoadElement getCurrentlyOn();

	/**
	 * Sets the value of the '{@link RailRoadModel.Train#getCurrentlyOn <em>Currently On</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Currently On</em>' reference.
	 * @see #getCurrentlyOn()
	 * @generated
	 */
	void setCurrentlyOn(RailRoadElement value);

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
	 * @see RailRoadModel.RailRoadModelPackage#getTrain_Id()
	 * @model id="true" required="true"
	 * @generated
	 */
	int getId();

	/**
	 * Sets the value of the '{@link RailRoadModel.Train#getId <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Id</em>' attribute.
	 * @see #getId()
	 * @generated
	 */
	void setId(int value);

	/**
	 * Returns the value of the '<em><b>Previously On</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Previously On</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Previously On</em>' reference.
	 * @see #setPreviouslyOn(RailRoadElement)
	 * @see RailRoadModel.RailRoadModelPackage#getTrain_PreviouslyOn()
	 * @model required="true"
	 * @generated
	 */
	RailRoadElement getPreviouslyOn();

	/**
	 * Sets the value of the '{@link RailRoadModel.Train#getPreviouslyOn <em>Previously On</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Previously On</em>' reference.
	 * @see #getPreviouslyOn()
	 * @generated
	 */
	void setPreviouslyOn(RailRoadElement value);

	/**
	 * Returns the value of the '<em><b>Point</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Point</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Point</em>' containment reference.
	 * @see #setPoint(Point)
	 * @see RailRoadModel.RailRoadModelPackage#getTrain_Point()
	 * @model containment="true" required="true"
	 * @generated
	 */
	Point getPoint();

	/**
	 * Sets the value of the '{@link RailRoadModel.Train#getPoint <em>Point</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Point</em>' containment reference.
	 * @see #getPoint()
	 * @generated
	 */
	void setPoint(Point value);

} // Train
