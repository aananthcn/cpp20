#include <iostream>

#include "BoxContainer.h"


int main() {
	//int
	std::cout << "BoxContainer of int : " << std::endl;
	BoxContainer<int> int_box;
	int_box.add(33);
	int_box.add(44);
	std::cout << "int_box : " << int_box << std::endl;
	
	//double
	std::cout << std::endl;
	std::cout << "BoxContainer of double : " << std::endl;
	BoxContainer<double> double_box;
	double_box.add(100.11);
	double_box.add(200.22);
	std::cout << "double_box : " << double_box << std::endl;

	//char
	std::cout << std::endl;
	std::cout << "BoxContainer of char" << std::endl;
	BoxContainer<char> char_box;
	char_box.add('H');
	char_box.add('e');
	char_box.add('l');
	char_box.add('l');
	char_box.add('o');
	char_box.add('o');
	std::cout << "char_box : " << char_box << std::endl;

	return 0;
}