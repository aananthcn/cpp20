#include <iostream>

class Point {
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;

	friend std::ostream& operator<<(std::ostream& os, const Point& point);

	// awkward
	std::ostream& operator<<(std::ostream& os) {
	 	std::cout << "member function: ";
		os << "Point [" << m_x << ", " << m_y << "]" << std::endl;
		return os;
	}

private:
	double m_x {};
	double m_y {};

	// private function
	double length() const;
};

std::ostream& operator<<(std::ostream& os, const Point& point) {
	std::cout << "friend function: ";
	os << "Point [" << point.m_x << ", " << point.m_y << "]" << std::endl;
	return os;
}

int main() {
	Point p1 {22.4, 57.5};
	std::cout << p1;

	Point p2 {88.2, 44.2};
	p2 << std::cout; // awkward

	std::cout << "\n\nThe right way to use:" << std::endl;
	std::cout << p1 << p2 << std::endl;

	return 0;
}