/**
 */
package RailRoadModel;

import org.eclipse.emf.common.util.EList;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Robot</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.Robot#getParts <em>Parts</em>}</li>
 * </ul>
 *
 * @see RailRoadModel.RailRoadModelPackage#getRobot()
 * @model
 * @generated
 */
public interface Robot extends RobotElement {
	/**
	 * Returns the value of the '<em><b>Parts</b></em>' containment reference list.
	 * The list contents are of type {@link RailRoadModel.RobotPart}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Parts</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Parts</em>' containment reference list.
	 * @see RailRoadModel.RailRoadModelPackage#getRobot_Parts()
	 * @model containment="true"
	 * @generated
	 */
	EList<RobotPart> getParts();

} // Robot
