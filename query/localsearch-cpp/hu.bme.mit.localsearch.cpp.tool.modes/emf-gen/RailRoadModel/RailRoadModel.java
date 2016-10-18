/**
 */
package RailRoadModel;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Rail Road Model</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.RailRoadModel#getSections <em>Sections</em>}</li>
 *   <li>{@link RailRoadModel.RailRoadModel#getTrains <em>Trains</em>}</li>
 * </ul>
 *
 * @see RailRoadModel.RailRoadModelPackage#getRailRoadModel()
 * @model
 * @generated
 */
public interface RailRoadModel extends EObject {
	/**
	 * Returns the value of the '<em><b>Sections</b></em>' containment reference list.
	 * The list contents are of type {@link RailRoadModel.RailRoadElement}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Sections</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Sections</em>' containment reference list.
	 * @see RailRoadModel.RailRoadModelPackage#getRailRoadModel_Sections()
	 * @model containment="true"
	 * @generated
	 */
	EList<RailRoadElement> getSections();

	/**
	 * Returns the value of the '<em><b>Trains</b></em>' containment reference list.
	 * The list contents are of type {@link RailRoadModel.Train}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Trains</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Trains</em>' containment reference list.
	 * @see RailRoadModel.RailRoadModelPackage#getRailRoadModel_Trains()
	 * @model containment="true"
	 * @generated
	 */
	EList<Train> getTrains();

} // RailRoadModel
