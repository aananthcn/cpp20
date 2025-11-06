#include <iostream>
#include <string>
#include <concepts>

template <std::floating_point T>
std::string concat_double(T a, T b) {
	return std::to_string(a) + std::to_string(b);
}

int main() {
	double double1 = 12.34;
	double double2 = 56.78;
	std::cout << "Concatenation of " << double1 << " and " << double2 << " is: " 
			  << concat_double(double1, double2) << std::endl;

	float float1 = 9.87f;
	float float2 = 6.54f;
	std::cout << "Concatenation of " << float1 << " and " << float2 << " is: " 
			  << concat_double(float1, float2) << std::endl;

	// Uncommenting the following lines will cause a compilation error
	// int int1 = 100;
	// int int2 = 250;
	// std::cout << "Concatenation of " << int1 << " and " << int2 << " is: " 
	// 		  << concat_double(int1, int2) << std::endl;

	return 0;
}