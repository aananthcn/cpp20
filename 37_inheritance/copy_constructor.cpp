#include <iostream>

class Person {
public:
	Person(std::string n, double a) : m_name(n), m_age(a) {}
	void print() {
		std::cout << " Name :" << m_name << std::endl;
		std::cout << " Age  :" << m_age << std::endl;
	}
private:
	std::string m_name;
	double m_age;
};


class Engineer : public Person {
public:
	// copy constructor, passing the bigger Engineer object to Person
	Engineer(Engineer& e) : Person(e), m_discipline(e.m_discipline) {
		std::cout << "COPY CONSTRUCTOR IS INVOKED" << std::endl;
	}

	// normal constructor
	Engineer(std::string n, std::string d, double a) : Person(n, a), m_discipline(d) {
		std::cout << "NORMAL CONSTRUCTOR IS INVOKED" << std::endl;
	}
	void print() {
		Person::print();
		std::cout << " Dept :" << m_discipline << std::endl;
	}
private:
	std::string m_discipline;
};


int main() {
	Engineer a("Aananth", "EEE", 49.9);
	Engineer b(a);

	b.print();

	return 0;
}