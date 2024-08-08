/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:58:54 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/03 17:56:14 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"


HumanB::HumanB(std::string name)
	: name(name)
{
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::removeWeapon()
{
	this->weapon = NULL;
}

void	HumanB::attack()
{
	if (weapon != NULL)
		std::cout << BOLD << ORANGE << name << RESET << " attacks with their " << BOLD << RED << weapon->getType() << RESET << std::endl;
	else
		std::cout << BOLD << ORANGE << name << RESET << " has no weapon" << std::endl;
}

HumanB::~HumanB()
{
}
