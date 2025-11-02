#include <iostream>

int max(const int& a, const int& b) {
	std::cout << "Const reference version called." << std::endl;
	return (a > b) ? a : b;
}

int max(int& a, int& b) {
	std::cout << "Non-const reference version called." << std::endl;
	return (a > b) ? a : b;
}


int main() {
	int x = 10;
	int y = 20;

	std::cout << "Max of " << x << " and " << y << " is " << max(x, y) << std::endl;

	const int cx = 15;
	const int cy = 25;

	std::cout << "Max of " << cx << " and " << cy << " is " << max(cx, cy) << std::endl;

	return 0;
}