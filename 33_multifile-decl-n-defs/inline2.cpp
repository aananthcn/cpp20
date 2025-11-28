#include <iostream>

// without "static", the compiler simply eliminates this function but links
// with inline1.cpp::do_something() function.
inline static void do_something() {
	std::cout << __FILE__ << ":" << __func__ << "()" << std::endl;
}



void inline2_main() {
	std::cout << "Entering inline2.cpp\n";
	do_something();
}