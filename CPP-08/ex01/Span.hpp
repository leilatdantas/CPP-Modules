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
	// Construtores e Destrutor
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	
	// Operador de atribuição
	Span& operator=(const Span& other);
	
	// Métodos principais
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	
	// Método para adicionar range de iteradores
	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
		if (_numbers.size() + distance > _maxSize)
			throw std::runtime_error("Cannot add numbers: would exceed maximum size");
		
		_numbers.insert(_numbers.end(), begin, end);
	}
	
	// Getters para debug
	unsigned int size() const { return _numbers.size(); }
	unsigned int maxSize() const { return _maxSize; }
	
	// Exceções personalizadas
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
