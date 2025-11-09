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
 
    double& x()  {
        double local_var{m_x};
        return local_var;
    }
    double& y()  {
        double local_var{m_y};
        return local_var;
    }
    //member variables
    private : 
    double m_x{1};
    double m_y{1};
};
 
 
int main()
{
     Point p1(21.2,4.2);
     std::cout << "value : " << p1.x() << std::endl;
     
    return 0;
}