#include <iostream>
#include <optional>
 
int main(){
 
    std::optional<int> age{};
    std::cout << "value : " << age.value() << std::endl;
    return 0;
}