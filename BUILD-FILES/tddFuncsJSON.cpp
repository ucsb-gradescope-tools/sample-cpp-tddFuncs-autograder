#include "tddFuncs.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <vector>
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::ostringstream;

#include <json/json.h> // from jsoncpp library (https://github.com/open-source-parsers/jsoncpp)

#define FILENAME "results.json"


class GradescopeReporter {

private:
  struct TestCase {
    double score;
    double max_score;
    std::string name;
    std::string output;
  };
  ifstream resultsIn;
  ofstream resultsOut;
  Json::Value root;
  bool inGroup;
  double groupMax;
  const char* groupName;
  std::vector<TestCase> testGroup;
  
public:
  GradescopeReporter() : inGroup(false) {
    resultsIn.open(FILENAME);
    if (resultsIn.fail()) {
      makeEmptyTestsArray();
    } else {
      resultsIn >> root; // read results.json into root
    }
  }
  
  ~GradescopeReporter() {
    if (inGroup) {
      std::cerr << "WARNING: MISSING END_GROUP for START_GROUP(" << groupMax << "," << groupName <<"); AUTOMATICALLY CALLED" << std::endl;
      END_GROUP();
    }
    resultsOut.open(FILENAME);
    resultsOut << root << endl;
    resultsOut.close();    
  }

  void makeEmptyTestsArray() {
    Json::Value emptyArray;
    emptyArray.append(Json::Value::null);
    emptyArray.clear();
    root["tests"] = emptyArray;
  }
  
  void addTestToJSON(int score,
          int max_score,
          std::string name,
          std::string output) {
    Json::Value newTest;
    newTest["score"] = score;
    newTest["max_score"] = max_score;
    newTest["name"] = name;
    newTest["output"] = output;
    root["tests"].append(newTest);
  }

  void addTestToGroup(double score,
          double max_score,
          std::string name,
          std::string output) {
    TestCase tc = {score, max_score, name, output};
    testGroup.push_back(tc);
  }
  
  void addTest(double score,
			    double max_score,
			    std::string name,
			    std::string output) {

    if (inGroup) {
      addTestToGroup(score, max_score, name, output);
    } else {
      addTestToJSON(score, max_score, name, output);
    }
  }

  void startgroup(double points, const char* const name){
    if (inGroup) {
      std::cerr << "ERROR: NESTED GROUPS NOT ALLOWED" << std::endl;
      exit(1);
    }
    inGroup = true;
    groupMax = points;
    groupName = name;
    assert(testGroup.empty());
    

  }
  void endgroup(){
    if (!inGroup) {
      std::cerr << "ERROR: END_GROUP HAS NO MATCHING START_GROUP" << std::endl;
      exit(1);
    }
    inGroup = false;
    
    double totalGroupPossible = 0.0;
    double totalGroupActual = 0.0;  
    std::string combinedMessage = "";

    for (auto tc: testGroup) {
      totalGroupActual += tc.score;
      totalGroupPossible += tc.max_score;

      combinedMessage += tc.output;
    }
    if(totalGroupPossible != 0.0){
      double scaledActual = (totalGroupActual / totalGroupPossible ) * groupMax;

      addTestToJSON(scaledActual, groupMax, groupName, combinedMessage);

      
    }
    testGroup.clear();
  }
  
};

static GradescopeReporter gsr; // constructor executes before main, destructor after


void assertEquals(const char* expected, 
                  const char* actual, 
                  std::string message) {
  /*std::ostringstream ea;
  //ea << "Expected: " << expected << " Actual: " << actual; 
    
  if (strcmp(expected, actual)==0) {
    ea << "PASSED: " << message << std::endl;
    
    addTest(1,1,message, ea.str());
  } else {
    ea << "   FAILED: " << message << std::endl
         << "     " << "Expected: " << expected << " Actual: " << actual << std::endl;
    addTest(0,1,message, ea.str());
  }
  std::cout << ea.str();*/
  assertEquals(std::string(expected), std::string(actual), message);
}

void assertEquals(const char* expected, 
                  std::string actual, 
                  std::string message) {

  assertEquals(std::string(expected), actual, message);

}



void addTest(double score,
          double max_score,
          std::string name,
          std::string output){

  gsr.addTest(score, max_score,name, output);

}

void assertTrue(bool expression,
                  std::string message) {

  std::ostringstream ea;
    
  if (expression) {
    ea << "| PASSED: " << message << endl;
    gsr.addTest(1,1,message,ea.str());
  } else {
    ea << "|   FAILED: " << message << endl;
    gsr.addTest(0,1,message,ea.str());
  }

  cout << ea.str();


}

void START_GROUP(double points, const char* const name){
  gsr.startgroup(points, name);
}

void END_GROUP(){
  gsr.endgroup();
  
}
