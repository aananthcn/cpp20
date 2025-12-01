#include <iostream>

//YOUR CODE WILL GO BELOW THIS LINE
//DON'T MODIFY ANYTHING ABOVE THIS LINE

class One {
	public : 
	One(int one ) : m_1 (one){
	}
	virtual void print() const{
		std::cout <<"data [one:" << m_1
			<< "]" ;
	}
	virtual void print(const std::string& color)const{
			std::cout <<"data [one:" << m_1
			<< " color:" << color 
			<< "]" ;	
	}

	protected : 
		int m_1{};
};

class Two : public One{
	public : 
	Two(int one, int two) : One(one), m_2(two) {
	}

	 void print() const override{
		std::cout <<"data [one:" << m_1
			<< " two:" << m_2 
			<< "]" ;
	}

	virtual void print(const std::string& color) const {
			std::cout <<"data [one:" << m_1
			<<" two:" << m_2
			<< " color:" << color
			<< "]" ;	
	}

	protected : 
		int m_2{};
};

class Three : public Two{
	public : 
	
	Three( int one, int two, int three) : Two(one,two) , m_3(three){
	}
	

	 void print() const override{
		std::cout <<"data [one:" << m_1
				 << " two:" << m_2 
				 << " three:" << m_3
				  << "]" ;
	}

	virtual void print(const std::string& color) const {
		std::cout <<"data [one:" << m_1
		<<" two:" << m_2
		<<" three:" << m_3
		<< " color:" << color
		<< "]" ;	
	}

	protected: 
		int m_3{};
};

//YOUR CODE WILL GO ABOVE THIS LINE
//DON'T MODIFY ANYTHING BELOW THIS LINE


inline void do_stuff(){

	One one(1);
	Two two(10,20);
	Three three(100,200,300);

	one.print("red");
	std::cout << "\n";

	two.print("green");
	std::cout << "\n";

	three.print("blue");


}


int main() {
	do_stuff();
	
	return 0;
}