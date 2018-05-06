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

template <class T, class G>
  void assertEquals(T expected, 
		    T actual, 
		    G message) {
  std::ostringstream ea;
  if (expected==actual) {
    ea << "| PASSED: " << message << std::endl;
  } else {
    ea << "|   FAILED: " << message 
       << " Expected: " << expected << " Actual: " << actual << std::endl;
  }
  std::cout << ea.str();
}

#define ASSERT_EQUALS(expected,actual) assertEquals(expected,actual,#actual)
#define ASSERT_TRUE(expression) assertTrue(expression,#expression)
 
void assertTrue(bool expression, std::string message="");

void START_GROUP(double points, const char* const name);
void END_GROUP();

#endif // TDDFUNCS_H
