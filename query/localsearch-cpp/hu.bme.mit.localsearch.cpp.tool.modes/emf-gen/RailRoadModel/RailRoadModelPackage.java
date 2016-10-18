/**
 */
package RailRoadModel;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EReference;

/**
 * <!-- begin-user-doc -->
 * The <b>Package</b> for the model.
 * It contains accessors for the meta objects to represent
 * <ul>
 *   <li>each class,</li>
 *   <li>each feature of each class,</li>
 *   <li>each operation of each class,</li>
 *   <li>each enum,</li>
 *   <li>and each data type</li>
 * </ul>
 * <!-- end-user-doc -->
 * @see RailRoadModel.RailRoadModelFactory
 * @model kind="package"
 *        annotation="http://www.eclipse.org/emf/2002/Ecore settingDelegates='org.eclipse.viatra.query.querybasedfeature'"
 * @generated
 */
public interface RailRoadModelPackage extends EPackage {
	/**
	 * The package name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNAME = "RailRoadModel";

	/**
	 * The package namespace URI.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNS_URI = "http://cpp/tool/modes/model";

	/**
	 * The package namespace name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNS_PREFIX = "hu.bme.mit.localsearch.cpp.tool.modes";

	/**
	 * The singleton instance of the package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	RailRoadModelPackage eINSTANCE = RailRoadModel.impl.RailRoadModelPackageImpl.init();

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.TrainImpl <em>Train</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.TrainImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getTrain()
	 * @generated
	 */
	int TRAIN = 0;

	/**
	 * The feature id for the '<em><b>Currently On</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRAIN__CURRENTLY_ON = 0;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRAIN__ID = 1;

	/**
	 * The feature id for the '<em><b>Previously On</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRAIN__PREVIOUSLY_ON = 2;

	/**
	 * The feature id for the '<em><b>Point</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRAIN__POINT = 3;

	/**
	 * The number of structural features of the '<em>Train</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRAIN_FEATURE_COUNT = 4;

	/**
	 * The number of operations of the '<em>Train</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRAIN_OPERATION_COUNT = 0;

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.RailRoadElementImpl <em>Rail Road Element</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.RailRoadElementImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRailRoadElement()
	 * @generated
	 */
	int RAIL_ROAD_ELEMENT = 1;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int RAIL_ROAD_ELEMENT__ID = 0;

	/**
	 * The feature id for the '<em><b>Points</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int RAIL_ROAD_ELEMENT__POINTS = 1;

	/**
	 * The number of structural features of the '<em>Rail Road Element</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int RAIL_ROAD_ELEMENT_FEATURE_COUNT = 2;

	/**
	 * The number of operations of the '<em>Rail Road Element</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int RAIL_ROAD_ELEMENT_OPERATION_COUNT = 0;

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.PointImpl <em>Point</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.PointImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getPoint()
	 * @generated
	 */
	int POINT = 2;

	/**
	 * The feature id for the '<em><b>X</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POINT__X = 0;

	/**
	 * The feature id for the '<em><b>Y</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POINT__Y = 1;

	/**
	 * The feature id for the '<em><b>Z</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POINT__Z = 2;

	/**
	 * The number of structural features of the '<em>Point</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POINT_FEATURE_COUNT = 3;

	/**
	 * The number of operations of the '<em>Point</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POINT_OPERATION_COUNT = 0;

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.RailRoadModelImpl <em>Rail Road Model</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.RailRoadModelImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRailRoadModel()
	 * @generated
	 */
	int RAIL_ROAD_MODEL = 3;

	/**
	 * The feature id for the '<em><b>Sections</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int RAIL_ROAD_MODEL__SECTIONS = 0;

	/**
	 * The feature id for the '<em><b>Trains</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int RAIL_ROAD_MODEL__TRAINS = 1;

	/**
	 * The number of structural features of the '<em>Rail Road Model</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int RAIL_ROAD_MODEL_FEATURE_COUNT = 2;

	/**
	 * The number of operations of the '<em>Rail Road Model</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int RAIL_ROAD_MODEL_OPERATION_COUNT = 0;

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.SegmentImpl <em>Segment</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.SegmentImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getSegment()
	 * @generated
	 */
	int SEGMENT = 4;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SEGMENT__ID = RAIL_ROAD_ELEMENT__ID;

