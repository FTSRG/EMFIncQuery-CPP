/**
 */
package RailRoadModel.impl;

import RailRoadModel.*;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EPackage;

import org.eclipse.emf.ecore.impl.EFactoryImpl;

import org.eclipse.emf.ecore.plugin.EcorePlugin;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model <b>Factory</b>.
 * <!-- end-user-doc -->
 * @generated
 */
public class RailRoadModelFactoryImpl extends EFactoryImpl implements RailRoadModelFactory {
	/**
	 * Creates the default factory implementation.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static RailRoadModelFactory init() {
		try {
			RailRoadModelFactory theRailRoadModelFactory = (RailRoadModelFactory)EPackage.Registry.INSTANCE.getEFactory(RailRoadModelPackage.eNS_URI);
			if (theRailRoadModelFactory != null) {
				return theRailRoadModelFactory;
			}
		}
		catch (Exception exception) {
			EcorePlugin.INSTANCE.log(exception);
		}
		return new RailRoadModelFactoryImpl();
	}

	/**
	 * Creates an instance of the factory.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RailRoadModelFactoryImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public EObject create(EClass eClass) {
		switch (eClass.getClassifierID()) {
			case RailRoadModelPackage.TRAIN: return createTrain();
			case RailRoadModelPackage.POINT: return createPoint();
			case RailRoadModelPackage.RAIL_ROAD_MODEL: return createRailRoadModel();
			case RailRoadModelPackage.SEGMENT: return createSegment();
			case RailRoadModelPackage.ROBOT: return createRobot();
			case RailRoadModelPackage.ROBOT_PART: return createRobotPart();
			case RailRoadModelPackage.ROBOT_MODEL: return createRobotModel();
			default:
				throw new IllegalArgumentException("The class '" + eClass.getName() + "' is not a valid classifier");
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Train createTrain() {
		TrainImpl train = new TrainImpl();
		return train;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Point createPoint() {
		PointImpl point = new PointImpl();
		return point;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RailRoadModel createRailRoadModel() {
		RailRoadModelImpl railRoadModel = new RailRoadModelImpl();
		return railRoadModel;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Segment createSegment() {
		SegmentImpl segment = new SegmentImpl();
		return segment;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Robot createRobot() {
		RobotImpl robot = new RobotImpl();
		return robot;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RobotPart createRobotPart() {
		RobotPartImpl robotPart = new RobotPartImpl();
		return robotPart;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RobotModel createRobotModel() {
		RobotModelImpl robotModel = new RobotModelImpl();
		return robotModel;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RailRoadModelPackage getRailRoadModelPackage() {
		return (RailRoadModelPackage)getEPackage();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @deprecated
	 * @generated
	 */
	@Deprecated
	public static RailRoadModelPackage getPackage() {
		return RailRoadModelPackage.eINSTANCE;
	}

} //RailRoadModelFactoryImpl
