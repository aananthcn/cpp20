#include <iostream>

const double* find_max_address(const double arr[], unsigned int size) {
	const double* max_addr = &arr[0];
	for (unsigned int i = 1; i < size; ++i) {
		if (arr[i] > *max_addr) {
			max_addr = &arr[i];
		}
	}
	return max_addr;
}


int main() {
	// double data[] = {3.5, 7.2, 1.8, 9.4, 5.6};
	double data[] = {-3.0, -2.0, -5.0};
	int index_of_max = 0;

	const double* max_addr = find_max_address(data, std::size(data));
	std::cout << "Maximum value is: " << *max_addr << " at address: " << max_addr << std::endl;
	index_of_max = static_cast<int>(max_addr - data);
	std::cout << "Index of the maximum value is: " << index_of_max 
			  << " (i.e., the " << index_of_max+1 << "th element )" << std::endl;

	return 0;
}