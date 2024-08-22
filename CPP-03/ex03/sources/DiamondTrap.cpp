/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:39:15 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/22 11:53:49 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	_name = "Default";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	_name = name;
	// ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
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
}

void	DiamondTrap::attack(const std::string target)
{
	FragTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DIAMOND NAME: " << _name << " CLAP NAME: " << ClapTrap::_name << std::endl; 
}


void	DiamondTrap::status()
{
	std::cout << "name: " << DiamondTrap::_name << std::endl;
	std::cout << "hit points: " << this->_hitPoints << std::endl;
	std::cout << "energy points: " << this->_energyPoints << std::endl;
	std::cout << "damage points: " << this->_attackDamage << std::endl;
}

int		DiamondTrap::getHitPoints()
{
	return _hitPoints;
}

int		DiamondTrap::getEnergyPoints()
{
	return _energyPoints;
}

int		DiamondTrap::getAttackDamage()
{
	return _attackDamage;
}


