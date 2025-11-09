#include <iostream>
#include <cmath>

class Point {
private:
	double m_x {0};
	double m_y {0};

public:
	Point(double x, double y) : m_x(x), m_y(y) {}

	double distance_to(Point other) {
		return std::sqrt(std::pow(other.m_x - m_x, 2) + std::pow(other.m_y - m_y, 2));
	}

	// Getters
	double x() const { return m_x; }
	double y() const { return m_y; } // If const is not mentioned here, calling y() on const Point objects will cause compilation error
};

int main() {
	Point p1{1.1,2.1};
	Point p2{3.2,5.2};
	const Point p3{4.3,6.3};

	std::cout << "Distance between points : " << p1.distance_to(p2) << std::endl;
	std::cout << "Y value of point p3: " << p3.y() << std::endl;

	return 0;
}