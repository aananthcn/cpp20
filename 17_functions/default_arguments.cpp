#include <iostream>

void greet(std::string name = "Friend", std::string greeting = "Hello",
	std::string message = "Nice to meet you!", int repeat = 1);

int main(){
	greet();
	greet("Alice");
	greet("Bob", "Hi", "How are you?");
	greet("Charlie", "Welcome", "Good to see you!");
	greet("Diana", "Hey", "What's up?", 3);
	return 0;
}


void greet(std::string name, std::string greeting, std::string message, int repeat){
	for (int i = 0; i < repeat; ++i) {
		std::cout << greeting << ", " << name << "! " << message << std::endl;
	}
}