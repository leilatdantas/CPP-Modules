/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:14:37 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/22 12:18:34 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "(SCAVTRAP) " << RESET << "Default has been created." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "(SCAVTRAP) " << RESET << _name << " created." << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	_name = other._name;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREEN << "(SCAVTRAP) " << RESET << _name << " destroyed." << std::endl;
}

void	ScavTrap::attack(const std::string target)
{
	if (_hitPoints == 0)
		std::cout << GREEN << "(SCAVTRAP) " << RESET << _name << " is dead. It can't do anything to " << target << std::endl;
	else if (_energyPoints == 0)
		std::cout << "(SCAVTRAP)" << _name << "has no energy points left to attack." << std::endl;
	else
	{
		std::cout << GREEN << "(SCAVTRAP) " << RESET << _name << " just attacked " << target << " and caused a damage of " << _attackDamage << " points of damage!" << std::endl; 
		_energyPoints--;
	}

}

void	ScavTrap::guardGate()
{
	std::cout << GREEN << "(SCAVTRAP) " << RESET << _name << " is now in Gate keeper mode." << std::endl; 
}


void	ScavTrap::status()
{
	std::cout << "name: " << this->_name << std::endl;
	std::cout << "hit points: " << this->_hitPoints << std::endl;
	std::cout << "energy points: " << this->_energyPoints << std::endl;
	std::cout << "damage points: " << this->_attackDamage << std::endl;
}

int		ScavTrap::getHitPoints()
{
	return _hitPoints;
}

int		ScavTrap::getEnergyPoints()
{
	return _energyPoints;
}

int		ScavTrap::getAttackDamage()
{
	return _attackDamage;
}