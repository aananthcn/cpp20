#include <iostream>
#include <string>


template <typename RetType = double, typename T, typename P>
RetType maximum(T a, P b) {
	return (a > b) ? a : b;
}

// Template specialization for const char* -- fix for the max2 error.

// template <>
// std::string maximum(const char* a, const char* b) {
// 	return (std::string(a) > std::string(b)) ? a : b;
// }

template <typename T, typename P, typename RetType = double>
RetType minimum(T a, P b) {
	return (a < b) ? a : b;
}

int main() {
	auto max1 = maximum(10, 20);
	std::cout << "Maximum of 10 and 20 is: " << max1 << std::endl;

	auto max2 = maximum<std::string>("Apple", "Banana");
	std::cout << "Maximum of \"Apple\" and \"Banana\" as 'const char*' is : " << max2 << std::endl;

	auto max3 = maximum<std::string, std::string, std::string>("Apple", "Banana");
	std::cout << "Maximum of \"Apple\" and \"Banana\" as 'std::string' is: " << max3 << std::endl;
}