#include <iostream>
#include <cmath>
 
class Point{
    public : 
    //methods
    Point() = delete;
    Point(double x, double y)
        : m_x(x), m_y(y){
    }
 
    Point(const Point& p)
     : m_x(p.x()), m_y(p.y())
    {
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
 
     static size_t point_count() {
        return s_point_count;
    }
 
      static Point* get_memory_location(){
            return this;
    }
 
 
    static inline size_t s_point_count{};
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
    Point p1(10.1,20.2);
    print_point(p1);
 
    return 0;
}