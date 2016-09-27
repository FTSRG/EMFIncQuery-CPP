#pragma once

namespace Viatra {
	namespace Query {
		namespace Model {
			/*
			class Field
			{
				virtual void set()
			};*/

			template<typename CLASS>
			class MetaData {

				template<typename TYPE, TYPE CLASS::*MP>
				class FieldData : Field
				{


				};

				std::vector<Field> fields;





			};

		}
	}
}