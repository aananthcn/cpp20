#include <iostream>

int main() {
	using hugeInt = long long int;
	typedef unsigned int uint;

	hugeInt bigNumber = 9'223'372'036'854'775'807;
	uint smallNumber = 4'294'967'295;
	int baseInt = -2'109'090'898;

	std::cout << "Big Number: " << bigNumber << std::endl;
	std::cout << "Size of hugeInt: " << sizeof(hugeInt) << " bytes" << std::endl;
	std::cout << "Small Number: " << smallNumber << std::endl;
	std::cout << "Size of uint: " << sizeof(uint) << " bytes" << std::endl;
	std::cout << "Base Int: " << baseInt << std::endl;
	std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;

	return 0;
}