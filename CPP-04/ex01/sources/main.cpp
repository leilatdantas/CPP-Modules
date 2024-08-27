/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:56:53 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/27 17:34:34 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"	

int main() {
    std::cout << "Creating animal objects..." << std::endl;
    
    // Teste de construção
    Cat cat1;
    Dog dog1;
    std::cout << "\n\n";

    // Teste de métodos
    cat1.makeSound();
    dog1.makeSound();
    std::cout << "\n\n";
    
    // Teste de cópia
    Cat cat2 = cat1;
    Dog dog2 = dog1;
    std::cout << "\n\n";
    
    // Teste de atribuição
    Cat cat3;
    cat3 = cat1;
    std::cout << "\n\n";

    Dog dog3;
    dog3 = dog1;
    std::cout << "\n\n";
    
    // Teste de destruição
    std::cout << "Exiting main..." << std::endl;
    
    return 0;
}