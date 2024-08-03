/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:12:20 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/02 19:22:26 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie default has been created." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << GREEN << name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << BLUE << name << RESET << " has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << name << RESET << " has been destroyed" << std::endl;
}


