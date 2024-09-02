/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:56:53 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/02 13:12:09 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"	

void	subjectTests()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

void	myTests()
{
    std::cout << YELLOW << "=== Copy Constructor Tests ===" << RESET << std::endl;
    Dog originalDog;
    Cat originalCat;
    std::cout << YELLOW << "=== CopiedDog ===" << RESET << std::endl;
    Dog copiedDog(originalDog);
    copiedDog.makeSound(); 
	std::cout << YELLOW << "=== CopiedCat ===" << RESET << std::endl;
    Cat copiedCat(originalCat);
    copiedCat.makeSound(); 

    std::cout << YELLOW << "\n=== Copy Assignment Operator Tests ===" << RESET << std::endl;
    Dog anotherDog;
    Cat anotherCat;
    std::cout << YELLOW << "=== Copy Assignment - AnotherDog ===" << RESET << std::endl;
    anotherDog = originalDog; 
    anotherDog.makeSound(); 
    std::cout << YELLOW << "=== Copy Assignment - AnotherCat ===" << RESET << std::endl;
    anotherCat = originalCat; 
    anotherCat.makeSound(); 
    std::cout << YELLOW << "\n=== Deleting Copied Animals ===" << RESET << std::endl;
}


void	wrongAnimalTests()
{
	WrongAnimal *wanimal = new WrongAnimal();
	WrongAnimal	*wcat = new WrongCat();
	WrongCat	*wwcat = new WrongCat();
	
    std::cout << YELLOW << "=== Wrong Animal Making sound ===" << RESET << std::endl;
	wanimal->makeSound();
    std::cout << YELLOW << "=== Wrong Cat created as a WrongAnimal trying to make sound ===" << RESET << std::endl;
	wcat->makeSound();
    std::cout << YELLOW << "=== Wrong Cat making sound ===" << RESET << std::endl;
	wwcat->makeSound();

    std::cout << YELLOW << "=== Deleting Wrong Animal ===" << RESET << std::endl;
	delete wanimal;
    std::cout << YELLOW << "=== Deleting Wrong Animal-Cat ===" << RESET << std::endl;
	delete wcat;
    std::cout << YELLOW << "=== Deleting Wrong Cat ===" << RESET << std::endl;
	delete wwcat;
}

void	newTests()
{
	Animal*	dog = new Dog();
	Animal* cat = new Cat();
    std::cout << YELLOW << "=== Before \"=\" operator ===" << RESET << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	*dog = *cat;
    std::cout << YELLOW << "=== After \"=\" operator ===" << RESET << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;
}

int main()
{
	subjectTests();
	// wrongAnimalTests();
	// myTests();
	// newTests();
}