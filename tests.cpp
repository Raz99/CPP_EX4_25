// Email: razcohenp@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"

using namespace my_container;

TEST_CASE("MyContainer and Iterators - basic functionality") {
    MyContainer<> c;  // Create an instance of MyContainer with default type (should be int)

    SUBCASE("Default constructor") {
        CHECK(c.size() == 0); // Initial size should be 0
    }

    SUBCASE("Default template type is int") {
        MyContainer<> cont; // Create an instance of MyContainer, should be with default type int
        cont.add(42); // If it's not int, this will not compile
        CHECK(cont.size() == 1); // Size should be 1 after adding an element
    }
}

TEST_CASE("MyContainer - add, remove, size and output operator") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    SUBCASE("Add elements") {
        // Add elements to the container
        c.add(10);
        c.add(20);
        c.add(30);
        
        CHECK(c.size() == 3); // Size should be 3 after adding elements
    }

    SUBCASE("Add duplicate elements") {
        // Add elements to the container
        c.add(10);
        c.add(20);
        c.add(10); // Adding a duplicate element
        
        CHECK(c.size() == 3); // Size should still be 3 since duplicates are allowed
    }

    SUBCASE("Remove existing element") {
        // Add elements to the container
        c.add(10);
        c.add(20);
        c.add(30);
        
        c.remove(20); // Remove an existing element
        CHECK_THROWS(c.remove(20)); // Verify it's actually removed
        CHECK(c.size() == 2); // Size should be 2 after removal
    }

    SUBCASE("Remove all occurrences of an element") {
        // Add elements to the container
        c.add(10);
        c.add(20);
        c.add(10); // Add 10 again to have two occurrences
        
        c.remove(10); // Remove all occurrences of 10
        CHECK_THROWS(c.remove(10)); // Verify it's actually removed
        CHECK(c.size() == 1); // Size should be 1 after removing both occurrences
    }

    SUBCASE("Remove non-existent element throws") {
        c.add(10); // Add an element to the container
        CHECK_THROWS(c.remove(40)); // Attempt to remove an element that doesn't exist should throw an exception
    }

    SUBCASE("Remove a single element from a container with one element") {
        c.add(10); // Add a single element
        c.remove(10); // Remove it
        CHECK_THROWS(c.remove(10)); // Verify it's actually removed
        CHECK(c.size() == 0); // Size should be 0 after removal
    }

    SUBCASE("Removing all elements one by one") {
        MyContainer<int> c; // Create a new instance of MyContainer with int type
        
        // Add elements to the container
        c.add(1);
        c.add(2);
        c.add(3);

        // Remove elements one by one
        c.remove(1);
        c.remove(2);
        c.remove(3);

        CHECK(c.size() == 0); // Size should be 0 after removing all elements
        CHECK(c.begin_order() == c.end_order()); // Check if the begin and end iterators are equal, indicating the container is empty
    }

    SUBCASE("Output operator") {
        // Add elements to the container
        c.add(1);
        c.add(2);
        c.add(3);

        // Check if the output operator works correctly
        std::stringstream out;
        out << c; // Use the output operator
        CHECK(out.str() == "[1, 2, 3]"); // Check if the output is as expected
    }
}

TEST_CASE("AscendingOrder iterator - basic functionality") {
    MyContainer<int> c; // Create an instance of MyContainer with int type
    
    // Add elements to the container
    c.add(4);
    c.add(2);
    c.add(6);

    // Original order: [4, 2, 6]

    std::vector<int> result; // Collect results in a vector

    // Iterate using AscendingOrder iterator
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({2, 4, 6})); // Check if the result matches the expected ascending order
}

TEST_CASE("DescendingOrder iterator - basic functionality") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(4);
    c.add(2);
    c.add(6);

    // Original order: [4, 2, 6]

    std::vector<int> result; // Collect results in a vector

    // Iterate using DescendingOrder iterator
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({6, 4, 2})); // Check if the result matches the expected descending order
}

TEST_CASE("SideCrossOrder iterator - basic functionality") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    // Original order: [7, 15, 6, 1, 2]

    std::vector<int> result; // Collect results in a vector

    // Iterate using SideCrossOrder iterator
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({1, 15, 2, 7, 6})); // Check if the result matches the expected side-cross order
}

TEST_CASE("ReverseOrder iterator - basic functionality") {
    MyContainer<int> c; // Create an instance of MyContainer with int type
    
    // Add elements to the container
    c.add(1);
    c.add(2);
    c.add(3);

    // Original order: [1, 2, 3]

    std::vector<int> result; // Collect results in a vector

    // Iterate using ReverseOrder iterator
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({3, 2, 1})); // Check if the result matches the expected reverse order
}

TEST_CASE("Order iterator - basic functionality") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(10);
    c.add(20);
    c.add(30);

    // Original order: [10, 20, 30]

    std::vector<int> result; // Collect results in a vector

    // Iterate using Order iterator
    for (auto it = c.begin_order(); it != c.end_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({10, 20, 30})); // Check if the result matches the expected order
}

