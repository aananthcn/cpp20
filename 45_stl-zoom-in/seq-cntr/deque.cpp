#include <iostream>
#include <deque>

int main() {
    // 1. Initialization
    std::deque<int> dq = {10, 20, 30}; // Initializer list

    // 2. Adding Elements
    dq.push_back(40);    // Adds to the end: {10, 20, 30, 40}
    dq.push_front(5);    // Adds to the front: {5, 10, 20, 30, 40}
    dq.emplace_back(50); // Constructs in-place at back

    // 3. Accessing Elements
    std::cout << "Front: " << dq.front() << "\n"; // Returns 5
    std::cout << "Back: " << dq.back() << "\n";   // Returns 50
    std::cout << "Index 2: " << dq[2] << "\n";    // Random access (20)

    // 4. Removing Elements
    dq.pop_front();      // Removes 5: {10, 20, 30, 40, 50}
    dq.pop_back();       // Removes 50: {10, 20, 30, 40}

    // 5. Capacity & Utilities
    std::cout << "Current size: " << dq.size() << "\n"; // 4
    if (!dq.empty()) {
        std::cout << "Deque is not empty.\n";
    }

    // 6. Iterating through the deque
    std::cout << "Elements: ";
    for (int val : dq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
