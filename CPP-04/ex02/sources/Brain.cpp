/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:23:42 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/27 16:38:25 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Random Idea";
	std::cout << GREEN << "(BRAIN) " << RESET << "constructor has been called." << std::endl; 
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << GREEN << "(BRAIN) " << RESET << "copy constructor has been called." << std::endl; 
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
		std::cout << GREEN << "(BRAIN) " << RESET << "copy assigment operator has been called." << std::endl; 

	}
	return *this;
}

Brain::~Brain()
{
	std::cout << GREEN << "(BRAIN) " << RESET << "destructor has been called." << std::endl; 
}
