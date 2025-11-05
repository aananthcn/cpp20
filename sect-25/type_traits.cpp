#include <iostream>
#include <type_traits>


int main() {
	// Printing boolalpha demonstration
	std::cout << "Just true : " << true << std::endl;
	std::cout << "std::boolalpha : " << std::boolalpha << true << std::endl;
	std::cout << "int test without std::boolalpha : " << std::is_integral<int>::value  << std::endl;

	// Check if int is an integral type
	std::cout << "Is int an integral type? " 
			  << std::boolalpha 
			  << std::is_integral<int>::value 
			  << std::endl;

	// Check if double is a floating point type
	std::cout << "Is double a floating point type? " 
			  << std::boolalpha 
			  << std::is_floating_point<double>::value 
			  << std::endl;

	// Check if char is a signed type
	std::cout << "Is char a signed type? " 
			  << std::boolalpha 
			  << std::is_signed<char>::value 
			  << std::endl;

	// Check if unsigned int is an unsigned type
	std::cout << "Is unsigned int an unsigned type? " 
			  << std::boolalpha 
			  << std::is_unsigned<unsigned int>::value 
			  << std::endl;

	// Check if float is a POD type
	std::cout << "Is float a POD type? " 
			  << std::boolalpha 
			  << std::is_pod<float>::value 
			  << std::endl;

	// Check if float is an integral type :-)
	std::cout << "Is float an integral type? "	
			  << std::boolalpha 
			  << std::is_integral<float>::value 
			  << std::endl;

	return 0;
}