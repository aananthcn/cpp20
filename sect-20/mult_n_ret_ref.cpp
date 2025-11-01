// #include <iostream>
 
// double multiply( const double& a,  const double& b){
//     return a*b;
// }

// int main( ){
 
//   double result = multiply(10.0,20.0);
//   std::cout << "result : " << result << std::endl;
 
//     return 0;
// }

#include <iostream>
 
double& multiply(  double& a,   double& b){
    return a*=b;
}

int main() {
	auto value1{10.0};
	auto value2{20.0};

	double result = multiply(value1, value2);
	std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2 << std::endl;
	++result; // ++ thing won't modify value1, here as result is a copy of value1
	std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2 << std::endl;

	return 0;
}