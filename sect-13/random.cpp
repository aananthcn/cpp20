#include <iostream>
#include <chrono>

std::string formatWithCommas(int n) {
    std::string num = std::to_string(n);
    int insertPosition = num.length() - 3;
    while (insertPosition > 0) {
        num.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    return num;
}

int main() {
	std::cout << "Random number: " << formatWithCommas(std::rand()) << "\n";
	std::cout << "RAND_MAX value : " << formatWithCommas(RAND_MAX) << "\n";

	// print time & seed
	std::srand(static_cast<int>(std::time(0)));
	std::cout << "Current time as string : " << std::chrono::system_clock::now() << "\n";
	std::cout << "Current time as seed : " << formatWithCommas(static_cast<int>(std::time(0))) << "\n";
	std::cout << "Random number after seeding : " << formatWithCommas(std::rand()) << "\n";

	return 0;
}