#include <iostream>
#include <list>      // For std::list
#include <algorithm> // For std::find

int main() {
    // 1. Initialization
    std::list<int> myList = {5, 10, 15, 20, 25, 30, 35};

    // 2. Efficiently Adding Elements
    myList.push_front(0);   // {0, 5, 10, 15, 20, 25, 30, 35}
    myList.push_back(40);    // {0, 5, 10, 15, 20, 25, 30, 35, 40}

    // 3. Finding an Element with std::find()
    auto it = std::find(myList.begin(), myList.end(), 20);
    if (it != myList.end()) {
        myList.insert(it, 22); // {..., 15, 22, 20, 25, ...}
    }

    // --- NEW: REVERSE TRAVERSAL SECTION ---
    // std::list supports bidirectional iterators. 
    // rbegin() points to the last element, and rend() points to the "element" before the first.
    std::cout << "List in Reverse: ";
    for (auto rit = myList.rbegin(); rit != myList.rend(); ++rit) {
        std::cout << *rit << " "; 
    }
    std::cout << "\n";
    // --------------------------------------

    // 4. Using remove_if() with a Lambda
    myList.remove_if([](int n) { 
        return n > 25; // Removes 30, 35, and 40
    });

    // 5. Using remove() for specific values
    myList.remove(10); 

    // 6. Displaying the final list (Forward)
    std::cout << "Final List (Forward): ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << "\nSize: " << myList.size() << std::endl;

    return 0;
}
