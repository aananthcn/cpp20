#include <iostream>
#include <concepts>

// Declaring a custom concept MyIntegral
template <typename T>
concept MyIntegral = std::integral<T>;

template <typename T>
concept Multipliable = requires(T a, T b) {
	{ a * b } -> std::same_as<T>;
};

template <typename T>
concept Incrementable = requires(T a) {
	{ ++a } -> std::same_as<T&>;
	{ a++ } -> std::same_as<T>;
	a += 1;
};

// Syntax 1: Using custom concept MyIntegral
template <typename T>
requires MyIntegral<T>
T add_my_int(T a, T b) {
	return a + b;
}

// Syntax 2: Using custom concept Multipliable
template <Multipliable T>
T mul_my_val(T a, T b) {
	return a * b;
}

// Syntax 3: Using custom concept Incrementable
auto increment_my_val(Incrementable auto a) {
	return ++a;
}

int main() {
	int int1 = 10;
	int int2 = 20;
	std::cout << "Sum of " << int1 << " and " << int2 << " is " 
			  << add_my_int(int1, int2) << std::endl;

	// Uncommenting the following lines will cause a compilation error
	// double double1 = 15.5;
	// double double2 = 10.3;
	// std::cout << "Sum of " << double1 << " and " << double2 << " is " 
	// 		  << add_my_int(double1, double2) << std::endl;

	// Testing mul_my_val
	std::cout << "Multiplication of " << int1 << " and " << int2 << " is " 
			  << mul_my_val(int1, int2) << std::endl;
	
	// Testing mul_my_val with invalid type (uncommenting will cause compilation error)
	// std::cout << "Multiplication of 10.3 and 15.5 is " 
	// 		  << mul_my_val(10.3, 15.5) << std::endl;

	// Testing increment_my_val
	std::cout << "Incrementing " << int1 << " gives " 
			  << increment_my_val(int1) << std::endl;
	
	// Testing increment_my_val with invalid type (uncommenting will cause compilation error)
	// std::cout << "Incrementing 15.5 gives " 
	// 		  << increment_my_val(15.5) << std::endl;

	return 0;
}


