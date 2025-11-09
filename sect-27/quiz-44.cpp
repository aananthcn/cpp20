#include <iostream>
 
struct Point{
    public : 
    //methods
    Point() = default;
    Point(double x, double y){
        m_x = x; 
        m_y = y;
    }
 
    void set_x(double x){
        m_x = x;
    }
 
    void set_y(double y){
        m_y = y;
    }
 
    double x(){
        return m_x;
    }
    double y(){
        return m_y;
    }
    //member variables
    private : 
    double m_x{1};
    double m_y{1};
};
 
void print_point( Point p){
	p.set_x(22.2);
	std::cout << "Point[x : " << p.x() << ", y : " << p.y() << "]" ;
}

void print_point2( Point* p){
    p->set_x(22.2);
    std::cout << "Point[x : " << p->x() << ", y : " << p->y() << "]" ;
}

void print_point3( const Point& p){
    p.set_x(22.2);
    std::cout << "Point[x : " << p.x() << ", y : " << p.y() << "]" ;
}

int main()
{
    const Point p1(21.2,4.2);
    print_point(p1);
	//print_point2(&p1);
	print_point3(p1);

    return 0;
}