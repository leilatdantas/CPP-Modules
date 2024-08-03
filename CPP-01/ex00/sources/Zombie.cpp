/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:09:51 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/02 18:10:43 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
}

void	Zombie::announce(void)
{
	std::cout << GREEN << name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string zname)
{
	name = zname;
	std::cout << BLUE << name << RESET << " has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << name << RESET << " has been destroyed" << std::endl;
}
