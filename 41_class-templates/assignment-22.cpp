#include <iostream>
#include <type_traits>
#include <concepts>
#include <string>


// forward declaration of the struct
template <typename T, typename P>
requires std::is_integral_v<T> && std::is_same_v<P, std::string>
struct Map;

// forward declaration of the function template
template <typename T, typename P>
std::ostream& operator<<(std::ostream& out, const Map<T,P>& right);


template <typename T, typename P>
requires std::is_integral_v<T> && std::is_same_v<P, std::string>
struct Map
{
private : 
    friend std::ostream& operator<< <>  (std::ostream& out, const Map<T,P>& operand);
    T m_key;
    P m_value;
public : 
    Map(T key, P value)
     : m_key(key), m_value(value)
    {}
};

template < typename T, typename P> 
 std::ostream& operator<<(std::ostream& out, const Map<T,P>& operand){
 
    out << "Map : [" << operand.m_key 
        << "," << operand.m_value << "]";
    return out;
}

int main() {
	Map<int, std::string> m1(11222,std::string{"Steve Murphy"}); 
	Map<long int,std::string> m2(22333,"Ahmed Malik");

	// following lines must throw errors
	// Map<double,unsigned int> m3(22.1,44555);
	// Map<int, int> m4(34, 3400);

	std::cout << "Assignment 22: code exited normally!!" << std::endl;
	return 0;
}