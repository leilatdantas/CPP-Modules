/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:58:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/19 12:42:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main() 
{
    // Creating a ClapTrap object
    ClapTrap clap("Clappy");

    // Testing ClapTrap's attack
    clap.attack("Target Dummy");

    // Creating a ScavTrap object
    ScavTrap scav("Scavvy");

    // Testing ScavTrap's attack
    scav.attack("Target Dummy");

    // Testing ScavTrap's special function
    scav.guardGate();
    return 0;
}

