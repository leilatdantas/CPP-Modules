# CPP-08 - Templated Containers, Iterators and Algorithms

This module deepens your knowledge of **STL containers**, **iterators**, and **algorithms**, focusing on building custom data structures that integrate with the STL ecosystem.

## 📚 Covered Concepts

- **STL Containers**: vector, list, deque, stack
- **STL Iterators**: forward, bidirectional, random access
- **STL Algorithms**: find, sort, min_element, max_element
- **Template Specialization**: Adapting templates for specific cases
- **Container Adapters**: How to create container adapters
- **Iterator Traits**: Iterator characteristics

## 🎯 Exercises

### Ex00 - Easy find
**Files**: `easyfind.hpp`, `main.cpp`

Implements a template function that finds an integer value in any STL container:

```cpp
template<typename T>
typename T::iterator easyfind(T& container, int value);
```

**Features**:
- ✅ Works with vector, list, deque, and other containers
- ✅ Uses `std::find()` internally
- ✅ Throws exception if element not found
- ✅ Supports const and non-const containers
- ✅ Returns iterator to the found element

**Functionality**:
- Search in different container types
- Custom exception handling
- Performance testing with large containers

### Ex01 - Span
**Files**: `Span.hpp`, `Span.cpp`, `main.cpp`

Implements a class that stores N integers and can calculate spans (differences):

```cpp
class Span
{
public:
	Span(unsigned int N);
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	
	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end);
};
```

**Features**:
- ✅ Limited capacity defined in the constructor
- ✅ Add numbers individually or by range
- ✅ Calculate smallest and largest difference between numbers
- ✅ Exceptions for invalid cases
- ✅ Optimized for large amounts of data

**Functionality**:
- Shortest span: smallest difference between any two numbers
- Longest span: difference between largest and smallest number
- Range insertion: add multiple numbers at once
- Exception safety: strict error control

### Ex02 - Mutated abomination
**Files**: `MutantStack.hpp`, `main.cpp`

Creates a stack that can also be iterated, combining std::stack with iterators:

```cpp
template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	
	iterator begin();
	iterator end();
	// ... other iterator types
};
```

**Features**:
- ✅ Inherits from std::stack, keeps LIFO functionality
- ✅ Adds iterators for traversal
- ✅ Supports forward and reverse iterators
- ✅ Compatible with STL algorithms
- ✅ Configurable underlying container

**Functionality**:
- Normal stack operations (push, pop, top)
- Iteration through elements
- Use with STL algorithms (sort, find, etc.)
- Different iterator types (const, reverse)

## 🔧 Compilation and Testing

### Compile all exercises:
```bash
make
```

### Compile a specific exercise:
```bash
make -C ex00  # or ex01, ex02
```

### Run tests:
```bash
make test
```

### Clean files:
```bash
make clean    # Remove object files
make fclean   # Remove executables
make re       # Rebuild everything
```

## 📝 Expected Output

### Ex00 - easyfind:
```
=== Test with std::vector ===
Vector: 1 2 3 4 5 6 7 8 9 10
Element 5 found at position: 4
Value found: 5
Element 15: Element not found in container

=== Test with std::list ===
List: 10 9 8 7 6 5 4 3 2 1
Element 3 found
Value found: 3
```

### Ex01 - span:
```
=== Basic Test ===
Numbers added: 6, 3, 17, 9, 11
Shortest span: 2
Longest span: 14

=== Exception Test ===
Trying to calculate span with empty container...
Exception caught: Cannot calculate span: need at least 2 numbers
```

### Ex02 - mutantstack:
```
=== Basic Operations Test ===
Stack empty? Yes
Size: 0
After adding 5 and 17:
Top: 17
Size: 2

=== Iterator Test ===
Stack contents (normal iterator): 5 17 3 5 737 0
Stack contents (reverse iterator): 0 737 5 3 17 5
```

## 💡 Key Concepts

### Iterator Categories
- **Input Iterator**: Single-pass sequential read
- **Output Iterator**: Single-pass sequential write  
- **Forward Iterator**: Multi-pass sequential read/write
- **Bidirectional Iterator**: Like forward, but can go both directions
- **Random Access Iterator**: Direct access to any position

### STL Integration
Custom containers follow STL conventions:
```cpp
typedef typename Container::iterator iterator;
typedef typename Container::value_type value_type;
typedef typename Container::size_type size_type;
```

### Exception Safety
- **Basic Guarantee**: Object remains valid after exception
- **Strong Guarantee**: Operation is atomic (all or nothing)
- **No-throw Guarantee**: Operation never throws

### Template Metaprogramming
```cpp
template<typename Iterator>
void addNumbers(Iterator begin, Iterator end)
{
	// std::distance automatically calculates the number of elements
	typename std::iterator_traits<Iterator>::difference_type distance;
	distance = std::distance(begin, end);
}
```

## 🔍 Implementation Details

### Performance Considerations
- **Ex00**: O(n) for linear search in containers
- **Ex01**: O(n log n) for shortest span (due to sort)
- **Ex02**: O(1) for stack operations, O(n) for iteration

### Memory Management
- Uses STL containers for automatic management
- RAII in all classes
- Exception safety in critical operations

### Algorithm Compatibility
- MutantStack works with std::sort, std::find, etc.
- Iterators follow STL standards
- Compatible with range-based for loops (C++11+)

### Template Flexibility
- easyfind works with any container that has iterators
- Span accepts any iterator type
- MutantStack allows different underlying containers

## 🚀 Possible Extensions

- **Ex00**: Binary search for sorted containers
- **Ex01**: Span for types other than int
- **Ex02**: MutantQueue, MutantPriorityQueue

This module prepares you for advanced concepts like generic programming and metaprogramming, essential for modern C++ and library development.