TEST_CASE("MiddleOutOrder iterator - basic functionality") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    // Original order: [7, 15, 6, 1, 2]

    std::vector<int> result; // Collect results in a vector

    // Iterate using MiddleOutOrder iterator
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({6, 15, 1, 7, 2})); // Check if the result matches the expected middle-out order
}

TEST_CASE("SideCrossOrder with odd number of elements") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    // Original order: [7, 15, 6, 1, 2]

    std::vector<int> result; // Collect results in a vector

    // Iterate using SideCrossOrder iterator
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    // Sorted: [1,2,6,7,15]
    // Expected: [1,15,2,7,6]
    CHECK(result == std::vector<int>({1, 15, 2, 7, 6})); // Check if the result matches the expected side-cross order
}

TEST_CASE("SideCrossOrder with even number of elements") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(4);
    c.add(1);
    c.add(3);
    c.add(2);

    // Original order: [4, 1, 3, 2]

    std::vector<int> result; // Collect results in a vector

    // Iterate using SideCrossOrder iterator
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    // Sorted: [1,2,3,4]
    // Expected: [1,4,2,3]
    CHECK(result == std::vector<int>({1, 4, 2, 3})); // Check if the result matches the expected side-cross order
}

TEST_CASE("MiddleOutOrder with odd number of elements") {
    MyContainer<int> c; // Create an instance of MyContainer with int type
    
    // Add elements to the container
    c.add(1);
    c.add(2);
    c.add(3);
    c.add(4);
    c.add(5);

    // Original order: [1, 2, 3, 4, 5]

    std::vector<int> result; // Collect results in a vector

    // Iterate using MiddleOutOrder iterator
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    // Expected middle-out order: 3,4,2,5,1 (middle = 3 [the element at index 2])
    CHECK(result == std::vector<int>({3, 2, 4, 1, 5}));
}

TEST_CASE("MiddleOutOrder with even number of elements") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(1);
    c.add(2);
    c.add(3);
    c.add(4);
    c.add(5);
    c.add(6);

    // Original order: [1, 2, 3, 4, 5, 6]

    std::vector<int> result; // Collect results in a vector

    // Iterate using MiddleOutOrder iterator
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({4, 3, 5, 2, 6, 1})); // Check if the result matches the expected middle-out order
}

TEST_CASE("MiddleOutOrder visits all elements exactly once") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(10);
    c.add(20);
    c.add(30);
    c.add(40);
    c.add(50);

    // Original order: [10, 20, 30, 40, 50]

    std::set<int> visited; // Use a set to track visited elements

    // Iterate using MiddleOutOrder iterator
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        visited.insert(*it); // Insert each element into the visited set
    }

    CHECK(visited.size() == 5); // Check if all elements were visited
    CHECK(visited == std::set<int>({10, 20, 30, 40, 50})); // Check if the visited set contains all elements
}

TEST_CASE("Empty container iterators are equal") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    SUBCASE("Empty container AscendingOrder iterator") {
        auto it_begin = c.begin_ascending_order(); // Get the beginning iterator for ascending order
        auto it_end = c.end_ascending_order(); // Get the end iterator for ascending order
        CHECK(it_begin == it_end); // Empty ascending order iterators should be equal
    }

    SUBCASE("Empty container DescendingOrder iterator") {
        auto it_begin = c.begin_descending_order(); // Get the beginning iterator for descending order
        auto it_end = c.end_descending_order(); // Get the end iterator for descending order
        CHECK(it_begin == it_end); // Empty descending order iterators should be equal
    }

    SUBCASE("Empty container SideCrossOrder iterator") {
        auto it_begin = c.begin_side_cross_order(); // Get the beginning iterator for side cross order
        auto it_end = c.end_side_cross_order(); // Get the end iterator for side cross order
        CHECK(it_begin == it_end); // Empty side cross order iterators should be equal
    }

    SUBCASE("Empty container ReverseOrder iterator") {
        auto it_begin = c.begin_reverse_order(); // Get the beginning iterator for reverse order
        auto it_end = c.end_reverse_order(); // Get the end iterator for reverse order
        CHECK(it_begin == it_end); // Empty reverse order iterators should be equal
    }

    SUBCASE("Empty container Order iterator") {
        auto it_begin = c.begin_order(); // Get the beginning iterator for regular order
        auto it_end = c.end_order(); // Get the end iterator for regular order
        CHECK(it_begin == it_end); // Empty order iterators should be equal
    }

    SUBCASE("Empty container MiddleOutOrder iterator") {
        auto it_begin = c.begin_middle_out_order(); // Get the beginning iterator for middle out order
        auto it_end = c.end_middle_out_order(); // Get the end iterator for middle out order
        CHECK(it_begin == it_end); // Empty middle out order iterators should be equal
    }
}

TEST_CASE("Negative and positive numbers in container") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(-10); // negative number
    c.add(0); // zero
    c.add(5); // positive number
    c.add(-3); // negative number

    // Original order: [-10, 0, 5, -3]

    std::vector<int> result; // Collect results in a vector

    // Iterate using AscendingOrder iterator
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({-10, -3, 0, 5})); // Check if the result matches the expected order
}

