/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:37:46 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/26 17:09:26 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
	: Animal("Cat")
{
	std::cout << PURPLE << "(CAT) " << RESET << "constructor called for " << PURPLE << this->type << RESET << "." << std::endl; 
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << PURPLE << "(CAT) " << RESET << "copy constructor called for " << PURPLE << this->type << "." << std::endl; 
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << PURPLE << "(CAT) " << RESET << "copy constructor called for " << PURPLE << this->type << "." << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << PURPLE << "(CAT) " << RESET << "destructor called for " << PURPLE << this->type << "." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "(CAT) " << RESET << "miau miau" << std::endl;
}

