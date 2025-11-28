#include <iostream>
 
enum  DayOfWeek{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};
 
 
 
 
int main(){
 
    DayOfWeek day{DayOfWeek::Tuesday};
    std::cout << "day : " << day  << std::endl;
    return 0;
}