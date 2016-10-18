/**
 */
package RailRoadModel;

import org.eclipse.emf.common.util.EList;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Segment</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link RailRoadModel.Segment#isIsEnabled <em>Is Enabled</em>}</li>
 *   <li>{@link RailRoadModel.Segment#getConnectedTo <em>Connected To</em>}</li>
 * </ul>
 *
 * @see RailRoadModel.RailRoadModelPackage#getSegment()
 * @model
 * @generated
 */
public interface Segment extends RailRoadElement {
	/**
	 * Returns the value of the '<em><b>Is Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Is Enabled</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Is Enabled</em>' attribute.
	 * @see #setIsEnabled(boolean)
	 * @see RailRoadModel.RailRoadModelPackage#getSegment_IsEnabled()
	 * @model required="true"
	 * @generated
	 */
	boolean isIsEnabled();

	/**
	 * Sets the value of the '{@link RailRoadModel.Segment#isIsEnabled <em>Is Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Is Enabled</em>' attribute.
	 * @see #isIsEnabled()
	 * @generated
	 */
	void setIsEnabled(boolean value);

	/**
	 * Returns the value of the '<em><b>Connected To</b></em>' reference list.
	 * The list contents are of type {@link RailRoadModel.RailRoadElement}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Connected To</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Connected To</em>' reference list.
	 * @see RailRoadModel.RailRoadModelPackage#getSegment_ConnectedTo()
	 * @model required="true" upper="2"
	 * @generated
	 */
	EList<RailRoadElement> getConnectedTo();

} // Segment
