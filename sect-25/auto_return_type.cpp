#include <iostream>
#include <string>
#include <cstring>

// Function template with auto return type to concatenate two values
template <typename U, typename V>
auto maximum(U x, V y) {
	return (x > y) ? x : y;
}

int main() {
	// Test with two integers
	int int1 = 100;
	int int2 = 250;
	std::cout << "Maximum of " << int1 << " and " << int2 << " is: " 
			  << maximum(int1, int2) << std::endl;

	// Test with two doubles
	double double1 = 12.34;
	double double2 = 56.78;
	std::cout << "Maximum of " << double1 << " and " << double2 << " is: " 
			  << maximum(double1, double2) << std::endl;

	// Test with two strings
	std::string str1 = "Apple";
	std::string str2 = "Banana";
	std::cout << "Maximum of \"" << str1 << "\" and \"" << str2 << "\" is: " 
			  << maximum(str1, str2) << std::endl;

	// Test with mixed types
	std::cout << "Maximum of " << int1 << " and " << double2 << " is: " 
			  << maximum(int1, double2) << std::endl;

	// std::cout << "Maximum of \"" << str1 << "\" and " << double1 << " is: " 
	// 		  << maximum(str1, double1) << std::endl;

	return 0;
}