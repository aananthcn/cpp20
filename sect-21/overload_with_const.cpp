#include <iostream>

// LESSON: In C++, it is not possible to overload functions based solely
// on the const type qualifier when applied to pass-by-value parameters.

// This program WON'T COMPILE

int min(int a, int b) {
	std::cout << "Non-const version called." << std::endl;
	return (a < b) ? a : b;
}

int min(const int a, const int b) {
	std::cout << "Const version called." << std::endl;
	return (a < b) ? a : b;
}

int main() {
	int x = 10;
	int y = 20;

	std::cout << "Min of " << x << " and " << y << " is " << min(x, y) << std::endl;

	const int cx = 15;
	const int cy = 25;

	std::cout << "Min of " << cx << " and " << cy << " is " << min(cx, cy) << std::endl;

	return 0;
}