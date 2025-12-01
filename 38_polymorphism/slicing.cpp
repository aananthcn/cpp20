#include <iostream>
class One {
    public : 
    One(int one ) : m_1 (one){
    }
    virtual void print() const{
        std::cout <<"data [one:" << m_1
            << "]\n" ;
    }
 
    protected : 
        int m_1{};
};
 
class Two : public One{
    public : 
    Two(int one, int two) : One(one), m_2(two) {
    }
 
    virtual void print() const{
        std::cout <<"data [one:" << m_1
            << " two:" << m_2 
            << "]\n" ;
    }
 
    protected : 
        int m_2{};
};
 
class Three : public Two{
    public : 
    
    Three( int one, int two, int three) : Two(one,two) , m_3(three){
    }
    
 
    virtual void print() const{
        std::cout <<"data [one:" << m_1
                 << " two:" << m_2 
                 << " three:" << m_3 << "]\n" ;
    }
    protected: 
        int m_3{};
};
 
 

int main()
{
    One one(1);
    Two two(10,20);
    Three three(100,200,300);
 
	std::cout << "One base = three; case:\n";
    One base = three; // Slicing off Three info and fit the One from Three into One
	base.print();
 
	std::cout << "One* base_ptr {&base}; case:\n";
    One* base_ptr {&base};
    base_ptr->print();
 
    return 0;
}