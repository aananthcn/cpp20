#include <iostream>

void some_function() noexcept {
	try {
		throw 1;
	}
	catch (int ex) {
		std::cout << "Handling int exceptoin in a function that is specified as \"noexcept\"" << std::endl;
		throw; // this is going to crash this app.
	}
}

int main() {
	some_function();

	return 0;
}