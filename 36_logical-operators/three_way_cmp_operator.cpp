#include <iostream>
#include <compare>
#include <limits>


int main() {
	int n1{5};
	int n2{5};
	int n3{0};

	auto iresult = (n1 <=> n2); // also known as spaceship operator

	std::cout << std::boolalpha;
	// std::cout << "n1 > n2 : " << (iresult > 0) << std::endl; // this throws error
	std::cout << "n1 > n2 : " << (iresult > 0) << "\n";
	// std::cout << "n1 > n2 : " << (iresult > n3) << "\n";  // throws error, can be compared with literal 0 only.
	// std::cout << "n1 > n2 : " << (iresult > 0.0) << "\n"; // throws error, cannot be compared with other than int literals only
	std::cout << "n1 >= n2 : " << (iresult >= 0) << "\n";
	std::cout << "n1 == n2: " << (iresult == 0) << '\n';
	std::cout << "n1 != n2: " << (iresult != 0) << '\n';
	std::cout << "n1 < n2 : " << (iresult < 0) << '\n';
	std::cout << "n1 <= n2 : " << (iresult <= 0) << '\n';

	std::string m1{"Hello"};
	std::string m2{"HELLO"};

	auto sresult = (m1 <=> m2);

	std::cout << "m1 > m2 : " << (sresult > 0) << "\n";
	std::cout << "m1 >= m2 : " << (sresult >= 0) << "\n";
	std::cout << "m1 == m2: " << (sresult == 0) << '\n';
	std::cout << "m1 != m2: " << (sresult != 0) << '\n';
	std::cout << "m1 < m2 : " << (sresult < 0) << '\n';
	std::cout << "m1 <= m2 : " << (sresult <= 0) << '\n';

	double d1{12.9};
	double d2{std::numeric_limits<double>::quiet_NaN()};

	auto dresult = (d1 <=> d2);

	std::cout << "d1 > d2 : " << (dresult > 0) << "\n";
	std::cout << "d1 < d2 : " << (dresult < 0) << "\n";
	std::cout << "d1 == d2 : " << (dresult == 0) << "\n";

	return 0;
}