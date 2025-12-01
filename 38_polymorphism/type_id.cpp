#include <iostream>

#include <cxxabi.h> // For abi::__cxa_demangle

class Shape {
public:
	Shape(std::string str) : m_name(std::move(str)) {}
	virtual void draw() {
		std::cout << "Shape class's draw called!!" << std::endl;
	}
private:
	std::string m_name;
};


class Oval : public Shape {
public:
	Oval(std::string str, double x, double y) : Shape(str), m_xradius(x), m_yradius(y) {}
	virtual void draw() {
		std::cout << "Oval class's draw with x = " << m_xradius << ", y = " << m_yradius << " called!!" <<  std::endl;
	}
protected:
	double m_xradius {};
	double m_yradius {};
};


class Circle : public Oval {
public:
	Circle(std::string str, double r) : Oval(str, r, r) {}
	virtual void draw() {
		std::cout << "Circle class's draw with radius = " << m_xradius << " called!!" << std::endl;
	}
private:
};



int main() {
	Shape shape1("Shape1");
	Shape shape2("Shape2");
	Oval oval1("Oval1", 1.8, 3.5);
	Oval oval2("Oval2", 2.0, 1.1);
	Oval oval3("Oval3", 1.5, 8.7);
	Circle circle1("Circle1", 3.2);
	Circle circle2("Circle2", 6.4);

	// Using raw pointers
	Shape* shapes_raw[] {&shape1, &oval1, &circle1, &shape2, &oval2, &circle2, &oval3};

	std::cout << "Printing raw pointer:" << std::endl;
	int i{};
	for (auto ptr: shapes_raw) {
		int status;
		// Get the mangled name
		const char* mangled_name = typeid(*ptr).name();
		
		// Demangle the name
		char* demangled_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);
		
		std::cout << ++i << ": type: ";
		std::cout << (status == 0 ? demangled_name : mangled_name) << " (typeid: " << mangled_name << ") " << std::endl;

		// Free the demangled name buffer
		std::free(demangled_name);
	}

	return 0;
}