#include <iostream>
#include <string>
 
int main(){
    
    //std::string message {"He said :  'Stay out of this' and left"};    // normal string literal
	//std::string message {R("He said :  'Stay out of this' and left")}; // error: missing parentheses
	std::string message {R"(He said :  'Stay out of this' and left)"};   // raw string literal
	std::string& message2 {message};
	std::string& message3  = message;

    std::cout << "message : " << message << std::endl;
	std::cout << "Address of message : " << &message << std::endl;
    std::cout << "message2 : " << message2 << std::endl;
	std::cout << "Address of message2 : " << &message2 << std::endl;
	std::cout << "message3 : " << message3 << std::endl;
	std::cout << "Address of message3 : " << &message3 << std::endl;
 
    return 0;
}
