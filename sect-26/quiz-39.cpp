#include <iostream>
#include <concepts>
 
template <typename T>
concept ConvertibleToStdString = requires( T n) {
                                     std::to_string(n);
                                 };
 
template <typename T>
requires ConvertibleToStdString<T>
auto concatenate(const T n1, const T  n2)
 -> decltype(std::to_string(n1) + std::to_string(n2));
 
 
int main(){
	// Calling the function with same types
	auto result1 = concatenate(11,22);
	std::cout << "result1 : " << result1 << std::endl;
 
	// Calling the function with different types - should cause compilation error
   	// auto result2 = concatenate(11,22.22); // ❌ Compile-time error
   	// std::cout << "result2 : " << result2 << std::endl;

	return 0;
}

template <typename T>
	requires ConvertibleToStdString<T>
auto concatenate(const T n1, const T n2)
	-> decltype(std::to_string(n1) + std::to_string(n2)) {
	return std::to_string(n1) + std::to_string(n2);
}