#include <iostream>

void do_stuff( int& a,  int b){
	a++;
	b++;
}

int main(){
 
	int x{3};
	int y{4};

	std::cout << "Before do_stuff: x = " << x << ", y = " << y << std::endl;
	do_stuff(x,y);
	std::cout << "After do_stuff: x = " << x << ", y = " << y << std::endl;
 
	return 0;
}
