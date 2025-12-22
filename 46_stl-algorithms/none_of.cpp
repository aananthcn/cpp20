#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


bool is_odd(int n){
   return n % 2 != 0; 
}


int main(){

    // std::vector<int> collection{2,6,8,49,64,71};
    //std::set<int> collection{2,6,8,40,64,70};
    int collection[] {2,6,8,40,64,70};

    
    if (std::none_of(std::begin(collection), std::end(collection), is_odd)) {
        std::cout << "(std::none_of) :  None of the numbers is odd" << std::endl;
    }else{
        std::cout << "(std::none_of) : At least one number is odd" << std::endl;
    }

   
    return 0;
}