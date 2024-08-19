/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:28:45 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/18 14:10:13 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor has been called;" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << PINK << "(CLAPTRAP) " << RESET << name << " constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " has been destructed." << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << /*"ClapTrap " <<*/ _name << "is dead. It can't do anything!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << /*"ClapTrap " <<*/ _name << "has no energy points to atack " << target << std::endl;
	else
	{
		_energyPoints--;
		std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{		
		std::cout << /*"ClapTrap " <<*/ _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints=-amount;
	}
	else
	{
		std::cout << /*"ClapTrap " <<*/ _name << " has no hit points left!" << std::endl;
	}
	if (_hitPoints < 0)
		_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		std::cout << /*"ClapTrap " <<*/ _name << " is repaired for " << amount << " points!" << std::endl;
		_hitPoints=+amount;
		_energyPoints--;
	}
	else
		std::cout << /*"ClapTrap " <<*/ _name << " has no energy points to be able to repair itself!" << std::endl;
}


