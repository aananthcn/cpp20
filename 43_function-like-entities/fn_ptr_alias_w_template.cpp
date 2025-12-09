#include <iostream>
#include <string>

// A function template we want to point to
template <typename T>
void print_value(T value) {
    std::cout << "Printing Value: " << value << std::endl;
}

// An alias template for the function pointer type
template <typename T>
using Callback = void (*)(T); //

int main() {
    // Instantiate the alias for int and assign a function pointer
    Callback<int> int_callback = &print_value<int>;
    int_callback(10);

    // Instantiate the alias for std::string and assign a function pointer
    Callback<std::string> string_callback = &print_value<std::string>;
    string_callback("Hello, world!");

    return 0;
}
