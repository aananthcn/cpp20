#ifndef POINT_H_AANANTH
#define POINT_H_AANANTH
#include <iostream>

#include "Number.h"

class Point {
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;

	// as a freestanding non-member function
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	friend void operator++(Point& pt); // prefix operator
	friend Point operator++(Point& pt, int); // postfix operator
	friend void operator--(Point& pt); // prefix operator
	friend Point operator--(Point& pt, int); // postfix operator

	// defaulted equality operator
	bool operator==(const Point& right) const = default;

	// type conversion from Number to Point
	operator Number() const {
		return Number(static_cast<int>(m_x));
	}

private:
	double m_x {};
	double m_y {};

	// private function
	double length() const;
};

// Non member functions (freestanding)
inline std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "Point [" << point.m_x << ", " << point.m_y << "]" << std::endl;
	return os;
}

inline void operator++(Point& pt) {
	++(pt.m_x);
	++(pt.m_y);
}

inline Point operator++(Point& pt, int) {
	Point lpt(pt);
	++pt;
	return lpt;
}

inline void operator--(Point& pt) {
	--(pt.m_x);
	--(pt.m_y);
}

inline Point operator--(Point& pt, int) {
	Point lpt(pt);
	--pt;
	return lpt;
}

#endif // POINT_H_AANANTH