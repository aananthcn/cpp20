#include <iostream>

int main() {
	try {
		int* p = new int[1000000000000000]; // attempt to allocate a huge array
		delete[] p; // deallocate if successful
	} catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}

	return 0;
}