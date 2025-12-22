#include <iostream>
#include <forward_list> // For std::forward_list
#include <algorithm>    // For std::find
#include <iterator>     // For std::distance (used to get size)

int main() {
    // 1. Initialization
    std::forward_list<int> flist = {10, 20, 30, 40};

    // 2. Adding Elements (Front-only)
    flist.push_front(5);      // {5, 10, 20, 30, 40}
    flist.emplace_front(0);   // {0, 5, 10, 20, 30, 40}

    // 3. Finding an Element with std::find()
    // Returns an iterator to the first instance of 30, or flist.end() if not found
    auto it = std::find(flist.begin(), flist.end(), 30);

    if (it != flist.end()) {
        std::cout << "Found value: " << *it << "\n";
        
        // 4. Modifying elements "After" a position
        // forward_list uses insert_after because it only knows the next node
        flist.insert_after(it, 35); // {0, 5, 10, 20, 30, 35, 40}
    }

    // 5. Deleting Elements
    flist.pop_front();        // Removes 0
    auto target = flist.begin(); // Pointing at 5
    flist.erase_after(target);   // Removes 10 (the element AFTER target)

    // 6. Common Utility Methods
    flist.reverse();          // Reverses the order
    flist.sort();             // Sorts the list (O(N log N))
    
    // Note: forward_list has no .size() method. Use std::distance instead.
    auto size = std::distance(flist.begin(), flist.end());
    std::cout << "List size: " << size << "\nElements: ";

	// Remove based on condition
	std::cout << "Removing 30..." << std::endl;
	flist.remove_if([](int n){return (n == 30);});

    for (int val : flist) {
        std::cout << val << " ";
    }

    return 0;
}
