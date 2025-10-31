#include <iostream>

void do_stuff( int* a,  int* b){
    //(*a)++;
    *a++;
}

int main(){
 
    int x{3};
    int y{4};
    do_stuff(&x,&y);
    std::cout << x << std::endl;
 
    return 0;
}