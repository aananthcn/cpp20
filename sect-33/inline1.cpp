#include <iostream>

void inline2_main();

inline void do_something() {
	std::cout << __FILE__ << ":" << __func__ << "()" << std::endl;
}


int main() {
	do_something();
	inline2_main();
}