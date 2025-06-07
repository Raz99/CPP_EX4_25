# Email: razcohenp@gmail.com
# Compiler and flags
CXX = g++
CXXFLAGS =  -g -std=c++17

# Executable names
DEMO_EXEC = demo
TEST_EXEC = tests

# Object files
DEMO_OBJS = MyDemo.o
TEST_OBJS = tests.o

# Declare targets that don't create files
.PHONY: all Main test valgrind clean

# Default target builds the GUI executable
all: $(DEMO_EXEC)

# DEMO
# Build the demo executable
$(DEMO_EXEC): MyDemo.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build demo object file
MyDemo.o: MyDemo.cpp MyContainer.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the demo executable
Main: $(DEMO_EXEC)
	./$(DEMO_EXEC)

# TESTS
# Build the test executable
$(TEST_EXEC): tests.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build test object file
tests.o: tests.cpp doctest.h MyContainer.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the test executable
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Valgrind - Memory check on demo and test executables
valgrind: $(DEMO_EXEC) $(TEST_EXEC)
	valgrind --leak-check=full ./$(DEMO_EXEC) ./$(TEST_EXEC)

 # Clean - Remove all generated files
clean:
	rm -f $(DEMO_EXEC) $(TEST_EXEC) *.o