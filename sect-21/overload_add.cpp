#include <iostream>
#include <string>
#include <cstring>


double add(double a, double b);
std::string add(std::string& a,std::string& b);
const char* add(char* a, const char* b);


void stitch_them(){
    char name[20] {"The sky"};
    auto result_str  = add (name," is blue");
    std::cout << "result_str : " <<  result_str;
}

double add(double a, double b){
	std::cout << "Adding two doubles: " << a << " + " << b << std::endl;
	return a + b;
}

std::string add(std::string& a,std::string& b){
	std::cout << "Concatenating two strings: " << a << " + " << b << std::endl;
	return a + b;
}

// C-style string concatenation, assumes enough space in 1st argument
const char* add(char* a, const char* b){
	std::cout << "Concatenating two C-style strings: " << a << " + " << b << std::endl;
	std::strcat(a, b);
	return a;
}

int main() {
	stitch_them();
	return 0;
}