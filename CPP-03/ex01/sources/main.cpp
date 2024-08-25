/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:58:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/25 15:17:06 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main() 
{
    // Creating a ScavTrap object
    ScavTrap scav("Scavvy");
    // scav.status();
    // Testing ScavTrap's attack
    scav.attack("Target Dummy");
    // Testing ClapTrap's takeDamage and beRepaired method in a ScavTrap
    scav.takeDamage(40);
    // scav.status();
    scav.beRepaired(10);
    // scav.status();
    // Testing ScavTrap's special function
    scav.guardGate();
    return 0;
}

