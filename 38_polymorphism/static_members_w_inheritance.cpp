#include <iostream>

class Base {
public:
	Base(int x) : m_x(x) {
		m_count++;
	}
	static inline unsigned int m_count;
	virtual void print() const {
		std::cout << "data[ x : " << m_x << "]";
	}
protected:
	int m_x;
};


class Derived : public Base {
public:
	Derived(int x, int y) : Base(x), m_y(y) {
		m_count++;
	}
	static inline unsigned int m_count;
	virtual void print() const {
		std::cout << "data[ x : " << m_x << " y:" << m_y << "]";
	}
private:
	int m_y;
};

int main() {
	Base b1(10);
    Base b2(20);
    std::cout << "base count : " << Base::m_count << std::endl;
    Derived d1(30,40);
    Derived d2(50,60);
    std::cout << "base count : " << Base::m_count << std::endl;
    std::cout << "derived count : " << Derived::m_count << std::endl;

	Base * b_ptr1 = &b1;
    Base * b_ptr2 = &d1;
    b_ptr1->print();
    std::cout << "\n";
    b_ptr2->print();

	return 0;
}