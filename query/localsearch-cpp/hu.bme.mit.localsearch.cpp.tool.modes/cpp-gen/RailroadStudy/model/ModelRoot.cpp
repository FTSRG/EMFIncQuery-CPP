
#include "ModelRoot.h"

#include<fstream>
#include"RailRoadModel_def.h"

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
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteTrain(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalTrain(id));
			else if (type == "RailRoadElement")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRailRoadElement(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRailRoadElement(id));
			else if (type == "Turnout")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteTurnout(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalTurnout(id));
			else if (type == "Point")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemotePoint(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalPoint(id));
			else if (type == "RailRoadModel")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRailRoadModel(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRailRoadModel(id));
			else if (type == "Segment")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteSegment(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalSegment(id));
			else if (type == "Path")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemotePath(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalPath(id));
			else if (type == "RobotPart")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRobotPart(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRobotPart(id));
			else if (type == "RobotElement")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRobotElement(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRobotElement(id));
			else if (type == "State")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteState(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalState(id));
			else if (type == "Frozen")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteFrozen(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalFrozen(id));
			else if (type == "Operational")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteOperational(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalOperational(id));
			else if (type == "Robot")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRobot(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRobot(id));
			else if (type == "RobotModel")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRobotModel(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRobotModel(id));
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
					case ::RailRoadModel::ITrain::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::ITrain*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("currentlyOn");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_currentlyOn(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("previouslyOn");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_previouslyOn(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
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
						
					case ::RailRoadModel::IRailRoadElement::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("points");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IPoint*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IPoint*>(modelElements[id]);
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
						
					case ::RailRoadModel::ITurnout::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::ITurnout*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("top");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_top(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("straight");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_straight(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("divergent");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_divergent(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("currentState");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_currentState(
									dynamic_cast<::RailRoadModel::IState*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("points");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IPoint*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IPoint*>(modelElements[id]);
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
						
					case ::RailRoadModel::IPoint::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IPoint*>(modelElements[id]);
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
						
					case ::RailRoadModel::IRailRoadModel::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRailRoadModel*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("segments");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IRailRoadElement*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[id]);
								}
								modelElement->set_segments(as_vector);
							}
							ref_elem = elem.get("trains");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::ITrain*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::ITrain*>(modelElements[id]);
								}
								modelElement->set_trains(as_vector);
							}
							ref_elem = elem.get("paths");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IPath*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IPath*>(modelElements[id]);
								}
								modelElement->set_paths(as_vector);
							}
						}
						break;
						
					case ::RailRoadModel::ISegment::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::ISegment*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("connectedTo");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IRailRoadElement*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[id]);
								}
								modelElement->set_connectedTo(as_vector);
							}
							ref_elem = elem.get("points");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IPoint*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IPoint*>(modelElements[id]);
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
						
					case ::RailRoadModel::IPath::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IPath*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("from");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_from(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("via");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_via(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("to");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_to(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
						}
						break;
						
					case ::RailRoadModel::IRobotPart::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRobotPart*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("nearBy");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::ITrain*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::ITrain*>(modelElements[id]);
								}
								modelElement->set_nearBy(as_vector);
							}
							ref_elem = elem.get("refSegment");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::ISegment*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::ISegment*>(modelElements[id]);
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
						
					case ::RailRoadModel::IRobotElement::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRobotElement*>(modelElements[id]);
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
						
					case ::RailRoadModel::IState::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IState*>(modelElements[id]);
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
						
					case ::RailRoadModel::IFrozen::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IFrozen*>(modelElements[id]);
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
						
					case ::RailRoadModel::IOperational::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IOperational*>(modelElements[id]);
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
						
					case ::RailRoadModel::IRobot::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRobot*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("robotParts");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IRobotPart*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRobotPart*>(modelElements[id]);
								}
								modelElement->set_robotParts(as_vector);
							}
						}
						break;
						
					case ::RailRoadModel::IRobotModel::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRobotModel*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("robots");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IRobot*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRobot*>(modelElements[id]);
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

