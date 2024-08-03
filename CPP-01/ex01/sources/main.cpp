/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:13:47 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/02 19:07:50 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
	Zombie *horde = zombieHorde(10, "Casca de bala");
	if (horde)
	{
		for(int i = 0; i < 10; i++)
			horde[i].announce();
		delete[] horde;	
	}
	else
		std::cout << "Memory allocation fail." << std::endl;
	return 0;
}
