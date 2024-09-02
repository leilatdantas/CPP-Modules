/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:29:07 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/02 13:11:44 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
	: type("AnimalDefault")
{
	std::cout << PINK << "(ANIMAL) " << RESET << "constructor called for " << PINK << this->type << RESET << std::endl; 
}

Animal::Animal(const Animal& other)
{
	(void)other;
	std::cout << PINK << "(ANIMAL) " << RESET << "copy constructor called." << std::endl; 
}

Animal& Animal::operator=(const Animal& other)
{
	(void)other;
	std::cout << PINK << "(ANIMAL) " << RESET << "copy operator assignment constructor called." << std::endl; 
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
