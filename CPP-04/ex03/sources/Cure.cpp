/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:57:03 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/02 15:28:07 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() 
	: AMateria("cure")
{
	std::cout << GREEN << "(CURE) " << RESET << "constructor." << std::endl;
}

Cure::Cure(const Cure& other)
	: AMateria(other)
{
	this->type = other.type;
	std::cout << GREEN << "(CURE) " << RESET << "copy constructor." << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << GREEN << "(CURE) " << RESET << "assigment operator constructor." << std::endl;
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << GREEN << "(CURE) " << RESET << "destructor." << std::endl;
}

AMateria* Cure::clone() const
{
	std::cout << GREEN << "(CURE) " << RESET << "has been cloned throughout ";
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << GREEN << target.getName() << RESET << "'s wounds *" << std::endl;
}
