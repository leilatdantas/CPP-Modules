/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:21:10 by lebarbos          #+#    #+#             */
/*   Updated: 2025/08/11 21:21:11 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

void testBasicOperations()
{
	std::cout << "=== Basic Operations Test ===" << std::endl;
	
	MutantStack<int> mstack;
	
	std::cout << "Is stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "After pushing 5 and 17:" << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.pop();
	
	std::cout << "After pop():" << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "After pushing 3, 5, 737, 0:" << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << std::endl;
}

void testIterators()
{
	std::cout << "=== Iterators Test ===" << std::endl;
	
	MutantStack<int> mstack;
	
	// Add elements
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "Stack contents (normal iterator): ";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	
	std::cout << "Stack contents (reverse iterator): ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void testWithList()
{
	std::cout << "=== Comparison with std::list ===" << std::endl;
	
	std::list<int> lst;
	
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	std::cout << "List contents: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "List size: " << lst.size() << std::endl;
	std::cout << std::endl;
}

void testCopyAndAssignment()
{
	std::cout << "=== Copy and Assignment Test ===" << std::endl;
	
	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);
	
	// Test copy constructor
	MutantStack<int> copied(original);
	
	std::cout << "Original: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Copy: ";
	for (MutantStack<int>::iterator it = copied.begin(); it != copied.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Test assignment operator
	MutantStack<int> assigned;
	assigned = original;
	
	std::cout << "Assigned: ";
	for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Modify original to check independence
	original.push(4);
	
	std::cout << "Original after pushing 4: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Copy still: ";
	for (MutantStack<int>::iterator it = copied.begin(); it != copied.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void testAlgorithms()
{
	std::cout << "=== STL Algorithms Test ===" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(3);
	mstack.push(1);
	mstack.push(4);
	mstack.push(1);
	mstack.push(5);
	
	std::cout << "Before sorting: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Sort using STL algorithm
	std::sort(mstack.begin(), mstack.end());
	
	std::cout << "After sorting: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Find element
	MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 4);
	if (found != mstack.end())
		std::cout << "Element 4 found!" << std::endl;
	
	std::cout << std::endl;
}

void testWithStrings()
{
	std::cout << "=== String Test ===" << std::endl;
	
	MutantStack<std::string> strStack;
	
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("of");
	strStack.push("Mutant");
	strStack.push("Stacks");
	
	std::cout << "String stack: ";
	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Top: " << strStack.top() << std::endl;
	std::cout << std::endl;
}

int main()
{
	testBasicOperations();
	testIterators();
	testWithList();
	testCopyAndAssignment();
	testAlgorithms();
	testWithStrings();
	
	return 0;
}
