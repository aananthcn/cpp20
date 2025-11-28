#include <iostream>
#include <iomanip>
#include <bitset>


using namespace std;

#include <cstdint>
#include <climits>

constexpr uint32_t rotl32(uint32_t value, unsigned int count) noexcept {
    const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;  // avoid undefined behavior
    return (value << count) | (value >> (-count & mask));
}

constexpr uint32_t rotr32(uint32_t value, unsigned int count) noexcept {
    const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;
    return (value >> count) | (value << (-count & mask));
}


int main(void) {
	int x = 10;

	(void)[&x](){x=20;};

	x++;
	cout << "Value of x = " << x << "\n";

    //Declare and initialize the variables
    float number1 {1.12345678901234567890f}; // Precision : 7
    double number2 {1.12345678901234567890}; // Precision : 15
    long double number3  {1.12345678901234567890L};
    
    //Print out the sizes
    std::cout << "sizeof float : " << sizeof(float) << std::endl;
    std::cout << "sizeof double : " << sizeof(double) << std::endl;
    std::cout << "sizeof long double : " << sizeof(long double) << std::endl;

    //Precision
    std::cout << std::setprecision(20); // Control the precision from std::cout.
    std::cout << "number1 is : " << number1 << std::endl; //7 digits
    std::cout << "number2 is : " << number2 << std::endl; // 15'ish digits
    std::cout << "number3 is : " << number3 << std::endl; // 15+ digits

	std::cout << "x in binary : 0b" << std::bitset<8> (x) << std::endl;

	rotl32(0xA0000005, 4);
	std::cout << "x after rotl32 by 4 : 0b" << std::bitset<8> (rotl32(x, 4)) << std::endl;

	return 0;
}

