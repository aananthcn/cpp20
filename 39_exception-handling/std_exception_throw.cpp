#include <iostream>

#define ARR_SIZE 5

int main() {
	int marks[ARR_SIZE];

	try {
		for (int i = 0; i < 10; i++) {
			if (i >= ARR_SIZE) {
				throw std::out_of_range("Errow while initializing marks!");
			}
			marks[i] = 0;
		}
	}
	catch(const std::exception& e) {
		std::cerr << "Exception occurred! Reason: " << e.what() << '\n';
	}
	
	return 0;
}