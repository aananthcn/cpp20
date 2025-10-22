
#include <iostream>

bool is_collection_sorted(int numbers[], unsigned int collection_size){
	// Don't modify anything above this line
	//Your code will go below this line

	bool sorted = true;
	for (unsigned int i = 1; i < collection_size; ++i) {
		if (numbers[i] < numbers[i - 1]) {
			sorted = false;
			break;
		}
	}

	//Your code will go above this line
	//Don't modify anything below this line

	return sorted;
}


int main() {
	int data1[] {1,2,4,5,8,12,13,16,71,92};
  	int data2[] {1,112,4,5,8,12,13,16,71,92};

	if (is_collection_sorted(data1, std::size(data1))) {
		std::cout << "Data1 is sorted\n";
	} else {
		std::cout << "Data1 is NOT sorted\n";
	}

	if (is_collection_sorted(data2, std::size(data2))) {
		std::cout << "Data2 is sorted\n";
	} else {
		std::cout << "Data2 is NOT sorted\n";
	}

  	return 0;
}