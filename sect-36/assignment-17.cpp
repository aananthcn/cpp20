// #pragma once
#include <iostream>
#include <cstring>
 
namespace CU {
 
class string {
    friend std::ostream& operator<< (std::ostream& out , const CU::string& s);
    friend string operator+(const string& left, const string& right);
    friend string& operator+=(string& left, const string& right);
	friend bool operator==(const string& left, const string& right);
	friend std::partial_ordering operator<=>(string left, string right);

 
public : 
     string(const char* data, size_t size = 15 ){
        m_size = size;
        m_data = new char [m_size];
        std::strcpy(m_data,data );
    }
 
    //Copy constructor
    string(const string& source){
        m_size = source.m_size;
        m_data = new char [m_size]; // We want to do deep copy here.
        std::strcpy(m_data,source.m_data);
    }
 
    //Copy assignment operator
    string& operator= (const string& right_operand){
        std::cout << "Copy assignment operator called" << std::endl;
        if(this != & right_operand){
            delete[] m_data;
            m_data = new char [right_operand.m_size];
            std::strcpy(m_data,right_operand.m_data);
        }
        return *this;
    }
 
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
 
    inline string operator+(const string& left, const string& right){
        string tmp(left);
        tmp += right;
        return tmp;
    }
 
    inline string& operator+=(string& left, const string& right){
        std::strcat(left.m_data,right.m_data);
        return left;
    }

	int str_equivalent(const char *s1, const char *s2) {
		while ((*s1 != '\0') && (*s2 != '\0')) {
			if (std::tolower(static_cast<unsigned char>(*s1)) != 
				std::tolower(static_cast<unsigned char>(*s2))) {
				return -1;
			}
			s1++;
			s2++;
		}

		return 0;
	}

	inline std::partial_ordering operator<=>(string left, string right) {
        if (std::strcmp(left.m_data, right.m_data) < 0) {
			return std::strong_ordering::less;
		}
		else if (std::strcmp(left.m_data, right.m_data) > 0) {
			return std::strong_ordering::greater;
		}
		else if (std::strcmp(left.m_data, right.m_data) == 0) {
			return std::strong_ordering::equal;
		}
		else if (str_equivalent(left.m_data, right.m_data) >= 0) {
			return std::strong_ordering::equivalent;
		}

		return std::partial_ordering::unordered;
    }

	inline bool operator==(const string& left, const string& right) {
    	return (left <=> right) == 0;
	}

} // CU namespace


int main() {
	CU::string a("Hello");
    CU::string b("World");
 
    std::cout << std::boolalpha;
    std::cout << std::endl;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "a > b : " << (a > "World") << std::endl; // Implicit conversion from left
    std::cout << "a > b : " << ("Hello" > b) << std::endl; // Implicit conversion from right
 
    std::cout << std::endl;
    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "a < b : " << (a < "World") << std::endl; // Implicit conversion from left
    std::cout << "a < b : " << ("Hello" < b) << std::endl; // Implicit conversion from right
 
    std::cout << std::endl;
    std::cout << "a >= b : " << (a >= b) << std::endl;
    std::cout << "a >= b : " << (a >= "World") << std::endl; // Implicit conversion from left
    std::cout << "a >= b : " << ("Hello" >= b) << std::endl; // Implicit conversion from right
 
    std::cout << std::endl;
    std::cout << "a <= b : " << (a <= b) << std::endl;
    std::cout << "a <= b : " << (a <= "World") << std::endl; // Implicit conversion from left
    std::cout << "a <= b : " << ("Hello" <= b) << std::endl; // Implicit conversion from right
 
    std::cout << std::endl;
    std::cout << "a == b : " << (a == b) << std::endl;
    std::cout << "a == b : " << (a == "World") << std::endl; // Implicit conversion from left
    std::cout << "a == b : " << ("Hello" == b) << std::endl; // Implicit conversion from right
 
    std::cout << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;
    std::cout << "a != b : " << (a != "World") << std::endl; // Implicit conversion from left
    std::cout << "a != b : " << ("Hello" != b) << std::endl; // Implicit conversion from right

	return 0;
}