	/**
	 * The feature id for the '<em><b>Points</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SEGMENT__POINTS = RAIL_ROAD_ELEMENT__POINTS;

	/**
	 * The feature id for the '<em><b>Is Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SEGMENT__IS_ENABLED = RAIL_ROAD_ELEMENT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Connected To</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SEGMENT__CONNECTED_TO = RAIL_ROAD_ELEMENT_FEATURE_COUNT + 1;

	/**
	 * The number of structural features of the '<em>Segment</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SEGMENT_FEATURE_COUNT = RAIL_ROAD_ELEMENT_FEATURE_COUNT + 2;

	/**
	 * The number of operations of the '<em>Segment</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SEGMENT_OPERATION_COUNT = RAIL_ROAD_ELEMENT_OPERATION_COUNT + 0;

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.RobotElementImpl <em>Robot Element</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.RobotElementImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRobotElement()
	 * @generated
	 */
	int ROBOT_ELEMENT = 5;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_ELEMENT__ID = 0;

	/**
	 * The feature id for the '<em><b>Position</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_ELEMENT__POSITION = 1;

	/**
	 * The number of structural features of the '<em>Robot Element</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_ELEMENT_FEATURE_COUNT = 2;

	/**
	 * The number of operations of the '<em>Robot Element</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_ELEMENT_OPERATION_COUNT = 0;

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.RobotImpl <em>Robot</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.RobotImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRobot()
	 * @generated
	 */
	int ROBOT = 6;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT__ID = ROBOT_ELEMENT__ID;

	/**
	 * The feature id for the '<em><b>Position</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT__POSITION = ROBOT_ELEMENT__POSITION;

	/**
	 * The feature id for the '<em><b>Parts</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT__PARTS = ROBOT_ELEMENT_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Robot</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_FEATURE_COUNT = ROBOT_ELEMENT_FEATURE_COUNT + 1;

	/**
	 * The number of operations of the '<em>Robot</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_OPERATION_COUNT = ROBOT_ELEMENT_OPERATION_COUNT + 0;

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.RobotPartImpl <em>Robot Part</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.RobotPartImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRobotPart()
	 * @generated
	 */
	int ROBOT_PART = 7;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_PART__ID = ROBOT_ELEMENT__ID;

	/**
	 * The feature id for the '<em><b>Position</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_PART__POSITION = ROBOT_ELEMENT__POSITION;

	/**
	 * The feature id for the '<em><b>Near By</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_PART__NEAR_BY = ROBOT_ELEMENT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Is Operational</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_PART__IS_OPERATIONAL = ROBOT_ELEMENT_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Ref Segment</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_PART__REF_SEGMENT = ROBOT_ELEMENT_FEATURE_COUNT + 2;

	/**
	 * The number of structural features of the '<em>Robot Part</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_PART_FEATURE_COUNT = ROBOT_ELEMENT_FEATURE_COUNT + 3;

	/**
	 * The number of operations of the '<em>Robot Part</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_PART_OPERATION_COUNT = ROBOT_ELEMENT_OPERATION_COUNT + 0;

	/**
	 * The meta object id for the '{@link RailRoadModel.impl.RobotModelImpl <em>Robot Model</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see RailRoadModel.impl.RobotModelImpl
	 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRobotModel()
	 * @generated
	 */
	int ROBOT_MODEL = 8;

	/**
	 * The feature id for the '<em><b>Robots</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_MODEL__ROBOTS = 0;

	/**
	 * The feature id for the '<em><b>Robotparts</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_MODEL__ROBOTPARTS = 1;

	/**
	 * The number of structural features of the '<em>Robot Model</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_MODEL_FEATURE_COUNT = 2;

	/**
	 * The number of operations of the '<em>Robot Model</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROBOT_MODEL_OPERATION_COUNT = 0;


	/**
	 * Returns the meta object for class '{@link RailRoadModel.Train <em>Train</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Train</em>'.
	 * @see RailRoadModel.Train
	 * @generated
	 */
	EClass getTrain();

	/**
	 * Returns the meta object for the reference '{@link RailRoadModel.Train#getCurrentlyOn <em>Currently On</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Currently On</em>'.
	 * @see RailRoadModel.Train#getCurrentlyOn()
	 * @see #getTrain()
	 * @generated
	 */
	EReference getTrain_CurrentlyOn();

	/**
	 * Returns the meta object for the attribute '{@link RailRoadModel.Train#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see RailRoadModel.Train#getId()
	 * @see #getTrain()
	 * @generated
	 */
	EAttribute getTrain_Id();

