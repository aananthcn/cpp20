#include <iostream>

bool is_palindrome(unsigned long long int num) {
	unsigned long long int original_num = num;
	unsigned long long int reversed_num = 0;

	while (num != 0) {
		unsigned int digit = num % 10;
		reversed_num = reversed_num * 10 + digit;
		num /= 10;
	}

	return (original_num == reversed_num);
}

int main() {
	unsigned long long int number{};
	std::cout << "Enter a positive integer: ";
	std::cin >> number;

	if (is_palindrome(number)) {
		std::cout << number << " is a palindrome." << std::endl;
	} else {
		std::cout << number << " is not a palindrome." << std::endl;
	}

	return 0;
}