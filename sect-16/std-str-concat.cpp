#include <string>
#include <iostream>

std::string build_from_raw_pieces(const char * str1, const char* str2){

    std::string result;
    
    //Don't modify anything above this line
    //Your code will go below this line
    result.append(static_cast<std::string>(str1) + ' ' + static_cast<std::string>(str2));
    //Your code will go above this line
    //Don't modify anything below this line
    return result;
}


int main() {
	const char* part1 {"Hello"};
	const char* part2 {"World!"};

	std::string full_string = build_from_raw_pieces(part1, part2);
	const char* full_cstr = full_string.c_str();
	std::cout << "The cstr is : " << full_cstr << std::endl;
	std::cout << "The full string is : " << full_string << std::endl;

	return 0;
}