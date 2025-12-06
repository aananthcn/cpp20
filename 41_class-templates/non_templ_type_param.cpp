#include <iostream>
#include <array>


//   N T T P   -   Non Template Type Parameters

// Avoid using this as for every different value of N (in the example below) the template
// would generate separate code for it and we will end up having a larger .text size. Use
// the normal way to setup the size during constructor as much as possible.
//
// But, safety (embedded) systems may be willing to compromise more .text size for safety.


template <typename T, std::size_t N> 
class StaticArray {
private:
    T arr[N]; // The size N is a compile-time constant
public:
    T& operator[](std::size_t pos) {
        if (pos >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[pos];
    }
    std::size_t size() const { return N; }
};


int main() {
    // Instantiation: T is int, N is 10
    StaticArray<int, 10> a1; 
    
    // Instantiation: T is double, N is 5
    StaticArray<double, 5> a2; 

    a1[0] = 42;
    std::cout << "Array size: " << a1.size() << ", Element 0: " << a1[0] << std::endl;

    return 0;
}
