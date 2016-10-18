/**
 */
package RailRoadModel.impl;

import PlatformModel.PlatformModelPackage;

import PlatformModel.impl.PlatformModelPackageImpl;

import RailRoadModel.Point;
import RailRoadModel.RailRoadElement;
import RailRoadModel.RailRoadModel;
import RailRoadModel.RailRoadModelFactory;
import RailRoadModel.RailRoadModelPackage;
import RailRoadModel.Robot;
import RailRoadModel.RobotElement;
import RailRoadModel.RobotModel;
import RailRoadModel.RobotPart;
import RailRoadModel.Segment;
import RailRoadModel.Train;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EReference;

import org.eclipse.emf.ecore.impl.EPackageImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model <b>Package</b>.
 * <!-- end-user-doc -->
 * @generated
 */
public class RailRoadModelPackageImpl extends EPackageImpl implements RailRoadModelPackage {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass trainEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass railRoadElementEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass pointEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass railRoadModelEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass segmentEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass robotElementEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass robotEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass robotPartEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass robotModelEClass = null;

	/**
	 * Creates an instance of the model <b>Package</b>, registered with
	 * {@link org.eclipse.emf.ecore.EPackage.Registry EPackage.Registry} by the package
	 * package URI value.
	 * <p>Note: the correct way to create the package is via the static
	 * factory method {@link #init init()}, which also performs
	 * initialization of the package, or returns the registered package,
	 * if one already exists.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see org.eclipse.emf.ecore.EPackage.Registry
	 * @see RailRoadModel.RailRoadModelPackage#eNS_URI
	 * @see #init()
	 * @generated
	 */
	private RailRoadModelPackageImpl() {
		super(eNS_URI, RailRoadModelFactory.eINSTANCE);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static boolean isInited = false;

	/**
	 * Creates, registers, and initializes the <b>Package</b> for this model, and for any others upon which it depends.
	 * 
	 * <p>This method is used to initialize {@link RailRoadModelPackage#eINSTANCE} when that field is accessed.
	 * Clients should not invoke it directly. Instead, they should simply access that field to obtain the package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #eNS_URI
	 * @see #createPackageContents()
	 * @see #initializePackageContents()
	 * @generated
	 */
	public static RailRoadModelPackage init() {
		if (isInited) return (RailRoadModelPackage)EPackage.Registry.INSTANCE.getEPackage(RailRoadModelPackage.eNS_URI);

		// Obtain or create and register package
		RailRoadModelPackageImpl theRailRoadModelPackage = (RailRoadModelPackageImpl)(EPackage.Registry.INSTANCE.get(eNS_URI) instanceof RailRoadModelPackageImpl ? EPackage.Registry.INSTANCE.get(eNS_URI) : new RailRoadModelPackageImpl());

		isInited = true;

		// Obtain or create and register interdependencies
		PlatformModelPackageImpl thePlatformModelPackage = (PlatformModelPackageImpl)(EPackage.Registry.INSTANCE.getEPackage(PlatformModelPackage.eNS_URI) instanceof PlatformModelPackageImpl ? EPackage.Registry.INSTANCE.getEPackage(PlatformModelPackage.eNS_URI) : PlatformModelPackage.eINSTANCE);

		// Create package meta-data objects
		theRailRoadModelPackage.createPackageContents();
		thePlatformModelPackage.createPackageContents();

		// Initialize created meta-data
		theRailRoadModelPackage.initializePackageContents();
		thePlatformModelPackage.initializePackageContents();

		// Mark meta-data to indicate it can't be changed
		theRailRoadModelPackage.freeze();

  
		// Update the registry and return the package
		EPackage.Registry.INSTANCE.put(RailRoadModelPackage.eNS_URI, theRailRoadModelPackage);
		return theRailRoadModelPackage;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getTrain() {
		return trainEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getTrain_CurrentlyOn() {
		return (EReference)trainEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getTrain_Id() {
		return (EAttribute)trainEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getTrain_PreviouslyOn() {
		return (EReference)trainEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getTrain_Point() {
		return (EReference)trainEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getRailRoadElement() {
		return railRoadElementEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getRailRoadElement_Id() {
		return (EAttribute)railRoadElementEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRailRoadElement_Points() {
		return (EReference)railRoadElementEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPoint() {
		return pointEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPoint_X() {
		return (EAttribute)pointEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPoint_Y() {
		return (EAttribute)pointEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPoint_Z() {
		return (EAttribute)pointEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getRailRoadModel() {
		return railRoadModelEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRailRoadModel_Sections() {
		return (EReference)railRoadModelEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRailRoadModel_Trains() {
		return (EReference)railRoadModelEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getSegment() {
		return segmentEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getSegment_IsEnabled() {
		return (EAttribute)segmentEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getSegment_ConnectedTo() {
		return (EReference)segmentEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getRobotElement() {
		return robotElementEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getRobotElement_Id() {
		return (EAttribute)robotElementEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRobotElement_Position() {
		return (EReference)robotElementEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getRobot() {
		return robotEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRobot_Parts() {
		return (EReference)robotEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getRobotPart() {
		return robotPartEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRobotPart_NearBy() {
		return (EReference)robotPartEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getRobotPart_IsOperational() {
		return (EAttribute)robotPartEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRobotPart_RefSegment() {
		return (EReference)robotPartEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getRobotModel() {
		return robotModelEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRobotModel_Robots() {
		return (EReference)robotModelEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRobotModel_Robotparts() {
		return (EReference)robotModelEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RailRoadModelFactory getRailRoadModelFactory() {
		return (RailRoadModelFactory)getEFactoryInstance();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private boolean isCreated = false;

	/**
	 * Creates the meta-model objects for the package.  This method is
	 * guarded to have no affect on any invocation but its first.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void createPackageContents() {
		if (isCreated) return;
		isCreated = true;

		// Create classes and their features
		trainEClass = createEClass(TRAIN);
		createEReference(trainEClass, TRAIN__CURRENTLY_ON);
		createEAttribute(trainEClass, TRAIN__ID);
		createEReference(trainEClass, TRAIN__PREVIOUSLY_ON);
		createEReference(trainEClass, TRAIN__POINT);

		railRoadElementEClass = createEClass(RAIL_ROAD_ELEMENT);
		createEAttribute(railRoadElementEClass, RAIL_ROAD_ELEMENT__ID);
		createEReference(railRoadElementEClass, RAIL_ROAD_ELEMENT__POINTS);

		pointEClass = createEClass(POINT);
		createEAttribute(pointEClass, POINT__X);
		createEAttribute(pointEClass, POINT__Y);
		createEAttribute(pointEClass, POINT__Z);

		railRoadModelEClass = createEClass(RAIL_ROAD_MODEL);
		createEReference(railRoadModelEClass, RAIL_ROAD_MODEL__SECTIONS);
		createEReference(railRoadModelEClass, RAIL_ROAD_MODEL__TRAINS);

		segmentEClass = createEClass(SEGMENT);
		createEAttribute(segmentEClass, SEGMENT__IS_ENABLED);
		createEReference(segmentEClass, SEGMENT__CONNECTED_TO);

		robotElementEClass = createEClass(ROBOT_ELEMENT);
		createEAttribute(robotElementEClass, ROBOT_ELEMENT__ID);
		createEReference(robotElementEClass, ROBOT_ELEMENT__POSITION);

		robotEClass = createEClass(ROBOT);
		createEReference(robotEClass, ROBOT__PARTS);

		robotPartEClass = createEClass(ROBOT_PART);
		createEReference(robotPartEClass, ROBOT_PART__NEAR_BY);
		createEAttribute(robotPartEClass, ROBOT_PART__IS_OPERATIONAL);
		createEReference(robotPartEClass, ROBOT_PART__REF_SEGMENT);

		robotModelEClass = createEClass(ROBOT_MODEL);
		createEReference(robotModelEClass, ROBOT_MODEL__ROBOTS);
		createEReference(robotModelEClass, ROBOT_MODEL__ROBOTPARTS);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private boolean isInitialized = false;

	/**
	 * Complete the initialization of the package and its meta-model.  This
	 * method is guarded to have no affect on any invocation but its first.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void initializePackageContents() {
		if (isInitialized) return;
		isInitialized = true;

		// Initialize package
		setName(eNAME);
		setNsPrefix(eNS_PREFIX);
		setNsURI(eNS_URI);

		// Create type parameters

		// Set bounds for type parameters

		// Add supertypes to classes
		segmentEClass.getESuperTypes().add(this.getRailRoadElement());
		robotEClass.getESuperTypes().add(this.getRobotElement());
		robotPartEClass.getESuperTypes().add(this.getRobotElement());

		// Initialize classes, features, and operations; add parameters
		initEClass(trainEClass, Train.class, "Train", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getTrain_CurrentlyOn(), this.getRailRoadElement(), null, "currentlyOn", null, 1, 1, Train.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getTrain_Id(), ecorePackage.getEInt(), "id", null, 1, 1, Train.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getTrain_PreviouslyOn(), this.getRailRoadElement(), null, "previouslyOn", null, 1, 1, Train.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getTrain_Point(), this.getPoint(), null, "point", null, 1, 1, Train.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(railRoadElementEClass, RailRoadElement.class, "RailRoadElement", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getRailRoadElement_Id(), ecorePackage.getEInt(), "id", null, 1, 1, RailRoadElement.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getRailRoadElement_Points(), this.getPoint(), null, "points", null, 2, -1, RailRoadElement.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(pointEClass, Point.class, "Point", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getPoint_X(), ecorePackage.getEDouble(), "x", null, 1, 1, Point.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getPoint_Y(), ecorePackage.getEDouble(), "y", null, 1, 1, Point.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getPoint_Z(), ecorePackage.getEDouble(), "z", null, 1, 1, Point.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(railRoadModelEClass, RailRoadModel.class, "RailRoadModel", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getRailRoadModel_Sections(), this.getRailRoadElement(), null, "sections", null, 0, -1, RailRoadModel.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getRailRoadModel_Trains(), this.getTrain(), null, "trains", null, 0, -1, RailRoadModel.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(segmentEClass, Segment.class, "Segment", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getSegment_IsEnabled(), ecorePackage.getEBoolean(), "isEnabled", null, 1, 1, Segment.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getSegment_ConnectedTo(), this.getRailRoadElement(), null, "connectedTo", null, 1, 2, Segment.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(robotElementEClass, RobotElement.class, "RobotElement", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getRobotElement_Id(), ecorePackage.getEInt(), "id", null, 1, 1, RobotElement.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getRobotElement_Position(), this.getPoint(), null, "position", null, 1, 1, RobotElement.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(robotEClass, Robot.class, "Robot", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getRobot_Parts(), this.getRobotPart(), null, "parts", null, 0, -1, Robot.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(robotPartEClass, RobotPart.class, "RobotPart", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getRobotPart_NearBy(), this.getTrain(), null, "nearBy", null, 0, -1, RobotPart.class, IS_TRANSIENT, IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getRobotPart_IsOperational(), ecorePackage.getEBoolean(), "isOperational", null, 0, 1, RobotPart.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getRobotPart_RefSegment(), this.getSegment(), null, "refSegment", null, 0, 1, RobotPart.class, IS_TRANSIENT, IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, IS_DERIVED, IS_ORDERED);

		initEClass(robotModelEClass, RobotModel.class, "RobotModel", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getRobotModel_Robots(), this.getRobot(), null, "robots", null, 0, -1, RobotModel.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getRobotModel_Robotparts(), this.getRobotPart(), null, "robotparts", null, 0, -1, RobotModel.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		// Create resource
		createResource(eNS_URI);

		// Create annotations
		// http://www.eclipse.org/emf/2002/Ecore
		createEcoreAnnotations();
	}

	/**
	 * Initializes the annotations for <b>http://www.eclipse.org/emf/2002/Ecore</b>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void createEcoreAnnotations() {
		String source = "http://www.eclipse.org/emf/2002/Ecore";	
		addAnnotation
		  (this, 
		   source, 
		   new String[] {
			 "settingDelegates", "org.eclipse.viatra.query.querybasedfeature"
		   });
	}

} //RailRoadModelPackageImpl
