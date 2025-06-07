#include <iostream>
#include "MyContainer.hpp"

using namespace my_container;

int main() {
    MyContainer<int> c; // Create an instance of MyContainer with int type
    std::cout << "Initial container:" << std::endl;
    std::cout << c << std::endl; // []

    // Add elements to the container
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);
    c.add(9);
    std::cout << "After adding elements:" << std::endl;
    std::cout << c << std::endl; // [7, 15, 6, 1, 2, 9]

    // Size of the container
    std::cout << "Size: " << c.size() << std::endl; // Size: 6

    // Remove all occurrences of 9
    c.remove(9);
    std::cout << "After removing 9:" << std::endl; // [7, 15, 6, 1, 2]
    std::cout << c << std::endl;

    // Ascending order iteration
    std::cout << "Ascending order: ";
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        std::cout << *it << ' '; // 1 2 6 7 15
    }
    std::cout << std::endl;

    return 0;
}