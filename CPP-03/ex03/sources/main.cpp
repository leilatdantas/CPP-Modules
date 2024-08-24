/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:57:26 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/24 19:00:05 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main() 
{
    // DiamondTrap robot("Lika");
    // FragTrap frag("Frag");
    // ScavTrap   scav("Scav");
    // scav.status();
    // frag.status();
    lika->status();
    lika->attack("LALALA");
    lika->status();
    lika->beRepaired(10);
    lika->status();
    lika->takeDamage(20);
    lika->status();
    lika->guardGate();
    lika->whoAmI();
    std::cout << "End of program.\n";
    delete lika;
    return 0;
}