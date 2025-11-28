#include <iostream>
#include <memory>

struct Point {
    Point (double x, double y) : m_x(x), m_y(y) {std::cout << "Point Obj. created!\n";}
    ~Point() {std::cout << "Point Obj. destroyed!\n";}
    double m_x{};
    double m_y{};
};

class Line{
public : 
    Line(std::unique_ptr<Point> start, std::unique_ptr<Point> end) : m_start(std::move(start)), m_end(std::move(end)) {
        std::cout << "Line Obj. created!\n";
    }
    ~Line() {std::cout << "Line Obj. destroyed!\n";}
 
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
    std::unique_ptr<Point> m_start {};
    std::unique_ptr<Point> m_end {};
};


int main() {
	// Point *p1 = new Point {1, 1};
	// Point *p2 = new Point {2, 2};
	std::unique_ptr<Point> p1 = std::make_unique<Point>(1,1);
    std::unique_ptr<Point> p2 = std::make_unique<Point>(2,2);

	// Line l1 {p1, p2};
	Line l1(std::move(p1),std::move(p2));

	// delete p1;
	// delete p2;

	return 0;
}