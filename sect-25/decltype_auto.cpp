#include <iostream>

template <typename T>
decltype(auto) maximum(T a, T b) {
	return (a > b) ? a : b;
}


int main() {
	int int1 = 10;
	int int2 = 20;
	std::cout << "Maximum of " << int1 << " and " << int2 << " is " 
			  << maximum(int1, int2) << std::endl;

	double double1 = 15.5;
	double double2 = 10.3;
	std::cout << "Maximum of " << double1 << " and " << double2 << " is " 
			  << maximum(double1, double2) << std::endl;

	std::string strA = "Hello";
	std::string strB = "World";
	std::cout << "Maximum of \"" << strA << "\" and \"" << strB << "\" is \"" 
			  << maximum(strA, strB) << "\"" << std::endl;

	return 0;
}