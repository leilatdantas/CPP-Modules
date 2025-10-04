/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:22:01 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 17:03:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <cctype>

class PmergeMe
{
private:
    // Generate Jacobsthal sequence up to n
    static std::vector<size_t> generateJacobsthal(size_t n);
    
    // Binary search for insertion position
    static std::vector<int>::iterator binarySearch(
        std::vector<int>::iterator first,
        std::vector<int>::iterator last,
        const int& value);
    
    // Recursive Ford-Johnson merge-insert sort for vector
    static void fordJohnsonVector(std::vector<int>& arr);
    
    // Binary search for insertion position (deque version)
    static std::deque<int>::iterator binarySearchDeque(
        std::deque<int>::iterator first,
        std::deque<int>::iterator last,
        const int& value);
    
    // Ford-Johnson merge-insert sort implementation for deque
    static void fordJohnsonDeque(std::deque<int>& arr);
    
    // Convert string to integer with validation
    static int stringToInt(const std::string& str);

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);
    
    // Main sorting function
    static void sort(int argc, char* argv[]);
};

// Custom Exception class
class PmergeMeException : public std::exception
{
private:
    std::string _message;
    
public:
    PmergeMeException(const std::string& message);
    virtual ~PmergeMeException() throw();
    virtual const char* what() const throw();
};

#endif