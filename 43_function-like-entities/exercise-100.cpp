#include <iostream>

// type alias
using cb_t = void (*)(double*, int);

// interface: passing the callback function
void modify(double* score, cb_t cb, int size) {
	cb(score, size);
}

// should print: data [11.1 21.3 31.2 41.3 ]
void multiply_by_2(double* score, int size) {
	for (int i{}; i < size; i++) {
		score[i] *= 2;
	}
}

void add_1(double* score, int size) {
	for (int i{}; i < size; i++) {
		score[i] += 1;
	}
}

// should print: data [20.2 40.6 60.4 80.6 ]
int main() {
	// modify case
	double scores1[] {10.1,20.3,30.2,40.3};

    modify(scores1,add_1,4); // calling the modify function with add_1 as the callback
 
    std::cout << "data [";
    for(unsigned int i{}; i < std::size(scores1); ++ i){
        std::cout << scores1[i] << " ";
    }
    std::cout << "]" << std::endl;


	// multiply_by_2 case
    double scores[] {10.1,20.3,30.2,40.3};
 
    modify(scores,multiply_by_2,4);
 
    std::cout << "data [";
    for(unsigned int i{}; i < std::size(scores); ++ i){
        std::cout << scores[i] << " ";
    }
    std::cout << "]" << std::endl;

	return 0;
}