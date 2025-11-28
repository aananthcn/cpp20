#include <iostream>

int main(int argc, char* argv[]) {
	std::cout << "Number of arguments: " << argc << std::endl;
	for (int i = 0; i < argc; ++i) {
		std::cout << "Argument " << i << ": " << argv[i] << std::endl;
	}
	return 0;
}

// NOTE: please look at the 8th argument and its output below
//
// PS C:\_E\labs\c_c++\cpp20> .\sect-19\cmdl_args.exe blah blah blah 2 4 % 98 (*&)
// Number of arguments: 9
// Argument 0: C:\_E\labs\c_c++\cpp20\sect-19\cmdl_args.exe
// Argument 1: blah
// Argument 2: blah
// Argument 3: blah
// Argument 4: 2
// Argument 5: 4
// Argument 6: %
// Argument 7: 98
// Argument 8: System.Management.Automation.PSRemotingJob