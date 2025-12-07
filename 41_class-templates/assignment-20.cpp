#include <iostream>

// forward declaration of the struct
template <typename T, typename P>
struct Map;

// forward declaration of the function template
template <typename T, typename P>
std::ostream& operator<<(std::ostream& out, const Map<T,P>& right);

template <typename T, typename P>
struct Map
{
private : 
    friend std::ostream& operator<< <> (std::ostream&, const Map<T,P>&);
 
    T m_key;
    P m_value;
public : 
    Map(T key, P value)
     : m_key(key), m_value(value)
    {}
};

// should print as ==> Map : [11222,Steve Murphy]
template <typename T, typename P>
std::ostream& operator<<(std::ostream& out, const Map<T,P>& right) {
	out << "Map : [" << right.m_key << "," << right.m_value << "]" << std::endl;
	return out;
}


int main() {
	Map<int, std::string> m1(11222,"Steve Murphy");
    std::cout << m1 << std::endl;	

	return 0;
}