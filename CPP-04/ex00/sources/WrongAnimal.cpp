/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:44:19 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/26 20:02:29 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimalDefault";
	std::cout << RED << "(WRONGANIMAL) " << RESET << "constructor called for " << RED << this->type << RESET << std::endl; 
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << RED << "(WRONGANIMAL) " << RESET << "constructor called for " << RED << this->type << RESET << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << RED << "(WRONGANIMAL) " << RESET << "copy constructor called for " << RED << this->type << RESET << std::endl; 
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << RED << "(WRONGANIMAL) " << RESET << "copy operator assignment constructor called for " << RED << this->type << RESET << std::endl; 
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "(WRONGANIMAL) " << RESET << "destructor called for " << RED << this->type << RESET << std::endl; 
}

void	WrongAnimal::makeSound() const
{
	std::cout << RED << "(WRONGANIMAL) " << RESET << "makes a wrong sound as a " << RED << this->type << RESET  << std::endl; 
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}
