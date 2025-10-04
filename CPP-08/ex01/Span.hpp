/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:20:20 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 10:28:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <iostream>

class Span
{
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
    
    // Private default constructor to force N parameter
    Span();
    
public:
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);
    
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    
    // Template function for range insertion
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end)
    {
        typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
        if (_numbers.size() + static_cast<unsigned int>(distance) > _maxSize)
            throw FullContainerException();
        _numbers.insert(_numbers.end(), begin, end);
    }
    
    // Utility functions
    unsigned int size() const { return _numbers.size(); }
    unsigned int maxSize() const { return _maxSize; }
    
    // Exception classes
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
