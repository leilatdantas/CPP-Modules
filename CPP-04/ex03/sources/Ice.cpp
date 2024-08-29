/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:57:09 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/29 21:58:49 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << BLUE << "(ICE) " << RESET << "constructor." << std::endl;
}

Ice::Ice(const Ice& other)
	: AMateria(other)
{
	std::cout << BLUE << "(ICE) " << RESET << "copy constructor." << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		std::cout << BLUE << "(ICE) " << RESET << "assigment operator constructor." << std::endl;
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << BLUE << "(ICE) " << RESET << "destructor." << std::endl;

}

AMateria* Ice::clone() const
{
	std::cout << BLUE << "(ICE) " << RESET << "has been cloned throughout ";
	return new Ice(*this);

}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << BLUE << target.getName() << RESET << " *" << std::endl;
}
