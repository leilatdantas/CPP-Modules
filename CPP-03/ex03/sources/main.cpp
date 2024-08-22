/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:57:26 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/22 12:15:02 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main() 
{
    std::cout << "Creating DiamondTrap object...\n";
    DiamondTrap robot("Lika");
    FragTrap frag("Frag");
    ScavTrap   svav("Scav");

    // robot.attack("LOSER");        // Testa o método attack() da ScavTrap
    // robot.highFivesGuys();
    // robot.guardGate();    // Testa o método guardGate() da ScavTrap
    // robot.whoAmI();       // Testa o método whoAmI() da DiamondTrap
    // std::cout << robot.getName() << std::endl;
    
    robot.status();
    robot.attack("opa");
    robot.whoAmI();
    frag.status();
    svav.status();
    std::cout << "End of program.\n";
    return 0;
}