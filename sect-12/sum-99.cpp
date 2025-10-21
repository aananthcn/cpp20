#include <iostream>

int main() {
	int sum = 0;
	for (int i = 1; i < 100; ++i) {
		sum += i;
	}
	std::cout << "The sum of integers from 1 to 99 is: " << sum << std::endl;
	return 0;
}