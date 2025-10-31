#include <iostream>

double compute_average(const double (&array)[10]);
// double compute_average1(const double& array[10]); // you can not do this!!


int main(){
	// double values[10] = { 10.5, 20.0, 30.5, 40.0, 50.5, 60.0, 70.5, 80.0, 90.5, 100.0 };
	double values[10] = { 10, 20, 30 }; // rest are initialized to 0.0
	double avg = compute_average(values);
	std::cout << "Average: " << avg << std::endl;
	return 0;
}

double compute_average(const double (&array)[10]){
	double sum = 0.0;
	for (const double& value : array){
		sum += value;
	}
	return sum / std::size(array);
}
