#include <iostream>
#include "MyContainer.hpp"

using namespace my_container;

int main() {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    std::cout << "Adding elements..." << std::endl;
    c.add(1);
    c.add(2);
    c.add(1);
    std::cout << c << std::endl; // [1, 2, 1]

    // Size of the container
    std::cout << "Size: " << c.size() << std::endl; // Size: 3

    // Remove all occurrences of 1
    std::cout << "Removing 1..." << std::endl;
    c.remove(1);
    std::cout << c << std::endl;  // [2]

    return 0;
}