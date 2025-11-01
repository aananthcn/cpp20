#include <iostream>

int& max(int& a, int& b) {
	return (a > b) ? a : b;
}

int& sum(int& a, int& b) {
	int result; // bad practice: returning reference to local variable
	result = a + b;
	std::cout << "Sum of " << a << " & " << b << " is : " << result << std::endl;
	return result;
}

int main() {
	int x = 10;
	int y = 20;

	std::cout << "Before modification: x = " << x << ", y = " << y << std::endl;

	// Modify the maximum value via reference
	int& max_ref = max(x, y);
	std::cout << "Maximum value before modification: " << max_ref << std::endl;

	// Increase the maximum value by 5
	max_ref += 5;
	std::cout << "After modification: x = " << x << ", y = " << y << std::endl;

	// Demonstrate the issue with returning reference to local variable
	int& sum_ref = sum(x, y);
	std::cout << "Sum (accessing the returned local variable -- undefined behavior): " << sum_ref << std::endl;

	return 0;
}