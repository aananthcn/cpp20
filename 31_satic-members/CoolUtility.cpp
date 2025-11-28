#include <iostream>

class CoolUtility {
public:
	CoolUtility() = delete;
	CoolUtility(const char *str) : m_object_description(str) {} 

	static const inline char* s_general_description {"Cool utility to move us all to Mars"}; // In C++17, this is not allowed, you need to initialize it outside the class in a .cpp file.

	// member function
	void what_do_you_do() {
		std::cout << m_object_description << std::endl;
	}

private:
	const char* m_object_description;
};

int main() {
	CoolUtility cu("I can take you from point A to point #");
	cu.what_do_you_do();
	std::cout << "general purpose : " << CoolUtility::s_general_description << std::endl;

	return 0;
}
