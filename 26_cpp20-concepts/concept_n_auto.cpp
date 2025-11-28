#include <iostream>
#include <concepts>

std::integral auto add(std::integral auto a, std::integral auto b) {
	return a + b;
}

int main() {
	int int1 = 10;
	int int2 = 20;
	std::cout << "Sum of " << int1 << " and " << int2 << " is " 
			  << add(int1, int2) << std::endl;

	// Test with chars
	char char1 = 'A';
	char char2 = 5;
	std::cout << "Sum of '" << char1 << "' and " << static_cast<int>(char2) << " is " 
			  << static_cast<int>(add(char1, char2)) << std::endl;
	
	// Test with long long
	long long ll1 = 10000000000LL;
	long long ll2 = 25000000000LL;
	std::cout << "Sum of " << ll1 << " and " << ll2 << " is " 
			  << add(ll1, ll2) << std::endl;

	// Uncommenting the following lines will cause a compilation error
	// double double1 = 15.5;
	// double double2 = 10.3;
	// std::cout << "Sum of " << double1 << " and " << double2 << " is " 
	// 		  << add(double1, double2) << std::endl;

	return 0;
}