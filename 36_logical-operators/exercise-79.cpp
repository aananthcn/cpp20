#include <iostream>


#include "MyString.h"


int main() {
	CU::string a("Hello");
    CU::string b("World");
 
    std::cout << std::boolalpha;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "a >= b : " << (a >= b) << std::endl;
    std::cout << "a <= b : " << (a <= b) << std::endl;
    std::cout << "a == b : " << (a == b) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;

	return 0;
}