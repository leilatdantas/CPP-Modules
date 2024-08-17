/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:16:02 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/17 18:19:02 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main() {
    ClapTrap claptrap("CT-01");
    // ClapTrap target("Target A", 50);

    // claptrap.showStatus();  // Mostrar status inicial
    // target.showStatus();    // Mostrar status inicial do alvo

    claptrap.attack("Target");  // Ataque ao alvo
    // target.showStatus();    // Mostrar status do alvo após o ataque

    claptrap.takeDamage(3);  // Receber dano
    claptrap.beRepaired(5);  // Reparo

    claptrap.attack("target");  // Outro ataque ao alvo
    // target.showStatus();    // Mostrar status do alvo após o ataque

    // claptrap.showStatus();  // Mostrar status final do ClapTrap

    return 0;
}
