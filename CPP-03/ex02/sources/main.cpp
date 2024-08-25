/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:57:26 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/25 15:06:24 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main() 
{
    ClapTrap clap("Clappy");
    clap.attack("Target Dummy");
    FragTrap frag("Fraggy");
    frag.attack("Enemy Target");
    frag.highFivesGuys();
    FragTrap fragCopy(frag);
    fragCopy.attack("Another Enemy");
    fragCopy.highFivesGuys();
    FragTrap fragAssigned = frag;
    fragAssigned.attack("Final Enemy");
    fragAssigned.highFivesGuys();
    fragAssigned.setHitPoints(10);
    fragAssigned.beRepaired(10);
    fragAssigned.status();
    return 0;
}
