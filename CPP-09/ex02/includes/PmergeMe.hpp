#ifndef PMERGEIMPL_HPP
#define PMERGEIMPL_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <sstream>

template <typename T>
class PmergeMe
{
private:
	// Generate Jacobsthal sequence up to n
	static std::vector<size_t> generateJacobsthal(size_t n)
	{
		std::vector<size_t> jacobsthal;
		if (n == 0) return jacobsthal;
		
		jacobsthal.push_back(1);
		if (n == 1) return jacobsthal;
		
		jacobsthal.push_back(1);
		
		size_t j = 1;
		while (j < n)
		{
			size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
			if (next > n) break;
			jacobsthal.push_back(next);
			j = next;
		}
		
		return jacobsthal;
	}
	
	// Binary search for insertion position
	static typename std::vector<T>::iterator binarySearch(
		typename std::vector<T>::iterator first,
		typename std::vector<T>::iterator last,
		const T& value)
	{
		while (first < last)
		{
			typename std::vector<T>::iterator mid = first + (last - first) / 2;
			if (*mid < value)
				first = mid + 1;
			else
				last = mid;
		}
		return first;
	}
	
	// Recursive Ford-Johnson merge-insert sort for vector
	static void fordJohnsonVector(std::vector<T>& arr)
	{
		if (arr.size() <= 1)
			return;
		
		// Handle odd element
		T oddElement = T();
		bool hasOdd = (arr.size() % 2) != 0;
		if (hasOdd)
		{
			oddElement = arr.back();
			arr.pop_back();
		}
		
		// Create groups of two elements and sort them
		std::vector<T> larger, smaller;
		
		for (size_t i = 0; i < arr.size(); i += 2)
		{
			T a = arr[i];
			T b = arr[i + 1];
			
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
		
		// Recursively sort the larger elements
		fordJohnsonVector(larger);
		
		// Build main chain starting with larger elements
		std::vector<T> mainChain = larger;
		
		// Insert the first smaller element at the beginning
		if (!smaller.empty())
		{
			mainChain.insert(mainChain.begin(), smaller[0]);
		}
		
		// Generate Jacobsthal sequence for insertion order
		std::vector<size_t> jacobsthal = generateJacobsthal(smaller.size());
		
		// Insert remaining elements using Jacobsthal sequence
		std::vector<bool> inserted(smaller.size(), false);
		if (!smaller.empty())
			inserted[0] = true; // First element already inserted
		
		for (size_t jIdx = 1; jIdx < jacobsthal.size(); ++jIdx)
		{
			size_t end = jacobsthal[jIdx] - 1; // Convert to 0-based index
			size_t start = (jIdx > 1) ? jacobsthal[jIdx - 1] : 1;
			
			// Insert elements in reverse order from end to start
			for (size_t i = end; i >= start && i < smaller.size(); --i)
			{
				if (!inserted[i])
				{
					typename std::vector<T>::iterator pos = binarySearch(
						mainChain.begin(), mainChain.end(), smaller[i]);
					mainChain.insert(pos, smaller[i]);
					inserted[i] = true;
				}
				if (i == 0) break; // Prevent underflow
			}
		}
		
		// Insert any remaining elements
		for (size_t i = 0; i < smaller.size(); ++i)
		{
			if (!inserted[i])
			{
				typename std::vector<T>::iterator pos = binarySearch(
					mainChain.begin(), mainChain.end(), smaller[i]);
				mainChain.insert(pos, smaller[i]);
			}
		}
		
		// Insert odd element using binary search
		if (hasOdd)
		{
			typename std::vector<T>::iterator pos = binarySearch(
				mainChain.begin(), mainChain.end(), oddElement);
			mainChain.insert(pos, oddElement);
		}
		
		arr = mainChain;
	}
	
	// Binary search for insertion position (deque version)
	static typename std::deque<T>::iterator binarySearchDeque(
		typename std::deque<T>::iterator first,
		typename std::deque<T>::iterator last,
		const T& value)
	{
		while (first < last)
		{
			typename std::deque<T>::iterator mid = first + (last - first) / 2;
			if (*mid < value)
				first = mid + 1;
			else
				last = mid;
		}
		return first;
	}
	
	// Ford-Johnson merge-insert sort implementation for deque
	static void fordJohnsonDeque(std::deque<T>& arr)
	{
		if (arr.size() <= 1)
			return;
		
		// Handle odd element
		T oddElement = T();
		bool hasOdd = (arr.size() % 2) != 0;
		if (hasOdd)
		{
			oddElement = arr.back();
			arr.pop_back();
		}
		
		// Create groups of two elements and sort them
		std::deque<T> larger, smaller;
		
		for (size_t i = 0; i < arr.size(); i += 2)
		{
			T a = arr[i];
			T b = arr[i + 1];
			
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
		
		// Recursively sort the larger elements
		fordJohnsonDeque(larger);
		
		// Build main chain starting with larger elements
		std::deque<T> mainChain = larger;
		
		// Insert the first smaller element at the beginning
		if (!smaller.empty())
		{
			mainChain.push_front(smaller[0]);
		}
		
		// Generate Jacobsthal sequence for insertion order
		std::vector<size_t> jacobsthal = generateJacobsthal(smaller.size());
		
		// Insert remaining elements using Jacobsthal sequence
		std::vector<bool> inserted(smaller.size(), false);
		if (!smaller.empty())
			inserted[0] = true; // First element already inserted
		
		for (size_t jIdx = 1; jIdx < jacobsthal.size(); ++jIdx)
		{
			size_t end = jacobsthal[jIdx] - 1; // Convert to 0-based index
			size_t start = (jIdx > 1) ? jacobsthal[jIdx - 1] : 1;
			
			// Insert elements in reverse order from end to start
			for (size_t i = end; i >= start && i < smaller.size(); --i)
			{
				if (!inserted[i])
				{
					typename std::deque<T>::iterator pos = binarySearchDeque(
						mainChain.begin(), mainChain.end(), smaller[i]);
					mainChain.insert(pos, smaller[i]);
					inserted[i] = true;
				}
				if (i == 0) break; // Prevent underflow
			}
		}
		
		// Insert any remaining elements
		for (size_t i = 0; i < smaller.size(); ++i)
		{
			if (!inserted[i])
			{
				typename std::deque<T>::iterator pos = binarySearchDeque(
					mainChain.begin(), mainChain.end(), smaller[i]);
				mainChain.insert(pos, smaller[i]);
			}
		}
		
		// Insert odd element using binary search
		if (hasOdd)
		{
			typename std::deque<T>::iterator pos = binarySearchDeque(
				mainChain.begin(), mainChain.end(), oddElement);
			mainChain.insert(pos, oddElement);
		}
		
		arr = mainChain;
	}
	
	// Convert string to integer with validation
	static int stringToInt(const std::string& str)
	{
		if (str.empty())
			throw std::invalid_argument("Error");
		
		for (size_t i = 0; i < str.length(); ++i)
		{
			if (!std::isdigit(str[i]))
				throw std::invalid_argument("Error");
		}
		
		std::stringstream ss(str);
		long num;
		ss >> num;
		
		if (ss.fail() || !ss.eof() || num < 0 || num > 2147483647)
			throw std::invalid_argument("Error");
		
		return static_cast<int>(num);
	}

public:
	static void sort(int argc, char* argv[])
	{
		if (argc < 2)
		{
			std::cerr << "Error" << std::endl;
			return;
		}
		
		try
		{
			// Parse and validate input
			std::vector<int> vecNumbers;
			std::deque<int> deqNumbers;
			
			for (int i = 1; i < argc; ++i)
			{
				int num = stringToInt(argv[i]);
				vecNumbers.push_back(num);
				deqNumbers.push_back(num);
			}
			
			// Check for duplicates
			std::vector<int> temp = vecNumbers;
			std::sort(temp.begin(), temp.end());
			for (size_t i = 1; i < temp.size(); ++i)
			{
				if (temp[i] == temp[i - 1])
					throw std::invalid_argument("Error");
			}
			
			// Display original sequence
			std::cout << "Before: ";
			for (size_t i = 0; i < vecNumbers.size(); ++i)
			{
				std::cout << vecNumbers[i];
				if (i < vecNumbers.size() - 1)
					std::cout << " ";
			}
			std::cout << std::endl;
			
			// Sort with vector and measure time
			std::clock_t start = std::clock();
			fordJohnsonVector(vecNumbers);
			std::clock_t end = std::clock();
			double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
			
			// Sort with deque and measure time
			start = std::clock();
			fordJohnsonDeque(deqNumbers);
			end = std::clock();
			double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
			
			// Display sorted sequence
			std::cout << "After:  ";
			for (size_t i = 0; i < vecNumbers.size(); ++i)
			{
				std::cout << vecNumbers[i];
				if (i < vecNumbers.size() - 1)
					std::cout << " ";
			}
			std::cout << std::endl;
			
			// Display timing information
			std::cout << "Time to process a range of " << vecNumbers.size() 
					  << " elements with std::vector : " << std::fixed 
					  << std::setprecision(5) << vectorTime << " us" << std::endl;
			
			std::cout << "Time to process a range of " << deqNumbers.size() 
					  << " elements with std::deque  : " << std::fixed 
					  << std::setprecision(5) << dequeTime << " us" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
};

#endif
