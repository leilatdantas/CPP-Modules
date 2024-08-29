/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:35:55 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/29 21:30:51 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

struct MateriaNode
{
	AMateria* materia;
	MateriaNode* next;
};

class Character : public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	AMateria*			inventory[4];
	MateriaNode*		unequipedList;
	void addUnequipedMateria(AMateria* m);
	void deleteUnequipedMaterias();
	std::string			name;
};

#endif