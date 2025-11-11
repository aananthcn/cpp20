#include <iostream>
#include <limits>

class Point {
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}

	// Line is a friend Point
	friend class Line;
	
private:
	double m_x {0.0};
	double m_y {0.0};
};

class Line {
public:
	Line() = default;
	Line(Point p1, Point p2) : m_p1(p1), m_p2(p2) {}

	// getters
	const Point& get_p1() const {
		return m_p1;
	}

	const Point& get_p2() const {
		return m_p2;
	}

	// other functions
	double slope() {
		if ((m_p2.m_x - m_p1.m_x) == 0) {
			return std::numeric_limits<double>::max();
		}
		else {
			return (m_p2.m_y - m_p1.m_y) / (m_p2.m_x - m_p1.m_x);
		}
	}

private:
	Point m_p1;
	Point m_p2;
};

int main() {
	Line l1 {{0.0, 0.0}, {20.0, 10.0}};
	std::cout << "The slope of l1 is " << l1.slope() << std::endl;
	Line l2 {{0.0, 0.0}, {1.0, 2.0}};
	std::cout << "The slope of l2 is " << l2.slope() << std::endl;
}