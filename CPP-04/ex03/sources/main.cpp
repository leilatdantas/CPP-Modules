/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:45:20 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/29 17:22:42 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Character.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

int main() 
{
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;

    // Criando uma fonte de matérias e aprendendo Ice e Cure
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Criando um personagem e equipando-o com Ice e Cure
    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    // Equipando Ice
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    // Equipando Cure
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Usando as matérias equipadas no personagem bob
    ICharacter* bob = new Character("bob");
    me->use(0, *bob); // Usando Ice
    me->use(1, *bob); // Usando Cure

    // Desequipando a matéria Ice
    me->unequip(0);
    
    // Reequipando um novo Ice no mesmo slot
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    // Deletando a matéria Ice que foi desequipada
    // delete tmp;

    // Usando as matérias novamente
    me->use(0, *bob); // Usando o novo Ice
    me->use(1, *bob); // Usando Cure

    // Limpando a memória
    delete bob;
    delete me;
    delete src;

	return 0; 
}
