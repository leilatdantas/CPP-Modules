/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:56:53 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/03 16:28:28 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"	

void    anotherTests()
{
    std::cout << YELLOW << "\n\n=== Creating animal objects ===" << RESET << std::endl;
    Cat cat1;
    Dog dog1;

    std::cout << YELLOW << "\n\n=== Modifying brain thoughts ===" << RESET << std::endl;
    cat1.setBrainThought(0, "I want to chase mice");
    dog1.setBrainThought(0, "I want to chase cats");

    std::cout << "cat1 thoughts:" << std::endl;
    cat1.printBrainThoughts();
    std::cout << "dog1 thoughts:" << std::endl;
    dog1.printBrainThoughts();
    std::cout << "\n\n";

    std::cout << YELLOW << "=== Copy tests: ===" << RESET << std::endl;
    Cat cat2 = cat1; // Construtor de cópia
    Dog dog2 = dog1; // Construtor de cópia

    std::cout << "cat2 thoughts (copied from cat1):" << std::endl;
    cat2.printBrainThoughts();
    std::cout << "dog2 thoughts (copied from dog1):" << std::endl;
    dog2.printBrainThoughts();
    std::cout << "\n\n";

    std::cout << YELLOW << "=== Assignment tests: ===" << RESET << std::endl;
    Cat cat3;
    cat3 = cat1; // Operador de atribuição
    Dog dog3;
    dog3 = dog1; // Operador de atribuição

    std::cout << "cat3 thoughts (assigned from cat1):" << std::endl;
    cat3.printBrainThoughts();
    std::cout << "dog3 thoughts (assigned from dog1):" << std::endl;
    dog3.printBrainThoughts();
    std::cout << "\n\n";

    std::cout << YELLOW << "=== Exiting: ===" << RESET << std::endl;
}

void    myTests()
{
    std::cout << YELLOW << "\n\n=== Creating animal objects ===" << RESET << std::endl;
    Cat cat1;
    Dog dog1;
    std::cout << "\n\n";

    std::cout << YELLOW << "=== Making sounds: ===" << RESET << std::endl;
    cat1.makeSound();
    dog1.makeSound();
    std::cout << "\n\n";
    
    
    std::cout << YELLOW << "=== Copy tests: ===" << RESET << std::endl;
    Cat cat2 = cat1;
    Dog dog2 = dog1;
    std::cout << "\n\n";
    
    std::cout << YELLOW << "=== Assignment tests: ===" << RESET << std::endl;
    Cat cat3;
    cat3 = cat1;
    std::cout << "\n\n";
    Dog dog3;
    dog3 = dog1;
    std::cout << "\n\n";
    
    std::cout << YELLOW << "=== Exiting: ===" << RESET << std::endl;
}

int main() 
{
    myTests();
    // anotherTests();
    return 0;
}