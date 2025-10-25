#include <iostream>

#define SIZE 10

int main() {
	int *p1 {new int[SIZE]}; // allocate an array of 10 integers
	int *p2 {p1};    // copy the address

	for (int i = 0; i < 10; ++i) {
		*p2++ = i * 10; // assign values using pointer arithmetic
	}
	p2 = p1; // reset p2 to the start of the array

	std::cout << "p1's address: " << &p1 << "\n";
	std::cout << "p2's address: " << &p2 << "\n";
	std::cout << "p1's content: " << p1 << "\n";
	std::cout << "p2's content: " << p2 << "\n";
	std::cout << "p1's dereferenced content: " << *p1 << "\n";
	std::cout << "p2's dereferenced content: " << *p2 << "\n";
	std::cout << "p2+1's dereferenced content: " << *(p2 + 1) << "\n";

	std::cout << "Array size: " << sizeof(*p1) * SIZE << " bytes \n";

	std::cout << "Array elements: ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << *(p1 + i) << " "; // access elements using pointer arithmetic
	}
	std::cout << "\n";

	delete[] p1; // deallocate the array

	int *p3 {nullptr}; // allocate a single integer
	delete p3;         // deallocate the single integer, no compiler error!
	// segmentation fault std::cout << "p3's dereferenced content: " << *p3 << "\n";

	return 0;
}