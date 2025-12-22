#include <iostream>

//YOUR IMPLEMENTATIONS WILL GO IN THIS FILE. DON'T TOUCH THE HEADER FILE
class MovableStack {
public:
    MovableStack();
    ~MovableStack();
    MovableStack(const MovableStack& other);
    MovableStack(MovableStack&& other) noexcept;
    MovableStack& operator=(const MovableStack& other);
    MovableStack& operator=(MovableStack&& other) noexcept;

    void push(int value);
    int pop();
    int top() const;
    bool empty() const;
    int getSize() const;

private:
    int size;
    int capacity;
    int* data;
};

//Implementation of the default constructor and destructor
MovableStack::MovableStack() : size(0), capacity(5) {
	data = new int[capacity];
	if (data == nullptr) {
		std::cout << "Initial stack allocation failed!!" << std::endl;
	}
}

MovableStack::~MovableStack() {
	delete[] data;
}


//Implementation for the copy and move constructors
MovableStack::MovableStack(const MovableStack& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    for (int i {}; i < other.size; i++) {
        data[i] = other.data[i];
    }
}

MovableStack::MovableStack(MovableStack&& other) noexcept : 
        size(other.size), capacity(other.capacity), data(other.data) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}


//Implemetations for the copy and move assignment operators
MovableStack& MovableStack::operator=(const MovableStack& other) {
    // self assignment check
    if (this == &other) return *this;

    // delete the current to prevent memory leak
    delete[] data;

    // copy the other data
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i {}; i < other.size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

MovableStack& MovableStack::operator=(MovableStack&& other) noexcept {
    // self assignment check
    if (this == &other) return *this;

    // delete the current to prevent memory leak
    delete[] data;
 
    // move data
    size = other.size;
    capacity = other.capacity;
    data = other.data;

    // clear the other
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}


// push() as implemented by Udemy
void MovableStack::push(int value) {
    if (size == capacity) {
        int* newData = new int[capacity * 2];
        std::copy(data, data + size, newData);
        delete[] data;
        data = newData;
        capacity *= 2;
    }
    data[size++] = value;
}

// Implemetations of top(), pop(), empty() and getSize()
int MovableStack::pop() {
	if (size > 0) {
		return data[--size];
	}

	return -1;
}

int MovableStack::top() const {
    if (size == 0) {
        throw std::out_of_range("Stack is empty");
    }
    return data[size - 1];
}

bool MovableStack::empty() const {
	return (size == 0);
}

int MovableStack::getSize() const {
	return size;
}


// Test Functions
int main() {
	MovableStack stack;
    std::cout << stack.getSize() << std::endl;// Prints 0
 
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout<< stack.getSize() << std::endl;// Prints 3
 
    stack.pop();
    std::cout << stack.getSize() << std::endl;// Prints 2
 
    stack.pop();
    std::cout << stack.getSize() << std::endl;// Prints 1
    
    stack.pop();
    std::cout << stack.getSize() << std::endl;// Prints 0

	return 0;
}