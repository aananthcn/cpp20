#include <iostream>

class Base {
public:
	virtual double add(double a = 5, double b = 5) const {
		return (a + b + 1); // slicing calls this, but with derived class's default arguments
	}
};


class Derived : public Base {
public:
	virtual double add(double a = 10, double b = 10) const {
		return (a + b + 2); // dynamic polymorphism call this via base pointer, with these args only.
	}
};


//   A V O I D   U S I N G   D E F A U L T   A R G S   I N   P O L Y M O R P H I C   F U N C T I O N S

int main() {
	// if vf is called via the base_ptr, then the derived function is called!
	Base* base_ptr = new Derived;
	std::cout << "def. args via base pointer: " << base_ptr->add() << std::endl;

	// if slicing happens, then base function is called.
	Derived der1;
	Base bas1 = der1; // S L I C I N G   H A P P E N S   H E R E
	std::cout << "def. args via sliced base var: " << bas1.add() << std::endl;

	return 0;
}