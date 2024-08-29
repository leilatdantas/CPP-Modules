/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:49:38 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/29 21:37:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
	: name("Default")
{
	for (int i = 0; i <= 3; i++)
		inventory[i] = NULL;
	unequipedList = NULL;
}

Character::Character(std::string name)
	: name(name)
{
	for (int i = 0; i <= 3; i++)
		inventory[i] = NULL;
	unequipedList = NULL;
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
	unequipedList = NULL;
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
	this->unequipedList = NULL;
	return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
		if (inventory[i])
		{
    		delete inventory[i];
			inventory[i] = NULL;
		}
    }
	deleteUnequipedMaterias();
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
		addUnequipedMateria(inventory[idx]);
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

void	Character::addUnequipedMateria(AMateria* m)
{
	MateriaNode	*newNode = new MateriaNode; 
	newNode->materia = m;
	newNode->next = unequipedList;
	unequipedList = newNode;
}
void	Character::deleteUnequipedMaterias()
{
	MateriaNode* tmp = unequipedList;
	while(tmp)
	{
		MateriaNode* next = tmp->next;
		delete tmp->materia;
		delete tmp;
		tmp = next; 
	}
}
