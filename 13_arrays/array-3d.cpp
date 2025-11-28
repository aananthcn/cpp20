#include <iostream>
#include <iomanip>

int main() {
	constexpr int sz_3d = 5;
	constexpr int sz_2d = 4;
	constexpr int sz_1d = 3;

	int array_3d[sz_3d][sz_2d][sz_1d]{
		{
			{1,2,3},
			{4,5,6},
			{7,8,9},
			{10,11,12}
		},
		{
			{13,14,15},
			{16,17,18},
			{19,20,21},
			{22,23,24}
		},
		{
			{25,26,27},
			{28,29,30},
			{31,32,33},
			{34,35,36}
		},
		{
			{37,38,39},
			{40,41,42},
			{43,44,45},
			{46,47,48}
		},
		{
			{49,50,51},
			{52,53,54},
			{55,56,57},
			{58,59,60}
		}
	};

	std::cout << "\nThe 3D array of size " << sz_3d << " x " << sz_2d << " x " << sz_1d << " are : \n\n";

	for (int i = 0; i < std::size(array_3d); ++i) {
		std::cout << "2D Layer " << i << ":\n===========\n  [";
		for (int j = 0; j < std::size(array_3d[i]); ++j) {
			for (int k = 0; k < std::size(array_3d[i][j]); ++k) {
				std::cout << std::setw(3) << array_3d[i][j][k] << " ";
			}
			if (j < std::size(array_3d[i]) - 1) {
				std::cout << "\n   ";
			}
			else {
				std::cout << "]\n"; // add closing bracket for the end of the 2D layer
			}
		}
		std::cout << "\n";
	}

	return 0;
}