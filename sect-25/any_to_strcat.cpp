#include <iostream>
#include <string>
#include <sstream> // Needed for std::ostringstream

// Function to concatenate two values by converting them to strings
template <typename U, typename V>
std::string concatenate(U x, V y) {
    std::ostringstream oss;
    oss << x << y;
    return oss.str();
}

int main() {
	// Test with two integers
	int int1 = 100;
	int int2 = 250;
	std::cout << "Concatenation of " << int1 << " and " << int2 << " is: " 
			  << concatenate(int1, int2) << std::endl;

	// Test with two doubles
	double double1 = 12.34;
	double double2 = 56.78;
	std::cout << "Concatenation of " << double1 << " and " << double2 << " is: " 
			  << concatenate(double1, double2) << std::endl;

	// Test with two strings
	std::string str1 = "Hello, ";
	std::string str2 = "World!";
	std::cout << "Concatenation of \"" << str1 << "\" and \"" << str2 << "\" is: " 
			  << concatenate(str1, str2) << std::endl;

	// Test with mixed types
	std::cout << "Concatenation of " << int1 << " and \"" << str2 << "\" is: " 
			  << concatenate(int1, str2) << std::endl;

	std::cout << "Concatenation of \"" << str1 << "\" and " << double2 << " is: " 
			  << concatenate(str1, double2) << std::endl;

	return 0;
}