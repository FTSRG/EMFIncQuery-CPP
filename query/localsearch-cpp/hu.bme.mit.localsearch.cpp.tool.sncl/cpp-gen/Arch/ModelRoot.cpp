
#include "ModelRoot.h"

#include<fstream>
#include"arch_def.h"

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

			if (type == "Node")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::arch::RemoteNode(id, node))
					: dynamic_cast<ModelElement*>(new ::arch::LocalNode(id));
			else if (type == "SN")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::arch::RemoteSN(id, node))
					: dynamic_cast<ModelElement*>(new ::arch::LocalSN(id));
			else if (type == "CL")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new ::arch::RemoteCL(id, node))
					: dynamic_cast<ModelElement*>(new ::arch::LocalCL(id));
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
					case ::arch::INode::type_id :
						{	
							auto * modelElement = dynamic_cast<::arch::INode*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							attrib_elem = elem.get("name");
							
							if( attrib_elem.is<::std::string>() )
							{
								modelElement->set_name( (::std::string)attrib_elem.get<::std::string>() );
							}
						}
						break;
						
					case ::arch::ISN::type_id :
						{	
							auto * modelElement = dynamic_cast<::arch::ISN*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("link");
							
							if( ref_elem.is<picojson::array>() )
							{
								as_array = ref_elem.get<picojson::array>();	
								std::vector<::arch::ISN*> as_vector(as_array.size());
								for(size_t i = 0 ; i < as_array.size() ; ++i)
								{
									int32_t id = (int32_t)as_array[i].get<int64_t>();
									as_vector[i] = dynamic_cast<::arch::ISN*>(modelElements[id]);
								}
								modelElement->set_link(as_vector);
							}
							attrib_elem = elem.get("name");
							
							if( attrib_elem.is<::std::string>() )
							{
								modelElement->set_name( (::std::string)attrib_elem.get<::std::string>() );
							}
						}
						break;
						
					case ::arch::ICL::type_id :
						{	
							auto * modelElement = dynamic_cast<::arch::ICL*>(modelElements[id]);
							picojson::value ref_elem;
							picojson::value attrib_elem;
							picojson::array as_array;
							
							ref_elem = elem.get("cnn");
							
							if( ref_elem.is<int64_t>() )
							{
								modelElement->set_cnn(
									dynamic_cast<::arch::ISN*>(modelElements[(int32_t)ref_elem.get<int64_t>()])
								);
							}
							attrib_elem = elem.get("countReachableSN");
							
							if( attrib_elem.is<int64_t>() )
							{
								modelElement->set_countReachableSN( (int)attrib_elem.get<int64_t>() );
							}
							attrib_elem = elem.get("name");
							
							if( attrib_elem.is<::std::string>() )
							{
								modelElement->set_name( (::std::string)attrib_elem.get<::std::string>() );
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

