module;
// Global module fragment

#include <string>
#include <iostream>

export module math; // Module declaration
//Module preamble
// import <iostream>;

//Module purview
export {
	double add(double a, double b);
	void greet(const std::string& name);
	void print_name_length(const char* c_str_name);

	class Point {
	public:
		Point() = default;
		Point(double x, double y);
		friend std::ostream& operator << (std::ostream& out, const Point& point) {
			out << "Point [ x : " << point.m_x << ", y : " << point.m_y << "]";
			return out;
		}
	private:
		double m_x;
		double m_y;
	}; // class Point
}