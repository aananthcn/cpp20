#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


class DivisibleBy
{
    private : 
        const int d;
    public : 
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; }
};
 
int main(){

    std::vector<int> collection{2,6,8,49,64,71};
    //std::set<int> collection{2,6,8,40,64,70};
    //int collection[] {2,6,8,40,64,70};

    if (std::any_of(std::begin(collection),std::end(collection), DivisibleBy(7))) {
        std::cout << "(std::any_of) : At least one number is divisible by 7" << std::endl;
    }else{
        std::cout << "(std::any_of) : None of the numbers is divisible by 7" << std::endl;
    }

    return 0;
}