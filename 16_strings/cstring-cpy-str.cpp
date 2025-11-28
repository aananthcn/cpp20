#include <iostream>
#include <cstring>


void extract_message( const char* src1 , const char* src2,
                        const char* src3, const char* src4){

    char* result;
    result = new char[20]; // Dynamically allocate for space
    
    //Don't modify anything above this line
    //Your code will go below this line
	char* p_result {result};
	bool first_word = true;
	const char *words[] = {"the", "sky", "is", "blue"};
	const char *sources[] = {src1, src2, src3, src4};

	// iterate through each source string and each target word
	for (auto src: sources) {
		for (const char* w: words) {
			// find and copy the word if it exists in the source string
			if (std::strstr(src, w) != nullptr) {
				// insert a space before each word except the first
				if (!first_word) {
					*p_result++ = ' ';
				} else {
					first_word = false;
				}

				// copy the word to the result
				std::strcpy(p_result, w);
				p_result += std::strlen(w);
			}
		}
	}
	std::cout << "result : " << result;

    //Your code will go above this line
    //Don't modify anything below this line

    delete[] result;
   
}

int main() {
	const char src1[] {"will old space the replace"};
    const char src2[] {"sense sky  hit has"};
    const char src3[] {"hello went is get"};
    const char src4[] {"red blue yellow orange"};

	extract_message(src1, src2, src3, src4);

	return 0;
}