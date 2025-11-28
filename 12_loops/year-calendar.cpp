#include <iostream>
#include <string>
#include <iomanip>

std::string weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int get_days_in_month(int year, int month) {
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			// Check for leap year
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				return 29;
			} else {
				return 28;
			}
		default:
			return 0; // Invalid month
	}
}

std::string get_month_name(int month) {
	switch (month) {
		case 1: return "January";
		case 2: return "February";
		case 3: return "March";
		case 4: return "April";
		case 5: return "May";
		case 6: return "June";
		case 7: return "July";
		case 8: return "August";
		case 9: return "September";
		case 10: return "October";
		case 11: return "November";
		case 12: return "December";
		default: return "Invalid Month";
	}
}

int main() {
	int year, day;
	constexpr int col_width{5};

	std::cout << "Enter year: ";
	std::cin >> year;
	std::cout << "Enter day of the New Year (1=Sun, 2=Mon, ..., 7=Sat): ";
	std::cin >> day;

	std::cout << "Calendar for " << year;

	for (int month = 1; month <= 12; ++month) {
		std::cout << "\n\n-- " << get_month_name(month) << " " << year << " --\n";

		// Print days of the week header
		for (int i {0} ; auto wd : weekdays) {
			std::cout << std::setw(col_width) << wd;
			if (++i == 7) {
				std::cout << "\n"; // New line at the end of the week
			}
		}

		// Print leading spaces for the first day
		for (int i = 1; i < day; ++i) {
			std::cout << std::setw(col_width) << " ";
		}

		// Print the days of the month
		int days_in_month = get_days_in_month(year, month);
		for (int date = 1; date <= days_in_month; ++date) {
			std::cout << std::setw(col_width) << date;
			if ((day + date - 1) % 7 == 0) {
				std::cout << "\n"; // New line at the end of the week
			}
		}

		// Update the starting day for the next month
		day = (day + days_in_month - 1) % 7 + 1;
	}
}