#include <iostream>

// const pointer to int example .... : int * const ptr_var1;
// You can't change the ptr itself, but you can change the value it points to.

// pointer to const int example .... : const int * ptr_var2;
// You can change the ptr to point to another int, but you can't change the value it points to.

// const pointer to const int example: const int * const ptr_var3;
// You can't change the ptr itself, nor can you change the value it points to.

int main() {
	int value1 = 10;
	int value2 = 20;

	// const pointer to int
	int * const constPtr = &value2;
	std::cout << "Value pointed to by constPtr: " << *constPtr << std::endl;
	*constPtr = 25; // Allowed: can modify value
	std::cout << "New value pointed to by constPtr: " << *constPtr << std::endl;
	// constPtr = &value1; // Error: cannot change the address stored in const pointer

	// pointer to const int
	const int * ptrToConst = &value1;
	std::cout << "Value pointed to by ptrToConst: " << *ptrToConst << std::endl;
	// *ptrToConst = 15; // Error: cannot modify value through pointer to const


	// const pointer to const int
	const int * const constPtrToConst = &value1;
	std::cout << "Value pointed to by constPtrToConst: " << *constPtrToConst << std::endl;
	// *constPtrToConst = 30; // Error: cannot modify value through pointer to const
	// constPtrToConst = &value2; // Error: cannot change the address stored in const pointer

	return 0;
}