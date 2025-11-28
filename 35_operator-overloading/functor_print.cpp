#include <iostream>

class Print {
public:
	void operator()(std::string name) {
		std::cout << "The name is : " << name << std::endl;
	}

	void operator()(std::string fname, std::string lname) {
		std::cout << "The name is : " << fname << " " << lname << std::endl;
	}

private:
};


int main() {
	Print print;

	print("Bajaj");
	print("Bajaj", "Chetak");

	return 0;
}