#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <numeric> // For std::iota

namespace my_container {
    template <typename T = int> // Default type is int
    
    class MyContainer {
        private:
        std::vector<T> data; // Internal storage for elements

        public:
        // Forward declaration of iterator classes
        class AscendingOrder;
        class DescendingOrder;
        class SideCrossOrder;
        class ReverseOrder;
        class Order;
        class MiddleOutOrder;

        // Add a new element to the container
        void add(const T& element) {
            data.push_back(element); // Add element to the end of the vector
        }

        // Remove all occurrences of a specific element from the container
        void remove(const T& element) {
            bool found = false; // Flag to check if the element was found
            auto it = data.begin(); // Iterator to traverse the vector

            // Iterate through the vector to find and remove the element
            while (it != data.end()) {
                // If the current element matches the one to remove
                if (*it == element) {
                    it = data.erase(it); // erase returns iterator to next element
                    found = true; // Set found to true
                }
                
                // If the current element does not match, move to the next element
                else {
                    ++it; // Move iterator to the next element
                }
            }
            
            // If the element was not found, throw an exception
            if (!found) {
                throw std::runtime_error("Element not found");
            }
        }

        // Return number of elements in the container
        size_t size() const {
            return data.size(); // Return the size of the vector
        }

        template <typename U> // Template declaration for friend function

        // Output operator (declaration of friend function)
        friend std::ostream& operator<<(std::ostream& os, const MyContainer<U>& container);

        // Begin iterator for ascending order
        AscendingOrder begin_ascending_order() const {
            return AscendingOrder(*this);
        }

        // End iterator for ascending order
        AscendingOrder end_ascending_order() const {
            AscendingOrder it(*this);
            it.it = it.indices.end();  // Access private member via friend relationship
            return it;
        }

        // // Begin iterator for descending order
        // DescendingOrder begin_descending_order() const {
        //     return DescendingOrder(*this);
        // }

        // // End iterator for descending order
        // DescendingOrder end_descending_order() const {
        //     DescendingOrder it(*this);
        //     it.it = it.sorted.end();
        //     return it;
        // }

        // Iterator for ascending order
        class AscendingOrder {
            private:
            std::vector<size_t> indices; // Vector to hold indices of elements
            typename std::vector<size_t>::iterator it; // Iterator for indices
            const MyContainer* container; // Reference to original container

            friend class MyContainer<T>;

            public:
            // Constructor - Create indices and sort them based on data values
            AscendingOrder(const MyContainer& c) : container(&c) {
                indices.resize(c.data.size()); // Resize indices to the size of data
                std::iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, 2, ...

                // Sort indices based on the values in the container's data
                std::sort(indices.begin(), indices.end(), [&c](size_t a, size_t b) { return c.data[a] < c.data[b]; });

                it = indices.begin(); // Initialize iterator to the beginning of the sorted indices
            }
            
            // Dereference operator
            const T& operator*() const {
                return container->data[*it];
            }

            // Prefix increment operator
            AscendingOrder& operator++() {
                ++it;
                return *this;
            }

            // Postfix increment operator
            AscendingOrder operator++(int) {
                AscendingOrder temp = *this;
                ++it;
                return temp;
            }

            // Equal operator
            bool operator==(const AscendingOrder& other) const {
                return it == other.it;
            }

            // Not equal operator
            bool operator!=(const AscendingOrder& other) const {
                return it != other.it;
            }
        };

        // // Iterator for ascending order
        // class AscendingOrder {
        //     private:
        //     std::vector<T> sorted;
        //     typename std::vector<T>::iterator it;

        //     friend class MyContainer<T>; // To allow MyContainer to access private members

        //     public:
        //     // Constructor
        //     AscendingOrder(const MyContainer& c) {
        //         sorted = c.data; // Copy the data from the container
        //         std::sort(sorted.begin(), sorted.end()); // Sort the data in ascending order
        //         it = sorted.begin(); // Initialize iterator to the beginning of the sorted vector
        //     }
            
