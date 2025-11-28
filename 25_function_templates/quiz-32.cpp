#include <iostream>
 
template <typename T>
T maximum( T a, T b){
    return (a > b) ? a : b;
}
 
int main()
{
    int a = 10;
    double b = 20.7;
    auto result =  maximum<long int>(a,b);
    std::cout << "result : " << result << std::endl;
    return 0;
}