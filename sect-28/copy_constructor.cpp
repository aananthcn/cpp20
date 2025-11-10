#include <iostream>

class Point {
private:
	double m_x {};
	double m_y {};
	int *p_scale {};

public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {
		p_scale = new int;
		*p_scale = 2;
	};
	~Point() {
		delete p_scale;
		p_scale = nullptr;
	}

	// Defining a copy constructor -- ❌ Compile-time error
	// Point(const Point p) : m_x(p.m_x), m_y(p.m_y) {
	// 	this->p_scale = new int;
	// 	*this->p_scale = *p->p_scale;
	// }

	// This works!! But some time is spent to allocate a new int.
	Point(const Point& p) : m_x(p.m_x), m_y(p.m_y), p_scale(new int (*p.p_scale)) {}


	void set_scale(int val) {
		if (this->p_scale) {
			*this->p_scale = val;
		}
	}

	void print_info() {
		std::cout << "x = " << m_x << ", y = " << m_y << "\n";
		std::cout << "scale = " << *p_scale << "\n";
	}
};


int main() {
	Point p1 {5.0, 4.0};
	Point p2 {p1};
	p2.set_scale(10);

	p2.print_info(); // expecting p2's scale to be 10
	p1.print_info(); // and p1's scale to be 2
}