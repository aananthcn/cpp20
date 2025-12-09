#include <iostream>
#include <functional>

class Multiply_by_2 {
public:
	void operator()(double score[], int size) {
		for (int i{}; i < size; i++) {
			score[i] *= 2;
		}
	}
};

// class Add_1 {
// public:
// 	void operator()(double score[], int size) {
// 		for (int i{}; i < size; i++) {
// 			score[i] += 1;
// 		}
// 	}
// };

inline void add_1(double score[], double size){
	for (int i{}; i < size; i++) {
		score[i] += 1;
	}
}


// template <typename T>
// void modify(double score[], T functor, int size) {
// 	functor(score, size);
// }

using mfr_t = std::function<void(double*, int)>;
void modify(double* score, mfr_t mfr, int size) {
	mfr(score, size);
}



int main() {
	double scores[] {10.1,20.3,30.2,40.3};
 
    Multiply_by_2 multiply_by_2;
    //Add_1 add1;
 
    modify(scores,multiply_by_2,4);
    modify(scores,add_1,4);
 
    std::cout << "data [";
    for(unsigned int i{}; i < std::size(scores); ++ i){
        std::cout << scores[i] << " ";
    }
    std::cout << "]" << std::endl;

	return 0;
}