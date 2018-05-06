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

void assertEquals(const char* expected, 
                  const char* actual, 
                  std::string message) {
  assertEquals(std::string(expected), std::string(actual), message);
}

void assertEquals(const char* expected, 
                  std::string actual, 
                  std::string message) {

  assertEquals(std::string(expected), actual, message);

}


void assertTrue(bool expression,
		std::string message) {

  std::ostringstream ea;
  
  if (expression) {
    ea << "| PASSED: " << message << endl;
  } else {
    ea << "|   FAILED: " << message << endl;
  }
  cout << ea.str();
}

void START_GROUP(double points, const char* const name){}
void END_GROUP(){}
