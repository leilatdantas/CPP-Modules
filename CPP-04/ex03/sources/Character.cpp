/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:49:38 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/28 17:42:39 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
	: name("Default")
{
}

Character::Character(std::string name)
	: name(name)
{
	
}

Character::Character(const Character& other)
	: name(other.name)
{
	AMateria* inventory[4];
	for (int i = 0; i <= 3; i++)
		inventory[i] = other.inventory[i];
	this->inventory[4] = *inventory;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		AMateria* inventory[4];
		for (int i = 0; i <= 3; i++)
			inventory[i] = other.inventory[i];
		this->inventory[4] = *inventory;
		this->name = other.name;
	}
	return *this;
}

Character::~Character()
{
	delete[] this->inventory;
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i++; i<=3)
	{
		if (this->inventory[i] == NULL)
			this->inventory[i] = m;
	}
}

void Character::unequip(int idx)
{
	for(int i = 0; i++; i<=3)
	{
		if (i == idx)
			this->inventory[i] == NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	inventory[idx]->use(target);
}
