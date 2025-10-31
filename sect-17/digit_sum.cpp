#include <iostream>

//Don't modify anything above this line
//Your code will go below this line
//REMEMBER THE NAME OF THE FUNCTION TO BE EXACTLY AS SPECIFIED.

unsigned int digit_sum(unsigned int input_number){
	unsigned int sum{0};
	while(input_number != 0){
		sum += input_number % 10;
		input_number /= 10;
	}
	return sum;
}

//Your code will go above this line
//Don't modify anything below this line

int main(){
	
	unsigned int number{};
	std::cout << "Enter a positive integer: ";
	std::cin >> number;
	
	unsigned int result = digit_sum(number);
	
	std::cout << "The sum of the digits in " << number << " is " << result << std::endl;
	
	return 0;
}
