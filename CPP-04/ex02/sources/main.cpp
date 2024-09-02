/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:56:53 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/02 14:59:57 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"	

int main()
{
    // const AAnimal test;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;
    return 0;
}