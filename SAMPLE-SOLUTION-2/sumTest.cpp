#include "add.h"
#include "tddFuncs.h"


int main() {

  START_GROUP(10.0, "tests for addEm from " __FILE__ );
  
  ASSERT_EQUALS(5,  addEm(2,3));
  ASSERT_EQUALS(0,  addEm(-3,3));
  ASSERT_EQUALS(15, addEm(10,5));

  END_GROUP();

  START_GROUP(10.0, "tests for addEm from " __FILE__ );

  ASSERT_EQUALS(9,  addEm(4,5));
  ASSERT_EQUALS(2,  addEm(-3,5));
  ASSERT_EQUALS(1, addEm(0,1));

  END_GROUP();

  // Ungrouped tests
  
  ASSERT_EQUALS(29,  addEm(4,25));
  ASSERT_EQUALS(32,  addEm(-3,35));
  ASSERT_EQUALS(41, addEm(0,41));

  
  return 0;
}
