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

	std::string str1 = "The sky is so blue, the grass is so green. Kids are running everywhere.";
	std::cout << "str1 = " << str1 << std::endl;
	std::cout << "Length of str1: " << str1.length() << std::endl;
	std::cout << "Capacity of str1: " << str1.capacity() << std::endl;
	str1.reserve(200);
	std::cout << "New capacity of str1 after reserve: " << str1.capacity() << std::endl;
	str1.shrink_to_fit();
	std::cout << "Capacity of str1 after shrink_to_fit: " << str1.capacity() << std::endl;
	str1.clear();
	std::cout << "Length of str1 after clear: " << str1.length() << std::endl;
	std::cout << "Capacity of str1 after clear: " << str1.capacity() << std::endl;
	std::cout << "std::string::npos: " << std::string::npos << std::endl;


	// string comparison
	std::string apple1{"apple"};
	std::string apple2{"Apple"};

	if (apple1 == apple2) {
		std::cout << apple1 << " is equal to " << apple2 << std::endl;
	} else if (apple1 > apple2) {
		std::cout << apple1 << " is greater than " << apple2 << std::endl;
	} else {
		std::cout << apple1 << " is less than " << apple2 << std::endl;
	}
	std::cout << "ASCII value of 'a': " << static_cast<int>('a') << std::endl;
	std::cout << "ASCII value of 'A': " << static_cast<int>('A') << std::endl;

	return 0;
}