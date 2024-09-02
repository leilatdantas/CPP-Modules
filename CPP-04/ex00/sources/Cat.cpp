/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:37:46 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/02 13:05:37 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
	: Animal()
{
	this->type = "Cat";
	std::cout << PURPLE << "(CAT) " << RESET << "constructor called for " << PURPLE << this->type << RESET << "." << std::endl; 
}

Cat::Cat(const Cat& other)
{
	this->type = other.type;
	std::cout << PURPLE << "(CAT) " << RESET << "copy constructor called for " << PURPLE << this->type << "." << std::endl; 
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << PURPLE << "(CAT) " << RESET << "copy assignment operator called for " << PURPLE << this->type << "." << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << PURPLE << "(CAT) " << RESET << "destructor called for " << PURPLE << this->type << "." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "(CAT) " << RESET << "miau miau" << std::endl;
}

