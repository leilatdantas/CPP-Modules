/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:49:38 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/02 15:42:18 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
	: name("Default")
{
	for (int i = 0; i <= 3; i++)
		inventory[i] = NULL;
	std::cout << "Character constructor called by " << PURPLE << name << RESET << std::endl; 
}

Character::Character(std::string name)
	: name(name)
{
	for (int i = 0; i <= 3; i++)
		inventory[i] = NULL;
	std::cout << "Character constructor called by " << PURPLE << name << RESET << std::endl; 
}

Character::Character(const Character& other)
	: name(other.name)
{
	for (int i = 0; i <= 3; i++)
	{
		inventory[i] = NULL;
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
			inventory[i]->setStatus(true);
		}
	}
	std::cout << PURPLE << name << RESET << " copy constructor." << std::endl; 
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i <= 3; i++)
		{
			if (inventory[i])
				delete inventory[i];
			inventory[i] = NULL;
			if (other.inventory[i])
			{
				inventory[i] = other.inventory[i]->clone();
				inventory[i]->setStatus(true);
			}
		}
		this->name = other.name;
	}
	std::cout << PURPLE << name << RESET << " copy assigment operator." << std::endl; 
	return *this;
}

Character::~Character()
{
	std::cout << "Calling " PURPLE << name << RESET << "'s destructor..." << std::endl; 
    for (int i = 0; i < 4; i++)
    {
		if (inventory[i])
		{
			std::cout << "~ destroying " PURPLE << name <<RESET <<  "'s equiped " << inventory[i]->getType() << ": ";
    		delete inventory[i];
			inventory[i] = NULL;
		}
    }
	std::cout << PURPLE << name << RESET << "'s destructor finished." << std::endl; 
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (m && !m->getStatus())
	{
		for(int i = 0; i<=3; i++)
		{
			if (this->inventory[i] == NULL)
			{
				this->inventory[i] = m;
				m->setStatus(true);
				Floor::removeUnequipedMateria(m);
				std::cout << "~ " << m->getType() << " equiped by " << PURPLE << name << RESET <<  " ~" << std::endl;
				return ;
			}
		}
		std::cout << "~ " << PURPLE << name << RESET <<  " has no space left to equip " << m->getType() << " ~" << std::endl;
		Floor::dropMateria(m);
	}
	else
	{
		std::cout << "~ trying to equip unexistent or unavaliable materia to " << PURPLE << name << RESET <<  " ~" << std::endl; 
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && inventory[idx])
	{
		std::cout << "~ " << inventory[idx]->getType() << " dropped by " << PURPLE << name << RESET <<  " ~" << std::endl; 
		Floor::dropMateria(inventory[idx]);
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
	else 
   		std::cout <<  "~ the materia you are trying to use is " <<  RED << "NOT " <<  RESET << "equiped by " << PURPLE <<  name << RESET << " ~" << std::endl;
}

void	Character::addToName(std::string newName)
{
	this->name = name + newName;
}
