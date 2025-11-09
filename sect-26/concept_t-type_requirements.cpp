#include <iostream>
#include <type_traits>

// Define a concept that requires a nested type named "value_type"
template <typename T>
concept HasValueType = requires {
    typename T::value_type; // <-- Type requirement
};

// A type that satisfies the concept
struct MyContainer {
    using value_type = int; // Nested type exists
};

// A type that does NOT satisfy the concept
struct NoValueType { };

template <HasValueType T>
void printTypeName() {
    std::cout << "T has a nested type called value_type\n";
}

int main() {
    printTypeName<MyContainer>();  // ✅ Works
    // printTypeName<NoValueType>(); // ❌ Compile-time error
}
