#include <iostream>

class Base {
public:
	Base() = default;
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
	Base base1;

	// upcasting is safe (derived to base)
	// downcasting is mostly unsafe (base to derived)
	try {
		// base class doesn't contain info on new elements possessed by the derived class
		// hence casting a base class object (not a pointer) to derived object with a 
		// larger memory layout is wrong!
		Derived der1 {dynamic_cast<Derived&>(base1)};
	}
	catch(const std::exception& e) {
		std::cerr << "Exception occurred! Reason: " << e.what() << '\n';
	}
	
	return 0;
}