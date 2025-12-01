#include <iostream>

class Shape {
public:
	Shape(std::string str) : m_name(std::move(str)) {}
	void draw() {
		std::cout << "Shape class's draw called!!" << std::endl;
	}
private:
	std::string m_name;
};


class Oval : public Shape {
public:
	Oval(std::string str, double x, double y) : Shape(str), m_xradius(x), m_yradius(y) {}
	void draw() {
		std::cout << "Oval class's draw with x = " << m_xradius << ", y = " << m_yradius << " called!!" <<  std::endl;
	}
protected:
	double m_xradius {};
	double m_yradius {};
};


class Circle : public Oval {
public:
	Circle(std::string str, double r) : Oval(str, r, r) {}
	void draw() {
		std::cout << "Circle class's draw with radius = " << m_xradius << " called!!" << std::endl;
	}
private:
};



int main() {
	Shape shape1("Shape1");
	Oval oval1("Oval1", 2.0, 3.5);
	Circle circle1("Circle1", 3.0);

	// P O I N T E R S
	Shape* shape_ptr;
	Oval* oval_ptr;
	Circle* circle_ptr;

	// drawing shape
	std::cout << "Printing shape1:" << std::endl;
	shape_ptr= &shape1;
	shape_ptr->draw();

	// drawing oval
	std::cout << "\nPrinting oval1:" << std::endl;
	shape_ptr = &oval1;
	shape_ptr->draw(); // expected it to draw oval, but itdrew shape only
	oval_ptr = &oval1;
	oval_ptr->draw();

	// drawing circle
	std::cout << "\nPrinting circle1:" << std::endl;
	shape_ptr = &circle1; // expected it to draw circle, but it drew shape only
	shape_ptr->draw();
	circle_ptr = &circle1;
	circle_ptr->draw();

	// R E F E R E N C E S
	Shape& shape_ref = shape1;
	Oval& oval_ref = oval1;
	Circle& circle_ref = circle1;

	std::cout << "\nPrinting Refences :" << std::endl;
	shape_ref.draw();
	oval_ref.draw();
	circle_ref.draw();
	Shape& shape_ref_to_circle = circle1;
	shape_ref_to_circle.draw(); // expected it to draw circle, but it drew shape only


	return 0;
}