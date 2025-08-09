#include "Span.hpp"

// Construtor
Span::Span(unsigned int N) : _maxSize(N)
{
	_numbers.reserve(N);
}

// Construtor de cópia
Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize)
{
}

// Destrutor
Span::~Span()
{
}

// Operador de atribuição
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return *this;
}

// Adicionar um número
void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullContainerException();
	
	_numbers.push_back(number);
}

// Encontrar o menor span (diferença)
int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	
	int minSpan = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	
	return minSpan;
}

// Encontrar o maior span (diferença)
int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	
	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
	
	return *maxIt - *minIt;
}
