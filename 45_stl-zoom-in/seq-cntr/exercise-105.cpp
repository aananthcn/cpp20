#include <list>
#include <iostream>
#include <iterator>
#include <stdexcept> // For std::out_of_range

template <typename T>
T& list_at(std::list<T>& l, size_t index) {
    if (index >= l.size()) {
        throw std::out_of_range("Index out of bounds");
    }

    auto it = l.begin();
    std::advance(it, index); // Moves the iterator O(n)
    return *it;
}

template <typename T, typename U>
void print_positions(std::list<T> l, std::list<U> p) {
	for (auto& i : p) {
		std::cout << "[" << i << "]:" << list_at(l, i) << std::endl;
	}
}

int main() {
	std::list<std::string> l = {"She","is","the","queen","of","the","blue","sky"};
	std::list<unsigned int> p = {2,7,1,6};
	print_positions(l,p);

	return 0;
}