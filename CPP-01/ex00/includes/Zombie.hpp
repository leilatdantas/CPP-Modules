/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:10:09 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/02 18:06:22 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>

#define ROSE "\033[38;5;217m"
#define ORANGE "\033[38;5;208m"
#define YELLOW "\033[38;5;228m"
#define GREEN "\033[38;5;148m"
#define CYAN "\033[38;5;159m"
#define BLUE "\033[38;5;153m"
#define PURPLE "\033[38;5;177m"
#define WHITE "\033[38;5;231m"
#define RED "\033[38;5;124m"
#define PINK "\033[38;5;198m"
#define RESET "\033[0m"
#define BOLD "\e[1m"

class Zombie
{
public:
	Zombie();
	Zombie(std::string zname);
	void	announce(void);
	~Zombie();

private:
	std::string	name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif