/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:57:26 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/19 12:58:06 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main() 
{
    std::cout << "Creating ClapTrap object:" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target Dummy");

    std::cout << "\nCreating FragTrap object:" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Enemy Target");
    frag.highFivesGuys();

    std::cout << "\nTesting copy constructor:" << std::endl;
    FragTrap fragCopy(frag);
    fragCopy.attack("Another Enemy");
    fragCopy.highFivesGuys();

    std::cout << "\nTesting assignment operator:" << std::endl;
    FragTrap fragAssigned = frag;
    fragAssigned.attack("Final Enemy");
    fragAssigned.highFivesGuys();

    std::cout << "\nExiting program (destructors will be called):" << std::endl;

    return 0;
}
