#include <iostream>  

int main(){
	// infinite loop example
	for( unsigned char i{10}; i >= 0 ; --i){
		std::cout << "value : " << static_cast<unsigned int>(i) << std::endl;
	}
	
	return 0;
}