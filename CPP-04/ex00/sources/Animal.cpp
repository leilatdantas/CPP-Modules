/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:29:07 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/26 17:09:18 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	this->type = "AnimalDefault";
	std::cout << PINK << "(ANIMAL) " << RESET << "constructor called for " << PINK << this->type << RESET << std::endl; 
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << PINK << "(ANIMAL) " << RESET << "constructor called for " << PINK << this->type << RESET << "." << std::endl; 
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << PINK << "(ANIMAL) " << RESET << "copy constructor called for " << PINK << this->type << RESET << "." << std::endl; 
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << PINK << "(ANIMAL) " << RESET << "copy operator assignment constructor called for " << PINK << this->type << RESET << std::endl; 
	return *this;
}

Animal::~Animal()
{
	std::cout << PINK << "(ANIMAL) " << RESET << "destructor called for " << PINK << this->type << RESET << std::endl; 
}

void	Animal::makeSound() const
{
	std::cout << PINK << "(ANIMAL) " << RESET << "makes some sound." << std::endl; 
}

std::string	Animal::getType() const
{
	return this->type;
}
