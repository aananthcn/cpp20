#include <iostream>
#include <memory>

struct Point {
    Point (double x, double y) : m_x(x), m_y(y) {}
    ~Point(){
        std::cout << "Point object dying" << std::endl;
    }
    double m_x{};
    double m_y{};
};
 
class Line{
public : 
	Line(std::shared_ptr<Point> start, std::shared_ptr<Point> end)
		: m_start(start), m_end(end){}
	~Line() {
        std::cout << "Line destroyed!" << std::endl;
	}
 
	double start_x() const{
		return m_start->m_x;
	}
	double start_y() const{
		return m_start->m_y;
	}
 
	double end_x() const{
		return m_end->m_x;
	}
	double end_y() const{
		return m_end->m_y;
	}
 
private : 
    std::shared_ptr<Point> m_start;
    std::shared_ptr<Point> m_end;
};


int main() {
	std::shared_ptr<Point> p1 = std::make_shared<Point>(1,1);
    std::shared_ptr<Point> p2 = std::make_shared<Point>(2,2);

    {
	    Line l1(p1, p2);
    } // l1 must get destroyed here.

	return 0; // both p1 and p2 must gets destroyed here.
}