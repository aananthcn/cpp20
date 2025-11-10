#include <iostream>


class Dog {
private:
	int m_age {0};
	std::string m_name {"Puppy"};
	std::string m_breed {"Mixed"};

public:
	Dog() = default;
	Dog(int age, std::string name = "Jimmy", std::string breed = "Husky")
		: m_age(age), m_name(name), m_breed(breed){}; // the order of initialiser list must match the order of member variables

	// name getter and setter
	void set_name(const std::string& name) {
		m_name = name;
	}
	std::string get_name() const {
		return m_name;
	}

	// breed getter and setter
	void set_breed(const std::string& breed) {
		m_breed = breed;
	}
	std::string get_breed() const {
		return m_breed;
	}

	// age getter and setter
	void set_age(int age) {
		m_age = age;
	}
	int get_age() const {
		return m_age;
	}
};

int main() {
	Dog dog1; // Default parameters will be used
	std::cout << "Dog1 => Name: " << dog1.get_name()
			  << ", Breed: " << dog1.get_breed()
			  << ", Age: " << dog1.get_age() << std::endl;

	Dog dog2(4); // Default name and breed will be used
	std::cout << "Dog2 => Name: " << dog2.get_name()
			  << ", Breed: " << dog2.get_breed()
			  << ", Age: " << dog2.get_age() << std::endl;

	Dog dog3(5, "Buddy"); // Default breed will be used
	std::cout << "Dog3 => Name: " << dog3.get_name()
			  << ", Breed: " << dog3.get_breed()
			  << ", Age: " << dog3.get_age() << std::endl;

	Dog dog4(3, "Max", "Golden Retriever"); // No default parameters used
	std::cout << "Dog4 => Name: " << dog4.get_name()
			  << ", Breed: " << dog4.get_breed()
			  << ", Age: " << dog4.get_age() << std::endl;
	
	// Demonstrating error cases (uncommenting will cause compilation errors)
	// Dog got5("Charlie"); // Error: no default age provided
	// Dog dog6("Rocky", "Beagle"); // Error: no default age provided

	return 0;
}