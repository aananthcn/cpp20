#include <iostream>


void replace_spaces( char data[] , unsigned int size){

    char * result{nullptr};
    
    //Don't modify anything above this line
    //Your code will go below this line
    
    //REMEMBER : WHEN YOU DYNAMICALLY ALLOCATE FOR SPACE FROM THE HEAP, YOU HAVE TO ACTIVELY RELEASE THAT TO THE
    //SYSTEM WHEN DONE WITH IT. BE A GOOD C++ CITIZEN!
    result = new char[size];
    for (unsigned int i = 0; i < size; ++i) {
        if (data[i] == ' ') {
            result[i] = '_';
        } else {
            result[i] = data[i];
        }
    }
	std::cout << "After replacing the spaces, we get : " << result;
    delete[] result;
	result = nullptr;

    //Your code will go above this line
    //Don't modify anything below this line 
}

int main() {
	char data[] {"John was 8 years old at the time."};

	replace_spaces(data, std::size(data));

	return 0;
}