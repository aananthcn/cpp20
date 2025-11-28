#include <iostream>

class A{
	public:
		void set_x(int x) {m_x = x;}
		int get_x() const {return m_x;}
	private :
	 int m_x;
};

class B : public A{
	public : 
		int m_y;
		void set_values(int x, int y, int z){
			//m_x = x;
			set_x(x);
			m_y = y;
			m_z = z;
		}
		void print() const{
			std::cout << "x : " << get_x() << ",y : " << m_y
				<< ",z : " << m_z ;
		}
	private : 
		int m_z;
};


int main() {
	B b;
    b.set_values(10,20,30);
    b.print();

	return 0;
}