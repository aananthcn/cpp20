#include <iostream>

class Point {
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;

	void operator++() {
		++m_x;
		++m_y;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& point);


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

	++p1;
	std::cout << p1;

	return 0;
}