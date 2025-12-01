#include <iostream>

class Base {
public:
	~Base() {
		std::cout << "Base destructor called!" << std::endl; 
	}
};

class Derived : public Base {
public:
	~Derived() {
		std::cout << "Derived destructor called!" << std::endl; 
	}
};


class Animal {
public:
	virtual ~Animal() {
		std::cout << "Animal destructor called!" << std::endl; 
	}
};

class Dog : public Animal {
public:
	virtual ~Dog() {
		std::cout << "Dog destructor called!" << std::endl; 
	}
};



int main() {
	Base* bas_ptr = new Derived;
	delete bas_ptr; // ⚠️ only Base destructor is called!! Bad! Use virtual destructor!

	Animal* ani_ptr = new Dog;
	delete ani_ptr; // both Dog and Animal destructors are called!!
}
