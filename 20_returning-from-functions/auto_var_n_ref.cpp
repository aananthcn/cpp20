#include <iostream>


int main() {
	// double
	double d = 10.0;
	auto ad = d;
	ad++;
	std::cout << "d   : " << d << ", ad   : " << ad << std::endl;

	// const double
	const double cd = d;
	auto acd = cd;
	// acd++; // error: cannot modify a const value
	std::cout << "cd  : " << cd << ", acd  : " << acd << " (const case)" << std::endl;

	// double&
	double& rd = d;
	auto ard = rd;
	ard++;
	std::cout << "d   : " << d << ", ard  : " << ard << std::endl;

	// auto& = double&
	double& rad = d;
	auto& arad = rad;
	arad++; // NOTE: this modifies rad
	std::cout << "rad : " << d << ", arad : " << arad << " (auto& case)" << std::endl;

	// const double&
	const double& rcd = cd;
	auto arcd = rcd;
	// arcd++; // error: cannot modify a const value
	std::cout << "cd  : " << cd << ", arcd : " << arcd << " (const case)" << std::endl;

	return 0;
}