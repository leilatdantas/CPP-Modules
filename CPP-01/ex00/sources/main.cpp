/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:45:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/08 13:43:38 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void testingNewZombie(Zombie *zombie)
{
	randomChump("CaFoo");
	zombie->announce();
}

int main(void)
{
	Zombie foo("Foo");
	foo.announce();
	Zombie *casco = newZombie("Casco");
	testingNewZombie(casco);
	delete(casco);
}
