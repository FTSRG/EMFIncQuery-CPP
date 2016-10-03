#pragma once

#include"../Model/IModelElemService.h"

#include<stdint.h>
#include<string>

namespace Viatra {
	namespace Query {
		namespace Distributed {
			class QueryService;

			class Node : public Model::IModelElemService
			{
			public:
				Node(std::string name, std::string ip, uint16_t port)
					: _name(name)
					, _ip(ip)
					, _port(port)
				{}
				uint16_t port() { return _port; }
				std::string name() { return _name; }
				std::string ip() { return _ip; }

			private:
				std::string _name;
				std::string _ip;
				uint16_t _port;
			};
		}
	}

}
