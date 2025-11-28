#include <iostream>

// LESSON-1: In C++, it is possible to overload functions based on pointer vs
// const pointer parameters. This program will compile and run successfully,
// demonstrating the two overloads.

// LESSON-2: However, attempting to overload based on const pointer vs
// const pointer to const data will result in a compilation error, as the
// compiler cannot distinguish between these two overloads.

int max(int* a, int* b) {
	std::cout << "Pointer version called." << std::endl;
	return (*a > *b) ? *a : *b;
}

int max(const int* a, const int* b) {
	std::cout << "Pointer to a const integer version called." << std::endl;
	return (*a > *b) ? *a : *b;
}

// This function overload gets compiler error due to limitation in C++
int max(int* const a, int* const b) {
	std::cout << "Const pointer version called." << std::endl;
	return (*a > *b) ? *a : *b;
}

// This function overload gets compiler error due to limitation in C++
int max(const int* const a, const int* const b) {
	std::cout << "Const pointer to a const integer version called." << std::endl;
	return (*a > *b) ? *a : *b;
}

int main() {
	int x = 10;
	int y = 20;

	std::cout << "Max of " << x << " and " << y << " is " << max(&x, &y) << std::endl;

	const int cx = 15;
	const int cy = 25;

	std::cout << "Max of " << cx << " and " << cy << " is " << max(&cx, &cy) << std::endl;

	return 0;
}