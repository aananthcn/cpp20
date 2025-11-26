#include <iostream>

#include "Point.h"

int main() {
	Point p1 {10, 10};
	Point p2 {20, 20};

	// class Point has no logical operator (except ==), but its type conversion
	// operator Number() has the implementations of all. The compiler will use 
	// those functions to perform the comparison in the following line:
	bool result = (p1 > p2);

	std::cout << std::boolalpha;
	std::cout << "p1 = " << p1;
	std::cout << "p2 = " << p2;
	std::cout << "  p1 > p2  : " << result << std::endl;
	std::cout << "  p1 >= p2 : " << (p1 >= p2) << std::endl;
	std::cout << "  p1 < p2  : " << (p1 < p2) << std::endl;
	std::cout << "  p1 <= p2 : " << (p1 <= p2) << std::endl;

	return 0;
}