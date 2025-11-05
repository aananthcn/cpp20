#include <iostream>
 
//Declaration
auto add ( auto a , auto b) -> decltype(a +b);
 
int main()
{
    int x{33};
    double y{33.6};
    auto result = add(x,y);
    std::cout << "result : " << result << std::endl;
    return 0;
}
 
//Definition
auto add ( auto a , auto b)-> decltype(a +b){
    return a + b;
}
