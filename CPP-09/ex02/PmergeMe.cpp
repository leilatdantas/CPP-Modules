/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:46:10 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 18:16:19 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// orthodox canonical form
PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

// generate jacobsthal sequence up to n
std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n == 0)
		return jacobsthal;

	jacobsthal.push_back(1);
	if (n == 1)
		return jacobsthal;

	jacobsthal.push_back(1);

	size_t j = 1;
	while (j < n)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next > n)
			break;
		jacobsthal.push_back(next);
		j = next;
	}

	return jacobsthal;
}

// binary search for insertion position
std::vector<int>::iterator PmergeMe::binarySearch(
	std::vector<int>::iterator first,
	std::vector<int>::iterator last,
	const int &value)
{
	while (first < last)
	{
		std::vector<int>::iterator mid = first + (last - first) / 2;
		if (*mid < value)
			first = mid + 1;
		else
			last = mid;
	}
	return first;
}

// recursive ford-johnson merge-insert sort for vector

void PmergeMe::fordJohnsonVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return;

    // handle odd element
    int oddElement = 0;
    bool hasOdd = (arr.size() % 2) != 0;
    if (hasOdd)
    {
        oddElement = arr.back();
        arr.pop_back();
    }

    // create groups of two elements and sort them
    std::vector<int> larger, smaller;

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];

        if (a > b)
        {
            larger.push_back(a);
            smaller.push_back(b);
        }
        else
        {
            larger.push_back(b);
            smaller.push_back(a);
        }
    }

    // recursively sort the larger elements
    fordJohnsonVector(larger);

    // build main chain starting with larger elements
    std::vector<int> mainChain = larger;

    // insert ALL smaller elements using binary search (no special-case front insertion)
    for (size_t i = 0; i < smaller.size(); ++i)
    {
        std::vector<int>::iterator pos = PmergeMe::binarySearch(mainChain.begin(), mainChain.end(), smaller[i]);
        mainChain.insert(pos, smaller[i]);
    }

    // insert odd element using binary search
    if (hasOdd)
    {
        std::vector<int>::iterator pos = PmergeMe::binarySearch(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }

    arr = mainChain;
}

// binary search for insertion position (deque version)
std::deque<int>::iterator PmergeMe::binarySearchDeque(
	std::deque<int>::iterator first,
	std::deque<int>::iterator last,
	const int &value)
{
	while (first < last)
	{
		std::deque<int>::iterator mid = first + (last - first) / 2;
		if (*mid < value)
			first = mid + 1;
		else
			last = mid;
	}
	return first;
}

// ford-johnson merge-insert sort implementation for deque
void PmergeMe::fordJohnsonDeque(std::deque<int> &arr)
{
    if (arr.size() <= 1)
        return;

    int oddElement = 0;
    bool hasOdd = (arr.size() % 2) != 0;
    if (hasOdd)
    {
        oddElement = arr.back();
        arr.pop_back();
    }

    std::deque<int> larger, smaller;

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];

        if (a > b)
        {
            larger.push_back(a);
            smaller.push_back(b);
        }
        else
        {
            larger.push_back(b);
            smaller.push_back(a);
        }
    }

    fordJohnsonDeque(larger);

    std::deque<int> mainChain = larger;

    for (size_t i = 0; i < smaller.size(); ++i)
    {
        std::deque<int>::iterator pos = binarySearchDeque(mainChain.begin(), mainChain.end(), smaller[i]);
        mainChain.insert(pos, smaller[i]);
    }

    if (hasOdd)
    {
        std::deque<int>::iterator pos = binarySearchDeque(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }

    arr = mainChain;
}

