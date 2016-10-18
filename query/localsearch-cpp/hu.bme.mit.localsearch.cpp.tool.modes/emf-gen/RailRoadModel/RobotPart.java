/**
 */
package RailRoadModel;

import org.eclipse.emf.common.util.EList;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Robot Part</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.RobotPart#getNearBy <em>Near By</em>}</li>
 *   <li>{@link RailRoadModel.RobotPart#isIsOperational <em>Is Operational</em>}</li>
 *   <li>{@link RailRoadModel.RobotPart#getRefSegment <em>Ref Segment</em>}</li>
 * </ul>
 *
 * @see RailRoadModel.RailRoadModelPackage#getRobotPart()
 * @model
 * @generated
 */
public interface RobotPart extends RobotElement {
	/**
	 * Returns the value of the '<em><b>Near By</b></em>' reference list.
	 * The list contents are of type {@link RailRoadModel.Train}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Near By</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Near By</em>' reference list.
	 * @see RailRoadModel.RailRoadModelPackage#getRobotPart_NearBy()
	 * @model transient="true" volatile="true" derived="true"
	 * @generated
	 */
	EList<Train> getNearBy();

	/**
	 * Returns the value of the '<em><b>Is Operational</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Is Operational</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Is Operational</em>' attribute.
	 * @see #setIsOperational(boolean)
	 * @see RailRoadModel.RailRoadModelPackage#getRobotPart_IsOperational()
	 * @model
	 * @generated
	 */
	boolean isIsOperational();

	/**
	 * Sets the value of the '{@link RailRoadModel.RobotPart#isIsOperational <em>Is Operational</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Is Operational</em>' attribute.
	 * @see #isIsOperational()
	 * @generated
	 */
	void setIsOperational(boolean value);

	/**
	 * Returns the value of the '<em><b>Ref Segment</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Ref Segment</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Ref Segment</em>' reference.
	 * @see #setRefSegment(Segment)
	 * @see RailRoadModel.RailRoadModelPackage#getRobotPart_RefSegment()
	 * @model transient="true" volatile="true" derived="true"
	 * @generated
	 */
	Segment getRefSegment();

	/**
	 * Sets the value of the '{@link RailRoadModel.RobotPart#getRefSegment <em>Ref Segment</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Ref Segment</em>' reference.
	 * @see #getRefSegment()
	 * @generated
	 */
	void setRefSegment(Segment value);

} // RobotPart
