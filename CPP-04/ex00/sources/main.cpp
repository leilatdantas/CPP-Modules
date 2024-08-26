/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:56:53 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/26 20:01:18 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"	

int main()
{
	const WrongAnimal* meta = new WrongAnimal();
	meta->makeSound();
	// const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	// j->makeSound();
	delete meta;
	// delete j;
	delete i;
	return 0;
}