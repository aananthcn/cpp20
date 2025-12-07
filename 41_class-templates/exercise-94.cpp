#include <iostream>
#include <array>


//   N T T P   -   Non Template Type Parameters


template <typename T, std::size_t N> 
class Point {
private:
    T m_data[N];
public:
	void set_value(int i, T val) {
		if (i < N) {
			m_data[i] = val;
		}
	}

	T get_value(int i) {
		if (i < N) {
			return m_data[i];
		}
		return static_cast<T>(0);
	}

	void print_info() {
		std::cout << "point : [ "; 
		for (int i{}; i < N; i++) {
			std::cout << m_data[i] << " ";
		}
		std::cout << "]";
	}
};


int main() {
	// 3D Point
	Point<int,3> point_3d;
    point_3d.set_value(0,10);
    point_3d.set_value(1,20);
    point_3d.set_value(2,30);
    point_3d.print_info() ;

	// 2D Point
	Point<double,2> point_2d; // set up a two dimensional point object
    point_2d.set_value(0,10.22); // set up the first component with a double literal
    point_2d.set_value(1,20.11); // set up the second component with a double literal
    point_2d.print_info() ; // print info. should print  point : [ 10.22 20.11 ]
	
	// get value test
	std::cout << "\n\n get value test:";
	std::cout << "point2d[0]: " << point_2d.get_value(0) << std::endl;

	return 0;
}