/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:13:41 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/03 17:52:02 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main() 
{
	std::cout << "**********************************************************************" << std::endl;
	std::cout << "*************************" << BOLD << PURPLE << " SUBJECT TESTS " << RESET << "******************************" << std::endl;
	std::cout << "**********************************************************************\n" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	std::cout << "\n**********************************************************************" << std::endl;
	std::cout << "*****************************" << BOLD << PURPLE << " MY TESTS " << RESET << "*******************************" << std::endl;
	std::cout << "**********************************************************************\n" << std::endl;
	{
		Weapon	littleKnife = Weapon("little knife");
		Weapon	littleGun = Weapon(".38");

		HumanA lika("Lika", littleKnife);
		lika.attack();
		HumanA bilu("Bilu", littleGun);
		bilu.attack();
		std::cout << std::endl;
	}
	{		
		Weapon	littleKnife = Weapon("little knife");
		Weapon	littleGun = Weapon(".38");

		HumanB lika("Lika");
		lika.attack();
		lika.setWeapon(littleKnife);
		lika.attack();
		lika.setWeapon(littleGun);
		lika.attack();
		littleGun.setType("water gun");
		lika.attack();
		HumanB bilu("Bilu");
		bilu.setWeapon(littleGun);
		bilu.attack();
		bilu.removeWeapon();
		bilu.attack();
	}

}

