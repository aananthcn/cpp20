#include <iostream>
#include <type_traits>

template <typename T, typename P>
struct Map
{
	static_assert(std::is_integral<T>::value, "Keys can only be of integral type!"); // approach - 1
	static_assert(std::is_same_v<P, std::string>, "Values can only be of std::string type!"); // approach - 2
private : 
    T m_key;
    P m_value;
public : 
    Map(T key, P value)
     : m_key(key), m_value(value)
    {}
};

int main() {
	Map<int, std::string> m1(11222,std::string{"Steve Murphy"}); 
	Map<long int,std::string> m2(22333,"Ahmed Malik");

	// following line must throw errors
	// Map<double,unsigned int> m3(22.1,44555);
	// Map<int, int> m4(34, 3400);

	return 0;
}