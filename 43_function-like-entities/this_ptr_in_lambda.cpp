#include <iostream>

class Item {
public:
	Item(int x) : m_var(x) {}
	void some_member_func() {
		auto func = [this] () {
			std::cout << "Member m_var = " << m_var << ", can be accesed inside lambda" << std::endl;
			std::cout << "This is only possible because of [this] pointer is passed via the capture list" << std::endl;
		};

		func();
	}
private:
	int m_var;
};

int main() {
	Item i1 {200};

	i1.some_member_func();

	return 0;
}