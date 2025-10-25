#include <iostream>
 
int main(){
    
    int age{33};
    int& age_ref{age};

	const int vayasu {44};
	// int& vayasu_ref{vayasu};  // error: cannot bind non-const lvalue reference to const
	const int& vayasu_ref{vayasu}; // okay: const lvalue reference can bind to const
 
    std::cout << "--Before--" << std::endl;
    std::cout << "age_ref: " << age_ref << std::endl;
    std::cout << "&age_ref : " << &age_ref << std::endl;
 
    int age1 {44};
	const int age2 {55};
    age_ref = age1;
	// vayasu_ref = age1; // error: cannot assign to a variable that is const
	// vayasu_ref = age2; // error: cannot assign to a variable that is const
 
    std::cout << "--After--" << std::endl;
    std::cout << "age_ref: " << age_ref << std::endl;
    std::cout << "&age_ref : " << &age_ref << std::endl;
 
    return 0;
}