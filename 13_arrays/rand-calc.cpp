#include <iostream>
#include <random>

constexpr char ops[] = {'+', '-', '*'};

int main() {
	std::cout << "Welcome to the greatest calculator on Earth!\n";
	bool keep_going = false;
	char user_choice;

	do {
		// seed the random number generator
		std::srand(static_cast<int>(std::time(0)));
		int op1 = std::rand() % 100;
		int op2 = std::rand() % 100;
		char operation = ops[std::rand() % std::size(ops)];

		// question the user and get input
		std::cout << "\nWhat's the result of " << op1 << " " << operation << " " << op2 << " : ";
		int user_result;
		std::cin >> user_result;

		int result;
		switch (operation) {
			case '+':
				result = op1 + op2;
				break;
			case '-':
				result = op1 - op2;
				break;
			case '*':
				result = op1 * op2;
				break;
			default:
				std::cerr << "Unknown operator!" << std::endl;
				return 1;
		}

		if (user_result == result) {
			std::cout << "Congratulations! Your got the result " << result << " right!\n";
		} else {
			std::cout << "Naah! The correct result is " << result << ".\n";
		}

		std::cout << "Do you want to try again (Y/N)? ";
		std::cin >> user_choice;
		keep_going = (user_choice == 'Y' || user_choice == 'y');

	} while (keep_going);

	return 0;
}