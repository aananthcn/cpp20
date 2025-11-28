#include <iostream>

// Concept - syntax 1
template <typename T>
requires std::integral<T>
T add_int(T a, T b) {
	return a + b;
}

// Concept - syntax 2
template <std::integral T>
T sub_int(T a, T b) {
	return a - b;
}

// Concept - syntax 3
auto mul_int(std::integral auto a, std::integral auto b) {
	return a * b;
}

// Concept - syntax 4 (C++20 only - requires clause at the end)
template <typename T>
T div_int(T a, T b) requires std::integral<T> {
	return a / b;
}


int main() {
	int int1 = 10;
	int int2 = 20;
	std::cout << "Sum of " << int1 << " and " << int2 << " is " 
			  << add_int(int1, int2) << std::endl;

	// Uncommenting the following lines will cause a compilation error
	// double double1 = 15.5;
	// double double2 = 10.3;
	// std::cout << "Sum of " << double1 << " and " << double2 << " is " 
	// 		  << add_int(double1, double2) << std::endl;

	// Testing sub_int
	std::cout << "Subtraction of " << int2 << " from " << int1 << " is " 
			  << sub_int(int1, int2) << std::endl;
	
	// Testing sub_int with invalid type (uncommenting will cause compilation error)
	// std::cout << "Subtraction of 15.5 from 10.3 is " 
	// 		  << sub_int(10.3, 15.5) << std::endl;

	// Testing mul_int
	std::cout << "Multiplication of " << int1 << " and " << int2 << " is " 
			  << mul_int(int1, int2) << std::endl;
	
	// Testing mul_int with invalid type (uncommenting will cause compilation error)
	// std::cout << "Multiplication of 10.3 and 15.5 is " 
	// 		  << mul_int(10.3, 15.5) << std::endl;

	// Testing div_int
	std::cout << "Division of " << int2 << " by " << int1 << " is " 
			  << div_int(int2, int1) << std::endl;
	
	// Testing div_int with invalid type (uncommenting will cause compilation error)
	// std::cout << "Division of 15.5 by 10.3 is " 
	// 		  << div_int(15.5, 10.3) << std::endl;

	return 0;
}