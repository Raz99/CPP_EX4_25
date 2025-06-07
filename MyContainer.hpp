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
            it.current_position = data.size();  // "End" state
            return it;
        }

        // Iterator for ascending order
        class AscendingOrder {
        private:
            std::vector<size_t> sorted_indices; // Indices sorted by values
            size_t current_position; // Current position in indices
            const MyContainer<T>* container_ptr; // Pointer to original container

            friend class MyContainer<T>; // To allow MyContainer to access private members

        public:
            // Constructor - builds the sorted indices vector
            AscendingOrder(const MyContainer<T>& container) : container_ptr(&container), current_position(0) {
                // Create indices vector: [0, 1, 2, ...]
                sorted_indices.resize(container.data.size()); // Initialize with size of data
                std::iota(sorted_indices.begin(), sorted_indices.end(), 0); // Fill with indices [0, 1, 2, ...]
                
                // Sort indices by values in original container
                std::sort(sorted_indices.begin(), sorted_indices.end(),
                         [&container](size_t a, size_t b) { return container.data[a] < container.data[b]; });
            }
            
            // Dereference operator - returns current element
            const T& operator*() const {
                size_t actual_index = sorted_indices[current_position];
                return container_ptr->data[actual_index];
            }
            
            // Increment operator - moves to next element
            AscendingOrder& operator++() {
                current_position++; // Increment current position
                return *this;
            }

            // Post-increment operator - returns current state before incrementing
            AscendingOrder operator++(int) {
                AscendingOrder temp = *this; // Create a copy of current state
                current_position++; // Increment current position
                return temp; // Return the copy
            }

            // Equal operator to compare iterators
            bool operator==(const AscendingOrder& other) const {
                return current_position == other.current_position;
            }
            
            // Not equal operator to compare iterators
            bool operator!=(const AscendingOrder& other) const {
                return current_position != other.current_position;
            }
        };

    }; // End of MyContainer class

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