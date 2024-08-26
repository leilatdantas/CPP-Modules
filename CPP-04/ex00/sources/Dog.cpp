/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:03:06 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/26 17:11:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
	: Animal("Dog")
{
	std::cout << BLUE << "(DOG) " << RESET << "constructor called for " << BLUE << this->type << RESET << "." << std::endl; 
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << BLUE << "(DOG) " << RESET << "copy constructor called for " << BLUE << this->type << "." << std::endl; 
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
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

