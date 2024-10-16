/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:09:25 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/02 15:19:27 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>
#include <iostream>

class AMateria
{
protected:
	std::string type;
	bool		taken;

public:
	AMateria(std::string const & type);
	
	AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();
	
	std::string const & getType() const;
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	
	bool const & getStatus() const;
	void		setStatus(bool status);

};

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
#define GRAY "\033[38;5;245m"

#endif