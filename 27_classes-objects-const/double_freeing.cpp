#include <iostream>
#include <string>

class Data {
public:
	Data(std::string value) : m_value(new std::string(value)) {}
	~Data() {
		delete m_value;
		m_value = nullptr;
	}

	std::string get_value() const { return *m_value; }
private:
	std::string* m_value;
};


void check_data(Data pass_by_value) {
	std::cout << "Checking Data value ==> " << pass_by_value.get_value() << std::endl;
}

void print_data(const Data& data_ref) {
	if (&data_ref == nullptr) {
		std::cout << "The important Data is lost! Poor programming & language!" << std::endl;
		return;
	}

	std::cout << "Printing Data value ==> " << data_ref.get_value() << std::endl;
}

int main() {
	Data data("Important Data");

	check_data(data); // This will cause double freeing issue
	print_data(data); // Although passing by reference is safe, but the data is already freed in last call!

	return 0;
}