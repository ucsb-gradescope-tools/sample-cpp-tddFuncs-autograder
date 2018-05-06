#include <iostream>
using namespace std;

#include "add.h"

void usage() {
  cerr << "usage: ./addCmdLine a b" << endl;
}

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    usage();
    return 1;
  }
  
  try {
    int a = stoi(argv[1]);
    int b = stoi(argv[2]);
    cout << "sum = " << addEm(a,b) << endl;
  } catch(invalid_argument e ) {
    usage();
    return 1;
  }
  
  return 0;
}
