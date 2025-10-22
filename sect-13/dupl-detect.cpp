#include <iostream>
#include <iterator>
#include <vector>

void unique_numbers_fn( int numbers[], unsigned int collection_size){
	//Don't modify anthing above this line
	//Your code should go below this line
	int unique_count = 0;

	// int unique_numbers[collection_size]; // VLA - Variable Length Array (not standard in C++)
	std::vector<int> unique_numbers;
	unique_numbers.reserve(collection_size);
	
	for (int i = 0; i < collection_size; ++i) {
		bool is_duplicate = false;
		for (int j = 0; j < i; ++j) {
			if (numbers[i] == numbers[j]) {
				is_duplicate = true;
				break;
			}
		}

		if (!is_duplicate) {
			unique_numbers[unique_count] = numbers[i];
			unique_count++;
		}
	}

	std::cout << "The collection contains " << unique_count << " unique numbers, they are : ";
	for (int i = 0; i < unique_count; ++i) {
		std::cout << unique_numbers[i] << " ";
	}

	//Your code should go above this line
	//Don't modify anything below this line
}


int main() {
	int numbers[]{1,2,4,5,1,8,2,3,6,1,4,2};
	// const unsigned int SIZE = sizeof(numbers) / sizeof(numbers[0]);
	const unsigned int SIZE = std::size(numbers);

	unique_numbers_fn(numbers, SIZE);

	return 0;
}