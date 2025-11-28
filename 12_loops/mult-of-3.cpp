#include <vector>
#include <iostream>

void print_multiples_of_3(){
    
    
    std::vector<int> numbers {1,21,4,5,7,3,9,3,5,17,15};

    //Don't modify anything above this line
    //Your code should go below this line
	bool first = true;
    for (auto value : numbers) {
		if (value % 3 == 0) {
			if (first) {
				std::cout << value;
				first = false;
			} else {
				std::cout << " " << value;
			}
		}
	}
    //Your code should go above this line
    //Don't modify anything below this line
    
}

int main() {
	print_multiples_of_3();
	return 0;
}