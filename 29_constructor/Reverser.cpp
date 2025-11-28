#include <iostream>
#include <vector>

class Reverser {
public:
    Reverser(std::initializer_list<int> list) : data(list) {
        if (data.empty())
            return; // nothing to reverse.

        auto i = data.begin(); // if you use list, then you will get compiler error, as list is const stuff.
        auto j = data.end() - 1;
        
        while (i < j) {
            std::swap(*i, *j); // swap saves copying to a temp var and then recopying.
            ++i;
            --j;
        }
    }

    void print() {
        std::cout << "Collection [";
        for (int elem : data) {
            std::cout << elem << " ";
        }
        std::cout << "\b]\n";
    }

private:
    std::vector<int> data;
};

int main() {
	Reverser r1{7,4,1,9,6};
	r1.print();
	Reverser r2 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	r2.print();
}