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
 
void print_point( Point& p){
    std::cout << "Point[x : " << p.x() << ", y : " << p.y() << "]" ;
}
 
int main()
{
    const Point p1(21.2,4.2);
    // print_point(p1); // ❌ Compile-time error: cannot bind non-const lvalue reference of type 'Point&' to an rvalue of type 'Point'
    return 0;
}