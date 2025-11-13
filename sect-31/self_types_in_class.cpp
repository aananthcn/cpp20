#include <iostream>

class Point {
public:
	// constructors
	Point() : Point(-1.0, -2.0) {} // delegated
	Point(double x, double y) : m_x(x), m_y(y), p_m_origin_point(nullptr) {
		++m_point_count;
	}

private:
	// member variables
	double m_x {0};
	double m_y {0};
	static inline size_t m_point_count;

	// self referential pointer
	Point* p_m_origin_point;

public:
	// static membrs of self type
	static Point m_origin_point1;
	static const Point m_origin_point2;

	// member function
	void print_info() const {
		std::cout << "x = " << m_x << ", y = " << m_y << std::endl;
		std::cout << "m_point_count = " << m_point_count << std::endl;
	}
};

Point Point::m_origin_point1 {1.0, 1.0};
const Point Point::m_origin_point2 {2.0, 2.0};

int main() {
	Point::m_origin_point1.print_info();
	Point::m_origin_point2.print_info();

	// create 4 more objects
	Point p1, p2, p3, p4;
	p1.print_info();
	p4.print_info();

	return 0;
}