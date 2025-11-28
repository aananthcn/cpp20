#include <iostream>

int main(){
	enum Color { RED, GREEN, BLUE, YELLOW };
	std::cout << "Size of enum Color: " << sizeof(Color) << " bytes" << std::endl;
	std::cout << "RED = " << RED << ", GREEN = " << GREEN 
	          << ", BLUE = " << BLUE << ", YELLOW = " << YELLOW << std::endl;

	enum class Direction { NORTH, EAST, SOUTH, WEST };
	std::cout << "Size of enum class Direction: " << sizeof(Direction) << " bytes" << std::endl;
	std::cout << "NORTH = " << static_cast<int>(Direction::NORTH)
	          << ", EAST = " << static_cast<int>(Direction::EAST)
	          << ", SOUTH = " << static_cast<int>(Direction::SOUTH)
	          << ", WEST = " << static_cast<int>(Direction::WEST) << std::endl;

	return 0;
}