
#ifndef _MODELROOT__H__
#define _MODELROOT__H__

#include<map>
#include"Viatra/Query/Model/ModelElement.h"


class ModelRoot
{
public:
	ModelRoot(const char * configjson);
	~ModelRoot()
	{
		FreeAllModelElement();
	}

private:
	void FreeAllModelElement();
	std::map<int, Viatra::Query::Model::ModelElement*> modelElements;


};



#endif