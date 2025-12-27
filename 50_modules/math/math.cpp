// import <iostream>; // this line generates error in LLVM
#include <iostream>
import math;

int main()
{
    auto result = add(10, 20);
    std::cout << "result : " << result << std::endl;

    greet("John");

    print_name_length("John");
}