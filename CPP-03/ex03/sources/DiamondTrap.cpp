/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:39:15 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/25 15:32:23 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << PURPLE << "(DIAMONDTRAP) " << RESET << "constructor has been called for " << PURPLE << "Default." << RESET << std::endl;
	_name = "Default";
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	ScavTrap scav("scav_aux");
	FragTrap frag("frag_aux");
	_hitPoints = frag.getHitPoints();
	_energyPoints = scav.getEnergyPoints();
	_attackDamage = frag.getAttackDamage();
	std::cout << PURPLE << "(DIAMONDTRAP) " << RESET << "constructor has been called for " << PURPLE << _name << RESET << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other) 
{
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << PURPLE << "(DIAMONDTRAP) " << RESET << "destructor has been called for " << PURPLE << _name << RESET << std::endl;
}

void	DiamondTrap::attack(const std::string target)
{
	std::cout << PURPLE << "(DIAMONDTRAP ATTACK) ";
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << PURPLE << "(DIAMONDTRAP) " << RESET << "I am " << PURPLE << _name << RESET << " and my ClapTrap name is " << PINK << ClapTrap::getName() << RESET << std::endl;
}

std::string		DiamondTrap::getName()
{
	return _name;
}


