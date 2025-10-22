#include <iostream>

void hunt_for_vowels(char message[], unsigned int size){
	unsigned int vowel_count{};//Initialized to zero

	//Don't modify anything above this line
	//Your code should go below this line

	for (unsigned int i = 0; i < size; ++i) {
		char ch = std::toupper(message[i]);
		switch (ch) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				vowel_count++;
				break;
			default:
				// Do nothing for non-vowel characters
				break;
		}
	}

	//Your code should go above this line
	//Don't modify anything below this line

	std::cout << "The string : " << message << " has " << vowel_count << " vowels";
}


int main() {
	char message[]{"Hello World! This is a simple C++20 program to count vowels."};
	const unsigned int SIZE = sizeof(message) / sizeof(message[0]);

	hunt_for_vowels(message, SIZE);

	return 0;
}