#include <iostream>
#include <functional>

struct Multiply_by_2{
	double operator() (double value) const{
		return value *2;
	}
};

inline double add_1(double value){
	return value+1;
}

using mfr_t = std::function<double(double)>;
void modify(double* score, mfr_t mfr_fn, int size) {
	for (int i{}; i < size; i++) {
		score[i] = mfr_fn(score[i]);
	}
}


double scores1[] {11.2, 22.1,33.4,44.3};
double scores2[] {11.2, 22.1,33.4,44.3};

int main() {

    //Functor
    Multiply_by_2 multiply_by_2;
    modify(scores1,multiply_by_2,4);
 
    std::cout << "data [ ";
    for( unsigned int i{}; i < 4; ++i){
      std::cout << scores1[i] << " ";
    }
   std::cout << "]";

    //Function pointer
    modify(scores2,add_1,4);
 
    std::cout << "\ndata [ ";
    for( unsigned int i{}; i < 4; ++i){
        std::cout << scores2[i] << " ";
    }
    std::cout << "]";

	return 0;
}
