#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

void testBasic()
{
	std::cout << "=== Basic Test ===" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Numbers added: 6, 3, 17, 9, 11" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testExceptions()
{
	std::cout << "=== Exception Test ===" << std::endl;

	Span sp = Span(3);

	// Test with empty container
	try
	{
		std::cout << "Trying to calculate span with empty container..." << std::endl;
		sp.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test with only one number
	sp.addNumber(42);
	try
	{
		std::cout << "Trying to calculate span with only one number..." << std::endl;
		sp.longestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test with full container
	sp.addNumber(10);
	sp.addNumber(20);
	try
	{
		std::cout << "Trying to add number to full container..." << std::endl;
		sp.addNumber(30);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "Current shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Current longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testRange()
{
	std::cout << "=== Iterator Range Test ===" << std::endl;

	Span sp = Span(10);

	// Test with vector
	std::vector<int> vec;
	for (int i = 1; i <= 5; i++)
		vec.push_back(i * 2);

	std::cout << "Adding vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	sp.addNumbers(vec.begin(), vec.end());

	// Test with list
	std::list<int> lst;
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);

	std::cout << "Adding list: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	sp.addNumbers(lst.begin(), lst.end());

	std::cout << "Total numbers: " << sp.size() << "/" << sp.maxSize() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testLarge()
{
	std::cout << "=== Large Numbers Test ===" << std::endl;

	const unsigned int N = 10000;
	Span sp = Span(N);

	std::vector<int> bigVec;
	bigVec.reserve(N);

	std::srand(std::time(NULL));
	for (unsigned int i = 0; i < N; i++)
	{
		bigVec.push_back(std::rand() % 1000000);
	}

	std::cout << "Adding " << N << " random numbers..." << std::endl;
	sp.addNumbers(bigVec.begin(), bigVec.end());

	std::cout << "Numbers added: " << sp.size() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testRangeException()
{
	std::cout << "=== Range Exception Test ===" << std::endl;

	Span sp = Span(3);

	std::vector<int> bigVec;
	for (int i = 0; i < 5; i++)
		bigVec.push_back(i);

	try
	{
		std::cout << "Trying to add 5 numbers to a container with capacity 3..." << std::endl;
		sp.addNumbers(bigVec.begin(), bigVec.end());
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

int main()
{
	testBasic();
	testExceptions();
	testRange();
	testLarge();
	testRangeException();

	return 0;
}
