#include <iostream>

#if 0 // change this to 1 if you want to try the 1st implementation
class Item {
public:
	Item() = default;
	~Item() {
		throw 42; // this is bad, as all destructors are noexcept functions by default!
	}
};
#else
class Item {
public:
	Item() = default;
	~Item() noexcept(false) {
		throw 42; // this is bad, as all destructors are noexcept functions by default!
	}
};
#endif

int main() {
	try {
		{
			Item tmp;
		}
	}
	catch (...) {
		std::cout << "Exception caught! You won't see this message if you use the first implementation of Item!" << std::endl;
	}

	return 0;
}