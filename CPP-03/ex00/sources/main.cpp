/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:16:02 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/25 14:51:46 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main() {
    ClapTrap claptrap("CT-01");
    claptrap.attack("Target");  // Attack the target
    claptrap.status();
    claptrap.takeDamage(2);  // Take damage
    claptrap.beRepaired(5);  // Repair
    claptrap.attack("Target");  // Another attack on the target
    claptrap.attack("Target");  // Another attack on the target
    claptrap.attack("Target");  // Another attack on the target
    claptrap.attack("Target");  // Another attack on the target
    claptrap.attack("Target");  // Another attack on the target
    claptrap.status();

    return 0;
}
