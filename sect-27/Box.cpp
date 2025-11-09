#include <iostream>


class Box {
private:
	double m_length {1};
	double m_width {1};
	double m_height {1};

public:
	Box() = default;
	// Box() : m_length(0), m_width(0), m_height(0) {} // You can't overload default constructor
	Box(double length, double width, double height)
		: m_length(length), m_width(width), m_height(height) {}

	double base_area() {
		return m_length * m_width;
	}
	double volume() {
		return m_length * m_width * m_height;
	}

	// Getters (if needed)
	double get_length() const { return m_length; }
	double get_width() const { return m_width; }
	double get_height() const { return m_height; }
};


int main() {
	Box box(10.1,20.4,30.3);
	Box box2;

    std::cout << "base area : " << box.base_area() << std::endl;
    std::cout << "volume : " << box.volume() << std::endl;

	// Testing default constructor
	std::cout << "base area (box2) : " << box2.base_area() << std::endl;
	std::cout << "volume (box2) : " << box2.volume() << std::endl;

	// Print member values using getters
	std::cout << "Length (box) : " << box2.get_length() << std::endl;
	std::cout << "Width (box) : " << box2.get_width() << std::endl;
	std::cout << "Height (box) : " << box2.get_height() << std::endl;

	return 0;
}