#include <iostream>

void incr_and_say_age(int *age) {
	(*age)++;
	std::cout << "Your age is now: " << *age << std::endl;
	
	int local_age = *age;
	local_age += 5;
	std::cout << "In 5 years, you will be: " << local_age << std::endl;
}

int main() {
	int age{};
	std::cout << "Enter your age: ";
	std::cin >> age;

	incr_and_say_age(&age);
	std::cout << "Back in main, your age is: " << age << std::endl;

	return 0;
}