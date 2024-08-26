/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:44:02 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/26 20:01:07 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <string>
#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	~WrongAnimal();
	void		makeSound() const;
	std::string	getType() const;
protected:
	std::string	type;
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

#endif