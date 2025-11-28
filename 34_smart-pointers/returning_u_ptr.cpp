#include <iostream>
#include <memory>


class Dog {
public:
	Dog() = delete;
	Dog(const char *n, const char *b, int a) : m_name(n), m_breed(b), m_age(a) {std::cout << "Dog \'" << n << "' created!\n";}
	Dog(const char *n) : Dog(n, "Sori Dog", 0) {}
	~Dog() {std::cout << "Dog \'" << m_name << "\' destroyed!\n";}
	void print_info() {
		std::cout << "Dog info:\n";
		std::cout << " name \t= " << m_name << "\n breed \t= " << m_breed << "\n age \t= " << m_age << "\n" << std::endl;
	}

private:
	std::string m_name {"Winston Churchil :-)"};
	std::string m_breed {"Breed that lead to millions die due to famine!"};
	int m_age {151}; // he must be bearing the karma even today (16 Nov 2025)
};


std::unique_ptr<Dog> get_unique_ptr() {
	std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Function Local");
	std::cout << "unique_ptr address(" << __func__ <<") : " << &p_dog << std::endl;
	return p_dog;
}


int main() {
	std::unique_ptr<Dog> pDog = get_unique_ptr();
	std::cout << "unique_ptr address(" << __func__ <<") : " << &pDog << std::endl;

	return 0;
}