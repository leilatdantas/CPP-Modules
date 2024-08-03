/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:57:49 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/03 17:58:00 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	void	setWeapon(Weapon &weapon);
	void	removeWeapon();
	void	attack();
	~HumanB();

private:
	std::string name;
	Weapon* weapon;
};

#endif