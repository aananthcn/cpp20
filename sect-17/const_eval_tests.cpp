// #include <iostream>
 
// consteval int add ( int a, int b ) {
//     return a + b;
// }

// int main()
// {
//     int x { 10 };
//     int y { 20 };
//     auto result  = add(x,y);
//     std::cout << "result : " << result << std::endl;
//     return 0;
// }

// #include <iostream>
 
// consteval int add ( int a, int b ) {
//     return a + b;
// }
// int main()
// {
//     const int x { 10 };
//     const int y { 20 };
//     auto result  = add(x,y);
//     std::cout << "result : " << result << std::endl;
//     return 0;
// }

#include <iostream>
// #include "map.h"
 
consteval int add ( int a, int b ) {
    return a + b;
}
int main()
{
    int a { 10 };
    int b { 20 };
 
    const int x { a };
    const int y { b };
 
    auto result  = add(x,y);
    std::cout << "result : " << result << std::endl;
    return 0;
}