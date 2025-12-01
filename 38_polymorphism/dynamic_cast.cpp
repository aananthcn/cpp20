#include <iostream>

class Animal {
public:
	Animal() {std::cout << "Animal Constructed!\n";}
	virtual ~Animal() {
		std::cout << "Animal destructor called!" << std::endl; 
	}
};

class Dog : public Animal {
public:
	Dog() {std::cout << "Dog Constructed!\n";}
	void bark() {
		std::cout << "Wow Wow wooo..." << std::endl;
	}

	virtual ~Dog() {
		std::cout << "Dog destructor called!" << std::endl; 
	}
};

class Husky : public Dog {
public:
	Husky() {std::cout << "Husky Constructed!\n";}
	void bark() {
		std::cout << "Wow Wow wooo..." << std::endl;
	}

	void speak() {
		std::cout << "I love woo..." << std::endl;
	}

	virtual ~Husky() {
		std::cout << "Husky destructor called!" << std::endl; 
	}
};


int main() {
	Animal* ani_ptr = new Dog;
	std::cout << "Created Dog object and store it in Animal pointer..." << std::endl;
	Dog* dog_ptr = dynamic_cast<Dog*>(ani_ptr);
	std::cout << "Dynamically casting the Animal pointer to Dog pointer..." << std::endl;

	if (dog_ptr) {
		std::cout << "BARK: ";
		dog_ptr->bark();
	}
	else {
		std::cout << "dynamic casting of animal pointer to dog pointer failed!!" << std::endl;
		delete ani_ptr;
	}
	delete dog_ptr;
	std::cout << std::endl;

	// You can't dynamically cast a base pointer holding the base container to derived pointer 
	ani_ptr = new Animal;
	std::cout << "Created Animal object and store it in Animal pointer..." << std::endl;
	dog_ptr = dynamic_cast<Dog*>(ani_ptr);
	std::cout << "Dynamically casting the Animal pointer to Dog pointer..." << std::endl;

	if (dog_ptr) {
		std::cout << "BARK: ";
		dog_ptr->bark();
	}
	else {
		std::cout << "dynamic casting of animal pointer to dog pointer failed!!" << std::endl;
		delete ani_ptr;
	}
	delete dog_ptr;
	std::cout << std::endl;

	// You can dynamically cast to 2 levels down in inheritance
	ani_ptr = new Husky;
	std::cout << "Created Husky object but stored it in Animal pointer..." << std::endl;
	Husky* husky_ptr = dynamic_cast<Husky*>(ani_ptr);
	std::cout << "Dynamically casting the Animal pointer to Husky pointer..." << std::endl;

	if (husky_ptr) {
		std::cout << "SPEAK: ";
		husky_ptr->speak();
	}
	else {
		std::cout << "dynamic casting of animal pointer to Husky pointer failed!!" << std::endl;
		delete ani_ptr;
	}
	delete husky_ptr;

	// int* int_ptr = new Husky; // uncomment to see the compiler error.

	return 0;
}
