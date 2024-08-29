/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:49:38 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/29 23:22:29 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
	: name("Default")
{
	for (int i = 0; i <= 3; i++)
		inventory[i] = NULL;
	unequipedList = NULL;
	std::cout << PURPLE << name << RESET << " constructor." << std::endl; 
}

Character::Character(std::string name)
	: name(name)
{
	for (int i = 0; i <= 3; i++)
		inventory[i] = NULL;
	unequipedList = NULL;
	std::cout << PURPLE << name << RESET << " constructor." << std::endl; 
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
				inventory[i] = other.inventory[i]->clone();
		}
		this->name = other.name;
	}
	this->unequipedList = NULL;
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
	deleteUnequipedMaterias();
	std::cout << PURPLE << name << RESET << "'s destructor finished." << std::endl; 
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for(int i = 0; i<=3; i++)
		{
			if (this->inventory[i] == NULL)
			{
				this->inventory[i] = m;
				std::cout << "~ " << m->getType() << " equiped by " << PURPLE << name << RESET <<  " ~" << std::endl; 
				return ;		
			}
		}
	}
	else
		std::cout << "~ trying to equip unexistent materia to " << PURPLE << name << RESET <<  " ~" << std::endl; 

}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && inventory[idx])
	{
		addUnequipedMateria(inventory[idx]);
		std::cout << "~ " << inventory[idx]->getType() << " dropped by " << PURPLE << name << RESET <<  " ~" << std::endl; 
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		inventory[idx]->use(target);
	}
	else 
   		std::cout <<  "~ the materia you are trying to use is " <<  RED << "NOT " <<  RESET << "equiped by " << PURPLE <<  name << RESET << " ~" << std::endl;
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
		std::cout << "~ destroying " PURPLE << name <<RESET <<  "'s dropped " << tmp->materia->getType() << ": ";
		MateriaNode* next = tmp->next;
		delete tmp->materia;
		delete tmp;
		tmp = next; 
	}
}
