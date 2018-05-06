#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream f("input.txt");

	if (f.is_open()) {
		string line;
		getline(f, line);
		cout << line.length() << endl;
	}

	return 0;
}