#include <iostream>

void print_uppercase(){
            for( unsigned char i{0}; i< 255 ; ++i){
                
            //Don't modify anything above thie line
            //Your code goes below this line
            if (i == 65) {
                std::cout << i;
            }
			else if (i >= 66 && i <= 90) {
				std::cout << " " << i;
			}
            //Your code goes above this line
            //Don't modify anything after this line
        }
}

int main() {
	print_uppercase();
	return 0;
}