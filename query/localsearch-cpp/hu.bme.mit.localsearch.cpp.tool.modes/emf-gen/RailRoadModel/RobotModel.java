/**
 */
package RailRoadModel;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Robot Model</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.RobotModel#getRobots <em>Robots</em>}</li>
 *   <li>{@link RailRoadModel.RobotModel#getRobotparts <em>Robotparts</em>}</li>
 * </ul>
 *
 * @see RailRoadModel.RailRoadModelPackage#getRobotModel()
 * @model
 * @generated
 */
public interface RobotModel extends EObject {
	/**
	 * Returns the value of the '<em><b>Robots</b></em>' containment reference list.
	 * The list contents are of type {@link RailRoadModel.Robot}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Robots</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Robots</em>' containment reference list.
	 * @see RailRoadModel.RailRoadModelPackage#getRobotModel_Robots()
	 * @model containment="true"
	 * @generated
	 */
	EList<Robot> getRobots();

	/**
	 * Returns the value of the '<em><b>Robotparts</b></em>' containment reference list.
	 * The list contents are of type {@link RailRoadModel.RobotPart}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Robotparts</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Robotparts</em>' containment reference list.
	 * @see RailRoadModel.RailRoadModelPackage#getRobotModel_Robotparts()
	 * @model containment="true"
	 * @generated
	 */
	EList<RobotPart> getRobotparts();

} // RobotModel
