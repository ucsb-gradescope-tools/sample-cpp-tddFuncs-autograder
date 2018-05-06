#include <iostream>
using namespace std;

#include "add.h"

int main(int argc, char const *argv[])
{
  cout << "Enter an integer value for a: ";
  int a;
  if (!(cin >> a)) {
    cout << "Not an integer!" << endl;
    return 0;
  }
  
  cout << "Enter an integer value for b: ";
  int b;
  if (!(cin >> b)) {
    cout << "Not an integer!" << endl;
    return 0;
  }
  
  cout << a << " + " << b << " = " << addEm(a,b) << endl;
  
  return 0;
}
