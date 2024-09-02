/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:49:17 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/26 19:49:27 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << ORANGE << "(WRONGCAT) " << RESET << "constructor called for " << ORANGE << this->type << std::endl; 
}

WrongCat::WrongCat(const WrongCat& other)
{
	(void)other;
	std::cout << ORANGE << "(WRONGCAT) " << RESET << "copy constructor called for " << ORANGE << this->type << std::endl; 
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	(void)other;
	std::cout << ORANGE << "(WRONGCAT) " << RESET << "copy constructor called for " << ORANGE << this->type << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << ORANGE << "(WRONGCAT) " << RESET << "destructor called for " << ORANGE << this->type << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << ORANGE << "(WRONGCAT) " << RESET << "wrong miau miau" << std::endl;
}

