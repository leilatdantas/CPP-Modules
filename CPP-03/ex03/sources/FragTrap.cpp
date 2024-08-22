/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:17:07 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/22 18:49:19 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << BLUE << "(FRAGTRAP) " << RESET << "constructor has been called for " << BLUE << "Default." << RESET << std::endl;


}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{

	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << BLUE << "(FRAGTRAP) " << RESET << "constructor has been called for " << BLUE << _name << RESET << std::endl;

}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	_name = other._name;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->ClapTrap::operator=(other);
		_name = other._name;

	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << "(FRAGTRAP) " << RESET << "destructor has been called for " << BLUE << _name << RESET << std::endl;

}

void	FragTrap::highFivesGuys(void)
{
	std::cout << BLUE "(FRAGTRAP) " << RESET << _name <<  ": High fives, guys!" << std::endl;
}

void	FragTrap::attack(const std::string target)
{
	if (_hitPoints == 0)
		std::cout << BLUE << "(FRAGTRAP) "  << RESET << _name << "is dead. It can't do anything!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << BLUE << "(FRAGTRAP) "  << RESET << _name << "has no energy points to atack " << target << std::endl;
	else
	{
		_energyPoints--;
		std::cout << BLUE << "(FRAGTRAP) " << RESET << _name <<  " just attacked really bad " << target << " causing a demage of " << _attackDamage << std::endl;
	}
}


void	FragTrap::status()
{
	std::cout << "name: " << this->_name << std::endl;
	std::cout << "hit points: " << this->_hitPoints << std::endl;
	std::cout << "energy points: " << this->_energyPoints << std::endl;
	std::cout << "damage points: " << this->_attackDamage << std::endl;
}

