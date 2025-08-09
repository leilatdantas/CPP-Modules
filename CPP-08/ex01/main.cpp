#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

void testBasic()
{
	std::cout << "=== Teste Básico ===" << std::endl;
	
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "Números adicionados: 6, 3, 17, 9, 11" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testExceptions()
{
	std::cout << "=== Teste de Exceções ===" << std::endl;
	
	Span sp = Span(3);
	
	// Teste com container vazio
	try
	{
		std::cout << "Tentando calcular span com container vazio..." << std::endl;
		sp.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exceção capturada: " << e.what() << std::endl;
	}
	
	// Teste com apenas um número
	sp.addNumber(42);
	try
	{
		std::cout << "Tentando calcular span com apenas um número..." << std::endl;
		sp.longestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exceção capturada: " << e.what() << std::endl;
	}
	
	// Teste com container cheio
	sp.addNumber(10);
	sp.addNumber(20);
	try
	{
		std::cout << "Tentando adicionar número em container cheio..." << std::endl;
		sp.addNumber(30);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exceção capturada: " << e.what() << std::endl;
	}
	
	std::cout << "Shortest span atual: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span atual: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testRange()
{
	std::cout << "=== Teste com Range de Iteradores ===" << std::endl;
	
	Span sp = Span(10);
	
	// Teste com vector
	std::vector<int> vec;
	for (int i = 1; i <= 5; i++)
		vec.push_back(i * 2);
	
	std::cout << "Adicionando vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	sp.addNumbers(vec.begin(), vec.end());
	
	// Teste com list
	std::list<int> lst;
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);
	
	std::cout << "Adicionando list: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	sp.addNumbers(lst.begin(), lst.end());
	
	std::cout << "Total de números: " << sp.size() << "/" << sp.maxSize() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testLarge()
{
	std::cout << "=== Teste com Muitos Números ===" << std::endl;
	
	const unsigned int N = 10000;
	Span sp = Span(N);
	
	std::vector<int> bigVec;
	bigVec.reserve(N);
	
	std::srand(std::time(NULL));
	for (unsigned int i = 0; i < N; i++)
	{
		bigVec.push_back(std::rand() % 1000000);
	}
	
	std::cout << "Adicionando " << N << " números aleatórios..." << std::endl;
	sp.addNumbers(bigVec.begin(), bigVec.end());
	
	std::cout << "Números adicionados: " << sp.size() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void testRangeException()
{
	std::cout << "=== Teste Exceção com Range ===" << std::endl;
	
	Span sp = Span(3);
	
	std::vector<int> bigVec;
	for (int i = 0; i < 5; i++)
		bigVec.push_back(i);
	
	try
	{
		std::cout << "Tentando adicionar 5 números em container de capacidade 3..." << std::endl;
		sp.addNumbers(bigVec.begin(), bigVec.end());
	}
	catch (const std::exception& e)
	{
		std::cout << "Exceção capturada: " << e.what() << std::endl;
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
