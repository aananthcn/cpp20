#include <iostream>

template <typename T>
class Adder {
public:
	Adder() = default;

	T add(T a, T b) {
		return a+b;
	}

	void do_something() {
		std::cout << "Doing something..." << std::endl;
	}
private:
};


// Template Specialization
template <>
class Adder <char*> {
public:
	Adder() = default;

	char* add(char* a, char* b) {
		return strcat(a, b);
	}

	// intentionally not defined the do_something() in the specialized template class
};


int main() {
	Adder<int> adder_int;
	adder_int.do_something();
	std::cout << "10 + 20 = " << adder_int.add(10, 20) << std::endl;

	Adder<char*> adder_cstr;
	//adder_cstr.do_something(); // this function is not available, as we have not defined it in specialization class
	char str1[32] = {"Hello"};
	char str2[] = {" Aananth!"};
	std::cout << "Hello + Aananth! = " << adder_cstr.add(str1, str2) << std::endl;

	return 0;
}
