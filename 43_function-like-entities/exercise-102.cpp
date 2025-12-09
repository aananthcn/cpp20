#include <iostream>


class Printer {
public:
	Printer(std::string color) : m_color(color) {}
	std::string operator()(std::string arg) {
		return std::string("[color: ")+m_color+", message: " + arg + "]";
	}

private:
	std::string m_color;
};


int main() {
	// to print: [color: red, message: Hello]
	Printer red_printer("red");
    auto result = red_printer("Hello");
    std::cout << result  << std::endl;

	// to print: [color: green, message: The sky is blue my friend!]
	Printer red_printer2("green");
    auto result2 = red_printer2("The sky is blue my friend!");
    std::cout << result2  << std::endl;

	return 0;
}