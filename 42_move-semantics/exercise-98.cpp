#include <iostream>


#include <cstring>

namespace CU{

class string{
	friend std::ostream& operator<< (std::ostream& out , const CU::string& s);

	public : 
	 string(const char* data, size_t size = 15 ){
		m_size = size;
		m_data = new char [m_size];
		std::strcpy(m_data,data );
	}

	string(const string& source) = delete;


    //YOUR CODE WILL GO BELOW THIS LINE
    //DON'T MODIFY ANYTHING ABOVE THIS LINE

	// move constructor
	string(string&& source) : m_data(source.m_data) {
		std::cout << "move constructor called!" << std::endl;
		if (&source == this)
			return;
		
		// steal from the source
		m_data = source.m_data;

		// invalidate source
		source.m_data = nullptr;
		source.m_size = 0;
	}

	void operator=(string&& source) {
		std::cout << "move assignment operator called!" << std::endl;
		if (&source == this)
			return;
	
		// release the current
		delete[] m_data;

		// steal from teh source
		m_data = source.m_data;
		m_size = source.m_size;

		// invalidate source
		source.m_data = nullptr;
		source.m_size = 0;

	}
	
	//YOUR CODE WILL GO ABOVE THIS LINE
	//DON'T MODIFY ANYTHING BELOW THIS LINE
	

	const char* c_str() const{
		return m_data;
	}

	~string(){
		delete [] m_data;
		m_data = nullptr;
	}
	private : 
	 unsigned int m_size;
	 char * m_data{nullptr};
};



	inline std::ostream& operator<< (std::ostream& out , const CU::string& s){
		out << s.m_data;
		return out;
	}

	
}


int main() {
	CU::string s1("Hello");
    CU::string tmp("World");
    const char* storage = tmp.c_str();
    s1 = std::move(tmp);

	tmp = std::move(CU::string("Baba"));

	return 0;
}