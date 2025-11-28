#include <iostream>


template <int threshold, typename T>
bool is_valid(T collection[], size_t size) {
	T sum{};

	for (size_t i = 0; i < size; ++i) {
		sum += collection[i];
	}
	return (sum > threshold) ? true : false;
}


int main() {
	int int_collection[] = {10, 20, 30, 40, 50};
	if (is_valid<100>(int_collection, std::size(int_collection))) {
		std::cout << "Integer collection is valid." << std::endl;
	} else {
		std::cout << "Integer collection is NOT valid." << std::endl;
	}

	double double_collection[] = {15.5, 25.5, 35.5};
	if (is_valid<70>(double_collection, std::size(double_collection))) {
		std::cout << "Double collection is valid." << std::endl;
	} else {
		std::cout << "Double collection is NOT valid." << std::endl;
	}

	// invoking without specifying threshold will throw compiler error!
	float float_collection[] = {5.5f, 10.5f, 15.5f};
	if (is_valid<130>(float_collection, std::size(float_collection))) {
		std::cout << "Float collection is valid." << std::endl;
	} else {
		std::cout << "Float collection is NOT valid." << std::endl;
	}

	return 0;
}