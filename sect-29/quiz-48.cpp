#include <iostream>
 
class Point{
    public : 
    //methods
    Point(double x = 10.1, double y = 100.1)
        : m_x(x), m_y(y){
    }
 
    Point(const Point& p)
     : m_x(p.x()), m_y(p.y())
    {
    }
 
    Point( Point& p)
     : m_x(p.x()), m_y(p.y())
    {
        std::cout << " non const cpy ctor called..." << std::endl;
 
    }
 
    void set_x(double x){
        m_x = x;
    }
 
    void set_y(double y){
        m_y = y;
    }
 
    double x() const   {
        return m_x;
    }
    double y() const   {
        return m_y;
    }
    //member variables
    private : 
    double m_x{1};
    double m_y{1};
};
 
void print_point(Point& p){
    std::cout << "Point[x : " << p.x() << ", y : " << p.y() << "]" ;
}
 
 
int main()
{
    Point p1(25.1,32.2);
    Point p2(p1);
    print_point(p2);
     
    return 0;
}