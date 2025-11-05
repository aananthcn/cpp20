#include <iostream>

void func_fp(double d) {
	std::cout << "Inside function: " << __func__ << " ==> ";
	std::cout << "Function for floating point called with value: " 
			  << d << std::endl;
}

void func_int(int i) {
	std::cout << "Inside function: " << __func__ << " ==> ";
	std::cout << "Function for integer called with value: " 
			  << i << std::endl;
}

template <typename T>
void func(T value) {
	if constexpr (std::is_floating_point_v<T>) {
		func_fp(value);
	} else if constexpr (std::is_integral_v<T>) {
		func_int(value);
	} else {
		static_assert(std::is_floating_point_v<T> || std::is_integral_v<T>, 
					  "Type must be either floating point or integral");
	}
}

int main() {
	func(10);       // Calls func_int
	func(15.5);     // Calls func_fp

	// Uncommenting the following line will cause a compilation error
	// func("Test"); // Static assert failure

	return 0;
}