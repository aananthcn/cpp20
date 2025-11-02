#include <iostream>

void say_my_name(const std::string& name) {
	std::cout << "My name is: " << name << std::endl;
}

void say_my_name(std::string name) {
	std::cout << "My name is: " << name << std::endl;
}

int main() {
	std::string name = "Alice";
	std::string& name_ref = name;

	say_my_name(name_ref);  // Attempt to call the first overload (const reference)
	say_my_name(name);      // Attempt to call the second overload (by value)

	return 0;
}