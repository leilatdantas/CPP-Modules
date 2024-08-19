/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:13:13 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/19 12:37:04 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include <iostream> 
#include <string> 
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public: 
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
	void	attack(const std::string target); // override attack from base class 
	void	guardGate();
};

#endif