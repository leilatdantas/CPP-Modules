/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:56:53 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/28 14:59:35 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"	

int main()
{
    // const AAnimal* animal = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return 0;
}