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
	Dog *d1 = new Dog("Doggo1", "Labrador", 7);
	Dog *d2 = new Dog("Doggo2");
	std::unique_ptr<Dog> d3{d1}; // This will move the content of d1 and developer need not worry about deleting the memory.
	d3.get()->print_info();
	d2->print_info();
	// d2 memory leaks!!
}
