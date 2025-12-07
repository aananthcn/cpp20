#include <iostream>

template <typename T = int , unsigned int size = 2>
requires std::is_arithmetic_v<T> // C++20 Concept

class Point{
private:
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

// operator <<
template <typename T, unsigned int size>
std::ostream& operator<<(std::ostream& out, const Point<T,size>& right) {
    out << "Point : [ dimension : " << right.get_size() << ", components : ";
    for (unsigned int i{}; i < right.get_size(); ++i){
        out << right.m_components[i] << ' ';
    }
    out << ']';
    return out;
}


template <typename T, int size>
requires std::is_default_constructible_v<T>

class Box {
private:
	T *m_items;
public:
#if 1 // set this to 0, to get a compiler error
	Box() {
		m_items = new T[size];
	}
#else
	Box() = delete;
#endif
	~Box() {
		delete [] m_items;
		m_items = nullptr;
	}
};


int main() {
	Point p1;
	Point<double, 5> p2;

	// uncomment the following to get the exception
	//Point<std::string, 7> p3;

	Box<double, 10> b1;

	std::cout << "The program ends now, without crash!" << std::endl;

	return 0 ;
}