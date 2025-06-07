// Email: razcohenp@gmail.com

#include <iostream>
#include "MyContainer.hpp"

using namespace my_container; // Use the my_container namespace

int main() {
    // MyContainer demonstration
    std::cout << "--- MyContainer demonstration ---" << std::endl;

    MyContainer<int> c; // Create an instance of MyContainer with int type
    std::cout << "Initial container: " << c << std::endl; // []

    // Add elements to the container
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);
    c.add(9);
    std::cout << "After adding elements: " << c << std::endl; // [7, 15, 6, 1, 2, 9]

    // Size of the container
    std::cout << "Size: " << c.size() << std::endl; // Size: 6

    // Remove all occurrences of 9
    c.remove(9);
    std::cout << "After removing 9: " << c << std::endl; // [7, 15, 6, 1, 2]

    // Iterators demonstration
    std::cout << "\n--- Iterators demonstration ---" << std::endl;

    // AscendingOrder iterator
    std::cout << "AscendingOrder: ";
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        std::cout << *it << ' '; // 1 2 6 7 15
    }
    std::cout << std::endl;

    // DescendingOrder iterator
    std::cout << "DescendingOrder: ";
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        std::cout << *it << ' '; // 15 7 6 2 1
    }
    std::cout << std::endl;

    // SideCrossOrder iterator
    std::cout << "SideCrossOrder: ";
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        std::cout << *it << ' '; // 1 15 2 7 6
    }
    std::cout << std::endl;

    // ReverseOrder iterator
    std::cout << "ReverseOrder: ";
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it) {
        std::cout << *it << ' '; // 2 1 6 15 7
    }
    std::cout << std::endl;

    // Order iterator
    std::cout << "Order: ";
    for (auto it = c.begin_order(); it != c.end_order(); ++it) {
        std::cout << *it << ' '; // 7 15 6 1 2
    }
    std::cout << std::endl;

    // MiddleOutOrder iterator
    std::cout << "MiddleOutOrder: ";
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        std::cout << *it << ' '; // 6 15 1 7 2
    }
    std::cout << std::endl;

    return 0;
}