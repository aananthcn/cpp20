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


int main() {
	auto p_dogs = std::unique_ptr<Dog[]> (new Dog[3] {Dog("Aurangazeb"), Dog("Reginald"), Dog("Agnew")});
	//auto p_dogs = std::make_unique<Dog[]> (5); // this syntax works, if default constructor for Dog is enabled.
	std::cout << "\nObjects created:" << std::endl;
	for(int i; i < 3; i++) {
		p_dogs[i].print_info();
	}
	return 0;
}
