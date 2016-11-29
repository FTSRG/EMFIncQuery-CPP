// **************************************
//
// COPY ME NEXT TO GENERATED MAKEFILE
//
// **************************************
#include "gtest/gtest.h"
#include "SNCLRuntimeTest.h"
#include "SNCLIteratorTest.h"
/**
 * @author Krisztian Toth
 */
/*
 * Unit testing for generated code from queries below.
 * package hu.bme.mit.localsearch.cpp.tool.featuretest.query
 * import "http://arch.ecore/model"
 * @Bind(parameters={S1})
 * pattern linked(S1,S2){SN(S1);	SN(S2);SN.link(S1,S2);} or
 * {SN(S1); SN(S2); SN.link(S2,S1);}
 *
 * pattern pconnected(C1,C2){SN(S1);	CL.cnn(C1,S1); CL.cnn(C2,S1);} or
 * {	CL.cnn(C1,S1); CL.cnn(C2,S2); find linked+(S1,S2);}
 */

 namespace Iterator {
  /*
   * Simple Test for uninitialized modell
   * Here the framework sets up the common environmet.
   */
   TEST_F(SNCLIteratorTest, EmptyInstances){
     TearDown();
     auto linkedMatches = linkedMatcher.matches();
     ASSERT_EQ(linkedMatches.size(), 0);
     auto pconnectedMatches = pconnectedMatcher.matches();
     ASSERT_EQ(pconnectedMatches.size(), 0);
   }

   /*
    * Testing hot deletion of a SN.
    * After deletation, the expected behavior is that the deleted object not included in any match.
    * The user responsible for delete dead pointers from runtime object hierarchy.
    * !! If want to use in distributed systems you need to ensure garbage collection's operation is atomic.
    */
    TEST_F(SNCLIteratorTest,runtimeDeleteSN){
      //Delete dead pointers before deletion
      std::string deletedName = deletableSN->name;
      snStore.remove(deletableSN);
      for(auto sn : snStore)
        for(auto it = sn->link.begin(); it != sn->link.end();++it)
          if(*it == deletableSN) sn->link.erase(it);
      for(auto cl : clStore)
        if(cl->cnn == deletableSN) cl->cnn = nullptr;
     //delete the object
      delete deletableSN;
      try{
        auto queriedMatches = pconnectedMatcher.matches();
        for(auto match : queriedMatches){
          if(match.C1->name == "C5" && match.C2->name == "C6") FAIL() << "Not properly handled one SN's delete. SN.name = " << deletedName;
          if(match.C1->name == "C6" && match.C2->name == "C5") FAIL() << "Not properly handled one SN's delete. SN.name = " << deletedName;
        }
      }catch(...){
        FAIL() << "Unhandled exception";
      }
    }

   /*
    * Testing hot deletion of a CL.
    * After deletation, the expected behavior is that the deleted object not included in any match.
    * The user responsible for delete dead pointer from runtime object hierarchy.
    * !! If want to use in distributed systems you need to ensure garbage collection's operation is atomic.
    */
    TEST_F(SNCLIteratorTest, runtimeDeleteCL){
      std::string deletedName = deletableCL->name;
      clStore.remove(deletableCL);
      delete deletableCL;
      try{
        auto queriedMatches = pconnectedMatcher.matches();
        for(auto match : queriedMatches){
          if(match.C1->name == "C2" || match.C2->name == "C2") FAIL() << "Not properly handled one CN's delete. CN.name = " << deletedName;
        }
      }catch(...){
        FAIL() << "Unhandled exception";
      }
    }

  /* Test that the LinkedMatcher found all matches and checks that really linked one to the other.
   * First checks that the number of matches is correct.
   * Secondly checks the validity of matches.
   * Thirdly checks that the numbor of SNs in the ring is correct.
   */
   TEST_F(SNCLIteratorTest, linkedQueryUnboundTest) {
     std::unordered_set<::std::string> checkList; //Stores the members of the queried match's SN's names.
     auto matches = linkedMatcher.matches();
     ASSERT_EQ(numOfLinks,matches.size());
     for(auto m : matches){
       checkList.insert(m.S1->name);
       checkList.insert(m.S2->name);
       if(!SNCLIteratorTest::validMatch(m)) FAIL() << "Unbound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
     }
     int i = 0;
     for(auto name : checkList) i++;
     ASSERT_EQ(numOfRingMembers, checkList.size());
   }
  /*
   * Testing matcher function with one parameter, signature matches(::arch::SN* S1).
   * It iterates over the SN instances and query the linked SN's.
   * Checks the cardinality of linked SN's and checks the validity of found match.
   */
   TEST_F(SNCLIteratorTest, linkedQuerySimpleBoundTest) {
     for(auto sn : snStore){
       auto matches = linkedMatcher.matches(sn);
       if(sn->name != "S5"){
         ASSERT_EQ(2,matches.size());
         for(auto m : matches){
           if(!SNCLIteratorTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
         }
       }
       else{
         ASSERT_EQ(0,matches.size());
       }
     }
   }
  /*
   * Testing matcher function with two parameter, signature matches(::arch::SN* S1, ::arch::SN* S2).
   * It checks every SN with every SN (cartesian product).
   * If the matcher finds connection, then checks it.
   * If the matcher finds no connection, then checks it.
   */
 TEST_F(SNCLIteratorTest, linkedQueryDoubleBoundTest) {
     for(auto s1 : snStore){
       for(auto s2 : snStore){
         auto matches = linkedMatcher.matches(s1,s2);
         if(matches.size() > 0)
           for(auto m : matches){
             if(!SNCLIteratorTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
           }
         else{
           Sncl_iterator::LinkedMatch m1;
           m1.S1 = s1;
           m1.S2 = s2;
           if(SNCLIteratorTest::validMatch(m1)) FAIL() << "Query didn't find a match: "<< m1.S1->name << "-" << m1.S2->name;
         }
       }
     }
   }
  /*
   * Testing for pconnected functionality.
   * It generates every combination of CL's, then filters the predefined combinations.
   * After filtering theoretically the queried and filtered set contains the same elements.
   */
   TEST_F(SNCLIteratorTest, pconnectedUnboundTest){
     //Generate combinations
     std::unordered_set<Sncl_iterator::PconnectedMatch> combinationOfCls;
     for(auto c1 : clStore){
       for(auto c2 : clStore){
         Sncl_iterator::PconnectedMatch m; m.C1 = c1; m.C2 = c2;
         combinationOfCls.insert(m);
       }
     }
     //Filtering
     auto queriedMatches = pconnectedMatcher.matches();
     //notConnectedSet contains all match (CL-CL connection) is not expected to find, initialized during setup environment
     for(auto notConnectedMatch: notConnectedSet){
       auto it = combinationOfCls.find(notConnectedMatch);
       ASSERT_NE(it,combinationOfCls.end());
       combinationOfCls.erase(it);
       it = queriedMatches.find(notConnectedMatch);
       //ASSERT_EQ(it, queriedMatches.end());(
       if(it != queriedMatches.end()) FAIL() << "Query found a match, that doesn't fit: " << it->C1->name << "-" << it->C2->name << std::endl;
     }
     //Check equality
     for(auto match : combinationOfCls){
       auto it = queriedMatches.find(match);
       if(it == queriedMatches.end()) FAIL() << "Query didn't find a match: " << match.C1->name << "-" << match.C2->name << std::endl;
     }
   }

   TEST_F(SNCLIteratorTest, countLinksUnboundTest){
     //Test initialized environment
     auto matches = countLinksMatcher.matches();
     ASSERT_EQ(matches.size(), clStore.size());
     for(auto && m : matches){
       if(m.numOfSN == 2 || m.numOfSN == 0){ // C1,C2,C3,C4,C5,C6
         if(m.numOfCL == 4){ //C1,C2,C3,C4
           auto str = m.C1->name;
           if(str != "C1" && str != "C2" && str != "C3" && str != "C4") FAIL() << "CountLinks Init error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
         }else if(m.numOfCL == 2){ //C5,C6
           auto str = m.C1->name;
           if(str != "C5" && str != "C6") FAIL() << "CountLinks Init error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
         }
       }else{
         FAIL() << "CountLinks Init error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
       }
     }
     //Test modification - new CL
     ::arch::CL* c2 = nullptr;
     auto c7 = new ::arch::CL(); c7->name = "C7";
     clStore.push_back(c7);
     for(auto cl : clStore) if(cl->name == "C2") c2 = cl;
     ASSERT_NE(c2, nullptr);
     c7->cnn = c2->cnn;
     matches = countLinksMatcher.matches();
     ASSERT_EQ(matches.size(), clStore.size());
     for(auto m : matches){
       auto str = m.C1->name;
       if((str == "C1" || str == "C2" || str == "C3" || str == "C4" || str == "C7" ) && m.numOfSN == 2 && m.numOfCL == 5);
       else if(str != "C5" && str != "C6") FAIL() << "CountLinks Modified  error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
     }
     //Test modification - new SN
     auto s2 = c2->cnn;
     auto s6 = new ::arch::SN(); s6->name = "S6";
     snStore.push_back(s6);
     s2->link.push_back(s6);
     matches = countLinksMatcher.matches();
     ASSERT_EQ(matches.size(), clStore.size());
     for(auto m : matches){
       auto str = m.C1->name;
       if((str == "C2" || str == "C7" )) if(m.numOfSN == 3 && m.numOfCL == 5);
       else FAIL() << "CountLinks Modified error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
     }
   }
   TEST_F(SNCLIteratorTest, greaterThanOneSNConnectionUnboundTest){
     auto matches = greaterMatcher.matches();
     ASSERT_EQ(matches.size(), clStore.size()-2);
     for(auto& m : matches){
       auto name = m.C1->name;
       if(name != "C1" && name != "C2" && name != "C3" && name != "C4")
         FAIL() << "GreaterThanOneSNConnection init " << m.C1->name << "was caught with greater than one SN connection.";
     }
   }
/*
 * Not okay, because PConnectedMatcher finds C6-C6 match.
 *
   TEST_F(SNCLIteratorTest, isolatedCLUnboundTest){
     auto matches = isolatedCLMatcher.matches();
     if(matches.size() != 0) FAIL() << "Isolated matcher found invalid match: " << matches.begin()->C1->name;
     ::arch::CL* forDelete = nullptr;
     for(auto cl : clStore){
       if(cl->name == "C5") forDelete = cl;
     }
     clStore.remove(forDelete);
     delete forDelete;
     matches = isolatedCLMatcher.matches();
	if(matches.size() > 1) FAIL() << "Isolated matcher found more matches than expected";
     	else if(matches.size() != 1) FAIL() << "Isolated match didn't found the C6 Node." << matches.size();
              else ASSERT_EQ(matches.begin()->C1->name, "C6");
   }*/

   TEST_F(SNCLIteratorTest, isolatedSNUnboundTest){
     auto matches = isolatedSNMatcher.matches();
     ASSERT_EQ(matches.size(), 2);
     for(auto& m : matches){
       if(m.C1->cnn->name != "S5") FAIL() << "IsolatedSN error: Found an unexpected match: " << m.C1->name << "--" << m.C1->cnn->name;
     }
     auto s6 = new ::arch::SN(); s6->name = "S6";
     snStore.push_back(s6);
     ::arch::SN* s5 = nullptr;
     for(auto sn : snStore){
       if(sn->name == "S5") s5 = sn;
     }
     ASSERT_NE(s5, nullptr);
     s6->link.push_back(s5);
     matches = isolatedSNMatcher.matches();
     ASSERT_EQ(matches.size(),0);
   }

   TEST_F(SNCLIteratorTest, notInRingUnboundTest){
     auto matches = notInRingMatcher.matches();
     ASSERT_EQ(matches.size(),2);
     for(auto& m : matches){
       auto name = m.C1->name;
       if(name != "C5" && name != "C6") FAIL() << "NotInRing error: found an unexpected match " << m.C1->name;
     }
   }
   TEST_F(SNCLIteratorTest, NumEqualityWithMemberUnboundTest){
     auto matches = numEqualWithMemberMatcher.matches();
     ASSERT_EQ(matches.size(), 2);
     for(auto cl : clStore) cl->countReachableSN = 2;
     matches = numEqualWithMemberMatcher.matches();
     ASSERT_EQ(matches.size(), 4);
     for(auto cl : clStore) cl->countReachableSN = 5;
     matches = numEqualWithMemberMatcher.matches();
     ASSERT_EQ(matches.size(), 0);
   }
   TEST_F(SNCLIteratorTest, NumInEqualityWithMemberUnboundTest){
     auto matches = numInEqualWithMemberMatcher.matches();
     ASSERT_EQ(matches.size(),4);
     for(auto cl : clStore) cl->countReachableSN = 2;
     matches = numInEqualWithMemberMatcher.matches();
     ASSERT_EQ(matches.size(),2);
     for(auto cl : clStore) cl->countReachableSN = 5;
     matches = numInEqualWithMemberMatcher.matches();
     ASSERT_EQ(matches.size(),clStore.size());
   }
   TEST_F(SNCLIteratorTest, ringMembersUnboundTest){
     auto matches = ringMemberMatcher.matches();
     ASSERT_EQ(matches.size(),4);
     for(auto && m : matches){
       auto str = m.C1->name;
       if(str != "C1" && str != "C2" && str != "C3" && str != "C4") FAIL() << "RingMembers Init error: unexpected ring member " << m.C1->name;
     }
   }
 }
namespace Runtime {
 /*
  * Simple Test for uninitialized modell
  * Here the framework sets up the common environmet.
  */
  TEST_F(SNCLRuntimeTest, EmptyInstances){
    TearDown();
    auto linkedMatches = linkedMatcher.matches();
    ASSERT_EQ(linkedMatches.size(), 0);
    auto pconnectedMatches = pconnectedMatcher.matches();
    ASSERT_EQ(pconnectedMatches.size(), 0);
  }

  /*
   * Testing hot deletion of a SN.
   * After deletation, the expected behavior is that the deleted object not included in any match.
   * The user responsible for delete dead pointers from runtime object hierarchy.
   * !! If want to use in distributed systems you need to ensure garbage collection's operation is atomic.
   */
   TEST_F(SNCLRuntimeTest,runtimeDeleteSN){
     //Delete dead pointers before deletion
     std::string deletedName = deletableSN->name;
     snStore.remove(deletableSN);
     for(auto sn : snStore)
       for(auto it = sn->link.begin(); it != sn->link.end();++it)
         if(*it == deletableSN) sn->link.erase(it);
     for(auto cl : clStore)
       if(cl->cnn == deletableSN) cl->cnn = nullptr;
    //delete the object
     delete deletableSN;
     try{
       auto queriedMatches = pconnectedMatcher.matches();
       for(auto match : queriedMatches){
         if(match.C1->name == "C5" && match.C2->name == "C6") FAIL() << "Not properly handled one SN's delete. SN.name = " << deletedName;
         if(match.C1->name == "C6" && match.C2->name == "C5") FAIL() << "Not properly handled one SN's delete. SN.name = " << deletedName;
       }
     }catch(...){
       FAIL() << "Unhandled exception";
     }
   }

  /*
   * Testing hot deletion of a CL.
   * After deletation, the expected behavior is that the deleted object not included in any match.
   * The user responsible for delete dead pointer from runtime object hierarchy.
   * !! If want to use in distributed systems you need to ensure garbage collection's operation is atomic.
   */
   TEST_F(SNCLRuntimeTest, runtimeDeleteCL){
     std::string deletedName = deletableCL->name;
     clStore.remove(deletableCL);
     delete deletableCL;
     try{
       auto queriedMatches = pconnectedMatcher.matches();
       for(auto match : queriedMatches){
         if(match.C1->name == "C2" || match.C2->name == "C2") FAIL() << "Not properly handled one CN's delete. CN.name = " << deletedName;
       }
     }catch(...){
       FAIL() << "Unhandled exception";
     }
   }

 /* Test that the LinkedMatcher found all matches and checks that really linked one to the other.
  * First checks that the number of matches is correct.
  * Secondly checks the validity of matches.
  * Thirdly checks that the numbor of SNs in the ring is correct.
  */
  TEST_F(SNCLRuntimeTest, linkedQueryUnboundTest) {
    std::unordered_set<::std::string> checkList; //Stores the members of the queried match's SN's names.
    auto matches = linkedMatcher.matches();
    ASSERT_EQ(numOfLinks,matches.size());
    for(auto m : matches){
      checkList.insert(m.S1->name);
      checkList.insert(m.S2->name);
      if(!SNCLRuntimeTest::validMatch(m)) FAIL() << "Unbound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
    }
    int i = 0;
    for(auto name : checkList) i++;
    ASSERT_EQ(numOfRingMembers, checkList.size());
  }
 /*
  * Testing matcher function with one parameter, signature matches(::arch::SN* S1).
  * It iterates over the SN instances and query the linked SN's.
  * Checks the cardinality of linked SN's and checks the validity of found match.
  */
  TEST_F(SNCLRuntimeTest, linkedQuerySimpleBoundTest) {
    for(auto sn : snStore){
      auto matches = linkedMatcher.matches(sn);
      if(sn->name != "S5"){
        ASSERT_EQ(2,matches.size());
        for(auto m : matches){
          if(!SNCLRuntimeTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
        }
      }
      else{
        ASSERT_EQ(0,matches.size());
      }
    }
  }
 /*
  * Testing matcher function with two parameter, signature matches(::arch::SN* S1, ::arch::SN* S2).
  * It checks every SN with every SN (cartesian product).
  * If the matcher finds connection, then checks it.
  * If the matcher finds no connection, then checks it.
  */
TEST_F(SNCLRuntimeTest, linkedQueryDoubleBoundTest) {
    for(auto s1 : snStore){
      for(auto s2 : snStore){
        auto matches = linkedMatcher.matches(s1,s2);
        if(matches.size() > 0)
          for(auto m : matches){
            if(!SNCLRuntimeTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
          }
        else{
          Sncl_runtime::LinkedMatch m1;
          m1.S1 = s1;
          m1.S2 = s2;
          if(SNCLRuntimeTest::validMatch(m1)) FAIL() << "Query didn't find a match: "<< m1.S1->name << "-" << m1.S2->name;
        }
      }
    }
  }
 /*
  * Testing for pconnected functionality.
  * It generates every combination of CL's, then filters the predefined combinations.
  * After filtering theoretically the queried and filtered set contains the same elements.
  */
  TEST_F(SNCLRuntimeTest, pconnectedUnboundTest){
    //Generate combinations
    std::unordered_set<Sncl_runtime::PconnectedMatch> combinationOfCls;
    for(auto c1 : clStore){
      for(auto c2 : clStore){
        Sncl_runtime::PconnectedMatch m; m.C1 = c1; m.C2 = c2;
        combinationOfCls.insert(m);
      }
    }
    //Filtering
    auto queriedMatches = pconnectedMatcher.matches();
    //notConnectedSet contains all match (CL-CL connection) is not expected to find, initialized during setup environment
    for(auto notConnectedMatch: notConnectedSet){
      auto it = combinationOfCls.find(notConnectedMatch);
      ASSERT_NE(it,combinationOfCls.end());
      combinationOfCls.erase(it);
      it = queriedMatches.find(notConnectedMatch);
      //ASSERT_EQ(it, queriedMatches.end());(
      if(it != queriedMatches.end()) FAIL() << "Query found a match, that doesn't fit: " << it->C1->name << "-" << it->C2->name << std::endl;
    }
    //Check equality
    for(auto match : combinationOfCls){
      auto it = queriedMatches.find(match);
      if(it == queriedMatches.end()) FAIL() << "Query didn't find a match: " << match.C1->name << "-" << match.C2->name << std::endl;
    }
  }

  TEST_F(SNCLRuntimeTest, countLinksUnboundTest){
    //Test initialized environment
    auto matches = countLinksMatcher.matches();
    ASSERT_EQ(matches.size(), clStore.size());
    for(auto && m : matches){
      if(m.numOfSN == 2 || m.numOfSN == 0){ // C1,C2,C3,C4,C5,C6
        if(m.numOfCL == 4){ //C1,C2,C3,C4
          auto str = m.C1->name;
          if(str != "C1" && str != "C2" && str != "C3" && str != "C4") FAIL() << "CountLinks Init error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
        }else if(m.numOfCL == 2){ //C5,C6
          auto str = m.C1->name;
          if(str != "C5" && str != "C6") FAIL() << "CountLinks Init error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
        }
      }else{
        FAIL() << "CountLinks Init error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
      }
    }
    //Test modification - new CL
    ::arch::CL* c2 = nullptr;
    auto c7 = new ::arch::CL(); c7->name = "C7";
    clStore.push_back(c7);
    for(auto cl : clStore) if(cl->name == "C2") c2 = cl;
    ASSERT_NE(c2, nullptr);
    c7->cnn = c2->cnn;
    matches = countLinksMatcher.matches();
    ASSERT_EQ(matches.size(), clStore.size());
    for(auto m : matches){
      auto str = m.C1->name;
      if((str == "C1" || str == "C2" || str == "C3" || str == "C4" || str == "C7" ) && m.numOfSN == 2 && m.numOfCL == 5);
      else if(str != "C5" && str != "C6") FAIL() << "CountLinks Modified  error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
    }
    //Test modification - new SN
    auto s2 = c2->cnn;
    auto s6 = new ::arch::SN(); s6->name = "S6";
    snStore.push_back(s6);
    s2->link.push_back(s6);
    matches = countLinksMatcher.matches();
    ASSERT_EQ(matches.size(), clStore.size());
    for(auto m : matches){
      auto str = m.C1->name;
      if((str == "C2" || str == "C7" )) if(m.numOfSN == 3 && m.numOfCL == 5);
      else FAIL() << "CountLinks Modified error: " << m.C1->name << " numOfSN=" << m.numOfSN << " numOfCL=" << m.numOfCL;
    }
  }
  TEST_F(SNCLRuntimeTest, greaterThanOneSNConnectionUnboundTest){
    auto matches = greaterMatcher.matches();
    ASSERT_EQ(matches.size(), clStore.size()-2);
    for(auto& m : matches){
      auto name = m.C1->name;
      if(name != "C1" && name != "C2" && name != "C3" && name != "C4")
        FAIL() << "GreaterThanOneSNConnection init " << m.C1->name << "was caught with greater than one SN connection.";
    }
  }
/*
 * Not okay, because PConnectedMatcher finds C6-C6 match.
 *
  TEST_F(SNCLRuntimeTest, isolatedCLUnboundTest){
    auto matches = isolatedCLMatcher.matches();
    if(matches.size() != 0) FAIL() << "Isolated matcher found invalid match: " << matches.begin()->C1->name;
    ::arch::CL* forDelete = nullptr;
    for(auto cl : clStore){
      if(cl->name == "C5") forDelete = cl;
    }
    clStore.remove(forDelete);
    delete forDelete;
    matches = isolatedCLMatcher.matches();
    if(matches.size() == 0) FAIL() << "Isolated match didn't found the C6 Node.";
      else if(matches.size() > 1) FAIL() << "Isolated matcher found more matches than expected";
             else ASSERT_EQ(matches.begin()->C1->name, "C6");
  }*/
  TEST_F(SNCLRuntimeTest, isolatedSNUnboundTest){
    auto matches = isolatedSNMatcher.matches();
    ASSERT_EQ(matches.size(), 2);
    for(auto& m : matches){
      if(m.C1->cnn->name != "S5") FAIL() << "IsolatedSN error: Found an unexpected match: " << m.C1->name << "--" << m.C1->cnn->name;
    }
    auto s6 = new ::arch::SN(); s6->name = "S6";
    snStore.push_back(s6);
    ::arch::SN* s5 = nullptr;
    for(auto sn : snStore){
      if(sn->name == "S5") s5 = sn;
    }
    ASSERT_NE(s5, nullptr);
    s6->link.push_back(s5);
    matches = isolatedSNMatcher.matches();
    ASSERT_EQ(matches.size(),0);
  }

  TEST_F(SNCLRuntimeTest, notInRingUnboundTest){
    auto matches = notInRingMatcher.matches();
    ASSERT_EQ(matches.size(),2);
    for(auto& m : matches){
      auto name = m.C1->name;
      if(name != "C5" && name != "C6") FAIL() << "NotInRing error: found an unexpected match " << m.C1->name;
    }
  }
  TEST_F(SNCLRuntimeTest, NumEqualityWithMemberUnboundTest){
    auto matches = numEqualWithMemberMatcher.matches();
    ASSERT_EQ(matches.size(), 2);
    for(auto cl : clStore) cl->countReachableSN = 2;
    matches = numEqualWithMemberMatcher.matches();
    ASSERT_EQ(matches.size(), 4);
    for(auto cl : clStore) cl->countReachableSN = 5;
    matches = numEqualWithMemberMatcher.matches();
    ASSERT_EQ(matches.size(), 0);
  }
  TEST_F(SNCLRuntimeTest, NumInEqualityWithMemberUnboundTest){
    auto matches = numInEqualWithMemberMatcher.matches();
    ASSERT_EQ(matches.size(),4);
    for(auto cl : clStore) cl->countReachableSN = 2;
    matches = numInEqualWithMemberMatcher.matches();
    ASSERT_EQ(matches.size(),2);
    for(auto cl : clStore) cl->countReachableSN = 5;
    matches = numInEqualWithMemberMatcher.matches();
    ASSERT_EQ(matches.size(),clStore.size());
  }
  TEST_F(SNCLRuntimeTest, ringMembersUnboundTest){
    auto matches = ringMemberMatcher.matches();
    ASSERT_EQ(matches.size(),4);
    for(auto && m : matches){
      auto str = m.C1->name;
      if(str != "C1" && str != "C2" && str != "C3" && str != "C4") FAIL() << "RingMembers Init error: unexpected ring member " << m.C1->name;
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
