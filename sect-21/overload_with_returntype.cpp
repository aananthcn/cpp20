#include <iostream>

// LESSON: In C++, it is not possible to overload functions based solely
// on return type. This is because the return type is not considered
// during function overload resolution.

double sum(double a, double b) {
	std::cout << "Sum of two doubles: " << a << " + " << b << std::endl;
	return a + b;
}

int sum(double a, double b) {
	std::cout << "Sum of doubles, but returns int: " << a << " + " << b << std::endl;
	return static_cast<int>(a) + static_cast<int>(b);
}

int main() {
	double x = 5.5;
	double y = 4.5;

	// This will cause a compilation error due to ambiguity
	double result = sum(x, y);
	std::cout << "Result: " << result << std::endl;

	int int_result = sum(x, y);
	std::cout << "Integer Result: " << int_result << std::endl;

	return 0;
}