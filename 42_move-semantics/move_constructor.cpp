#include <iostream>
// #include <algorithm>

class MemoryBlock {
public:
	// Constructor
	explicit MemoryBlock(size_t len) : m_length(len), m_data(new unsigned char[len]) {
		std::cout << "Constructor called, allocating memory of " 
			<< len << " bytes" << std::endl; 
	}

	// 🚛 Move Constructor
	MemoryBlock(MemoryBlock&& other) noexcept : m_data(nullptr), m_length(0) {
		std::cout << "Move constructor called, stealing data!" << std::endl;

		// steal the data and length from the other
		m_data = other.m_data;
		m_length = other.m_length;

		// reset the other
		other.m_data = nullptr;
		other.m_length = 0;
	}

	// Destructor
	~MemoryBlock() {
		std::cout << "Destructor called, deleting memory." << std::endl;
		delete[] m_data;
	}

private:
	unsigned char* m_data;
	size_t m_length;
};


MemoryBlock createBlock(bool condition) {
    MemoryBlock localObj1(20); 
    MemoryBlock localObj2(30);

    if (condition) {
        return localObj1; // Compiler often cannot optimize this path as easily
    } else {
        return localObj2; // Different named object on another path
    }
    // With multiple possible return objects, the compiler usually must use the move constructor as a fallback.
}

int main() {
	// MemoryBlock mb1 = std::move(MemoryBlock(50)); // move constructor will be called
	MemoryBlock mb1 = createBlock(true);
	MemoryBlock mb2(10); // regular constructor will be called

	return 0;
}