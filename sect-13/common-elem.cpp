#include <iostream>

void common_elements(int array_1[], int array_2[]) {
	// REMEMBER, The input arrays array_1 and array_2 have a fixed size of 10

	// Don't modify anything above this line
	// Your code will go below this line
	int common_elems[10];
	int ce_index = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (array_1[i] == array_2[j]) {
				common_elems[ce_index++] = array_1[i];
			}
		}
	}

	// Print the initial message
    if (ce_index)
	    std::cout << "There are " << ce_index << " common elements they are : ";
    else
        std::cout << "There are " << ce_index << " common elements";
	
	// Print the common elements
	for (int i = 0; i < ce_index; i++) {
		std::cout << common_elems[i] << " ";
	}

	// Your code will go above this line
	// Don't modify anything after this line
}


int main() {
	int data1[] {1,2,3,4,5,6,7,8,9,10};
	int data2[] {5,6,7,8,9,10,11,12,13,14};
	//int data2[] {11,12,13,14,15,16,17,18,19,20};

	common_elements(data1, data2);

	return 0;
}