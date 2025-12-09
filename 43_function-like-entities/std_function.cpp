#include <iostream>
#include <functional>

// F U N C T O R
class Encrypt {
public:
	char operator() (const char& param) {
		return static_cast<char> (param +3);
	}
};

// L A M D A
auto decrypt = [] (const char& param) {
	return static_cast<char> (param -3);
};


std::function<char(const char&)> my_modifier;


int main() {
	Encrypt encrypt;

	my_modifier = encrypt;
	std::cout << "Encrypted data of 'A': " << my_modifier('A') << std::endl;

	my_modifier = decrypt;
	std::cout << "Decrypted data of 'D': " << my_modifier('D') << std::endl;

	return 0;
}