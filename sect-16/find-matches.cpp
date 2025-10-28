#include <iostream>
#include <cstring>


void find_matches(std::string data[] , unsigned int size, const char* key){

    std::string * matches = new std::string [size]; // Create std::string array on the heap. Remember to release
    //Don't modify anything above this line
    //Your code should go below this line

	int match_count = 0;
	for (int i = 0; i < size; ++i){
		if(data[i].find(key) != std::string::npos){
			matches[match_count++] = data[i];
		}
	}
	std::cout << "Found " << match_count << " matches. They are:";
	for (int i = 0; i < match_count; ++i){
		if(!matches[i].empty()){
			std::cout << " " << matches[i];
		}
	}

    //Your code should go above this line
    //Don't modify anything below this line
    

    delete[] matches; // Remember to release the memory.
   
}

int main() {
	std::string data[] = {
		"catching","iteration","fresh","iterative","outside","mercy"
	};
	const char* key = "iter";

	find_matches(data, std::size(data), key);

	return 0;
}