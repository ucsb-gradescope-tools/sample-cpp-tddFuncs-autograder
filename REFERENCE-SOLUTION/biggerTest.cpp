#include "add.h"
#include "tddFuncs.h"

int main() {


  START_GROUP(20.0, "tests for bigger from " __FILE__ );
  
  ASSERT_EQUALS(3, bigger(2,3));
  ASSERT_EQUALS(3, bigger(-3,3));
  ASSERT_EQUALS(6, bigger(6,-6));
  ASSERT_EQUALS(10,bigger(10,5));
  ASSERT_EQUALS(10,bigger(10,5));
  
  END_GROUP();


  // ungrouped tests
  
  ASSERT_EQUALS(9, bigger(2,9));
  ASSERT_EQUALS(7, bigger(-3,7));
  ASSERT_EQUALS(16, bigger(16,4));

  return 0;
}
