#include <iostream>

template <typename T>
void swap_data(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	int x = 10;
	int y = 20;

	std::cout << "Before swap_data: x = " << x << ", y = " << y << std::endl;
	swap_data(x, y);
	std::cout << "After swap_data: x = " << x << ", y = " << y << std::endl;

	double p = 5.5;
	double q = 9.9;

	std::cout << "Before swap_data: p = " << p << ", q = " << q << std::endl;
	swap_data(p, q);
	std::cout << "After swap_data: p = " << p << ", q = " << q << std::endl;

	std::string str1 = "Hello";
	std::string str2 = "World";

	std::cout << "Before swap_data: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	swap_data(str1, str2);
	std::cout << "After swap_data: str1 = " << str1 << ", str2 = " << str2 << std::endl;

	return 0;
}