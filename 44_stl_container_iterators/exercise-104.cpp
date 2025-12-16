#include <iostream>
#include <list>
#include <algorithm>

template <typename T>
std::list<T> union_func(const std::list<T>& l1, const std::list<T>& l2){

    std::list<T> result;
    auto itl1 = l1.begin();
    auto itl2 = l2.begin();
    
    //YOUR CODE WILL GO BELOW THIS LINE 
    //DON'T MODIFY ANYTHING ABOVE THIS LINE
    while (itl1 != l1.end()) {
		bool found = false;

		for (const auto& item : result) {
			if (item == *itl1) {
				found = true;
				break;
			}
		}
		if (!found) {
			result.push_back(*itl1);
		}
		itl1++;
	}

    while (itl2 != l2.end()) {
		bool found = false;
		for (auto& item : result) {
			if (item == *itl2) {
				found = true;
				break;
			}
		}
		if (!found) {
			result.push_back(*itl2);
		}
		itl2++;
	}

	result.sort();
    
    //YOUR CODE WILL GO ABOVE THIS LINE 
    //DON'T MODIFY ANYTHING BELOW THIS LINE

    return result;

}

template <typename T>
void print_list( const std::list<T>& l){

    for(auto &e : l){
        std::cout << e << " ";
    }
    std::cout << std::endl;

}


int main() {
	std::list<int> l1 = {3, 4, 5,7,11};
    std::list<int> l2 = {1,4,6,7,9};

	std::list<int> l3 = union_func(l1, l2);
	
	print_list(l3);
	return 0;
}