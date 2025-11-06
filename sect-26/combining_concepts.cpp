#include <iostream>
#include <type_traits>


template <typename T>
concept TinyType = requires(T t) {
	requires sizeof(T) < 4;
};

// Using the concept in a function template
template <typename T>
T tiny_add(T a, T b) requires TinyType<T> {
	return a + b;
}

int main() {
	short int int1 = 10;
	short int int2 = 20;
	std::cout << "Sum of " << int1 << " and " << int2 << " is " 
			  << tiny_add(int1, int2) << std::endl;

	char char1 = 'A';
	char char2 = 5;
	std::cout << "Sum of '" << char1 << "' and " << static_cast<int>(char2) << " is " 
			  << static_cast<int>(tiny_add(char1, char2)) << std::endl;

	// Uncommenting the following lines will cause a compilation error
	// double double1 = 15.5;
	// double double2 = 10.3;
	// std::cout << "Sum of " << double1 << " and " << double2 << " is " 
	// 		  << tiny_add(double1, double2) << std::endl;

	return 0;
}