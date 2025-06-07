#include <iostream>
#include "MyContainer.hpp"

using namespace my_container;

int main() {
    MyContainer<int> c; // Create an instance of MyContainer with int type
    std::cout << "Initial container:" << std::endl;
    std::cout << c << std::endl; // []

    // Add elements to the container
    c.add(1);
    c.add(2);
    c.add(1);
    std::cout << "After adding elements (1, 2, 1):" << std::endl;
    std::cout << c << std::endl; // [1, 2, 1]

    // Size of the container
    std::cout << "Size: " << c.size() << std::endl; // Size: 3

    // Remove all occurrences of 1
    c.remove(1);
    std::cout << "After removing 1:" << std::endl;
    std::cout << c << std::endl;  // [2]

    std::cout << "[";
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        std::cout << *it << ' '; // 2
    }
    std::cout << "]" << std::endl;

    return 0;
}