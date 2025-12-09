#include <iostream>

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

// using functor in a template function
template <typename Modifier>
std::string& encrypt(std::string& str, Modifier mf) {
	for (size_t i{}; i < str.size(); i++) {
		str[i] = mf(str[i]);
	}

	return str;
}

int main() {
	Encrypt functor; // a class object instance
	std::cout << "E = " << functor('E') << std::endl; // the object is called as function

	// using FUNCTOR
	std::string name {"Aananth C N"};
	std::cout << "Aananth C N = " << encrypt(name, functor) << std::endl;

	// using LAMBDA
	std::string name2 {"Ddqdqwk#F#Q"};
	std::cout << "Ddqdqwk#F#Q = " << encrypt(name2, decrypt) << std::endl;
}