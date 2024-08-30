/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:14:51 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/30 12:43:22 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
	: type(type), taken(false)
{
}

AMateria::AMateria(const AMateria& other)
{
	this->type = other.type;
	this->taken = false;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->taken = false;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return this->type;
}

bool const & AMateria::getStatus() const
{
	return this->taken;
}

void	AMateria::setStatus(bool status)
{
	this->taken = status;
}

