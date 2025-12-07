#ifndef POINT_H_AANANTH_19
#define POINT_H_AANANTH_19

#include <iostream>

template <typename T = int , unsigned int size = 2>
class Point{
    T m_components[size];
public :
    unsigned int get_size() const{
        return size;
    }
    void set_value(unsigned int index, T value){
        m_components[index] = value;
    }

	// make friend with outside functions
	template <typename U, unsigned int N>
    friend std::ostream& operator<<(std::ostream& out, const Point<U,N>& right);
};


// should print: Point : [ dimension :  3, components : 10 20 30 ]
template <typename T, unsigned int size>
std::ostream& operator<<(std::ostream& out, const Point<T,size>& right) {
    out << "Point : [ dimension : " << right.get_size() << ", components : ";
    for (unsigned int i{}; i < right.get_size(); ++i){
        out << right.m_components[i] << ' ';
    }
    out << ']';
    return out;
}

#endif