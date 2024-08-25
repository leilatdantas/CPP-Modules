/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:28:45 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/25 13:00:38 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << PINK << "(CLAPTRAP) " << RESET << "constructor has been called for " << PINK << "default." << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << PINK << "(CLAPTRAP) " << RESET << "constructor has been called for " << PINK << _name << RESET << std::endl;
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
	std::cout << PINK << "(CLAPTRAP) " << RESET << "destructor has been called for " << PINK << _name << RESET << std::endl;

}

void	ClapTrap::attack(const std::string target)
{
	if (_hitPoints == 0)
		std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " is dead. It can't attack "<< target << std::endl;
	else if (_energyPoints == 0)
		std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " has no energy points to atack " << target << std::endl;
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
		std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints = _hitPoints - amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
	}
	else
		std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " has no hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " is repaired for " << amount << " points!" << std::endl;
		_hitPoints= _hitPoints + amount;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " is dead and is not able to repair itself!" << std::endl;
	else
		std::cout << PINK << "(CLAPTRAP) " << RESET << _name << " has no energy points to be able to repair itself!" << std::endl;
}


int				ClapTrap::getHitPoints(void)
{
	return _hitPoints;
}

int				ClapTrap::getEnergyPoints(void)
{
	return _energyPoints;
}

int				ClapTrap::getAttackDamage(void)
{
	return _attackDamage;
}

std::string		ClapTrap::getName()
{
	return _name;
}

void	ClapTrap::status()
{
	std::cout << "name: " << getName() << std::endl;
	std::cout << "hit points: " << _hitPoints << std::endl;
	std::cout << "energy points: " << _energyPoints << std::endl;
	std::cout << "damage points: " << _attackDamage << std::endl;
}
