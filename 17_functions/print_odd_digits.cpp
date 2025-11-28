#include <iostream>


//Don't modify anything above this line
//Your code will go below this line

void show_odds(unsigned long long int input_number){
	while(input_number != 0){
		unsigned int digit = input_number % 10;
		if(digit % 2 != 0){
			std::cout << digit;
		}
		input_number /= 10;
	}
	std::cout << std::endl;
}

//Your code will go above this line
//Don't modify anything below this line


int main(){
	
	unsigned long long int number{};
	std::cout << "Enter a positive integer: ";
	std::cin >> number;
	
	std::cout << "The odd digits in " << number << " are: ";
	show_odds(number);
	
	return 0;
}