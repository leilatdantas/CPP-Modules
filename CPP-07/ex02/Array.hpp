#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	// Default constructor - creates an empty array
	Array() : _array(NULL), _size(0) {}
	
	// Constructor with parameter - creates an array with n elements
	Array(unsigned int n) : _array(new T[n]), _size(n)
	{
		// Initializes all elements with default value
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = T();
	}
	
	// Copy constructor
	Array(const Array &other) : _array(NULL), _size(0)
	{
		*this = other;
	}
	
	// Destructor
	~Array()
	{
		delete[] _array;
	}
	
	// Assignment operator
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		return *this;
	}
	
	// Access operator with bounds checking
	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _array[index];
	}
	
	// Const access operator
	const T &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _array[index];
	}
	
	// Function to get the size
	unsigned int size() const
	{
		return _size;
	}
};

#endif
