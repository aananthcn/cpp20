#include <iostream>

class DividebyZeroException : public std::exception { // my exception class deriving the public members of std::exception
public:
	DividebyZeroException(int a, int b) : m_num(a), m_den(b), 
		m_message("DividebyZeroException : Trying to divide " + std::to_string(m_num) + " by " + std::to_string(m_den)) {}

	virtual const char* what() const noexcept {
		return m_message.c_str();
	}

private:
	int m_num {};
	int m_den {};
	std::string m_message {};
};


int divide(int a, int b){
	if(b == 0)
		throw DividebyZeroException(a,b);
	return a/b;
}


int main() {
	try {
		divide(9, 0);
	}
	catch(const DividebyZeroException& ex) {
		std::cout << ex.what();
	}	

	return 0;
}