#include <iostream>


void find_stuf_out( char data[] , unsigned int size){

    unsigned int vowel_count{};
    unsigned int consonant_count{};
    
    //Don't modify anything above this line
    //Your code should go below this line
   
   for (unsigned int i = 0; i < size; ++i) {
	   char ch = std::toupper(data[i]);
	   if ((ch >= 'A') && (ch <= 'Z')) {
		   switch (ch) {
			   case 'A':
			   case 'E':
			   case 'I':
			   case 'O':
			   case 'U':
				   vowel_count++;
				   break;
			   default:
				   consonant_count++;
				   break;
		   }
	   }
	}
	std::cout << "The string contains " << vowel_count << " vowels and " << consonant_count << " consonants";

    //Your code should go above this line
    //Don't modify anything below this line
}

int main() {
	char data[] {"John was 8 years old at the time."};

	find_stuf_out(data, std::size(data));

	return 0;
}