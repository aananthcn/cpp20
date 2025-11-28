#include <iostream>


unsigned int factorial(unsigned n) {
	if (n <= 1) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}

int main() {
	unsigned int number{};

	std::cout << "Enter a positive integer to compute its factorial: ";
	std::cin >> number;

	unsigned int result = factorial(number);
	std::cout << "Factorial of " << number << " is " << result << std::endl;

	return 0;
}