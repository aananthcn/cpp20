#include <iostream>

class A{
	protected :
	 int m_x;
};

class B : public A{
	public : 
		int m_y;
		void set_values(int x, int y, int z){
			m_x = x;
			m_y = y;
			m_z = z;
		}
		void print() const{
			std::cout << "x : " << m_x << ", y : " << m_y
				<< ", z : " << m_z;
		}

		friend void apply_changes(B& b);
	private : 
		int m_z;
};

inline void apply_changes(B& b){
	b.m_x *=2;
}

// Aananth created 'class C' to check the constructor level access at the time of creation.
class C : private B {
public:
	C(const B& b) {
		m_y = b.m_y;
	}
	int get_my() { return m_y; }
private:
};

int main() {
	B b;
    b.set_values(10,20,30);
    apply_changes(b);
    b.print();

	// constructor level access check
	C c{b};
	std::cout << "\nb.m_y = " <<  c.get_my() << std::endl;

	return 0;
}