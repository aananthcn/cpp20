#include <iostream>


// LESSON: In C++, it is possible to overload functions based on constant or
// reference qualifiers, even if the underlying type is the same. But, this
// is a good example of how the compiler is unable to resolve the best 
// match when both overloads can accept the same argument.

// THIS CODE WILL NOT COMPILE DUE TO AMBIGUITY

void say_my_name(const std::string& name) {
	std::cout << "My name is: " << name << std::endl;
}

void say_my_name(std::string name) {
	std::cout << "My name is: " << name << std::endl;
}

int main() {
	std::string alice = "Alice";
	std::string& alice_ref = alice;
	std::string baba {"Baba"};

	say_my_name(name_ref); // Attempt to call the first overload (const reference)
	say_my_name(alice);      // Attempt to call the second overload (by value)
	say_my_name(baba);       // Attempt to call the second overload (by value)

	return 0;
}