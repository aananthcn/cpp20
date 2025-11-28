#include <iostream>
#include <string>

std::string get_day_name(int day) {
	switch (day) {
		case 1:
			return "Monday";
		case 2:
			return "Tuesday";
		case 3:
			return "Wednesday";
		case 4:
			return "Thursday";
		case 5:
			return "Friday";
		case 6:
			return "Saturday";
		case 7:
			return "Sunday";
		default:
			return "Invalid day!";
	}
}

int main() {
	int day, days_passed, past_day;
	std::string day_name, past_day_name;
	
	std::cout << "Which day is today [1: Monday, ..., 7: Sunday] : ";
	std::cin >> day;
	day_name = get_day_name(day);

	std::cout << "How many days passed since today: ";
	std::cin >> days_passed;
	past_day = day - (days_passed % 7);
	if (past_day <= 0) {
		past_day += 7;
	}
	past_day_name = get_day_name(past_day);


	if (day >= 1 && day <= 7) {
		std::cout << "Today is " << day_name << std::endl;
		std::cout << "If we went " << days_passed << " days back, we would hit a " << past_day_name << "." << std::endl;
	} else {
		std::cout << day << " is not a valid day. Bye!" << std::endl;
	}
}