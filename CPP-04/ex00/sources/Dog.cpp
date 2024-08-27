/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:03:06 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/27 16:16:56 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << BLUE << "(DOG) " << RESET << "constructor called for " << BLUE << this->type << RESET << "." << std::endl; 
}

Dog::Dog(const Dog& other)
{
	this->type = other.type;
	std::cout << BLUE << "(DOG) " << RESET << "copy constructor called for " << BLUE << this->type << "." << std::endl; 
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << BLUE << "(DOG) " << RESET << "copy constructor called for " << BLUE << this->type << "." << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << BLUE << "(DOG) " << RESET << "destructor called for " << BLUE << this->type << "." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "(DOG) " << RESET << "au au" << std::endl;
}

