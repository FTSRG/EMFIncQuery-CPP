#pragma once

namespace Viatra {
	namespace Query {
		namespace Model {

			// Interface for an object which can provide access to a field of a Model Element
			class IModelElemService
			{
			public:
				IModelElemService() {}
				virtual ~IModelElemService() {}
				/*
				template<typename T> void setReference( int id, int fieldID, T* reference ){
					
				}*/

			protected:
				virtual std::string getData(int id, int FieldID) = 0;
				virtual void setData(int id, int FieldID, std::string ser_data) = 0;
				/*
				// Serialize datatype
				template<typename T>
				static std::string serializeAttributeToString(T data)
				{
					std::string ret;
					std::stringstream ss;
					ss < data;
					ss >> ret;
					return ret;
				}
				// serialize reference
				template<typename T>
				static std::string serializeReferenceToString(T data)
				{
					std::string ret;
					std::stringstream ss;
					ss << data->id();
					ss >> ret;
					return ret;
				}
				// Parse datatype
				template<typename T>
				static T parseAttributeFromString(std::string data)
				{
					T ret;
					std::stringstream ss;
					ss << data;
					ss >> ret;
					return ret;
				}
				// Parse reference
				template<typename T>
				static T parseReferenceFromString(std::string data)
				{
					int id;
					std::stringstream ss;
					ss << data;
					ss >> id;
					return dynamic_cast<T>(modelRoot->findModelElementByID(id));
				}*/
			};
		}
	}
}