	/**
	 * Returns the meta object for the reference '{@link RailRoadModel.Train#getPreviouslyOn <em>Previously On</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Previously On</em>'.
	 * @see RailRoadModel.Train#getPreviouslyOn()
	 * @see #getTrain()
	 * @generated
	 */
	EReference getTrain_PreviouslyOn();

	/**
	 * Returns the meta object for the containment reference '{@link RailRoadModel.Train#getPoint <em>Point</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Point</em>'.
	 * @see RailRoadModel.Train#getPoint()
	 * @see #getTrain()
	 * @generated
	 */
	EReference getTrain_Point();

	/**
	 * Returns the meta object for class '{@link RailRoadModel.RailRoadElement <em>Rail Road Element</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Rail Road Element</em>'.
	 * @see RailRoadModel.RailRoadElement
	 * @generated
	 */
	EClass getRailRoadElement();

	/**
	 * Returns the meta object for the attribute '{@link RailRoadModel.RailRoadElement#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see RailRoadModel.RailRoadElement#getId()
	 * @see #getRailRoadElement()
	 * @generated
	 */
	EAttribute getRailRoadElement_Id();

	/**
	 * Returns the meta object for the containment reference list '{@link RailRoadModel.RailRoadElement#getPoints <em>Points</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Points</em>'.
	 * @see RailRoadModel.RailRoadElement#getPoints()
	 * @see #getRailRoadElement()
	 * @generated
	 */
	EReference getRailRoadElement_Points();

	/**
	 * Returns the meta object for class '{@link RailRoadModel.Point <em>Point</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Point</em>'.
	 * @see RailRoadModel.Point
	 * @generated
	 */
	EClass getPoint();

	/**
	 * Returns the meta object for the attribute '{@link RailRoadModel.Point#getX <em>X</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>X</em>'.
	 * @see RailRoadModel.Point#getX()
	 * @see #getPoint()
	 * @generated
	 */
	EAttribute getPoint_X();

	/**
	 * Returns the meta object for the attribute '{@link RailRoadModel.Point#getY <em>Y</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Y</em>'.
	 * @see RailRoadModel.Point#getY()
	 * @see #getPoint()
	 * @generated
	 */
	EAttribute getPoint_Y();

	/**
	 * Returns the meta object for the attribute '{@link RailRoadModel.Point#getZ <em>Z</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Z</em>'.
	 * @see RailRoadModel.Point#getZ()
	 * @see #getPoint()
	 * @generated
	 */
	EAttribute getPoint_Z();

	/**
	 * Returns the meta object for class '{@link RailRoadModel.RailRoadModel <em>Rail Road Model</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Rail Road Model</em>'.
	 * @see RailRoadModel.RailRoadModel
	 * @generated
	 */
	EClass getRailRoadModel();

	/**
	 * Returns the meta object for the containment reference list '{@link RailRoadModel.RailRoadModel#getSections <em>Sections</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Sections</em>'.
	 * @see RailRoadModel.RailRoadModel#getSections()
	 * @see #getRailRoadModel()
	 * @generated
	 */
	EReference getRailRoadModel_Sections();

	/**
	 * Returns the meta object for the containment reference list '{@link RailRoadModel.RailRoadModel#getTrains <em>Trains</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Trains</em>'.
	 * @see RailRoadModel.RailRoadModel#getTrains()
	 * @see #getRailRoadModel()
	 * @generated
	 */
	EReference getRailRoadModel_Trains();

	/**
	 * Returns the meta object for class '{@link RailRoadModel.Segment <em>Segment</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Segment</em>'.
	 * @see RailRoadModel.Segment
	 * @generated
	 */
	EClass getSegment();

	/**
	 * Returns the meta object for the attribute '{@link RailRoadModel.Segment#isIsEnabled <em>Is Enabled</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Is Enabled</em>'.
	 * @see RailRoadModel.Segment#isIsEnabled()
	 * @see #getSegment()
	 * @generated
	 */
	EAttribute getSegment_IsEnabled();

	/**
	 * Returns the meta object for the reference list '{@link RailRoadModel.Segment#getConnectedTo <em>Connected To</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference list '<em>Connected To</em>'.
	 * @see RailRoadModel.Segment#getConnectedTo()
	 * @see #getSegment()
	 * @generated
	 */
	EReference getSegment_ConnectedTo();

	/**
	 * Returns the meta object for class '{@link RailRoadModel.RobotElement <em>Robot Element</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Robot Element</em>'.
	 * @see RailRoadModel.RobotElement
	 * @generated
	 */
	EClass getRobotElement();

