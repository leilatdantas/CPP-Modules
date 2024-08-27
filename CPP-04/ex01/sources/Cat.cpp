/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:37:46 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/27 17:26:47 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << PURPLE << "(CAT) " << RESET << "constructor called for " << PURPLE << this->type << RESET << "." << std::endl; 
}

Cat::Cat(const Cat& other)
{
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << PURPLE << "(CAT) " << RESET << "copy constructor called for " << PURPLE << this->type << "." << std::endl; 
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << PURPLE << "(CAT) " << RESET << "copy constructor called for " << PURPLE << this->type << "." << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << PURPLE << "(CAT) " << RESET << "destructor called for " << PURPLE << this->type << "." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "(CAT) " << RESET << "miau miau" << std::endl;
}

