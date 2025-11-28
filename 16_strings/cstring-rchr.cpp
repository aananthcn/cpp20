#include <iostream>
#include <cstring>

int main() {
	// find the first occurrence of '/' and count how many characters from the start
	const char *str {"/home/user/documents/report.txt"};
	const char *ptr = str;
	const char *filename {};
	int count = 0;

	// count occurrences of '/' in the string
	while ((ptr = std::strchr(ptr, '/')) != nullptr) {
		++count;
		++ptr;
		// print the position of each '/'
		std::cout << "'/' found at position: " << (ptr - str - 1) << std::endl;
	}
	std::cout << "Total '/' characters found: " << count << std::endl;

	// find the last occurrence of '/' in the string
	ptr = std::strrchr(str, '/');
	if (ptr) {
		std::cout << "Found last '/' at position: " << (ptr - str) << std::endl;
		std::cout << "Substring after last '/': " << (ptr + 1) << std::endl;
		filename = ptr + 1;
	} else {
		std::cout << "'/' not found" << std::endl;
	}

	// check if the file has a .txt extension
	if (std::strcmp((std::strrchr(filename, '.') + 1), "txt") == 0) {
		std::cout << "The file is of type text." << std::endl;
	}

	return 0;
}