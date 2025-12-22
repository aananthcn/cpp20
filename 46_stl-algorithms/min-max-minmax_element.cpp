#include <iostream>
#include <algorithm>
#include <set>
#include <list>


int main(){

    //std::vector<int> v {3,400,51,6,7,23,56,71};
    //int v[] {3,400,51,6,7,1123,56,71};
    std::list<int> v {3,400,51,6,7,23,56,71};

	// M A X   E L E M E N T
    auto result = std::max_element(std::begin(v), std::end(v));
    std::cout << "max element is : " << *result << std::endl;

	// M I N   E L E M E N T
    result = std::min_element(std::begin(v),std::end(v));
    std::cout << "min element is : " << *result << std::endl;


    std::cout << "----------" << std::endl;

    //Distances : closest and furthest
    int number_to_find {100};
    
    auto distance = [number_to_find](int x, int y){
        return (std::abs(x-number_to_find) < std::abs(y-number_to_find));
    };
    
    //Finding the closest
    result = std::min_element(std::begin(v),std::end(v),distance);
    std::cout << *result << " is closest to " << number_to_find << std::endl;
    
    //Finding the furthest
    result = std::max_element(std::begin(v),std::end(v),distance);
    std::cout << *result << " is furthest from  " << number_to_find << std::endl;


    std::cout << "--------------------------------" << std::endl;


	// M I N M A X   E L E M E N T
    const auto[near,far] = std::minmax_element(std::begin(v),std::end(v),distance);
    std::cout << *near << " is closest to " << number_to_find << std::endl;
    std::cout << *far << " is furthest from  " << number_to_find << std::endl;
    
    return 0;
}