#include <iostream>


template <typename T = int, unsigned int size = 2>
class Point{
	T m_components[size];
public : 
	T get_value(unsigned int index) const{
		return m_components[index];
	}
	void set_value(unsigned int index, T value){
		m_components[index] = value;
	}
	void print_info() const{
		std::cout << "point : [ ";
		for(unsigned int i{0}; i < size ; ++i){
			std::cout << m_components[i] << " " ;
 		}
		 std::cout << "]";
	}
	unsigned int get_size() const{
	    return size;
	}
};


int main() {
	Point point_2d;
    point_2d.set_value(0,10);
    point_2d.set_value(1,20);
    point_2d.print_info() ;

	return 0;
}