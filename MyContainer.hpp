#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <vector>
#include <stdexcept>
#include <iostream>

namespace my_container {
    template <typename T = int> // Default type is int
    
    class MyContainer {
        private:
        std::vector<T> data; // Internal storage for elements

        public:        
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