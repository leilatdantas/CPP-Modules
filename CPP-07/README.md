# CPP-07 - C++ Templates

This module introduces the fundamental concepts of **Templates** in C++, enabling the creation of generic code that works with different data types.

## 📚 Covered Concepts

- **Function Templates**: Generic functions
- **Template Argument Deduction**: Automatic type deduction
- **Class Templates**: Generic classes
- **Template Instantiation**: How the compiler generates specific code
- **Exception Handling**: Exception handling in templates

## 🎯 Exercises

### Ex00 - Start with a few functions
**File**: `whatever.hpp`

Implements three basic template functions:
- `swap()`: Swaps values between two variables
- `min()`: Returns the smaller value
- `max()`: Returns the larger value

```cpp
template<typename T>
void swap(T &a, T &b);

template<typename T>
T min(T const &a, T const &b);

template<typename T>
T max(T const &a, T const &b);
```

**Features**:
- Works with any type that supports the required operators
- Uses references for efficiency and to allow modification (swap)
- Uses const parameters when appropriate

### Ex01 - Iter
**File**: `iter.hpp`

Implements a template function that applies a function to all elements of an array:

```cpp
template<typename T, typename F>
void iter(T *array, size_t length, F func);
```

**Features**:
- Accepts arrays of any type
- Accepts any compatible function/functor
- Checks for null pointers
- Demonstrates the concept of Higher-Order Functions in C++

### Ex02 - Array
**File**: `Array.hpp`

Implements a template class representing a generic dynamic array:

```cpp
template<typename T>
class Array
{
public:
	Array();                        // Default constructor
	Array(unsigned int n);          // Constructor with size
	Array(const Array &other);      // Copy constructor
	~Array();                       // Destructor
	
	Array &operator=(const Array &other);  // Assignment operator
	T &operator[](unsigned int index);     // Index access
	unsigned int size() const;             // Array size
};
```

**Features**:
- Automatic memory management
- Bounds checking with exceptions
- Deep copy
- Initialization with default values
- Exception safety

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
make clean    # Removes object files
make fclean   # Removes executables
make re       # Recompiles everything
```

## 📝 Expected Output

### Ex00 - whatever:
```
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

### Ex01 - iter:
```
=== Integer test ===
Original array: 1 2 3 4 5 
After increment: 2 3 4 5 6 

=== Char test ===
Original array: h e l l o 
Uppercase: H E L L O 

=== String test ===
String array: Hello World Templates CPP
```

### Ex02 - array:
```
=== Empty Array Test ===
Empty array size: 0

=== Integer Array Test ===
Copied array size: 750
Independent copy works correctly!
All values match!

=== Exception Test ===
Exception caught for negative index: Index out of bounds
Exception caught for out-of-bounds index: Index out of bounds

=== String Array Test ===
String array: Hello World of Templates !
```

## 💡 Key Concepts

### Template Instantiation
The compiler generates specific code for each used type:
```cpp
// When using swap<int>, the compiler generates:
void swap(int &a, int &b) { /* ... */ }

// When using swap<string>, the compiler generates:
void swap(string &a, string &b) { /* ... */ }
```

### Type Requirements
Templates work with any type that meets the requirements:
- `min/max`: need the `<` or `>` operator
- `swap`: need copy constructor and `=` operator
- `Array`: needs default constructor

### Exception Safety
The Array class offers strong exception safety:
- If an operation fails, the object remains in a valid state
- RAII (Resource Acquisition Is Initialization)
- Bounds checking with appropriate exceptions

## 🔍 Implementation Details

### Performance
- Templates have no runtime overhead
- All work is done at compile-time
- Automatic inlining
- Type-specific optimizations

### Memory Management
- The Array class uses RAII for automatic management
- Prevents memory leaks
- Deep copy to avoid ownership issues
- Automatic destruction when out of scope

This project provides a solid foundation for understanding how STL containers work and prepares you for more advanced C++ metaprogramming concepts.