        //     // Dereference operator
        //     const T& operator*() const {
        //         return *it;
        //     }

        //     // Prefix increment operator
        //     AscendingOrder& operator++() {
        //         ++it;
        //         return *this;
        //     }

        //     // Postfix increment operator
        //     AscendingOrder operator++(int) {
        //         AscendingOrder temp = *this; // Create a copy of the current iterator
        //         ++it; // Move to the next element
        //         return temp; // Return the copy
        //     }

        //     // Equal operator to compare iterators
        //     bool operator==(const AscendingOrder& other) const {
        //         return it == other.it;
        //     }

        //     // Not equal operator to compare iterators
        //     bool operator!=(const AscendingOrder& other) const {
        //         return it != other.it;
        //     }
        // };

        // // Iterator for descending order
        // class DescendingOrder {
        //     private:
        //     std::vector<T> sorted;
        //     typename std::vector<T>::iterator it;

        //     friend class MyContainer<T>; // To allow MyContainer to access private members

        //     public:
        //     // Constructor
        //     DescendingOrder(const MyContainer& c) {
        //         sorted = c.data; // Copy the data from the container
        //         std::sort(sorted.begin(), sorted.end(), std::greater<T>()); // Sort the data in descending order
        //         it = sorted.begin(); // Initialize iterator to the beginning of the sorted vector
        //     }
            
        //     // Dereference operator
        //     const T& operator*() const {
        //         return *it;
        //     }

        //     // Prefix increment operator
        //     DescendingOrder& operator++() {
        //         ++it;
        //         return *this;
        //     }

        //     // Postfix increment operator
        //     DescendingOrder operator++(int) {
        //         AscendingOrder temp = *this; // Create a copy of the current iterator
        //         ++it; // Move to the next element
        //         return temp; // Return the copy
        //     }

        //     // Equal operator to compare iterators
        //     bool operator==(const DescendingOrder& other) const {
        //         return it == other.it;
        //     }

        //     // Not equal operator to compare iterators
        //     bool operator!=(const DescendingOrder& other) const {
        //         return it != other.it;
        //     }
        // };

        // // Iterator for ascending order
        // class SideCrossOrder {
        //     private:
        //     std::vector<T> ordered;
        //     typename std::vector<T>::iterator it;

        //     public:
        //     // Constructor
        //     SideCrossOrder(const MyContainer& c) {
        //         MyContainer<T> temp = c.data; // Create an empty temporary container
        //         std::sort(temp.begin(), temp.end()); // Sort the data in ascending order
        //         sorted
                
        //         it = sorted.begin(); // Initialize iterator to the beginning of the sorted vector
        //     }
            
        //     // Dereference operator
        //     const T& operator*() const {
        //         return *it;
        //     }

        //     // Prefix increment operator
        //     SideCrossOrder& operator++() {
        //         ++it;
        //         return *this;
        //     }

        //     // Postfix increment operator
        //     SideCrossOrder operator++(int) {
        //         SideCrossOrder temp = *this; // Create a copy of the current iterator
        //         ++it; // Move to the next element
        //         return temp; // Return the copy
        //     }

        //     // Equal operator to compare iterators
        //     bool operator==(const AscendingOrder& other) const {
        //         return it == other.it;
        //     }

        //     // Not equal operator to compare iterators
        //     bool operator!=(const AscendingOrder& other) const {
        //         return it != other.it;
        //     }
        // };
    };

    template <typename T> // Template declaration

    // Output operator (friend function)
    std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        os << "["; // Start output with an opening bracket

        // Iterate through the elements and output them
        for (size_t i = 0; i < container.data.size(); i++) {
            os << container.data[i]; // Output the element

            // Check if it's not the last element
            if (i < container.data.size() - 1) {
                os << ", "; // Add a comma if it's not the last element
            }
        }
        
        os << "]"; // End output with a closing bracket
        return os;
    }
} // namespace my_container

#endif