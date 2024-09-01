/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:45:20 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/01 18:12:03 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Floor.hpp"
#include "../includes/Character.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

void    subjectTests()
{
	std::cout << "**********************************************************************" << std::endl;
	std::cout << "*************************" << BOLD << PURPLE << " SUBJECT TESTS " << RESET << "******************************" << std::endl;
	std::cout << "**********************************************************************\n" << std::endl;
	
    IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void    myTests()
{
	std::cout << "\n**********************************************************************" << std::endl;
	std::cout << "*****************************" << BOLD << PURPLE << " MY TESTS " << RESET << "*******************************" << std::endl;
	std::cout << "**********************************************************************\n" << std::endl;
    // Creating the MateriaSource and learning Ice and Cure
    std::cout << YELLOW <<  "=== Creating MateriaSource and learning Ice and Cure ===" << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Creating character "me" and equipping the materia
    std::cout << YELLOW << "\n=== Creating character 'me' and equipping with Ice and Cure ===" << RESET << std::endl;
    Character* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Creating character "bob" and using the materia from "me"
    std::cout << YELLOW << "\n=== Creating character 'bob' ===" << RESET << std::endl;
    ICharacter* bob = new Character("bob");
    bob->equip(tmp);
    std::cout << YELLOW << "=== Trying to use a materia without equipping 'bob' ===" << RESET << std::endl;
    bob->use(1, *me);
    std::cout << YELLOW << "=== Using the materia from 'me' on 'bob' ===" << RESET << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    // Testing the copy constructor
    std::cout << YELLOW << "\n=== Testing the copy constructor ===" << RESET << std::endl;
    Character* copy = new Character(*me);
    std::cout << GRAY << "'copy' character created from 'me'." << RESET << std::endl;
    copy->use(0, *bob);
    copy->use(1, *bob);
    copy->unequip(0);
    copy->unequip(1);

    // Testing the assignment operator
    std::cout << YELLOW << "\n=== Testing the assignment operator ===" << RESET << std::endl;
    Character* assignment = new Character("assignment");
    *assignment = *me;
    std::cout << GRAY << "'assignment' character is now a copy of 'me'." <<  RESET << std::endl;
    assignment->use(0, *bob);
    assignment->use(1, *bob);
    assignment->unequip(1);
    assignment->unequip(0);
    assignment->use(0, *bob);

    // Testing unequip
    std::cout << YELLOW << "\n=== Testing unequip of a materia ===" << RESET << std::endl;
    me->unequip(0);  // Unequip the first materia (Ice)
    me->use(0, *bob);  // Try to use the unequipped materia (should fail)
    
    // memory cleanup
    std::cout << YELLOW << "\n=== Cleaning up memory ===" << RESET << std::endl;
    delete bob;
    delete me;
    delete copy;
    delete assignment;
    delete src;
}

int main() 
{

    // subjectTests();

    AMateria *c1 = new Cure();
    AMateria *i1 = new Ice();
    ICharacter *bob = new Character("bob");
    std::cout << i1->getType() << std::endl;
    i1->use(*bob);
    *i1 = *c1;
    std::cout << i1->getType() << std::endl;
    i1->use(*bob);
    delete c1;
    delete i1;
    // myTests();
    return 0;
}
