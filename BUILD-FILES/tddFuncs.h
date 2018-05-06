#ifndef TDDFUNCS_H
#define TDDFUNCS_H

#include <string>
#include <sstream>
#include <iostream>


void assertEquals(const char* expected, 
		  const char* actual, 
		  std::string message);

void assertEquals(const char* expected, 
		  std::string actual, 
		  std::string message);

void addTest(double score,
          double max_score,
          std::string name,
          std::string output);

template <class T, class G>
void assertEquals(T expected, 
                  T actual, 
                  G message) {
  std::ostringstream ea;
  //ea << "Expected: " << expected << " Actual: " << actual; 
    
  if (expected==actual) {
    ea << "| PASSED: " << message << std::endl;
    
    addTest(1,1,message, ea.str());
  } else {
    ea << "|   FAILED: " << message 
       << " Expected: " << expected << " Actual: " << actual << std::endl;
    addTest(0,1,message, ea.str());
  }
  std::cout << ea.str();
}


/*
void assertEquals(int expected, 
		  int actual, 
		  std::string message);
		  */

void START_GROUP(double points, const char* const name);

void END_GROUP();
#endif // TDDFUNCS_H
