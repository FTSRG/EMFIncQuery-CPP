#include <iostream>
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Query/SzilardDerived.h"
#include "model/factory_def.h"
#include "Viatra/Query/Query/QueryQueryGroup.h"

const int tartalyID = 1;
const int szilardID = 2;
using namespace factory;
using namespace Viatra::Query;
using namespace Viatra::Query::Query;
using namespace std;

void print(Tartaly* ptr){
	
	if(ptr != nullptr && ptr->allapot != nullptr)
		cout << "Tartaly ID:" << ptr->ID << " halmazallapot ID: " << ptr->allapot->ID << endl;
    else if(ptr != nullptr) cout << "Tartaly ID: " << ptr->ID << " Halmazallapot nem ismert" <<endl;
}

int main(int argc, char **argv)
{	
	Tartaly* t = new Tartaly(); t->ID = tartalyID;
	Viz* v = new Viz(); t->tarol = v;
	
	Szilard* sz = new Szilard(); sz->ID = szilardID;
	Folyekony* f = new Folyekony(); f->ID = 3;
	Goz* g = new Goz(); g->ID = 4;
	
	ModelRoot modelRoot;
	cout << "Homerseklet = -20 C" << endl;
    SzilardUpdate<ModelRoot>::update(modelRoot, tartalyID, szilardID, -20);
	print(t);
	cout << "Homerseklet = 0 C" << endl;
    SzilardUpdate<ModelRoot>::update(modelRoot, tartalyID, szilardID, 0);
	print(t);
    cout << "------------Reset------------" << endl;
    t->allapot = nullptr;
    cout << "Homerseklet = 0 C" << endl;
    SzilardUpdate<ModelRoot>::update(modelRoot, tartalyID, szilardID, 0);
    print(t);
	return 0;
}
