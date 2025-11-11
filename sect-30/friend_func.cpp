#include <iostream>

class Square {
private:
	double m_side_length {1.0};
	double postion[3] {0.0, 0.0, 0.0};
	std::string color {"white"};
	int shade {0};

public:
	Square() = default;

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

	friend const std::string& get_square_color(const Square& sq);
	friend int get_square_shade(const Square& sq);
};

const std::string& get_square_color(const Square& sq) {
	return sq.color;
}

int get_square_shade(const Square& sq) {
	return sq.shade;
}


int main() {
	std::cout << "This program demonstrate Friend Function!\n";
	Square s1;
	std::cout << "Color of s1 = " << get_square_color(s1);
	std::cout << "s1's shade = " << get_square_shade(s1);

	Square s2 {30.2, 0.0, 0.0, 0.0, "Yellow", 99};
	std::cout << "Color of s2 = " << get_square_color(s2);
	std::cout << "s2's shade = " << get_square_shade(s2);

	return 0;
}
