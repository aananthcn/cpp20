#include <iostream>

enum class DayOfWeek {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

void print_day(DayOfWeek day){
    switch(day){
        case    DayOfWeek::Monday :
            std::cout << "Today is Monday";
        break;

        case    DayOfWeek::Tuesday :
            std::cout << "Today is Tuesday";
        break;

        case   DayOfWeek::Wednesday : 
            std::cout << "Today is Wednesday";
        break;

        case   DayOfWeek::Thursday : 
            std::cout << "Today is Thursday";
        break;

        case    DayOfWeek::Friday : 
            std::cout << "Today is Friday" ;
        break;

        case    DayOfWeek::Saturday : 
            std::cout << "Today is Saturday";

         case    DayOfWeek::Sunday :
            std::cout << "Today is Sunday" ;
        break;

        default : 
        std::cout << "No day";
    }
}

int main(){
	DayOfWeek today { DayOfWeek::Wednesday };
	print_day(today);
	std::cout << std::endl;
	return 0;
}