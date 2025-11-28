#include <iostream>
#include <string>

class Square1 {
private:
	double m_side_length {1.0};

public:
	Square1(double side_length)
		: m_side_length(side_length) {}
	double area() const {
		return m_side_length * m_side_length;
	}
	std::string is_bigger_than(const Square1& other) const {
		if (this->area() > other.area()) {
			return "is bigger than";
		} else {
			return "is smaller than";
		}
	}
};

class Square2 {
private:
	double m_side_length {1.0};

public:
	// Explicit constructor
	explicit Square2(double side_length)
		: m_side_length(side_length) {}
	double area() const {
		return m_side_length * m_side_length;
	}
	std::string is_bigger_than(const Square2& other) const {
		if (this->area() > other.area()) {
			return "bigger than";
		} else {
			return "smaller than";
		}
	}
};

int main() {
	Square1 sq1(4.0);
	std::cout << "Square1 with side 4.0 is " << sq1.is_bigger_than(2.0) // ✅ Works (Implicit conversion from double to Square1)
		<< " square with side 2.0" << std::endl;

	// Uncommenting the following lines will cause a compilation error
	Square2 sq2(4.0);
	// std::cout << "Square2 with side 4.0 is " << sq2.is_bigger_than(2.0) // ❌ Compile-time error
	// 	<< " square with side 2.0" << std::endl;

	return 0;
}