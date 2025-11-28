#include <iostream>
#include <cstring>

template <typename T>
T get_max(T a, T b) {
	return (a > b) ? a : b;
}

// Template specialization for const char*
template <>
const char* get_max<const char*>(const char* a, const char* b) {
	return (std::strcmp(a, b) > 0) ? a : b;
}

int main() {
	// Integer comparison
	int int1 = 10, int2 = 20;
	std::cout << "Max of " << int1 << " and " << int2 << " is " << get_max(int1, int2) << std::endl;

	// Double comparison
	double double1 = 15.5, double2 = 10.3;
	std::cout << "Max of " << double1 << " and " << double2 << " is " << get_max(double1, double2) << std::endl;

	// String comparison
	std::string strA = "Hello", strB = "World";
	std::cout << "Max of \"" << strA << "\" and \"" << strB << "\" is \"" << get_max(strA, strB) << "\"" << std::endl;

	// Const char* comparison using specialized template
	const char* str1 = "Apple";
	const char* str2 = "Banana";
	std::cout << "Max of \"" << str1 << "\" and \"" << str2 << "\" is \"" << get_max(str1, str2) << "\"" << std::endl;

	return 0;
}