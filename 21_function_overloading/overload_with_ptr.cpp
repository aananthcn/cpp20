#include <iostream>

int sum(int* a, int* b) {
	std::cout << "Pointer version called." << std::endl;
	return (*a + *b);
}

int sum(int a, int b) {
	std::cout << "Pass by value version called." << std::endl;
	return (a + b);
}


int main() {
	int x = 10;
	int y = 20;

	std::cout << "Sum of " << x << " and " << y << " is " << sum(&x, &y) << std::endl;
	std::cout << "Sum of " << x << " and " << y << " is " << sum(x, y) << std::endl;

	return 0;
}