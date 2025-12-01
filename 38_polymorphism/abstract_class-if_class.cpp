#include <iostream>

// Abstract class as interface
class StreamInsertable {
	friend std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand);

public:
	virtual void stream_insert(std::ostream& out) const = 0; // pure virtual function.
};

std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand) {
	operand.stream_insert(out);
	return out;
}


// Concrete class 
class Point : public StreamInsertable { // ❤️ This line does the magic of exposing all 
// functions and operators of base class to Point class. Because of this, point objects
// can be directly sent to output redirection operator '<<' without having to implement
// an operator overload functions in Point class!
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y) {}
	~Point() = default;

	virtual void stream_insert(std::ostream& out) const override {
		out << "Point [x:" << m_x << ", y: " << m_y << "]";
	}

private:
	double m_x {};
	double m_y {};
};


int main() {
	// create new Point object
	Point p1(2.3, 5.1);

	std::cout << p1 << std::endl;


	return 0;
}