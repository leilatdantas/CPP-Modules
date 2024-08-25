/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:57:26 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/25 15:25:09 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main() 
{
    DiamondTrap lika("Lika");
    lika.status();
    lika.whoAmI();
    lika.attack("Ugly Target");
    // lika.status();
    // lika.beRepaired(10);
    // lika.status();
    // lika.takeDamage(20);
    // lika.status();
    // lika.guardGate();
    return 0;
}