#include <iostream>


double sum_3d(const double arr[][3][3], unsigned int size){
	double total_sum{};

	unsigned int dim1_size = size; 
	unsigned int dim2_size = 3; 
	unsigned int dim3_size = 2;

	for(unsigned int i = 0; i < dim1_size; ++i){
		for(unsigned int j = 0; j < dim2_size; ++j){
			for(unsigned int k = 0; k < dim3_size; ++k){
				total_sum += arr[i][j][k];
			}
		}
	}

	return total_sum;
}

int main(){
	double my_3d_array[2][3][3] = {
		{
			{1.1, 2.2, 3.3},
			{4.4, 5.5, 6.6},
			{2.4, 3.5, 4.6}
		},
		{
			{7.7, 8.8, 9.9},
			{10.1, 11.11, 12.12},
			{1.1, 7.11, 2.12}
		}
	};

	double result = sum_3d(my_3d_array, std::size(my_3d_array));
	std::cout << "Total sum of elements in 3D array: " << result << std::endl;

	return 0;
}