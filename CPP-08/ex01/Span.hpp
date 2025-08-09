#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <climits>

class Span
{
private:
	std::vector<int> _numbers;
	unsigned int _maxSize;
	
public:
	// Constructors and Destructor
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	
	// Assignment operator
	Span& operator=(const Span& other);
	
	// Main methods
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	
	// Method to add a range of iterators
	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
		if (_numbers.size() + distance > _maxSize)
			throw std::runtime_error("Cannot add numbers: would exceed maximum size");
		
		_numbers.insert(_numbers.end(), begin, end);
	}
	
	// Getters for debug
	unsigned int size() const { return _numbers.size(); }
	unsigned int maxSize() const { return _maxSize; }
	
	// Custom exceptions
	class FullContainerException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Container is full, cannot add more numbers";
		}
	};
	
	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Cannot calculate span: need at least 2 numbers";
		}
	};
};

#endif
