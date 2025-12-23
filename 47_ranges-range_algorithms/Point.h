#ifndef POINT_H_AANANTH
#define POINT_H_AANANTH
#include <iostream>


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
	std::partial_ordering operator<=>(const Point& right) const;

public:
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

inline double Point::length() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

inline std::partial_ordering Point::operator<=>(const Point& right) const{
	if(length() > right.length())
		return std::partial_ordering::greater;
	else if(length() == right.length())
		return std::partial_ordering::equivalent;
	else if(length() < right.length())
		return std::partial_ordering::less;
	else
		return std::partial_ordering::unordered;
}


#endif // POINT_H_AANANTH