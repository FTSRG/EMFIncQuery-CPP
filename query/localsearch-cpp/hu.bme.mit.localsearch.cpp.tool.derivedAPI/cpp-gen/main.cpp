#include <cmath>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Matcher/ModelIndex.h"

#include "model/RailRoadModel_def.h"
#include "Ecore/ecore_def.h"
#include "Viatra/Query/DerivedFeatures/NearByMatcher.h"
#include "Viatra/Query/DerivedFeatures/NearByUpdater.h"

using namespace Viatra::Query;
using namespace Viatra::Query::DerivedFeatures;
using namespace std;
int main(){
  ModelRoot modelRoot;

	//auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
  cout << "Engine Created" << endl;
  //auto nearByMatcher = engine.matcher<NearByQuerySpecification>();
  cout << "Matcher Created" << endl;
  int robotPartID = 0; int trainID=0; double robX=0.0; double robY=0.0; double robZ=0.0; double trX=0.0; double trY=0.0; double trZ=0.0;
  //auto matches = nearByMatcher.matches(robotPartID, trainID, robX, robY, robZ, trX, trY, trZ);
	update<ModelRoot>(robotPartID, trainID, robX, robY, robZ, trX, trY, trZ);
	cout << "Matches Queried" << endl;
}