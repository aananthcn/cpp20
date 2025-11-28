#include <iostream>

int main() {
	int x = 10;
	int y = 20;
	int retval {};

	auto lambda_sum = [=]() {
		// return x++ + y; // error: cannot modify a captured variable in a non-mutable lambda
		return x + y;
	};

	retval = lambda_sum();
	// retval = 30, x = 10 now and y = 20, and you will get Sum of 10 and 20 is 30!
	std::cout << "Sum of " << x << " and " << y << " is " << retval << std::endl;
	return 0;
}