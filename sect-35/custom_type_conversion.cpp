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
	Number n1 {22};
	Number n2 {10};

	// convert Number to double
	double result = double(n1 + n2) + 0.7;
	std::cout << "result = " << result << std::endl;

	// convert Number to Point
	Point p1 {n1};
	std::cout << p1;
	std::cout << "Length of p1 from origin: " << p1.length() << std::endl;

	return 0;
}