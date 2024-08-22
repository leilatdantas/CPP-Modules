/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:39:52 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/22 12:16:11 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ClapTrap, public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();
	void	attack(const std::string target);
	void	whoAmI();
	void	status();
	int		getHitPoints();
	int		getEnergyPoints();
	int		getAttackDamage();
private:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif