#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template<typename T, typename F>
void iter(T *array, size_t length, F func)
{
	if (!array)
		return;
	
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// Função auxiliar para testes
template<typename T>
void print(T const &x)
{
	std::cout << x << " ";
}

template<typename T>
void increment(T &x)
{
	x++;
}

#endif
