#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

void testBasicOperations()
{
	std::cout << "=== Teste Operações Básicas ===" << std::endl;
	
	MutantStack<int> mstack;
	
	std::cout << "Stack vazia? " << (mstack.empty() ? "Sim" : "Não") << std::endl;
	std::cout << "Tamanho: " << mstack.size() << std::endl;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Após adicionar 5 e 17:" << std::endl;
	std::cout << "Topo: " << mstack.top() << std::endl;
	std::cout << "Tamanho: " << mstack.size() << std::endl;
	
	mstack.pop();
	
	std::cout << "Após pop():" << std::endl;
	std::cout << "Tamanho: " << mstack.size() << std::endl;
	std::cout << "Topo: " << mstack.top() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "Após adicionar 3, 5, 737, 0:" << std::endl;
	std::cout << "Tamanho: " << mstack.size() << std::endl;
	std::cout << "Topo: " << mstack.top() << std::endl;
	std::cout << std::endl;
}

void testIterators()
{
	std::cout << "=== Teste Iteradores ===" << std::endl;
	
	MutantStack<int> mstack;
	
	// Adicionar elementos
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "Stack contents (iterador normal): ";
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
	
	std::cout << "Stack contents (iterador reverso): ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void testWithList()
{
	std::cout << "=== Comparação com std::list ===" << std::endl;
	
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
	std::cout << "=== Teste Cópia e Atribuição ===" << std::endl;
	
	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);
	
	// Teste construtor de cópia
	MutantStack<int> copied(original);
	
	std::cout << "Original: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Cópia: ";
	for (MutantStack<int>::iterator it = copied.begin(); it != copied.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Teste operador de atribuição
	MutantStack<int> assigned;
	assigned = original;
	
	std::cout << "Atribuída: ";
	for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Modificar original para verificar independência
	original.push(4);
	
	std::cout << "Original após adicionar 4: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Cópia ainda: ";
	for (MutantStack<int>::iterator it = copied.begin(); it != copied.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void testAlgorithms()
{
	std::cout << "=== Teste com Algoritmos STL ===" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(3);
	mstack.push(1);
	mstack.push(4);
	mstack.push(1);
	mstack.push(5);
	
	std::cout << "Antes da ordenação: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Ordenar usando algoritmo STL
	std::sort(mstack.begin(), mstack.end());
	
	std::cout << "Após ordenação: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Encontrar elemento
	MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 4);
	if (found != mstack.end())
		std::cout << "Elemento 4 encontrado!" << std::endl;
	
	std::cout << std::endl;
}

void testWithStrings()
{
	std::cout << "=== Teste com Strings ===" << std::endl;
	
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
	
	std::cout << "Topo: " << strStack.top() << std::endl;
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
