#include <iostream>

class One {
	public : 
	One(int one ) : m_1 (one){
	}

	One(const One& source) : m_1(source.m_1) {}

	protected : 
		int m_1;
};

class Two : public One{
	public : 
	Two(int one, int two) : One(one), m_2(two) {
	}
	
	Two(const Two& source) : One(source), m_2(source.m_2) {}
	
	protected : 
		int m_2;
};

class Three : public Two{
	public : 
	Three( int one, int two, int three) : Two(one,two) , m_3(three) {}
	//Copy constructor
	Three(const Three& source) : Two(source), m_3(source.m_3) {}

	void print() const{
		std::cout <<"data [one:" << m_1
				 << " two:" << m_2 
				 << " three:" << m_3 << "]" ;
	}
	protected: 
		int m_3;
};

int main() {
	Three t1(11,2,7);
    Three t2 = t1;
    t2.print();

	return 0;
}