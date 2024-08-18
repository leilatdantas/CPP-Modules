/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:58:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/18 14:00:14 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main() {
    // Criando um objeto ClapTrap
    ClapTrap clap("Clappy");

    // Testando o ataque de ClapTrap
    clap.attack("Target Dummy");

    // Criando um objeto ScavTrap
    ScavTrap scav("Scavvy");

    // Testando o ataque de ScavTrap
    scav.attack("Target Dummy");

    // Testando a função especial de ScavTrap
    scav.guardGate();

    // Testando a cópia de ScavTrap
    ScavTrap scavCopy(scav);
    scavCopy.attack("Another Target");

    // Testando o operador de atribuição
    ScavTrap scavAssigned = scav;
    scavAssigned.attack("Final Target");

    // Finalizando o programa (destrutores serão chamados)
    return 0;
}

