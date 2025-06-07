// Email: razcohenp@gmail.com

#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream> // For std::ostream
#include <numeric> // For std::iota (to fill a vector with sequential numbers)

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

            // Begin iterator for AscendingOrder
            AscendingOrder begin_ascending_order() const {
                return AscendingOrder(*this);
            }

            // End iterator for AscendingOrder
            AscendingOrder end_ascending_order() const {
                AscendingOrder it(*this);
                it.current_position = data.size(); // "End" state
                return it;
            }

            // Begin iterator for DescendingOrder
            DescendingOrder begin_descending_order() const {
                return DescendingOrder(*this);
            }

            // End iterator for DescendingOrder
            DescendingOrder end_descending_order() const {
                DescendingOrder it(*this);
                it.current_position = data.size(); // "End" state
                return it;
            }

            // Begin iterator for SideCrossOrder
            SideCrossOrder begin_side_cross_order() const {
                return SideCrossOrder(*this);
            }

            // End iterator for SideCrossOrder
            SideCrossOrder end_side_cross_order() const {
                SideCrossOrder it(*this);
                it.current_position = data.size(); // "End" state
                return it;
            }

            // Begin iterator for ReverseOrder
            ReverseOrder begin_reverse_order() const {
                return ReverseOrder(*this);
            }

            // End iterator for ReverseOrder
            ReverseOrder end_reverse_order() const {
                ReverseOrder it(*this);
                it.current_position = data.size(); // "End" state
                return it;
            }

            // Begin iterator for Order
            Order begin_order() const {
                return Order(*this);
            }

            // End iterator for Order
            Order end_order() const {
                Order it(*this);
                it.current_position = data.size(); // "End" state
                return it;
            }

            // Begin iterator for MiddleOutOrder
            MiddleOutOrder begin_middle_out_order() const {
                return MiddleOutOrder(*this);
            }

            // End iterator for MiddleOutOrder
            MiddleOutOrder end_middle_out_order() const {
                MiddleOutOrder it(*this);
                it.current_position = data.size(); // "End" state
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

            // Iterator for descending order
            class DescendingOrder {
                private:
                    std::vector<size_t> sorted_indices; // Indices sorted by values
                    size_t current_position; // Current position in indices
                    const MyContainer<T>* container_ptr; // Pointer to original container

                    friend class MyContainer<T>; // To allow MyContainer to access private members

                public:
                    // Constructor - builds the sorted indices vector
                    DescendingOrder(const MyContainer<T>& container) : container_ptr(&container), current_position(0) {
                        // Create indices vector: [0, 1, 2, ...]
                        sorted_indices.resize(container.data.size()); // Initialize with size of data
                        std::iota(sorted_indices.begin(), sorted_indices.end(), 0); // Fill with indices [0, 1, 2, ...]
                        
                        // Sort indices by values in original container
                        std::sort(sorted_indices.begin(), sorted_indices.end(),
                                [&container](size_t a, size_t b) { return container.data[a] > container.data[b]; });
                    }

                    // Dereference operator - returns current element
                    const T& operator*() const {
                        size_t actual_index = sorted_indices[current_position];
                        return container_ptr->data[actual_index];
                    }
                    
                    // Increment operator - moves to next element
                    DescendingOrder& operator++() {
                        current_position++; // Increment current position
                        return *this;
                    }

                    // Post-increment operator - returns current state before incrementing
                    DescendingOrder operator++(int) {
                        DescendingOrder temp = *this; // Create a copy of current state
                        current_position++; // Increment current position
                        return temp; // Return the copy
                    }

                    // Equal operator to compare iterators
                    bool operator==(const DescendingOrder& other) const {
                        return current_position == other.current_position;
                    }
                    
                    // Not equal operator to compare iterators
                    bool operator!=(const DescendingOrder& other) const {
                        return current_position != other.current_position;
                    }
            };

            // Iterator for side-cross order
            class SideCrossOrder {
                private:
                    std::vector<size_t> sorted_indices; // Indices sorted by values
                    size_t current_position; // Current position in indices
                    const MyContainer<T>* container_ptr; // Pointer to original container

                    friend class MyContainer<T>; // To allow MyContainer to access private members

                public:
                    // Constructor - builds the sorted indices vector
                    SideCrossOrder(const MyContainer<T>& container) : container_ptr(&container), current_position(0) {
                        sorted_indices.resize(container.data.size()); // Initialize with size of data

                        // Temporary vector for sorting
                        std::vector<size_t> temp;
                        temp.resize(container.data.size()); // Initialize with size of data
                        std::iota(temp.begin(), temp.end(), 0); // Fill with indices [0, 1, 2, ...]
                        size_t left = 0, right = temp.size() - 1; // Initialize pointers for side-cross pattern
                        size_t i = 0; // Index for temp vector
                        
                        // Sort indices by values in original container (ascending order)
                        std::sort(temp.begin(), temp.end(),
                                [&container](size_t a, size_t b) { return container.data[a] < container.data[b]; });
                        
                        // Create side-cross pattern
                        while (left < right) {
                            sorted_indices[i++] = temp[left++]; // Take from left (smallest remaining)
                            sorted_indices[i++] = temp[right--]; // Take from right (largest remaining)
                        }

                        // Handle middle element if odd number of elements
                        if(left == right) {
                            sorted_indices[i++] = temp[left++]; // Add the middle element
                        }
                    }

                    // Dereference operator - returns current element
                    const T& operator*() const {
                        size_t actual_index = sorted_indices[current_position];
                        return container_ptr->data[actual_index];
                    }
                    
                    // Increment operator - moves to next element
                    SideCrossOrder& operator++() {
                        current_position++; // Increment current position
                        return *this;
                    }

                    // Post-increment operator - returns current state before incrementing
                    SideCrossOrder operator++(int) {
                        SideCrossOrder temp = *this; // Create a copy of current state
                        current_position++; // Increment current position
                        return temp; // Return the copy
                    }

                    // Equal operator to compare iterators
                    bool operator==(const SideCrossOrder& other) const {
                        return current_position == other.current_position;
                    }
                    
                    // Not equal operator to compare iterators
                    bool operator!=(const SideCrossOrder& other) const {
                        return current_position != other.current_position;
                    }
            };

            // Iterator for reverse order
            class ReverseOrder {
                private:
                    std::vector<size_t> sorted_indices; // Indices sorted by values
                    size_t current_position; // Current position in indices
                    const MyContainer<T>* container_ptr; // Pointer to original container

                    friend class MyContainer<T>; // To allow MyContainer to access private members

                public:
                    // Constructor - builds the sorted indices vector
                    ReverseOrder(const MyContainer<T>& container) : container_ptr(&container), current_position(0) {
                        // Create indices vector: [0, 1, 2, ...]
                        sorted_indices.resize(container.data.size()); // Initialize with size of data
                        std::iota(sorted_indices.begin(), sorted_indices.end(), 0); // Fill with indices [0, 1, 2, ...]
                        std::reverse(sorted_indices.begin(), sorted_indices.end()); // => [..., 2, 1, 0] (Reverse)
                    }
                    
                    // Dereference operator - returns current element
                    const T& operator*() const {
                        size_t actual_index = sorted_indices[current_position];
                        return container_ptr->data[actual_index];
                    }
                    
                    // Increment operator - moves to next element
                    ReverseOrder& operator++() {
                        current_position++; // Increment current position
                        return *this;
                    }

                    // Post-increment operator - returns current state before incrementing
                    ReverseOrder operator++(int) {
                        ReverseOrder temp = *this; // Create a copy of current state
                        current_position++; // Increment current position
                        return temp; // Return the copy
                    }

                    // Equal operator to compare iterators
                    bool operator==(const ReverseOrder& other) const {
                        return current_position == other.current_position;
                    }
                    
                    // Not equal operator to compare iterators
                    bool operator!=(const ReverseOrder& other) const {
                        return current_position != other.current_position;
                    }
            };

            // Iterator for regular order
            class Order {
                private:
                    std::vector<size_t> sorted_indices; // Indices sorted by values
                    size_t current_position; // Current position in indices
                    const MyContainer<T>* container_ptr; // Pointer to original container

                    friend class MyContainer<T>; // To allow MyContainer to access private members

                public:
                    // Constructor - builds the sorted indices vector
                    Order(const MyContainer<T>& container) : container_ptr(&container), current_position(0) {
                        // Create indices vector: [0, 1, 2, ...]
                        sorted_indices.resize(container.data.size()); // Initialize with size of data
                        std::iota(sorted_indices.begin(), sorted_indices.end(), 0); // Fill with indices [0, 1, 2, ...]
                    }
                    
                    // Dereference operator - returns current element
                    const T& operator*() const {
                        size_t actual_index = sorted_indices[current_position];
                        return container_ptr->data[actual_index];
                    }
                    
                    // Increment operator - moves to next element
                    Order& operator++() {
                        current_position++; // Increment current position
                        return *this;
                    }

                    // Post-increment operator - returns current state before incrementing
                    Order operator++(int) {
                        Order temp = *this; // Create a copy of current state
                        current_position++; // Increment current position
                        return temp; // Return the copy
                    }

                    // Equal operator to compare iterators
                    bool operator==(const Order& other) const {
                        return current_position == other.current_position;
                    }
                    
                    // Not equal operator to compare iterators
                    bool operator!=(const Order& other) const {
                        return current_position != other.current_position;
                    }
            };

            // Iterator for middle-out order
            class MiddleOutOrder {
                private:
                    std::vector<size_t> sorted_indices; // Indices sorted by values
                    size_t current_position; // Current position in indices
                    const MyContainer<T>* container_ptr; // Pointer to original container

                    friend class MyContainer<T>; // To allow MyContainer to access private members

                public:
                    // Constructor - builds the sorted indices vector
                    MiddleOutOrder(const MyContainer<T>& container) : container_ptr(&container), current_position(0) {
                        size_t size = container.data.size(); // Get size of the container
                        if (size == 0) return;  // In case of empty container
                        
                        sorted_indices.resize(size); // Initialize with size of data
                        size_t mid = size / 2;  // Find middle index
                        size_t i = 0; // Index for sorted indices vector
                        
                        sorted_indices[i++] = mid; // Start with middle element
                        
                        // Alternate between left and right of middle
                        for (size_t offset = 1; offset <= mid; ++offset) {
                            // Add element to the left of middle (if exists)
                            if (mid >= offset) {
                                sorted_indices[i++] = mid - offset;
                            }
                            
                            // Add element to the right of middle (if exists)
                            if (mid + offset < size) {
                                sorted_indices[i++] = mid + offset;
                            }
                        }
                    }

                    // Dereference operator - returns current element
                    const T& operator*() const {
                        size_t actual_index = sorted_indices[current_position];
                        return container_ptr->data[actual_index];
                    }
                    
                    // Increment operator - moves to next element
                    MiddleOutOrder& operator++() {
                        current_position++; // Increment current position
                        return *this;
                    }

                    // Post-increment operator - returns current state before incrementing
                    MiddleOutOrder operator++(int) {
                        MiddleOutOrder temp = *this; // Create a copy of current state
                        current_position++; // Increment current position
                        return temp; // Return the copy
                    }

                    // Equal operator to compare iterators
                    bool operator==(const MiddleOutOrder& other) const {
                        return current_position == other.current_position;
                    }
                    
                    // Not equal operator to compare iterators
                    bool operator!=(const MiddleOutOrder& other) const {
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