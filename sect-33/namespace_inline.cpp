#include <iostream>

inline int age {12};

inline void print_age1() {
	age = 13;
	std::cout << "Age = " << age << "\n";
}


namespace {
	void print_age2() {
		age = 14;
		std::cout << "Age = " << age << "\n";
	}
}


int main() {
	std::cout << "Age = " << age << "\n";
	print_age1();
	print_age2();
	std::cout << "Age = " << age << "\n";
	return 0;
}