
#include "ModelRoot.h"

#include<fstream>
#include"RailRoadModel_def.h"
#include"RailRoadModel/EnumHelper.h"

#define PICOJSON_USE_INT64
#include<picojson.h>


using namespace Viatra::Query::Model;
								
ModelRoot::ModelRoot(const char * configjson)
{
	try {
		std::ifstream ifs(configjson);
		picojson::value root;
		std::string err = picojson::parse(root, ifs);
		if (!err.empty()) {
			throw err;
		}

		auto localnode = root.get("localnode").get<std::string>();

		auto elements = root.get("model").get<picojson::value::array>();

		// Creating class instances
		for (auto & elem : elements)
		{
			bool is_remote = elem.get(":node").get<std::string>() != localnode;
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
			else if (type == "RobotElement")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRobotElement(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRobotElement(id));
			else if (type == "Robot")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRobot(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRobot(id));
			else if (type == "RobotPart")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::RailRoadModel::RemoteRobotPart(id, node))
					: dynamic_cast<ModelElement*>(new ::RailRoadModel::LocalRobotPart(id));
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
			bool is_remote = elem.get(":node").get<std::string>() != localnode;
			std::string type = elem.get(":type").get<std::string>();
			int id = static_cast<int>(elem.get(":id").get<double>());
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
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("previouslyOn");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_previouslyOn(
									dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("point");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_point(
									dynamic_cast<::RailRoadModel::IPoint*>(modelElements[ref_elem.get<int64_t>()])
								);
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( attrib_elem.get<int64_t>() );
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
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IPoint*>(modelElements[id]);
								}
								modelElement->set_points(as_vector);
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( attrib_elem.get<int64_t>() );
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
								modelElement->set_x( attrib_elem.get<double>() );
							}
							attrib_elem = elem.get("y");
							
							if( attrib_elem.is<double>() )
							{
								modelElement->set_y( attrib_elem.get<double>() );
							}
							attrib_elem = elem.get("z");
							
							if( attrib_elem.is<double>() )
							{
								modelElement->set_z( attrib_elem.get<double>() );
							}
						}
						break;
						
					case ::RailRoadModel::IRailRoadModel::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRailRoadModel*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("sections");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IRailRoadElement*> as_vector(as_array.size());
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[id]);
								}
								modelElement->set_sections(as_vector);
							}
							ref_elem = elem.get("trains");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::ITrain*> as_vector(as_array.size());
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::ITrain*>(modelElements[id]);
								}
								modelElement->set_trains(as_vector);
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
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRailRoadElement*>(modelElements[id]);
								}
								modelElement->set_connectedTo(as_vector);
							}
							ref_elem = elem.get("points");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IPoint*> as_vector(as_array.size());
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IPoint*>(modelElements[id]);
								}
								modelElement->set_points(as_vector);
							}
							attrib_elem = elem.get("isEnabled");
							
							if( attrib_elem.is<std::string>() )
							{
								modelElement->set_isEnabled( attrib_elem.get<std::string>() == "true" );
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::RailRoadModel::IRobotElement::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRobotElement*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("position");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_position(
									dynamic_cast<::RailRoadModel::IPoint*>(modelElements[ref_elem.get<int64_t>()])
								);
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( attrib_elem.get<int64_t>() );
							}
						}
						break;
						
					case ::RailRoadModel::IRobot::type_id :
						{	
							auto * modelElement = dynamic_cast<::RailRoadModel::IRobot*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("parts");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IRobotPart*> as_vector(as_array.size());
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRobotPart*>(modelElements[id]);
								}
								modelElement->set_parts(as_vector);
							}
							ref_elem = elem.get("position");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_position(
									dynamic_cast<::RailRoadModel::IPoint*>(modelElements[ref_elem.get<int64_t>()])
								);
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( attrib_elem.get<int64_t>() );
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
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::ITrain*>(modelElements[id]);
								}
								modelElement->set_nearBy(as_vector);
							}
							ref_elem = elem.get("refSegment");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_refSegment(
									dynamic_cast<::RailRoadModel::ISegment*>(modelElements[ref_elem.get<int64_t>()])
								);
							}
							ref_elem = elem.get("position");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_position(
									dynamic_cast<::RailRoadModel::IPoint*>(modelElements[ref_elem.get<int64_t>()])
								);
							}
							attrib_elem = elem.get("isOperational");
							
							if( attrib_elem.is<std::string>() )
							{
								modelElement->set_isOperational( attrib_elem.get<std::string>() == "true" );
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( attrib_elem.get<int64_t>() );
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
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRobot*>(modelElements[id]);
								}
								modelElement->set_robots(as_vector);
							}
							ref_elem = elem.get("robotparts");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::IRobotPart*> as_vector(as_array.size());
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::IRobotPart*>(modelElements[id]);
								}
								modelElement->set_robotparts(as_vector);
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

