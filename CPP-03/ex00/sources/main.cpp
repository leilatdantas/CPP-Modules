/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:16:02 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/25 12:44:35 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main() {
    ClapTrap claptrap("CT-01");

    claptrap.attack("Target");  // Ataque ao alvo
    claptrap.status();
    claptrap.takeDamage(100);  // Receber dano
    claptrap.beRepaired(5);  // Reparo
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.takeDamage(100);  // Receber dano
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.attack("target");  // Outro ataque ao alvo
    claptrap.status();

    return 0;
}
