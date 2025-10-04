/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:20:43 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 18:30:35 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{
    _numbers.reserve(N);
}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

// add single number
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw FullContainerException();
    _numbers.push_back(number);
}

// find shortest span between any two numbers
int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

// find longest span 
int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    
    int minVal = _numbers[0];
    int maxVal = _numbers[0];
    
    for (size_t i = 1; i < _numbers.size(); ++i)
    {
        if (_numbers[i] < minVal)
            minVal = _numbers[i];
        if (_numbers[i] > maxVal)
            maxVal = _numbers[i];
    }
    
    return maxVal - minVal;
}
