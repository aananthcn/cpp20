#include <iostream>

template <typename T>
concept Addable = requires(T a, T b) {
	{ a + b } noexcept -> std::convertible_to<int>; // Compound requirement: syntax and semantics
};

Addable auto add_values(Addable auto a, Addable auto b) {
	return a + b;
}

int main() {
	// Test with integers
	int int1 = 10;
	int int2 = 20;
	std::cout << "Sum of " << int1 << " and " << int2 << " is " 
			  << add_values(int1, int2) << std::endl;

	// Test with doubles
	double double1 = 15.5;
	double double2 = 10.3;
	std::cout << "Sum of " << double1 << " and " << double2 << " is " 
			  << add_values(double1, double2) << std::endl;

	// Test with chars
	char char1 = 'A';
	char char2 = 5;
	std::cout << "Sum of '" << char1 << "' and " << static_cast<int>(char2) << " is " 
			  << static_cast<int>(add_values(char1, char2)) << std::endl;

	// Uncommenting the following lines will cause a compilation error
	// std::string strA = "Hello, ";
	// std::string strB = "World!";
	// std::cout << "Sum of \"" << strA << "\" and \"" << strB << "\" is \"" 
	// 		  << add_values(strA, strB) << "\"" << std::endl;

	return 0;
}