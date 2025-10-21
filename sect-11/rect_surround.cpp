#include <iostream>

int main() {
	int x, y;

	std::cout << "Welcome to the territory control. Please type in your x and y coordinates:\n";
	std::cout << "Type in your x position: ";
	std::cin >> x;
	std::cout << "Type in your y position: ";
	std::cin >> y;

	constexpr int rect_x_length {20};
	constexpr int rect_y_length {10};
	constexpr int left_edge = -rect_x_length / 2;
	constexpr int right_edge = rect_x_length / 2;
	constexpr int top_edge = rect_y_length / 2;
	constexpr int bottom_edge = -rect_y_length / 2;

	if (x >= left_edge && x <= right_edge && y >= bottom_edge && y <= top_edge) {
		std::cout << "You are completely surrounded. Don't move!" << std::endl;
	} else {
		std::cout << "You're out of reach!" << std::endl;
	}

	return 0;
}