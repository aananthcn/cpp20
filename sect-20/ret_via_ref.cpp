#include <iostream>

void is_sum_even(int data[], unsigned int size, bool& result) {
	int sum = 0;
	for (unsigned int i = 0; i < size; ++i) {
		sum += data[i];
	}
	result = (sum % 2 == 0);
}

int main() {
	int data[] = {1, 2, 3, 4, 5};
	bool even_sum;
	is_sum_even(data, 5, even_sum);
	if (even_sum) {
		std::cout << "The sum is even." << std::endl;
	} else {
		std::cout << "The sum is odd." << std::endl;
	}
	return 0;
}