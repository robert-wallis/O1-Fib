#include <iostream>
#include <string>
#include "fib.hpp"

using namespace std;

void usage(const char* progName) {
	cout << "Usage: " << progName 
		 << " N" << endl 
		 << "\t N \t: the position in the fibonacci sequence" << endl << endl;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		usage(argv[0]);
		return -1;
	}
	int fibN = strtol(argv[1], nullptr, 10);
	if (fibN <= 0) {
		usage(argv[0]);
		return -1;
	}

	cout << "fib(" << fibN << ") is: ";
	cout << fib(fibN) << endl;

	return 0;
}
