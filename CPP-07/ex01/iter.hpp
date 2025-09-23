/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:18:37 by lebarbos          #+#    #+#             */
/*   Updated: 2025/09/23 20:35:20 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

// Helper function for testing
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
