#include <iostream>

int*  maximum_address( int data[], unsigned int size){
	int *max_address;

	//Don't modify anything above this line
	//Your code will go below this line

	max_address = &data[0];
	for (unsigned int i = 0; i < size; ++i) {
		if (data[i] > *max_address) {
			max_address = &data[i];
		}
	}

	//Your code should go above this line
	//Don't modify anything after this line
	return max_address;
}

int main() {
  //int data[] {11,2,52,53,9,13,5,7,12,11};
  int data[] {181,82,22,53,19,1,51,217,12,11};

  int* max_addr = maximum_address(data, std::size(data));
  std::cout << "The maximum value is at address: " << max_addr << " with value: " << *max_addr << std::endl;

  return 0;
}