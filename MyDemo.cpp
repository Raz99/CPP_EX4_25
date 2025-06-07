#include <iostream>
#include "MyContainer.hpp"

using namespace my_container;

int main() {
    MyContainer<int> c;
    c.add(1);
    c.add(2);
    c.add(1);

    // Size of the container
    std::cout << "Size: " << c.size() << std::endl;
    std::cout << c << std::endl; // [1, 2, 1]

    // Remove all occurrences of 1
    c.remove(1);
    std::cout << c << std::endl;  // [2]

    return 0;
}