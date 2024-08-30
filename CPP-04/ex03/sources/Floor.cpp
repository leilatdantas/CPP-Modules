/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:33:03 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/30 16:23:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Floor.hpp"

Floor::Floor()
{
	std::cout << ORANGE << "~ a floor has been created to collect the dropped materials ~ " << RESET << std::endl;
	
}

Floor::~Floor()
{
	s_MateriaNode* tmp = unequipedList;
	while(tmp)
	{
		s_MateriaNode* next = tmp->next;
		if (tmp)
		{
			if (tmp->materia)
			{
				std::cout << "~ destroying dropped " << tmp->materia->getType() << ": ";
				delete tmp->materia;
				tmp->materia = NULL;
			}
		}
		delete tmp;
		tmp = next; 
	}
}

Floor&	Floor::getFloor()
{
	static Floor floor;
	return floor;
}

void	Floor::dropMateria(AMateria* m)
{
	getFloor().addUnequipedMateria(m);
}

void	Floor::addUnequipedMateria(AMateria* m)
{
	s_MateriaNode	*newNode = new s_MateriaNode; 
	newNode->materia = m;
	m->setStatus(false);
	newNode->next = unequipedList;
	unequipedList = newNode;
}

void Floor::removeUnequipedMateria(AMateria* m)
{
	s_MateriaNode* current = getFloor().unequipedList;
	s_MateriaNode* previous = NULL;

	while (current != NULL)
	{
		if (current->materia == m)
		{
			if (previous == NULL)
				getFloor().unequipedList = current->next;
			else
				previous->next = current->next;
			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}
}

