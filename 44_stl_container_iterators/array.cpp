#include <array>
#include <iostream>

int main() {
    std::array<int, 5> numbers {10, 20, 30, 40, 50};

    // Accessing elements using the [] operator (no bounds checking)
    std::cout << "First element: " << numbers[0] << std::endl;
    std::cout << "Third element: " << numbers[2] << std::endl;

    // Accessing elements using the .at() method (with bounds checking)
    try {
        std::cout << "Fifth element: " << numbers.at(4) << std::endl;
        // This line would throw an exception:
        numbers.at(10) = 100; 
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range access: " << e.what() << std::endl;
    }

	std::cout << "\nNumbers: ";
	for (int i{}; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

    return 0;
}
