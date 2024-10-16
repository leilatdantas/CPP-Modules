/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:28:19 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/30 18:03:58 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i <= 3; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for(int i = 0; i <= 3; i++)
	{
		this->materias[i] = NULL;
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for(int i = 0; i <= 3; i++)
		{
			if (materias[i])
				delete materias[i];
			materias[i] = NULL;
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
		{
			delete materias[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] == NULL)
		{
			materias[i] = m;
			std::cout << "~ the ability of " << PINK << m->getType() << RESET << " has been learned ~" << std::endl;
			return ;
		}
	}
	std::cout  << "~ there is no space left to learn " <<  m->getType() << " ~" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
		{
			std::cout << "~ " << PINK << type << RESET << " materia creation ~" << std::endl;
			return materias[i]->clone();
		}
	}
	std::cout << "~ there's no  materia named " << PINK << type << RESET  << " ~" << std::endl;
	return NULL;
}

