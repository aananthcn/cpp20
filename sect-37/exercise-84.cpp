#include <iostream>

//YOUR CODE WILL GO BELOW THIS LINE
//DON'T MODIFY ANYTHING ABOVE THIS LINE

class One {
public:
	One(){
		std::cout << "1";
	}
};

class Two : public One {
public:
	Two(){
		std::cout << "2";
	}
};

class Three : public Two {
public:
	Three(){
		std::cout << "3";
	}
};

//YOUR CODE WILL GO ABOVE THIS LINE
//DON'T MODIFY ANYTHING BELOW THIS LINE

inline void do_stuff(){
    Three t;
}


int main() {
	do_stuff();

	return 0;
}