/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:48:07 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/05 19:17:40 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*p[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	while (i <= 3)
	{
		if (level == levels[i] && i < 4)
		{
			(this->*p[i])();
 			return ;
		}
		i++;
	}
	if (i == 4)
		std::cout << PURPLE << "Now I'm just complaining about insignificant stuff, sorry." << RESET << std::endl;
}

void	Harl::debug(void)
{
	std::cout << PINK << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << BLUE << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << ORANGE << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << RESET << std::endl;
}
void	Harl::error(void)
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}
