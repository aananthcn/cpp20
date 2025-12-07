#include <iostream>
#include <concepts>
#include <type_traits>


class TinyType {
public : 
	TinyType() = default;
	TinyType( int value) : m_wrapped_int(value){}
	friend std::ostream& operator<<(std::ostream& out, const TinyType& operand);
private : 
	int m_wrapped_int{};
};

std::ostream& operator<<(std::ostream& out, const TinyType& operand) {
	out << operand.m_wrapped_int;
	return out;
}


template <typename T>
concept NumericConceptType = (std::integral<T> || std::floating_point<T> || std::same_as<T, TinyType>)
                         && !std::same_as<T, bool>
                         && !std::same_as<T, char>;


 
// forward declarations
template <typename T = int , unsigned int size = 2>
requires NumericConceptType<T>
class Point;

template < typename T, unsigned int size> 
 std::ostream& operator<<(std::ostream& out, const Point<T,size>& operand);

// definitions
template <typename T, unsigned int size>
requires NumericConceptType<T>
class Point{
    friend std::ostream& operator<< <> (std::ostream&, const Point<T,size>&);
    T m_components[size];
public :
    Point() = default;
    unsigned int get_size() const{
        return size;
    }
    void set_value(unsigned int index, T value){
        m_components[index] = value;
    }
};
 
 
template < typename T, unsigned int size> 
 std::ostream& operator<<(std::ostream& out, const Point<T,size>& operand){
    out << "Point : [ dimension :  " << size
        <<  ", components : " ;     
    for(size_t i{0}; i < size; ++i){
        out << operand.m_components[i] << " " ;
    }
    out << "]";
    
    return out;
}
 

int main()
{
    Point<TinyType,3> point_3d_tiny_types;
    point_3d_tiny_types.set_value(0,TinyType(10));
    point_3d_tiny_types.set_value(1,TinyType(20));
    point_3d_tiny_types.set_value(2,TinyType(30));
    std::cout << point_3d_tiny_types << std::endl;

	// Point<std::string, 5> point_str_types; // expecting errors
 
    return 0;
}