#include <iostream>


class Dog {
private:
	int m_age {0};
	std::string m_name {"Unknown"};
	std::string m_breed {"Mixed"};
	mutable int call_count {0}; // Mutable variable to track calls to get_name()

public:
	Dog(int age, std::string name, std::string breed)
		: m_age(age), m_name(name), m_breed(breed) {}

	void set_name(const std::string& name) {
		m_name = name;
	}

	std::string get_name() const {
		++call_count; // Modifying mutable variable in const method
		return m_name;
	}

	int get_call_count() const {
		return call_count;
	}
};

int main() {
	Dog dog(3, "Buddy", "Golden Retriever");

	std::cout << "Dog's name: " << dog.get_name() << std::endl;
	std::cout << "get_name() called " << dog.get_call_count() << " times." << std::endl;

	dog.set_name("Max");
	std::cout << "Dog's new name: " << dog.get_name() << std::endl;
	std::cout << "get_name() called " << dog.get_call_count() << " times." << std::endl;

	const Dog const_dog(5, "Charlie", "Beagle");
	std::cout << "Const Dog's name: " << const_dog.get_name() << std::endl;
	std::cout << "get_name() called " << const_dog.get_call_count() << " times." << std::endl;
	std::cout << "Const Dog's name: " << const_dog.get_name() << std::endl;
	std::cout << "get_name() called " << const_dog.get_call_count() << " times." << std::endl;

	return 0;
}