// convert string to integer with validation
int PmergeMe::stringToInt(const std::string &str)
{
	if (str.empty())
		throw std::invalid_argument("Error: empty argument detected");

	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
		{
			std::string errorMsg = "Error: invalid character '" + std::string(1, str[i]) + "' in argument '" + str + "'";
			throw std::invalid_argument(errorMsg);
		}
	}

	std::stringstream ss(str);
	long num;
	ss >> num;

	if (ss.fail())
		throw std::invalid_argument("Error: failed to convert '" + str + "' to integer");

	if (!ss.eof())
		throw std::invalid_argument("Error: extra characters found in '" + str + "'");

	if (num < 0)
		throw std::invalid_argument("Error: negative number '" + str + "' not allowed");

	if (num > 2147483647)
		throw std::invalid_argument("Error: number '" + str + "' exceeds maximum value (2147483647)");

	return static_cast<int>(num);
}

// main sorting function
void PmergeMe::sort(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: no arguments provided. Usage: " << argv[0] << " [positive integers...]" << std::endl;
		return;
	}

	try
	{
		// parse and validate input
		std::vector<int> vecNumbers;
		std::deque<int> deqNumbers;

		for (int i = 1; i < argc; ++i)
		{
			try
			{
				int num = stringToInt(argv[i]);
				vecNumbers.push_back(num);
				deqNumbers.push_back(num);
			}
			catch (const std::invalid_argument &e)
			{
				throw std::invalid_argument(std::string(e.what()) + " (argument " +
											std::string(1, '0' + i) + ")");
			}
		}

		if (vecNumbers.empty())
			throw std::invalid_argument("Error: no valid numbers provided");

		// // check for duplicates
		// std::vector<int> temp = vecNumbers;
		// std::sort(temp.begin(), temp.end());
		// for (size_t i = 1; i < temp.size(); ++i)
		// {
		// 	if (temp[i] == temp[i - 1])
		// 	{
		// 		std::stringstream ss;
		// 		ss << "Error: duplicate number '" << temp[i] << "' found in arguments";
		// 		throw std::invalid_argument(ss.str());
		// 	}
		// }

		// check for reasonable size limit
		if (vecNumbers.size() > 100000)
		{
			std::stringstream ss;
			ss << "Error: too many arguments (" << vecNumbers.size()
			   << "). Maximum recommended: 100000";
			throw std::invalid_argument(ss.str());
		}

		// display original sequence
		std::cout << "Before: ";
		for (size_t i = 0; i < vecNumbers.size(); ++i)
		{
			std::cout << vecNumbers[i];
			if (i < vecNumbers.size() - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
// =============== display original sequence - FOR DEQUE  ===============
		// std::cout << "Before - DEQUE NUMBERS: ";
		// for (size_t i = 0; i < vecNumbers.size(); ++i)
		// {
		// 	std::cout << vecNumbers[i];
		// 	if (i < vecNumbers.size() - 1)
		// 		std::cout << " ";
		// }
		// std::cout << std::endl;

		// sort with vector and measure time
		std::clock_t start = std::clock();
		fordJohnsonVector(vecNumbers);
		std::clock_t end = std::clock();
		double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		
		// sort with deque and measure time
		start = std::clock();
		fordJohnsonDeque(deqNumbers);
		end = std::clock();
		double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		
		// display sorted sequence
		std::cout << "After:  ";
		for (size_t i = 0; i < vecNumbers.size(); ++i)
		{
			std::cout << vecNumbers[i];
			if (i < vecNumbers.size() - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
// =============== display sorted sequence - FOR DEQUE  ===============
		// std::cout << "After - DEQUE:  ";
		// for (size_t i = 0; i < vecNumbers.size(); ++i)
		// {
		// 	std::cout << vecNumbers[i];
		// 	if (i < vecNumbers.size() - 1)
		// 	std::cout << " ";
		// }
		// std::cout << std::endl;

		// display timing information
		std::cout << "Time to process a range of " << vecNumbers.size()
				  << " elements with std::vector : " << std::fixed
				  << std::setprecision(5) << vectorTime << " us" << std::endl;

		std::cout << "Time to process a range of " << deqNumbers.size()
				  << " elements with std::deque  : " << std::fixed
				  << std::setprecision(5) << dequeTime << " us" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}