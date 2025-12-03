#include <iostream>
#include <thread>
#include <chrono>

void custom_terminate_function() {
	std::cout << "Our custom terminate function called!" << std::endl;
	std::cout << "This program is going to end in 3 seconds!" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000)); //wait for 3 seconds
	std::abort(); // this will terminate, even without this, the system will kill this app.
}


int main() {
	std::set_terminate(&custom_terminate_function);

	throw 1; // this will be handled by the custom_terinate_function.

	return 0;
}