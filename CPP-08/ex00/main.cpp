/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:19:36 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/02 20:10:58 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

/**
 * @file main.cpp
 * @brief Demonstrates the usage of the easyfind function with various STL containers.
 *
 * This program tests the easyfind function with different standard containers:
 * - std::vector<int>: A dynamic array that allows fast random access and efficient insertion/removal at the end.
 * - std::list<int>: A doubly-linked list supporting efficient insertion/removal anywhere, but slower random access.
 * - std::deque<int>: A double-ended queue supporting fast insertion/removal at both ends.
 * - const std::vector<int>: Demonstrates usage with a constant container.
 *
 * The program:
 * 1. Fills each container with sample data.
 * 2. Prints the contents of each container.
 * 3. Attempts to find specific elements using easyfind, handling both found and not found cases.
 * 4. Demonstrates exception handling when an element is not found.
 *
 */
int main()
{
	std::cout << "=== Test with std::vector ===" << std::endl;
	
	// Test with vector
	std::vector<int> vec;
	for (int i = 1; i <= 10; i++)
		vec.push_back(i);
	
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	try
	{
		std::vector<int>::iterator found = easyfind(vec, 5);
		std::cout << "Element 5 found at position: " << std::distance(vec.begin(), found) << std::endl;
		std::cout << "Value found: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try
	{
		easyfind(vec, 15);
		std::cout << "Element 15 found" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Element 15: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test with std::list ===" << std::endl;
	
	// Test with list
	std::list<int> lst;
	for (int i = 10; i >= 1; i--)
		lst.push_back(i);
	
	std::cout << "List: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	try
	{
		std::list<int>::iterator found = easyfind(lst, 3);
		std::cout << "Element 3 found" << std::endl;
		std::cout << "Value found: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test with std::deque ===" << std::endl;
	
	// Test with deque
	std::deque<int> deq;
	deq.push_back(42);
	deq.push_back(21);
	deq.push_back(84);
	deq.push_front(7);
	
	std::cout << "Deque: ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	try
	{
		std::deque<int>::iterator found = easyfind(deq, 21);
		std::cout << "Element 21 found" << std::endl;
		std::cout << "Value found: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try
	{
		easyfind(deq, 100);
		std::cout << "Element 100 found" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Element 100: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test with const container ===" << std::endl;
	
	const std::vector<int> constVec(vec);
	try
	{
		std::vector<int>::const_iterator found = easyfind(constVec, 8);
		std::cout << "Element 8 found in const container" << std::endl;
		std::cout << "Value found: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}
