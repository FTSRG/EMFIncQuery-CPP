#pragma once

namespace Viatra {
	namespace Query {
		namespace Model {

			// Interface for an object which can provide access to a field of a Model Element
			class IModelElemService
			{
			public:
				virtual ~IModelElemService()
				{}
				/*
				virtual  getData(int id, int FieldID,) = 0;
				virtual void setData(int id, int FieldID, std::string ser_data) = 0;
				*/
			};
		}
	}
}
