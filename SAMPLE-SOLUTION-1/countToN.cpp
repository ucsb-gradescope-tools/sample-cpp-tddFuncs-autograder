#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		cerr << "usage: ./countToN int_to_count_to" << endl;
		return 0;
	}

	try {
		int n = stoi(argv[1]);
		for (int i = 0; i <= n; i++) {
			cout << i << endl;
		}
	} catch(invalid_argument e ) {
		cerr << "usage: ./countToN int_to_count_to" << endl;
	}

	return 0;
}