#include <iostream>
#include <limits>

int max_subsequence_sum(int sequence[] , unsigned int size){
    //YOUR CODE WILL GO BELOW THIS LINE 
    //DON'T MODIFY ANYTHING ABOVE THIS LINE
    int max_sum = 0;
	for (unsigned int i = 0; i < size; ++i) {
		int current_sum = 0;
		for (unsigned int j = i; j < size; ++j) {
			current_sum += sequence[j];
			if (current_sum > max_sum) {
				max_sum = current_sum;
			}
		}
	}

	return max_sum;
    //YOUR CODE WILL GO ABOVE THIS LINE
    //DON'T MODIFY ANYTHING BELOW THIS LINE B
}

int main(){
	int seq1[] = { -2, 11, -4, 13, -5, -2 };
	int seq2[] = { -1, -2, -3, -4 };
	int seq3[] = { 3, -4, 6, 1, 1, -2, 2, 3};
	
	std::cout << "Max subsequence sum of seq1: " << max_subsequence_sum(seq1, std::size(seq1)) << std::endl; // Expected output: 20
	std::cout << "Max subsequence sum of seq2: " << max_subsequence_sum(seq2, std::size(seq2)) << std::endl; // Expected output: 0
	std::cout << "Max subsequence sum of seq3: " << max_subsequence_sum(seq3, std::size(seq3)) << std::endl; // Expected output: 15
	
	return 0;
}