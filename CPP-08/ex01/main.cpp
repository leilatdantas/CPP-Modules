/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:19:51 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 10:37:18 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <deque>


void testAddNumbers() {
	std::cout << "\n=== Generic addNumbers with List Test ===" << std::endl;
	{
		// Create a list with data
		std::list<int> sourceList;
		sourceList.push_back(42);
		sourceList.push_back(17);
		sourceList.push_back(89);
		sourceList.push_back(3);
		sourceList.push_back(56);

		std::cout << "Data in list: ";
		for (std::list<int>::iterator it = sourceList.begin(); it != sourceList.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Use addNumbers directly with list iterators
		Span sp(10);
		sp.addNumbers(sourceList.begin(), sourceList.end());

		std::cout << "Added " << sp.size() << " numbers from the list to Span" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Generic addNumbers with Different Containers ===" << std::endl;
	{
		Span sp(20);

		// 1. Add from a vector
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << "After adding vector: " << sp.size() << " elements" << std::endl;

		// 2. Add from a list
		std::list<int> lst;
		lst.push_back(40);
		lst.push_back(50);
		lst.push_back(60);
		sp.addNumbers(lst.begin(), lst.end());
		std::cout << "After adding list: " << sp.size() << " elements" << std::endl;

		// 3. Add from a deque
		std::deque<int> deq;
		deq.push_back(70);
		deq.push_back(80);
		deq.push_back(90);
		sp.addNumbers(deq.begin(), deq.end());
		std::cout << "After adding deque: " << sp.size() << " elements" << std::endl;

		std::cout << "Final shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Final longest span: " << sp.longestSpan() << std::endl;
	}
}



int main()
{
	std::cout << "=== Subject Test ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; // Should output: 2
		std::cout << sp.longestSpan() << std::endl;	 // Should output: 14
	}

	std::cout << "\n=== Exception Tests ===" << std::endl;
	{
		// Test container full exception
		try
		{
			Span sp(2);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3); // Should throw
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}

		// Test no span exception
		try
		{
			Span sp(5);
			sp.addNumber(42);
			std::cout << sp.shortestSpan(); // Should throw
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Range Addition Test ===" << std::endl;
	{
		Span sp(10);
		std::vector<int> numbers;
		for (int i = 0; i < 8; ++i)
			numbers.push_back(i * 10);

		sp.addNumbers(numbers.begin(), numbers.end());
		sp.addNumber(5);
		sp.addNumber(62);

		sp.printNumbers();
		std::cout << "Size: " << sp.size() << "/" << sp.maxSize() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Large Container Test (10,000+ numbers) ===" << std::endl;
	{
		const unsigned int SIZE = 10000;
		Span bigSpan(SIZE);

		// Fill with random numbers
		std::srand(std::time(0));
		std::vector<int> randomNumbers;
		for (unsigned int i = 0; i < SIZE; ++i)
			randomNumbers.push_back(std::rand() % 100000);

		// Use range addition (much faster than 10k addNumber() calls!)
		bigSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());

		std::cout << "Created Span with " << bigSpan.size() << " numbers" << std::endl;
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	}

	std::cout << "\n=== Range Exception Test ===" << std::endl;
	{
		try
		{
			Span sp(5);
			std::vector<int> tooMany; // C++98 way
			tooMany.push_back(1);
			tooMany.push_back(2);
			tooMany.push_back(3);
			tooMany.push_back(4);
			tooMany.push_back(5);
			tooMany.push_back(6);
			tooMany.push_back(7); // 7 numbers for size 5
			sp.addNumbers(tooMany.begin(), tooMany.end());
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}
	// testAddNumbers();

	return 0;
}
