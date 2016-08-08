#include "Viatra/Query/QueryEngine.h"
#include "UnfinishedIndex.h"
#include "unfinished_def.h"
#include "Viatra/Query/UnfinishedQuery/EnumInEqualityMatcher.h"
#include "Viatra/Query/UnfinishedQuery/EnumInsideMatcher.h"

#include <cmath>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

using namespace std;
using namespace ::unfinished;
using namespace ::Viatra::Query;
using namespace ::Viatra::Query::UnfinishedQuery;

int main(){
  auto item1 = new Item(); item1->count = 1; item1->status = Status::UNFINISHED;
  auto item2 = new Item(); item2->count = 2; item2->status = Status::FINISHED;
  auto item3 = new Item(); item3->count = 3; item3->status = Status::INPROGRESS;

  auto engine = QueryEngine<Item>empty();
  auto inEqualityMatcher = engine.matcher<EnumInEqualityQuerySpecification>();

  cout << "InEqualityMatch size : " << inEqualityMatcher.matches().size() << endl;

  for(auto&& m : inEqualityMatcher.matches()){
    cout << "Match Found: Item" << m.I1->count << " - Status : " << m.Stat1 << endl;
  }

  auto insideMatcher = engine.matcher<EnumInsideQuerySpecification>();

  cout << "InsideMatcher size : " << insideMatcher.matches().size() << endl;

  for(auto&& m : insideMatcher.matches()){
    cout << "Match Found: Item" << m.I1->count << " - Status : " << m.Stat1 << endl;
  }

}
