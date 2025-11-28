#include <iostream>
 
int main(){
 
    unsigned int age{13};
 
    auto say_my_age = [age](){
        std::cout << "You are " << age << " years old!" << std::endl;
        ++age;
    };
    say_my_age();
    std::cout << "age " << age << std::endl;
 
    return 0;
}