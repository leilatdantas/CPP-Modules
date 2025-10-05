/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:21:10 by lebarbos          #+#    #+#             */
/*   Updated: 2025/10/04 11:45:09 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

void subjectTests()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void subjectTestsWithList()
{
    std::cout << "=== Subject Tests with std::list (for comparison) ===" << std::endl;
    
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
	//[...]
    mstack.push_back(0);
    
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    // std::stack<int> s(mstack);
}

void subjectTestsWithDeque()
{
    std::cout << "=== Subject Tests with std::deque (for comparison) ===" << std::endl;
    
    std::deque<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
	//[...]
    mstack.push_back(0);
    
    std::deque<int>::iterator it = mstack.begin();
    std::deque<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void subjectTestsWithVector()
{
    std::cout << "=== Subject Tests with std::vector (for comparison) ===" << std::endl;
    
    std::vector<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
	//[...]
    mstack.push_back(0);
    
    std::vector<int>::iterator it = mstack.begin();
    std::vector<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    // std::stack<int> s(mstack);
}

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
    std::cout << "=== ORIGINAL SUBJECT TEST ===" << std::endl;
    subjectTests();
    
    std::cout << "\n=== COMPARISON TESTS ===" << std::endl;
    subjectTestsWithList();
    subjectTestsWithDeque();
    subjectTestsWithVector();
    
    std::cout << "\n=== ADDITIONAL TESTS ===" << std::endl;
	testBasicOperations();
    testCopyAndAssignment();
    testWithStrings();

    return 0;
}
