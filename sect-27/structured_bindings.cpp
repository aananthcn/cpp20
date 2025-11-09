#include <iostream>

struct Point {
	double m_x{1};
	double m_y{1};
	float scale{1.0f};
};

int main() {
	Point p1{2.2,3.3,4.4f};

	auto& [x_ref, y_ref, scale_ref] = p1;

	std::cout << "Point before structured bindings modification: "
			  << "x = " << x_ref << ", y = " << y_ref 
			  << ", scale = " << scale_ref << std::endl;

	x_ref = 5.5;
	y_ref = 6.6;
	scale_ref = 7.7f;

	std::cout << "Point after structured bindings modification: "
			  << "x = " << p1.m_x << ", y = " << p1.m_y 
			  << ", scale = " << p1.scale << std::endl;

	return 0;
}