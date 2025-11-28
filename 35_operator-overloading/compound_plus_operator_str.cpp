#include <iostream>
#include <cstring>

namespace CU {

class string{
	public : 
	explicit string(const char* data, size_t size = 15) {
		m_size = size;
		m_data = new char [m_size];
		std::strcpy(m_data,data );
	}

	string(const string& source){
		m_size = source.m_size;
		m_data = new char [m_size]; // We want to do deep copy here.
		std::strcpy(m_data,source.m_data);
	}

	~string(){
		delete [] m_data;
		m_data = nullptr;
	}

	// getter function
	const char* c_str() const{
		return m_data;
	}


	// friend declarations
	friend std::ostream& operator<<(std::ostream& out, const CU::string& s);
	friend CU::string& operator+=(CU::string& left, const CU::string& s);
	friend CU::string operator+(const CU::string& left, const CU::string& s);

	private : 
	 unsigned int m_size;
	 char * m_data{nullptr};
};

inline std::ostream& operator<<(std::ostream& out , const CU::string& s) {
	out << s.m_data;
	return out;
}

inline CU::string& operator+=(CU::string& left, const CU::string& right) {
	// create new data space and copy+cat data to it
	char *nd = new char[left.m_data, left.m_size+right.m_size];
	std::strcpy(nd, left.m_data);
	std::strcat(nd, right.m_data);

	// free the old left data and adjust the new left
	delete left.m_data;
	left.m_data = nd;
	left.m_size = left.m_size+right.m_size;

	// return the new string as new left
	return left;
}

inline CU::string operator+(const CU::string& left, const CU::string& right) {
	string ns(left.m_data, left.m_size+right.m_size);
	std::strcat(ns.m_data, right.m_data);

	// return the new string
	return ns;
}

} // CU namespace


inline void use_cu_string(const CU::string& s){
	std::cout << s;
}

int main() {
    CU::string last_name("John ");
    CU::string first_name{"Snow"};
    
    std::cout << "full name : " <<  (last_name += first_name) << std::endl;
    auto result = last_name + first_name;
    std::cout << "full name : " << result << std::endl;

	return 0;
}