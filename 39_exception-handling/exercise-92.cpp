#include <iostream>

class DividebyZeroException {
public:
	DividebyZeroException(int a, int b) : m_num(a), m_den(b) {}
	std::string what() const {
		std::string err_msg {"Error : Trying to divide "};

		return err_msg + std::to_string(m_num) + " by " + std::to_string(m_den);
	}
private:
	int m_num {};
	int m_den {};
};

int divide(int a, int b){
	if(b == 0)
		throw DividebyZeroException(a,b);
	return a/b;
}

void trouble(int num){
	try
	{
		divide(num,0);
	}
	catch(const DividebyZeroException& ex)
	{
		std::cout << ex.what();
	}	
}


int main() {
	trouble(10);

	return 0;
}