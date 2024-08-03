/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:12:02 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/02 19:20:50 by lebarbos         ###   ########.fr       */
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
	Zombie(std::string name);
	void	announce(void);
	void	setName(std::string name);
	~Zombie();

private:
	std::string	name;
};

Zombie*    zombieHorde( int N, std::string name );

#endif