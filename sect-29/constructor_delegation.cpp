#include <iostream>

class Square {
private:
	double m_side_length {1.0};
	double postion[3] {0.0, 0.0, 0.0};
	std::string color {"white"};
	int shade {0};

public:
	// Normal constructor with all parameters
	Square(double side_length, double x, double y, double z, std::string color, int shade)
		: m_side_length(side_length), postion{x, y, z}, color(color), shade(shade) {}

	// Delegating constructor with position at 0, default color and shade
	Square(double side_length)
		: Square(side_length, 0.0, 0.0, 0.0, "white", 0) {}

	double area() const {
		return m_side_length * m_side_length;
	}
	std::string info() const {
		return "Square with side length " + std::to_string(m_side_length) +
			   ", position (" + std::to_string(postion[0]) + ", " +
			   std::to_string(postion[1]) + ", " +
			   std::to_string(postion[2]) + "), color " + color +
			   ", shade " + std::to_string(shade);
	}
};

int main() {
	Square sq1(4.0, 1.0, 2.0, 3.0, "red", 5);
	std::cout << sq1.info() << " has area " << sq1.area() << std::endl;

	Square sq2(3.0); // Delegating constructor will be used
	std::cout << sq2.info() << " has area " << sq2.area() << std::endl;

	return 0;
}