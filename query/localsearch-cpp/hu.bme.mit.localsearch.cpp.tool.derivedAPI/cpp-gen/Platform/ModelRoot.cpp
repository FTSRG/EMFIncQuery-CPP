
#include "ModelRoot.h"

#include<fstream>
#include"PlatformModel_def.h"
#include"PlatformModel/EnumHelper.h"

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

			if (type == "Node")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::PlatformModel::RemoteNode(id, node))
					: dynamic_cast<ModelElement*>(new ::PlatformModel::LocalNode(id));
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
					case ::PlatformModel::INode::type_id :
						{	
							auto * modelElement = dynamic_cast<::PlatformModel::INode*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("executes");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::ISegment*> as_vector(as_array.size());
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::ISegment*>(modelElements[id]);
								}
								modelElement->set_executes(as_vector);
							}
							ref_elem = elem.get("derivedExecutes");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::RailRoadModel::ITrain*> as_vector(as_array.size());
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									int64_t id = as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::RailRoadModel::ITrain*>(modelElements[id]);
								}
								modelElement->set_derivedExecutes(as_vector);
							}
							attrib_elem = elem.get("id");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_id( attrib_elem.get<int64_t>() );
							}
							attrib_elem = elem.get("responsibleFor");
							
							if( attrib_elem.is<picojson::array>() )
							{
								auto as_array = attrib_elem.get<array>();	
								std::vector<int*> as_vector(as_array.size());
								for(int i = 0 ; i < as_array.size() ; ++i)
								{
									as_vector[i] = as_array[i].get<int64_t>();
								}
								modelElement->set_responsibleFor(as_vector);
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

