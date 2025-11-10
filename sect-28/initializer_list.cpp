#include <iostream>

class Point {
private:
	double m_x {};
	double m_y {};

public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {
		std::cout << "Constructor with parameter called!!\n";
	};
	Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) {
		std::cout << "Copy constructor called!!\n";
	}
	~Point() {}

	// Initializer list
	Point(std::initializer_list<double> list) {
		std::cout << "Constructor with Initializer list called !!\n";
		m_x = *list.begin();
		m_y = *(list.begin()+1);
	}

	void print_info() {
		std::cout << "x = " << m_x << ", y = " << m_y << "\n";
	}
};


int main() {
	Point p1 {5.0, 4.0};
	Point p2 {p1};

	p2.print_info(); // expecting p2's scale to be 10
	p1.print_info(); // and p1's scale to be 2
}