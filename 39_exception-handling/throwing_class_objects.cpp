#include <iostream>

class ErrorInfo {
public:
	ErrorInfo(std::string s) : m_message(s) {}
	void print_error() {
		std::cout << m_message << std::endl;
	}
private:
	std::string m_message;
};


int main() {
	try {
		throw ErrorInfo(std::string("Caught an error at ") + __FILE__ + 
			std::string(" ") + __func__ + std::string("() : ") + std::to_string(__LINE__));
	}
	catch (ErrorInfo& ex) {
		ex.print_error();
	}

	return 0;
}