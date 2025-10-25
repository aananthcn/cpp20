#include <iostream>


void merge_arrays(int data1[], int data2[],
           unsigned int size1, unsigned int size2){

    //Don't modify anything above this line
    //Your code will go below this line

	int *new_array = new int[size1 + size2];
	for (unsigned int i = 0; i < size1; ++i) {
		new_array[i] = data1[i];
	}
	for (unsigned int j = 0; j < size2; ++j) {
		new_array[size1 + j] = data2[j];
	}
	for (unsigned int k = 0; k < size1 + size2; ++k) {
		std::cout << new_array[k] << " ";
	}
	delete[] new_array;

    //Your code will go above this line
    //Don't modify anything below this line

}


int main() {
	int data1[] {1,2,3,4,5,66,77};
	int data2[] {10,20,30,40,50,60};

	merge_arrays(data1, data2, std::size(data1), std::size(data2));

	return 0;
}