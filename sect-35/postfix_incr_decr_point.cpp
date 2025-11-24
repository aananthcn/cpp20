#include <iostream>

class Point {
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;

	// UNCOMMENT THE FOLLOWING 2 FUNCTIONS BUT COMMENT THE FRIEND FUNCTIONS TO MAKE THIS WORKING!
	// void operator++() {
	// 	++m_x;
	// 	++m_y;
	// }

	// Point operator++(int) {
	// 	Point local_point(*this);
	// 	++(*this);
	// 	return *this;
	// }

	// as a freestanding non-member function
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	friend void operator++(Point& pt); // prefix operator
	friend Point operator++(Point& pt, int); // postfix operator
	friend void operator--(Point& pt); // prefix operator
	friend Point operator--(Point& pt, int); // postfix operator


private:
	double m_x {};
	double m_y {};

	// private function
	double length() const;
};

// Non member functions (freestanding)
std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "Point [" << point.m_x << ", " << point.m_y << "]" << std::endl;
	return os;
}

void operator++(Point& pt) {
	++(pt.m_x);
	++(pt.m_y);
}

Point operator++(Point& pt, int) {
	Point lpt(pt);
	++pt;
	return lpt;
}

void operator--(Point& pt) {
	--(pt.m_x);
	--(pt.m_y);
}

Point operator--(Point& pt, int) {
	Point lpt(pt);
	--pt;
	return lpt;
}


int main() {
	Point p1 {22.4, 57.5};
	std::cout << p1;

	p1++;
	std::cout << p1;

	++p1;
	std::cout << p1;


	Point p2 {10, 10};
	std::cout << "p2 : " << (p2--);
	std::cout << "p2 : " << p2;

	return 0;
}