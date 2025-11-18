#include <iostream>
#include <memory>

class Person {
public:
	Person() = delete;
	Person(std::string name) : m_name(name) {
		std::cout << "Person \'" << name << "\' created!" << std::endl;
	}
	~Person() { std::cout << "Object \'" << m_name << "\' destroyed!" << std::endl; }

	// member function
	void m_set_friend(std::shared_ptr<Person> p) {
		m_friend = p;
	}

private:
	std::weak_ptr<Person> m_friend;
	// std::shared_ptr<Person> m_friend; // if you uncomment the previous line and use this, then this program will leak memory!!
	std::string m_name {"Unnamed"};
};

int main() {
	std::shared_ptr<Person> p1 = std::make_shared<Person> ("Alex");
	std::shared_ptr<Person> p2 = std::make_shared<Person> ("Beth");

	// create a circular dependency
	p1.get()->m_set_friend(p2);
	p2.get()->m_set_friend(p1);

	return 0;
}