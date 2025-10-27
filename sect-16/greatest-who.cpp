#include <string>
#include <iostream>

std::string who_s_the_greatest(std::string data[] , unsigned int size){
    
    std::string result;
    
    //Don't modify anything above this line
    //Your code will go below this line

	result = data[0];
	for (unsigned int i = 1; i < size; ++i) {
		if (data[i] > result) {
			result = data[i];
		}
	}

    //Your code will go above this line
    //Don't modify anything below this line
  
    return result;
}

int main() {
	std::string names[] = {"I","am","the","king","of","the","jungle"};
	std::string greatest = who_s_the_greatest(names, std::size(names));
	std::cout << "The greatest string is: " << greatest << std::endl;
	return 0;
}