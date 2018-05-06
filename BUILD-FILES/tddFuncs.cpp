#include "tddFuncs.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cerr;
using std::ostringstream;

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


void addTest(double score,
	     double max_score,
	     std::string name,
	     std::string output) {}


void START_GROUP(double points, const char* const name){}
void END_GROUP(){}
