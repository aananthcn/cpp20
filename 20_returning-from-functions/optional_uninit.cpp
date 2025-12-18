#include <iostream>
#include <optional>
 
int main(){
 
    std::optional<int> age{};

    // The following line will throw `bad optional access` exception as
    // age is not initialized with a proper value.
    std::cout << "value : " << age.value() << std::endl;

    return 0;
}
