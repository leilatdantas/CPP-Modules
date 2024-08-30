/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:28:47 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/30 15:57:19 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP
#include "Character.hpp"
#include "AMateria.hpp"

struct s_MateriaNode
{
	AMateria* materia;
	s_MateriaNode* next;
};

class Floor
{
public:
	Floor();
	~Floor();
	static	Floor&	getFloor();
	static	void	dropMateria(AMateria* m);
	void			addUnequipedMateria(AMateria* m);
	static void		removeUnequipedMateria(AMateria *m);
private:
	s_MateriaNode*		unequipedList;
};

#endif