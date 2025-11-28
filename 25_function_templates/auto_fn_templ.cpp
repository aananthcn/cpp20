#include <iostream>

auto sum(auto a, auto b) {
	static_assert(std::is_same_v<decltype(a), decltype(b)>, "Parameters must be of the same type");
	return a + b;
}


int main() {
	int int1 = 10;
	int int2 = 20;
	std::cout << "Sum of " << int1 << " and " << int2 << " is " 
			  << sum(int1, int2) << std::endl;

	double double1 = 15.5;
	double double2 = 10.3;
	std::cout << "Sum of " << double1 << " and " << double2 << " is " 
			  << sum(double1, double2) << std::endl;

	std::string strA = "Hello, ";
	std::string strB = "World!";
	std::cout << "Sum of \"" << strA << "\" and \"" << strB << "\" is \"" 
			  << sum(strA, strB) << "\"" << std::endl;

	// Try passing different types (uncommenting the following lines will cause a compilation error)
	// std::cout << sum(int1, double1) << std::endl;

	return 0;
}