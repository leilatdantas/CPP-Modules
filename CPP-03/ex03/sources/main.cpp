/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:57:26 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/23 14:03:29 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main() 
{
    std::cout << "Creating DiamondTrap object...\n";
    DiamondTrap robot("Lika");
    FragTrap frag("Frag");
    ScavTrap   scav("Scav");

    // robot.attack("LOSER");        // Testa o método attack() da ScavTrap
    // robot.highFivesGuys();
    // robot.guardGate();    // Testa o método guardGate() da ScavTrap
    // robot.whoAmI();       // Testa o método whoAmI() da DiamondTrap
    // std::cout << robot.getName() << std::endl;
    
    scav.status();
    frag.status();
    robot.status();
    robot.attack("LALALA");
    robot.status();
    robot.beRepaired(10);
    robot.status();
    robot.takeDamage(20);
    robot.status();
    robot.guardGate();
    robot.whoAmI();

    std::cout << "End of program.\n";
    return 0;
}