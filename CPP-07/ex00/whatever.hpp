/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:18:20 by lebarbos          #+#    #+#             */
/*   Updated: 2025/08/11 21:18:21 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(T const &a, T const &b)
{
	return (a < b) ? a : b;
}

template<typename T>
T max(T const &a, T const &b)
{
	return (a > b) ? a : b;
}

#endif
