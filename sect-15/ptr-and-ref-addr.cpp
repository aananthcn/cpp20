#include <iostream>

int main() {
	int age {22};
	int *p_age {&age}; // pointer to age variable
	// error: int &r_age; // reference must be initialized
	int &r_age {age};  // reference to age variable

	std::cout << "Address of age variable: " << &age << "\n";
	std::cout << "Address held by p_age pointer: " << p_age << "\n";
	std::cout << "Address held by r_age reference: " << &r_age << "\n";

	std::cout << "value1 : " << *p_age << std::endl;
    std::cout << "value2 : " << r_age << std::endl;

	return 0;
}