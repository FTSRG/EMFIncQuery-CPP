
#include "ModelRoot.h"

#include<fstream>
#include<picojson.h>

#include<cyberPhysicalSystem/HostInstance.h>
#include<cyberPhysicalSystem/ApplicationInstance.h>

#include<Viatra/Query/Model/ModelElement.h>

using namespace cyberPhysicalSystem;
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

		for (auto & elem : elements)
		{
			bool is_remote = elem.get("node").get<std::string>() != localnode;
			std::string type = elem.get("type").get<std::string>();
			int id = static_cast<int>(elem.get("id").get<double>());
			if (modelElements.find(id) != modelElements.end())
				throw std::string("Identifier is already used");

			auto node = nullptr;

			if (type == "HostInstance")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new RemoteHostInstance(id, node))
					: dynamic_cast<ModelElement*>(new LocalHostInstance(id));
			else if (type == "ApplicationInstance")
				modelElements[id] = is_remote
					? dynamic_cast<ModelElement*>(new RemoteApplicationInstance(id, node))
					: dynamic_cast<ModelElement*>(new LocalApplicationInstance(id));
			else
				throw std::string("ModelElement type cannot be understood");
		}		
	}
	catch (std::string& str)
	{
		std::cout << str << std::endl;
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

