#include <iostream>
#include <cmath>

class Point {
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;

	// free standing member function
	friend std::ostream& operator<<(std::ostream& os, const Point& point);

	// member function
	inline double length() const {
		return sqrt(pow(m_x - 0.0, 2) + pow(m_y - 0.0, 2));
	}

	Point& operator=(const Point& right) {
		// this check is to avoid loss of data esp. in case of pointer (see commented code below).
		if(this != &right) {
			// delete p_data;
			// p_data = new int (*(right.p_data));
			m_x = right.m_x;
			m_y = right.m_y;
		}
		return *this;
	}

private:
	double m_x {};
	double m_y {};
};


class Number {
public:
	Number() = default;
	Number(auto x) : m_wrapped_int(x) {}

	// private member functions - custom type functions
	operator double() const {
		return static_cast<double>(m_wrapped_int);
	}
	operator Point() const {
		return Point(static_cast<double>(m_wrapped_int), static_cast<double>(m_wrapped_int));
	}

	// free standing member function
	friend Number operator+(const Number& left, const Number& right);

private:
	int m_wrapped_int;
};


// free standing member functions
Number operator+(const Number& left, const Number& right) {
	return Number(left.m_wrapped_int + right.m_wrapped_int);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "Point [" << point.m_x << ", " << point.m_y << "]" << std::endl;
	return os;
}

int main() {
	Point p1 {24.8, 9.2};

	Point p2 = p1;
	std::cout << "p2 = " << p2;

	Point p3 {12.3, 45.6};
	p1 = p3;
	std::cout << "p1 = " << p1;


	return 0;
}