#include <iostream>
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Query/SzilardDerived.h"
#include "model/factory_def.h"

const int tartalyID = 1;
const int szilardID = 2;

void print(Tartaly* ptr){
	using namespace std;
	if(ptr != nullptr && ptr->allapot != nullptr)
		cout << "Tartaly ID:" << ptr->ID << " halmazallapot ID: " << ptr->allapot->ID << endl;
}

int main(int argc, char **argv)
{
	using namespace factory;
	
	Tartaly* t = new Tartaly(); t->ID = tartalyID;
	Viz* v = new Viz(); t->tarol = v;
	
	Szilard* sz = new Szilard(); sz.ID = szilardID;
	Folyekony* f = new Folyekony(); f.ID = 3;
	Goz* g = new Goz(); g.ID = 4;
	
	ModelRoot modelRoot;
	
	SzilardUpdater<ModelRoot>::update(modelRoot, tartalyID, szilardID, -20);
	print(t);
	
	return 0;
}
