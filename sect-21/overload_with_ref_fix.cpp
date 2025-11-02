#include <iostream>


// LESSON: In C++, it is possible to overload functions based on pointer or
// reference qualifiers, even if the underlying type is the same. But it is 
// possible to overload based on const vs non-const references.

void say_my_name(const std::string& name) {
	std::cout << "My name is: " << name << std::endl;
	std::cout << "Overload with const reference called." << std::endl;
}

void say_my_name(std::string& name) {
	std::cout << "My name is: " << name << std::endl;
	std::cout << "Overload with non-const reference called." << std::endl;
}

int main() {
	std::string alice = "Alice";
	std::string& alice_ref = alice;
	std::string baba {"Baba"};

	say_my_name(alice_ref);  // Attempt to call the second overload (non const reference)
	say_my_name(alice);      // Attempt to call the second overload (by value)
	say_my_name(baba);       // Attempt to call the second overload (by value)
	say_my_name("Charlie");  // Attempt to call the fist overload (const reference)

	return 0;
}