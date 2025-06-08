# MyContainer - CPP_EX4_25

## Overview

This project implements a generic container `MyContainer<T>` in C++ with dynamic storage and multiple custom iterators. It is part of Assignment 4 for Systems Programming course, aimed at practicing **templates**, **iterators**, **functors**, and **container design**.

## Requirements

- C++17 or higher
- No external dependencies
- `valgrind` for memory checks
- Tested with [doctest](https://github.com/doctest/doctest)

## Features

- **MyContainer** - Class of dynamic container for comparable types (default: `int`)
- Operations:
  - `add(const T&)` – insert element
  - `remove(const T&)` – remove all instances
  - `size()` – return current count
  - `operator<<` – print the container

### Iterators:
Each iterator provides a different traversal strategy over the container:
- `AscendingOrder` – sorted ascending
- `DescendingOrder` – sorted descending
- `SideCrossOrder` – alternate min/max
- `ReverseOrder` – reverse insertion order
- `Order` – insertion order
- `MiddleOutOrder` – from center outward

Each iterator supports `begin()`, `end()`, `operator*`, `operator++` (Prefix and Postfix), `operator==` and `operator!=`.

## Project Structure

```
.
├── MyContainer.hpp     # Container and internal iterator definitions
├── MyDemo.cpp          # Demo usage with all iterator types
├── test.cpp            # Unit tests (with doctest)
├── Makefile            # Build/test/memory check automation
└── README.md           # Project documentation
```

## Build & Run

```bash
make Main        # Run the demo
make test        # Run unit tests
make valgrind    # Check for memory leaks
make clean       # Remove all generated files
```