	/**
	 * Returns the meta object for the attribute '{@link RailRoadModel.RobotElement#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see RailRoadModel.RobotElement#getId()
	 * @see #getRobotElement()
	 * @generated
	 */
	EAttribute getRobotElement_Id();

	/**
	 * Returns the meta object for the containment reference '{@link RailRoadModel.RobotElement#getPosition <em>Position</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Position</em>'.
	 * @see RailRoadModel.RobotElement#getPosition()
	 * @see #getRobotElement()
	 * @generated
	 */
	EReference getRobotElement_Position();

	/**
	 * Returns the meta object for class '{@link RailRoadModel.Robot <em>Robot</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Robot</em>'.
	 * @see RailRoadModel.Robot
	 * @generated
	 */
	EClass getRobot();

	/**
	 * Returns the meta object for the containment reference list '{@link RailRoadModel.Robot#getParts <em>Parts</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Parts</em>'.
	 * @see RailRoadModel.Robot#getParts()
	 * @see #getRobot()
	 * @generated
	 */
	EReference getRobot_Parts();

	/**
	 * Returns the meta object for class '{@link RailRoadModel.RobotPart <em>Robot Part</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Robot Part</em>'.
	 * @see RailRoadModel.RobotPart
	 * @generated
	 */
	EClass getRobotPart();

	/**
	 * Returns the meta object for the reference list '{@link RailRoadModel.RobotPart#getNearBy <em>Near By</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference list '<em>Near By</em>'.
	 * @see RailRoadModel.RobotPart#getNearBy()
	 * @see #getRobotPart()
	 * @generated
	 */
	EReference getRobotPart_NearBy();

	/**
	 * Returns the meta object for the attribute '{@link RailRoadModel.RobotPart#isIsOperational <em>Is Operational</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Is Operational</em>'.
	 * @see RailRoadModel.RobotPart#isIsOperational()
	 * @see #getRobotPart()
	 * @generated
	 */
	EAttribute getRobotPart_IsOperational();

	/**
	 * Returns the meta object for the reference '{@link RailRoadModel.RobotPart#getRefSegment <em>Ref Segment</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Ref Segment</em>'.
	 * @see RailRoadModel.RobotPart#getRefSegment()
	 * @see #getRobotPart()
	 * @generated
	 */
	EReference getRobotPart_RefSegment();

	/**
	 * Returns the meta object for class '{@link RailRoadModel.RobotModel <em>Robot Model</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Robot Model</em>'.
	 * @see RailRoadModel.RobotModel
	 * @generated
	 */
	EClass getRobotModel();

	/**
	 * Returns the meta object for the containment reference list '{@link RailRoadModel.RobotModel#getRobots <em>Robots</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Robots</em>'.
	 * @see RailRoadModel.RobotModel#getRobots()
	 * @see #getRobotModel()
	 * @generated
	 */
	EReference getRobotModel_Robots();

	/**
	 * Returns the meta object for the containment reference list '{@link RailRoadModel.RobotModel#getRobotparts <em>Robotparts</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Robotparts</em>'.
	 * @see RailRoadModel.RobotModel#getRobotparts()
	 * @see #getRobotModel()
	 * @generated
	 */
	EReference getRobotModel_Robotparts();

	/**
	 * Returns the factory that creates the instances of the model.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the factory that creates the instances of the model.
	 * @generated
	 */
	RailRoadModelFactory getRailRoadModelFactory();

	/**
	 * <!-- begin-user-doc -->
	 * Defines literals for the meta objects that represent
	 * <ul>
	 *   <li>each class,</li>
	 *   <li>each feature of each class,</li>
	 *   <li>each operation of each class,</li>
	 *   <li>each enum,</li>
	 *   <li>and each data type</li>
	 * </ul>
	 * <!-- end-user-doc -->
	 * @generated
	 */
	interface Literals {
		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.TrainImpl <em>Train</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.TrainImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getTrain()
		 * @generated
		 */
		EClass TRAIN = eINSTANCE.getTrain();

		/**
		 * The meta object literal for the '<em><b>Currently On</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference TRAIN__CURRENTLY_ON = eINSTANCE.getTrain_CurrentlyOn();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute TRAIN__ID = eINSTANCE.getTrain_Id();

		/**
		 * The meta object literal for the '<em><b>Previously On</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference TRAIN__PREVIOUSLY_ON = eINSTANCE.getTrain_PreviouslyOn();

		/**
		 * The meta object literal for the '<em><b>Point</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference TRAIN__POINT = eINSTANCE.getTrain_Point();

		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.RailRoadElementImpl <em>Rail Road Element</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.RailRoadElementImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRailRoadElement()
		 * @generated
		 */
		EClass RAIL_ROAD_ELEMENT = eINSTANCE.getRailRoadElement();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute RAIL_ROAD_ELEMENT__ID = eINSTANCE.getRailRoadElement_Id();

