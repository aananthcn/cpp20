#include <iostream>

class Person {
public:
	Person(std::string n, std::string c) : name(n), caste(c) {};
protected:
	std::string name;
private:
	std::string caste; // the myth, indians believe
};


class Engineer : private Person {
public:
	Engineer(std::string n, std::string d) : Person(n, "Unknown"), department(d) {}

	// member variables
	using Person::name; // resurrected member, because it is either protected or private originally.
	// using Person::caste; // can't resurrect the private members.
	std::string department;
};


class Employee : public Engineer {
public:
    // following constructor was later added to prove that we can also intialize the base class Engineer from here.
	Employee(std::string n, std::string c, std::string d, double e) : Engineer(n, d), experience(e), college(c) {}

	// member functions, can access name because it was resurrected in Engineer
	Employee(std::string n, std::string d, double e) : Engineer(n, d) {
		name = n;
		department = d;
		experience = e;
		college = "Unknown";
	}

	void print_details() {
		std::cout << "Employee Details:" << "\n\tName: " << name << "\n\tDiscipline: " << department << "\n\tExperience: " << experience << " years" << std::endl;
		std::cout << "\tCollege: " << college << std::endl;
	}

	// member variables
	double experience;
protected:
	std::string college;
};


int main() {
	Employee e1 {"Aananth C N", "EEE", 25.5};
	e1.print_details();

	// to demonstrate the custom constructor that initializes the base class Engineer from here.
	Employee e2 {"Aananth C N", "IIT Madras", "Elect. Engg.", 25.5};
	e2.print_details();

	return 0;
}