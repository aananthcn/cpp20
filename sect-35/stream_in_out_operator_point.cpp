#include <iostream>

class Point {
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;

	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	friend std::istream& operator>>(std::istream& is, Point& point);

private:
	double m_x {};
	double m_y {};

	// private function
	double length() const;
};

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "Point [" << point.m_x << ", " << point.m_y << "]" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
	std::cout << "Please type in the coordinates for the point.\n";
	std::cout << "order [x,y], separatd by spaces : ";
	is >> point.m_x >> point.m_y;

	return is;
}

int main() {
	Point p1;
	std::cin >> p1;
	std::cout << p1;

	return 0;
}