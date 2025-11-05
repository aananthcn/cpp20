#include <iostream>
 
template <typename T, typename P>
auto add(T a, P b) -> decltype(a +b);
 
int main()
{
    auto result = add(11,22ul);
    std::cout << "result : " << result << std::endl;
    return 0;
}
 
 
