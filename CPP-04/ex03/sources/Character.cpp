/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:49:38 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/29 17:24:04 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
	: name("Default")
{
	for (int i = 0; i <= 3; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name)
	: name(name)
{
	for (int i = 0; i <= 3; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other)
	: name(other.name)
{
	for (int i = 0; i <= 3; i++)
	{
		inventory[i] = NULL;
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
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
				inventory[i] = other.inventory[i]->clone();
		}
		this->name = other.name;
	}
	return *this;
}

Character::~Character()
{
    // Deleta todas as matérias ainda no inventário
    for (int i = 0; i < 4; i++)
    {
		if (inventory[i])
    		delete inventory[i];
		// inventory[i] = NULL;
    }
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i<=3; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;		
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && inventory[idx])
	{
		delete inventory[idx];
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		inventory[idx]->use(target);
	}
}
