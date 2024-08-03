/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:58:43 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/03 17:56:48 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
	: name(name), weapon(weapon)
{
}

void HumanA::attack()
{
	std::cout << BOLD << ORANGE << name << RESET << " attacks with their " << BOLD << RED << weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA()
{
}
