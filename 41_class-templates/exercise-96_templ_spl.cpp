#include <iostream>

template <typename T>
struct Map
{
	T m_key;
	T m_value;
	Map(T key, T value)
	 : m_key(key), m_value(value)
	{}
	bool compare_to( const Map& other) const{
		return (m_key == other.m_key)&&(m_value == other.m_value);
	}
   
	void print_info() const{
		std::cout << "map [";
		std:: cout << m_key << "," << m_value;
		std::cout << "]";
	}
    
};

#define MAP_SIZE	(64)
template <>
struct Map <const char*>
{
	char m_key[MAP_SIZE];
	char m_value[MAP_SIZE];
	Map(const char* key, const char* value) {
		std::strncpy(m_key, key, MAP_SIZE-1);
		m_key[MAP_SIZE-1] = '\0';
		std::strncpy(m_value, value, MAP_SIZE-1);
		m_value[MAP_SIZE-1] = '\0';
	}
	bool compare_to(const Map& other) const {
		return ((std::strcmp(m_key, other.m_key) == 0) &&
			    (std::strcmp(m_value, other.m_value) == 0));
	}
	void print_info() const{
		std::cout << "map [";
		std:: cout << m_key << "," << m_value;
		std::cout << "]";
	}
};




int main() {
	// Integer Map
	Map<int> m1(11,22);
    Map<int> m2(11,22);
	std::cout << "Comparing " << m1.m_value << " == " << m2.m_value << std::endl;
    auto result1 = m1.compare_to(m2);
    std::cout << "result : " << std::boolalpha << result1 << std::endl;
    m1.print_info();
	std::cout << std::endl;

	// Char* Map
	Map<const char*> ms1("Daniel","Gakwaya");
    std::string last_name {"Daniel"};
    std::string first_name{"Gakwaya"};
    Map<const char*> ms2(last_name.c_str(),first_name.c_str());
	std::cout << "\nComparing " << ms1.m_value << " == " << ms2.m_value << std::endl;
    auto result2 = ms1.compare_to(ms2);
    std::cout << "result : " << std::boolalpha << result2 << std::endl;

	return 0;
}