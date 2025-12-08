#include <iostream>

double add(double a, double b) {
	return a + b;
}


int main() {
	int x {5};
	int y {10};

	int&& outcome = x + y;
	double&& result = add(10.1, 20.2);

	// temporary vlaues become usable way down, through out the lifetime
	// of the program

	std::cout << "Program doing some other things..." << std::endl;
	std::cout << "outcome is : " << outcome << std::endl;
	std::cout << "result is : " << result << std::endl;

	return 0;
}