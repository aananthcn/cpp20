#include <string>

//function declaration
template <typename T, typename P>
std::string concatenate(T a, P b);


//Function definition
template <typename T, typename P>
std::string concatenate(T a, P b) {
   return (std::to_string(a) + std::to_string(b));
}

#include <iostream>
 
int main()
{
    auto message = concatenate(11,22ul);
    std::cout << "result : " << message << std::endl;
    return 0;
}