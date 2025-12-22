#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


int main(){

    // std::vector<int> collection{2,6,8,49,64,71};
    std::set<int> collection{2,6,8,40,64,70};
    //int collection[] {2,6,8,40,64,70};

    if (std::all_of(std::begin(collection), std::end(collection), [](int i){ return i % 2 == 0; })) {
        std::cout << "(std::all_of) :  All numbers in collection are even" << std::endl;
    }else{
        std::cout << "(std::all_of) : Not all numbers in collection are even" << std::endl;
    }

    return 0;
}