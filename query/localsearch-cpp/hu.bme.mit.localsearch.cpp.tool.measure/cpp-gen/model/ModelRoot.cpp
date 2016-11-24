
#include "ModelRoot.h"

#include<fstream>
#include"railRoadModel_def.h"

#define PICOJSON_USE_INT64
#include<picojson.h>


using namespace Viatra::Query::Model;
								
ModelRoot::ModelRoot(){
	
}

ModelRoot::ModelRoot(const char * configjson, const char * localNodeName)
{
	try {
		std::ifstream ifs(configjson);
		picojson::value root;
		std::string err = picojson::parse(root, ifs);
		if (!err.empty()) {
			throw err;
		}
		
		auto elements = root.get("model").get<picojson::value::array>();

		// Creating class instances
		for (auto & elem : elements)
		{
			bool is_remote = elem.get(":node").get<std::string>() != localNodeName;
			std::string type = elem.get(":type").get<std::string>();
			int id = static_cast<int>(elem.get(":id").get<double>());
			if (modelElements.find(id) != modelElements.end())
				throw std::string("Identifier is already used");

			auto node = nullptr;

			if (type == "Train")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteTrain(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalTrain(id));
			else if (type == "RailRoadElement")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteRailRoadElement(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalRailRoadElement(id));
			else if (type == "Turnout")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteTurnout(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalTurnout(id));
			else if (type == "Point")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemotePoint(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalPoint(id));
			else if (type == "RailRoadModel")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteRailRoadModel(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalRailRoadModel(id));
			else if (type == "Segment")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteSegment(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalSegment(id));
			else if (type == "Path")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemotePath(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalPath(id));
			else if (type == "RobotPart")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteRobotPart(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalRobotPart(id));
			else if (type == "RobotElement")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteRobotElement(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalRobotElement(id));
			else if (type == "State")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteState(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalState(id));
			else if (type == "Frozen")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteFrozen(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalFrozen(id));
			else if (type == "Operational")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteOperational(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalOperational(id));
			else if (type == "Robot")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteRobot(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalRobot(id));
			else if (type == "RobotModel")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::railRoadModel::RemoteRobotModel(id, node))
					: dynamic_cast<ModelElement*>(new ::railRoadModel::LocalRobotModel(id));
			else 

				throw std::string("ModelElement type cannot be read");

		}		
		
		// Filling class instances with data
		for (auto & elem : elements)
		{
			bool is_remote = elem.get(":node").get<std::string>() != localNodeName;
			std::string type = elem.get(":type").get<std::string>();
			int32_t id = static_cast<int>(elem.get(":id").get<double>());
			auto modelElement = modelElements.find(id)->second;
		
			if( !is_remote )
			{
				switch( modelElements[id]->get_type_id() ){
					case ::railRoadModel::ITrain::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::ITrain*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("currentlyOn");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_currentlyOn(
									dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("previouslyOn");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_previouslyOn(
									dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							attrib_elem = elem.get("x");
							
							if( attrib_elem.is<double>() )
							{
								modelElement->set_x( (double)attrib_elem.get<double>() );
							}
							attrib_elem = elem.get("y");
							
							if( attrib_elem.is<double>() )
							{
								modelElement->set_y( (double)attrib_elem.get<double>() );
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::IRailRoadElement::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("points");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::IPoint*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::IPoint*>(modelElements[id]);
								}
								modelElement->set_points(as_vector);
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::ITurnout::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::ITurnout*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("top");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_top(
									dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("straight");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_straight(
									dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("divergent");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_divergent(
									dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("currentState");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_currentState(
									dynamic_cast<::railRoadModel::IState*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("points");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::IPoint*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::IPoint*>(modelElements[id]);
								}
								modelElement->set_points(as_vector);
							}
							attrib_elem = elem.get("currentlyDivergent");
							
							if( attrib_elem.is<bool>() )
							{
								modelElement->set_currentlyDivergent( (bool)attrib_elem.get<bool>() );
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::IPoint::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IPoint*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							attrib_elem = elem.get("x");
							
							if( attrib_elem.is<double>() )
							{
								modelElement->set_x( (double)attrib_elem.get<double>() );
							}
							attrib_elem = elem.get("y");
							
							if( attrib_elem.is<double>() )
							{
								modelElement->set_y( (double)attrib_elem.get<double>() );
							}
						}
						break;
						
					case ::railRoadModel::IRailRoadModel::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IRailRoadModel*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("segments");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::IRailRoadElement*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[id]);
								}
								modelElement->set_segments(as_vector);
							}
							ref_elem = elem.get("trains");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::ITrain*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::ITrain*>(modelElements[id]);
								}
								modelElement->set_trains(as_vector);
							}
							ref_elem = elem.get("paths");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::IPath*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::IPath*>(modelElements[id]);
								}
								modelElement->set_paths(as_vector);
							}
						}
						break;
						
					case ::railRoadModel::ISegment::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::ISegment*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("connectedTo");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::IRailRoadElement*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[id]);
								}
								modelElement->set_connectedTo(as_vector);
							}
							ref_elem = elem.get("points");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::IPoint*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::IPoint*>(modelElements[id]);
								}
								modelElement->set_points(as_vector);
							}
							attrib_elem = elem.get("isEnabled");
							
							if( attrib_elem.is<bool>() )
							{
								modelElement->set_isEnabled( (bool)attrib_elem.get<bool>() );
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::IPath::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IPath*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("from");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_from(
									dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("via");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_via(
									dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("to");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_to(
									dynamic_cast<::railRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
						}
						break;
						
					case ::railRoadModel::IRobotPart::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IRobotPart*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("nearBy");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::ITrain*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::ITrain*>(modelElements[id]);
								}
								modelElement->set_nearBy(as_vector);
							}
							ref_elem = elem.get("refSegment");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::ISegment*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::ISegment*>(modelElements[id]);
								}
								modelElement->set_refSegment(as_vector);
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::IRobotElement::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IRobotElement*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::IState::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IState*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::IFrozen::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IFrozen*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::IOperational::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IOperational*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( (int)attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::railRoadModel::IRobot::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IRobot*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("robotParts");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::IRobotPart*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::IRobotPart*>(modelElements[id]);
								}
								modelElement->set_robotParts(as_vector);
							}
						}
						break;
						
					case ::railRoadModel::IRobotModel::type_id :
						{	
							auto * modelElement = dynamic_cast<::railRoadModel::IRobotModel*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("robots");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::railRoadModel::IRobot*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::railRoadModel::IRobot*>(modelElements[id]);
								}
								modelElement->set_robots(as_vector);
							}
						}
						break;
						
				}
			}
		}		
	}
	catch (std::string& str)
	{
		std::cout << str << std::endl;
		FreeAllModelElement();
		throw;
	}
	catch (std::exception& ex)
	{				
		std::cout << ex.what() << std::endl;
		FreeAllModelElement();
		throw;
	}
	catch (...)
	{				
		std::cout << "Unexpected exception" << std::endl;
		FreeAllModelElement();
		throw;
	}
}

void ModelRoot::FreeAllModelElement()
{
	for (auto & ptr : modelElements)
	{
		delete ptr.second;
	}
}