		/**
		 * The meta object literal for the '<em><b>Points</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference RAIL_ROAD_ELEMENT__POINTS = eINSTANCE.getRailRoadElement_Points();

		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.PointImpl <em>Point</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.PointImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getPoint()
		 * @generated
		 */
		EClass POINT = eINSTANCE.getPoint();

		/**
		 * The meta object literal for the '<em><b>X</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute POINT__X = eINSTANCE.getPoint_X();

		/**
		 * The meta object literal for the '<em><b>Y</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute POINT__Y = eINSTANCE.getPoint_Y();

		/**
		 * The meta object literal for the '<em><b>Z</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute POINT__Z = eINSTANCE.getPoint_Z();

		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.RailRoadModelImpl <em>Rail Road Model</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.RailRoadModelImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRailRoadModel()
		 * @generated
		 */
		EClass RAIL_ROAD_MODEL = eINSTANCE.getRailRoadModel();

		/**
		 * The meta object literal for the '<em><b>Sections</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference RAIL_ROAD_MODEL__SECTIONS = eINSTANCE.getRailRoadModel_Sections();

		/**
		 * The meta object literal for the '<em><b>Trains</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference RAIL_ROAD_MODEL__TRAINS = eINSTANCE.getRailRoadModel_Trains();

		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.SegmentImpl <em>Segment</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.SegmentImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getSegment()
		 * @generated
		 */
		EClass SEGMENT = eINSTANCE.getSegment();

		/**
		 * The meta object literal for the '<em><b>Is Enabled</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute SEGMENT__IS_ENABLED = eINSTANCE.getSegment_IsEnabled();

		/**
		 * The meta object literal for the '<em><b>Connected To</b></em>' reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference SEGMENT__CONNECTED_TO = eINSTANCE.getSegment_ConnectedTo();

		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.RobotElementImpl <em>Robot Element</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.RobotElementImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRobotElement()
		 * @generated
		 */
		EClass ROBOT_ELEMENT = eINSTANCE.getRobotElement();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ROBOT_ELEMENT__ID = eINSTANCE.getRobotElement_Id();

		/**
		 * The meta object literal for the '<em><b>Position</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ROBOT_ELEMENT__POSITION = eINSTANCE.getRobotElement_Position();

		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.RobotImpl <em>Robot</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.RobotImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRobot()
		 * @generated
		 */
		EClass ROBOT = eINSTANCE.getRobot();

		/**
		 * The meta object literal for the '<em><b>Parts</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ROBOT__PARTS = eINSTANCE.getRobot_Parts();

		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.RobotPartImpl <em>Robot Part</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.RobotPartImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRobotPart()
		 * @generated
		 */
		EClass ROBOT_PART = eINSTANCE.getRobotPart();

		/**
		 * The meta object literal for the '<em><b>Near By</b></em>' reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ROBOT_PART__NEAR_BY = eINSTANCE.getRobotPart_NearBy();

		/**
		 * The meta object literal for the '<em><b>Is Operational</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ROBOT_PART__IS_OPERATIONAL = eINSTANCE.getRobotPart_IsOperational();

		/**
		 * The meta object literal for the '<em><b>Ref Segment</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ROBOT_PART__REF_SEGMENT = eINSTANCE.getRobotPart_RefSegment();

		/**
		 * The meta object literal for the '{@link RailRoadModel.impl.RobotModelImpl <em>Robot Model</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see RailRoadModel.impl.RobotModelImpl
		 * @see RailRoadModel.impl.RailRoadModelPackageImpl#getRobotModel()
		 * @generated
		 */
		EClass ROBOT_MODEL = eINSTANCE.getRobotModel();

		/**
		 * The meta object literal for the '<em><b>Robots</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ROBOT_MODEL__ROBOTS = eINSTANCE.getRobotModel_Robots();

		/**
		 * The meta object literal for the '<em><b>Robotparts</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ROBOT_MODEL__ROBOTPARTS = eINSTANCE.getRobotModel_Robotparts();

	}

} //RailRoadModelPackage
