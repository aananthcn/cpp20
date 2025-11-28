#include <iostream>

int main() {
	ptrdiff_t diff;
	int arr[] = {10, 20, 30, 40, 50};
	int* ptr1 = &arr[1]; // Points to 20
	int* ptr2 = &arr[4]; // Points to 50

	diff = ptr2 - ptr1; // Calculate the difference in terms of number of elements
	std::cout << "Difference between ptr2 and ptr1: " << diff << " elements." << std::endl;

	diff = ptr1 - ptr2; // Reverse difference
	std::cout << "Difference between ptr1 and ptr2: " << diff << " elements." << std::endl;

	return 0;
}