TEST_CASE("Iterator remains valid after using remove") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(10);
    c.add(20);
    c.add(30);
    c.add(40);

    // Create an ascending order iterator
    auto it = c.begin_ascending_order(); // Should point to 10
    CHECK(*it == 10);

    // Remove an element that is not the current one
    c.remove(30); // Remove 30 while the iterator still points to 10

    // Check that the iterator still points to 10
    CHECK(*it == 10);

    // Advance the iterator and verify correct order
    ++it;
    CHECK(*it == 20);

    // Advance the iterator again, should now point to 40 since 30 was removed
    ++it;
    CHECK(*it == 40);

    // Advance to the end
    ++it; // Now it should be at the end
    CHECK(it == c.end_ascending_order()); // Check if it reached the end
}

TEST_CASE("Iterator on duplicate elements") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(10);
    c.add(20);
    c.add(10); // Duplicate
    c.add(10); // Duplicate

    // Original order: [10, 20, 10, 10]

    std::vector<int> result; // Collect results in a vector

    // Iterate using AscendingOrder iterator
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<int>({10, 10, 10, 20})); // Check if duplicates are handled correctly
}

TEST_CASE("Multiple iterators on the same container") {
    MyContainer<int> c; // Create an instance of MyContainer with int type

    // Add elements to the container
    c.add(4);
    c.add(2);
    c.add(6);
    c.add(1);

    // Original order: [4, 2, 6, 1]

    // Create two iterators
    auto it1 = c.begin_ascending_order(); // [1, 2, 4, 6]
    auto it2 = c.begin_descending_order(); // [6, 4, 2, 1]

    CHECK(*it1 == 1); // Check first element in ascending order
    CHECK(*it2 == 6); // Check first element in descending order

    ++it1; // Move to next element in ascending order
    ++it2; // Move to next element in descending order

    CHECK(*it1 == 2); // Check second element in ascending order
    CHECK(*it2 == 4); // Check second element in descending order
}

TEST_CASE("MyContainer with strings") {
    MyContainer<std::string> c; // Create an instance of MyContainer with string type

    // Add elements to the container
    c.add("apple");
    c.add("banana");
    c.add("apple");
    
    CHECK(c.size() == 3); // Size should be 3 after adding elements

    c.remove("apple"); // Should remove both "apple"
    CHECK(c.size() == 1); // Size should be 1 after removing "apple"
    CHECK_THROWS(c.remove("apple")); // Verify it's actually removed
}

TEST_CASE("AscendingOrder with strings") {
    MyContainer<std::string> c; // Create an instance of MyContainer with string type

    // Add elements to the container
    c.add("banana");
    c.add("apple");
    c.add("cherry");

    // Original order: ["banana", "apple", "cherry"]

    std::vector<std::string> result; // Collect results in a vector

    // Iterate using AscendingOrder iterator
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<std::string>({"apple", "banana", "cherry"})); // Check if the result matches the expected ascending order
}

TEST_CASE("SideCrossOrder with strings") {
    MyContainer<std::string> c; // Create an instance of MyContainer with string type

    // Add elements to the container
    c.add("apple");
    c.add("banana");
    c.add("cherry");
    c.add("date");

    // Original order: ["apple", "banana", "cherry", "date"]

    std::vector<std::string> result; // Collect results in a vector

    // Iterate using SideCrossOrder iterator
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<std::string>({"apple", "date", "banana", "cherry"})); // Check if the result matches expected order
}

TEST_CASE("MyContainer with doubles") {
    MyContainer<double> c; // Create an instance of MyContainer with double type

    // Add elements to the container
    c.add(1.5);
    c.add(2.5);
    c.add(1.5); // Duplicate

    CHECK(c.size() == 3); // Size should be 3 after adding elements

    c.remove(1.5); // Remove one occurrence of 1.5
    CHECK(c.size() == 1); // Size should be 1 after removing one occurrence
    CHECK_THROWS(c.remove(1.5)); // Verify it's actually removed
}

TEST_CASE("AscendingOrder with doubles including negative numbers") {
    MyContainer<double> c; // Create an instance of MyContainer with double type

    // Add elements to the container
    c.add(2.2);
    c.add(0.1);
    c.add(-4.5); // Add negative number

    // Original order: [2.2, 0.1, -4.5]

    std::vector<double> result; // Collect results in a vector

    // Iterate using AscendingOrder iterator
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<double>({-4.5, 0.1, 2.2})); // Check if the result matches the expected order
}

TEST_CASE("DescendingOrder with doubles including negative numbers") {
    MyContainer<double> c; // Create an instance of MyContainer with double type

    // Add elements to the container
    c.add(2.2);
    c.add(0.1);
    c.add(-4.5); // Add negative number

    // Original order: [2.2, 0.1, -4.5]

    std::vector<double> result; // Collect results in a vector

    // Iterate using DescendingOrder iterator
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        result.push_back(*it); // Insert each element into the result vector
    }

    CHECK(result == std::vector<double>({2.2, 0.1, -4.5})); // Check if the result matches the expected order
}
