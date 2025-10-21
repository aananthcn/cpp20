#include <iostream>
#include <string>

int main() {
	int day;
	std::string day_name;
	
	std::cout << "Which day is today [1: Monday, ..., 7: Sunday] : ";
	std::cin >> day;

	switch (day) {
		case 1:
			day_name = "Monday";
			break;
		case 2:
			day_name = "Tuesday";
			break;
		case 3:
			day_name = "Wednesday";
			break;
		case 4:
			day_name = "Thursday";
			break;
		case 5:
			day_name = "Friday";
			break;
		case 6:
			day_name = "Saturday";
			break;
		case 7:
			day_name = "Sunday";
			break;
		default:
			day_name = "Invalid day!";
			break;
	}

	if (day >= 1 && day <= 7) {
		std::cout << "Today is " << day_name << ". Let's have some fun!" << std::endl;
	} else {
		std::cout << day << " is not a valid day. Bye!" << std::endl;
	}
}