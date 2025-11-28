#include <iostream>

void insertion_sort(int * array, unsigned int size){
//YOUR CODE WILL GO BELOW THIS LINE 
//DON'T MODIFY ANYTHING ABOVE THIS LINE

	int key, j;
	for (unsigned int i = 1; i < size; i++) {
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key) {
			// swap element j (prev) and j+1 (curr)
			array[j + 1] = array[j];
			// move to next element on the left
			j--;;
		}
		array[j + 1] = key;
	}

//YOUR CODE WILL GO ABOVE THIS LINE
//DON'T MODIFY ANYTHING BELOW THIS LINE
}

void print_array(int* arr, unsigned int n) 
{ 
    for (unsigned int i = 0; i < n; i++){
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;
}


int main() 
{ 
	int arr[] = {6, 3, 5, 7, 4, 2};

	std::cout << "Array before sorting: ";
	print_array(arr, std::size(arr));
	insertion_sort(arr, std::size(arr));
	std::cout << "Array after sorting: "; 
	print_array(arr, std::size(arr));

	return 0; 
}