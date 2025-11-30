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
	std::cout << "use_count of p1 = " << p1.use_count() << std::endl;

    {
	    Line l1(p1, p2); // the use_count of p1 will go to 2 here
		std::shared_ptr<Point> p1_1 = p1; // use_count of p1 goes to 3 here
		std::cout << "use_count of p1 = " << p1.use_count() << std::endl;
    } // l1 must get destroyed here.

	// the use_count of p1 will drop to 1 here
	std::cout << "use_count of p1 = " << p1.use_count() << std::endl;

	return 0; // both p1 and p2 must gets destroyed here.
}