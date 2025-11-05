#include <iostream>

template <typename T, typename U, typename V>
void print_person_info(T name, U age, V height) {
	std::cout << "Name: " << name << ", Age: " << age << ", Height: " << height << " cm" << std::endl;
}


int main() {
	std::string name = "Alice";
	int age = 30;
	double height = 165.5;

	print_person_info(name, age, height);

	// You can also use different types
	print_person_info("Bob", 25, 180); // using const char* for name
	print_person_info("Charlie", 28, 175.2f); // using float for height
	print_person_info(std::string("Diana"), 22.5, 160.0); // using double for age
	print_person_info(&name, &age, &height); // using pointers, although not useful here
	print_person_info<std::string, int, int>(name, age, height); // explicit template arguments

	return 0;
}