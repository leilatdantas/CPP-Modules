# CPP Module 09

This module covers advanced C++ concepts focusing on STL containers and algorithms.

## Exercises

### ex00: Bitcoin Exchange
- **Objective**: Create a program that displays the value of bitcoins on certain dates
- **Key Concepts**: 
  - std::map for data storage and retrieval
  - File I/O operations
  - CSV parsing
  - Date validation
  - Error handling for invalid inputs
- **Usage**: `./btc data.csv`
- **Features**:
  - Reads bitcoin price database from CSV file
  - Validates date format (YYYY-MM-DD)
  - Handles value range validation (0-1000)
  - Provides detailed error messages

### ex01: Reverse Polish Notation (RPN)
- **Objective**: Implement a RPN calculator using a stack-based approach
- **Key Concepts**:
  - std::stack for expression evaluation
  - Mathematical expression parsing
  - Operator precedence handling
  - Exception handling for invalid expressions
- **Usage**: `./RPN "expression"`
- **Features**:
  - Supports basic arithmetic operations (+, -, *, /)
  - Validates numeric inputs
  - Handles division by zero errors
  - Stack-based evaluation algorithm

### ex02: PmergeMe - Ford-Johnson Algorithm
- **Objective**: Implement the Ford-Johnson merge-insert sort algorithm
- **Key Concepts**:
  - Template programming for container flexibility
  - std::vector and std::deque containers
  - Ford-Johnson merge-insert sort algorithm
  - Performance comparison between containers
  - Time complexity measurement
- **Usage**: `./PmergeMe [positive integers]`
- **Features**:
  - Sorts positive integers only
  - Implements Ford-Johnson algorithm for both vector and deque
  - Measures and compares execution times
  - Validates input for duplicates and negative numbers
  - Template-based design for type safety

## Compilation

Each exercise can be compiled individually using the provided Makefiles:

```bash
# Ex00
cd ex00 && make

# Ex01  
cd ex01 && make

# Ex02
cd ex02 && make
```

All programs compile with `-Wall -Wextra -Werror -std=c++98` flags.

## Key Learning Objectives

1. **STL Container Mastery**: Understanding when and how to use different containers
2. **Algorithm Implementation**: Implementing complex algorithms like Ford-Johnson sort
3. **Performance Analysis**: Measuring and comparing algorithm performance
4. **Template Programming**: Creating flexible, reusable code
5. **Error Handling**: Robust input validation and exception handling
6. **File I/O**: Reading and parsing structured data files

## Algorithm Details

### Ford-Johnson Merge-Insert Sort
The Ford-Johnson algorithm is a comparison-based sorting algorithm that minimizes the number of comparisons needed. It works by:

1. **Pairing**: Group elements in pairs and sort each pair
2. **Recursive Sort**: Sort pairs by their larger elements
3. **Main Chain**: Create a sequence with the larger elements
4. **Binary Insertion**: Insert smaller elements using binary search
5. **Optimization**: Use specific insertion orders to minimize comparisons

This algorithm is theoretically optimal for small sequences and provides excellent performance characteristics for the data sizes typically used in the exercise.
