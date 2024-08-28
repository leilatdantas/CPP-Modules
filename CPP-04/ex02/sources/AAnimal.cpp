/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:29:07 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/27 16:14:27 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "AAnimalDefault";
	std::cout << PINK << "(ANIMAL) " << RESET << "constructor called for " << PINK << this->type << RESET << std::endl; 
}

AAnimal::AAnimal(const AAnimal& other)
{
	this->type = other.type;
	std::cout << PINK << "(ANIMAL) " << RESET << "copy constructor called for " << PINK << this->type << RESET << "." << std::endl; 
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << PINK << "(ANIMAL) " << RESET << "copy operator assignment constructor called for " << PINK << this->type << RESET << std::endl; 
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << PINK << "(ANIMAL) " << RESET << "destructor called for " << PINK << this->type << RESET << std::endl; 
}

void	AAnimal::makeSound() const
{
	std::cout << PINK << "(ANIMAL) " << RESET << "makes some sound." << std::endl; 
}

std::string	AAnimal::getType() const
{
	return this->type;
}
