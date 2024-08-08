/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:13:30 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/08 13:48:32 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	Zombie *horde = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return horde;
}