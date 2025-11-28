#include <iostream>

int main() {
	int number;

	std::cout << "Please type in an integral value: \n";
	std::cin >> number;

	if (number % 2 == 0) {
		std::cout << number << " is even." << std::endl;
	} else {
		std::cout << number << " is odd." << std::endl;
	}

	return 0;
}