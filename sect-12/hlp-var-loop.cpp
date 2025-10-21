#include <iostream>

int main() {
	// list variable in range check section
	for (auto multiplier2{4}; int value : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
		std::cout << " result : " << (value * multiplier2) << std::endl;
	}
}