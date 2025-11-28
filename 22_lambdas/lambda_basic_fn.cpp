#include <iostream>


int main() {
	// printing out from Lambda function
	auto retval = []() {
		std::cout << "Hello from Lambda function!" << std::endl;
		return 42; // there is no way to auto count the no of char printed using cout, so returning a random value
	} ();

	std::cout << "Lambda function returned: " << retval << " [not comparable to printf()!]" << std::endl;

	return 0;
}