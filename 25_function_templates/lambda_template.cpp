#include <iostream>
#include <string>


int main() {
	auto lambda_sum = [] <typename T>(T a, T b) {
		return a + b;
	};

	// Test with integers
	std::cout << "Sum of 10 and 20 is " 
			  << lambda_sum(10, 20) << std::endl;

	// Test with doubles
	std::cout << "Sum of 15.5 and 10.3 is " 
			  << lambda_sum(15.5, 10.3) << std::endl;

	// Test with strings
	std::string strA = "Hello, ";
	std::string strB = "World!";
	std::cout << "Sum of \"" << strA << "\" and \"" << strB << "\" is \"" 
			  << lambda_sum(strA, strB) << "\"" << std::endl;
}