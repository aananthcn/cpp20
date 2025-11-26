#include <iostream>

#include "Point.h"


int main() {
	Point p1 {3.0, 4.8};
	Point p2 {p1};
	Point p3 {3.0, 4.79999999};

	if (p1 == p2)
		std::cout << "p1 == p2" << std::endl;
	else 
		std::cout << "p1 != p2" << std::endl;

	if (p1 == p3)
		std::cout << "p1 == p3" << std::endl;
	else 
		std::cout << "p1 != p3" << std::endl;

	std::cout <<std::boolalpha;
	std::cout << "p1 == Point(3.0, 4.8) : " << (p1 == Point(3.0, 4.8)) << std::endl;

	return 0;
}