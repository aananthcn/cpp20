#ifndef NUMBER_H_AANANTH
#define NUMBER_H_AANANTH

#include <iostream>

class Number {
public:
	Number() = default;
	Number(auto x) : m_wrapped_int(x) {}

	// public member function - custom type functions
	operator double() const {
		return static_cast<double>(m_wrapped_int);
	}

	// other public member functions
	int get_wrapped_int() const {return m_wrapped_int;}

	// free standing member function
	friend Number operator+(const Number& left, const Number& right);
	friend std::ostream& operator<<(std::ostream& os, const Number& num);

private:
	int m_wrapped_int;
};

// free standing member functions
inline Number operator+(const Number& left, const Number& right) {
	return Number(left.m_wrapped_int + right.m_wrapped_int);
}

std::ostream& operator<<(std::ostream& os, const Number& num) {
	os << num.m_wrapped_int << std::endl;
	return os;
}


// logical operators member functions
inline auto operator<=>(const Number& left, const Number& right) {
	return (left.get_wrapped_int() <=> right.get_wrapped_int());
}

inline auto operator<=>(int left, const Number& right) {
	return (left <=> right.get_wrapped_int());
}

inline bool operator==(const Number& left, const Number& right) {
	return (left.get_wrapped_int() == right.get_wrapped_int());
}
inline bool operator==(int left, const Number& right) {
	return (left == right.get_wrapped_int());
}

#endif