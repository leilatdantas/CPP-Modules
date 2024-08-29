/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:45:20 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/29 22:54:00 by lebarbos         ###   ########.fr       */
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

    // // Criando uma fonte de matérias e aprendendo Ice e Cure
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    
    // // Criando um personagem e equipando-o com Ice e Cure
    // ICharacter* me = new Character("me");
    // AMateria* tmp;
    
    // // Equipando Ice
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    
    // // Equipando Cure
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // // Usando as matérias equipadas no personagem bob
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob); // Usando Ice
    // me->use(1, *bob); // Usando Cure

    // // Desequipando a matéria Ice
    // me->unequip(0);
    
    // // Reequipando um novo Ice no mesmo slot
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    
    // // Deletando a matéria Ice que foi desequipada
    // // delete tmp;

    // // Usando as matérias novamente
    // me->use(0, *bob); // Usando o novo Ice
    // me->use(1, *bob); // Usando Cure

    // // Limpando a memória
    // delete bob;
    // delete me;
    // delete src;
    // Creating the MateriaSource and learning Ice and Cure
    std::cout << YELLOW <<  "=== Creating MateriaSource and learning Ice and Cure ===" << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Creating character "me" and equipping the materia
    std::cout << YELLOW << "\n=== Creating character 'me' and equipping with Ice and Cure ===" << RESET << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Creating character "bob" and using the materia from "me"
    std::cout << YELLOW << "\n=== Creating character 'bob' ===" << RESET << std::endl;
    ICharacter* bob = new Character("bob");
    std::cout << YELLOW << "=== Trying to use a materia without equipping 'bob' ===" << RESET << std::endl;
    bob->use(0, *me);
    std::cout << YELLOW << "=== Using the materia from 'me' on 'bob' ===" << RESET << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    // Testing the copy constructor
    std::cout << YELLOW << "\n=== Testing the copy constructor ===" << RESET << std::endl;
    Character* copy = new Character(*dynamic_cast<Character*>(me));
    std::cout << GRAY << "'copy' character created from 'me'." << RESET << std::endl;
    copy->use(0, *bob);
    copy->use(1, *bob);

    // Testing the assignment operator
    std::cout << YELLOW << "\n=== Testing the assignment operator ===" << RESET << std::endl;
    Character* assignment = new Character("assignment");
    *assignment = *dynamic_cast<Character*>(me);
    std::cout << GRAY << "'assignment' character is now a copy of 'me'." <<  RESET << std::endl;
    assignment->use(0, *bob);
    assignment->use(1, *bob);
    assignment->unequip(1);
    assignment->unequip(0);

    // Testing unequip
    std::cout << YELLOW << "\n=== Testing unequip of a materia ===" << RESET << std::endl;
    me->unequip(0);  // Unequip the first materia (Ice)
    me->use(0, *bob);  // Try to use the unequipped materia (should fail silently)
    
    // Memory cleanup
    std::cout << YELLOW << "\n=== Cleaning up memory ===" << RESET << std::endl;
    delete bob;
    delete me;
    delete copy;
    delete assignment;
    delete src;
    
    return 0;
}
