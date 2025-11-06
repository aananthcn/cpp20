#include <iostream>
#include <concepts>
#include <string>

template <typename T, typename U>
concept ConvertibleToStdString = requires(T n, U m) {
                                     std::to_string(n);
									 std::to_string(m);
                                 };
 
template <typename T, typename U>
requires ConvertibleToStdString<T, U>
 auto concatenate(const T   n1, const U  n2) 
 ->decltype(std::to_string(n1) + std::to_string(n2)) 
{
    return std::to_string(n1) + std::to_string(n2);
}

int main(){
 
   auto result = concatenate(11,22.22);
   std::cout << "result : " << result << std::endl;
   return 0;
}