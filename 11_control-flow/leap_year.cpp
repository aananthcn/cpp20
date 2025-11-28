#include <iostream>

int main() {
	unsigned int year;
	std::cout << "Enter a year: ";
	std::cin >> year;

	bool is_leap {};

	if (((year % 4 == 0 && year % 100) != 0) || ((year % 400) == 0)) {
		is_leap = true;
	}

	if (is_leap) {
		std::cout << year << " is a leap year." << std::endl;
	} else {
		std::cout << year << " is not a leap year." << std::endl;
	}

	return 0;
}