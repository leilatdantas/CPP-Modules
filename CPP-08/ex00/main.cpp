#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "=== Teste com std::vector ===" << std::endl;
	
	// Teste com vector
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
		std::cout << "Elemento 5 encontrado na posição: " << std::distance(vec.begin(), found) << std::endl;
		std::cout << "Valor encontrado: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}
	
	try
	{
		easyfind(vec, 15);
		std::cout << "Elemento 15 encontrado" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Elemento 15: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Teste com std::list ===" << std::endl;
	
	// Teste com list
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
		std::cout << "Elemento 3 encontrado" << std::endl;
		std::cout << "Valor encontrado: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Teste com std::deque ===" << std::endl;
	
	// Teste com deque
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
		std::cout << "Elemento 21 encontrado" << std::endl;
		std::cout << "Valor encontrado: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}
	
	try
	{
		easyfind(deq, 100);
		std::cout << "Elemento 100 encontrado" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Elemento 100: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Teste com container const ===" << std::endl;
	
	const std::vector<int> constVec(vec);
	try
	{
		std::vector<int>::const_iterator found = easyfind(constVec, 8);
		std::cout << "Elemento 8 encontrado em container const" << std::endl;
		std::cout << "Valor encontrado: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}
	
	return 0;
}
