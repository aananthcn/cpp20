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


std::shared_ptr<Dog> get_shared_ptr(std::shared_ptr<Dog> arg) {
	std::cout << "\nPrinting from " << __func__ << "()\n";
	std::cout << "Use count of shared pointer = " << arg.use_count() << std::endl;
	return arg; // return a copy of pointer
}

std::unique_ptr<Dog> get_unique_ptr() {
	std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Function Local");
	std::cout << "unique_ptr address(" << __func__ <<") : " << &p_dog << std::endl;
	return p_dog;
}

int main() {
	std::shared_ptr<Dog> p1 = std::make_shared<Dog> ("Yunus"); // the only object of Dog is created here
	std::shared_ptr<Dog> p2 {p1};
	std::shared_ptr<Dog> p3 = p2;
	std::shared_ptr<Dog> p4 = get_shared_ptr(p3); // create a copy of pointer and pass

	std::cout << "\nPrinting from " << __func__ << "()\n";
	std::cout << "Use count of shared pointer (p2) = " << p1.use_count() << std::endl;
	p2.get()->print_info();
	std::cout << "Use count of shared pointer (p4) = " << p3.use_count() << std::endl;
	p4.get()->print_info();

	// try to convert a unique pointer to shared
	std::shared_ptr<Dog> p5 = get_unique_ptr();
	p5.get()->print_info();
	std::cout << "Use count of shared pointer (p5) = " << p5.use_count() << std::endl;

	// check if that can be shared
	std::shared_ptr<Dog> p6 {p5};
	p6.get()->print_info();
	std::cout << "Use count of shared pointer (p6) = " << p6.use_count() << std::endl;

	return 0;
}