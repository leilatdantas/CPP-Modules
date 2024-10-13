/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:03:17 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 11:32:55 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void testBureaucratCreation()
{

}

void testBureaucratOperations(Bureaucrat& bob, Bureaucrat& alice)
{
	try
	{
		bob.incrementGrade();
		std::cout << bob << std::endl;

		/* Uncomment to catch an exception on increment: */
		// bob.incrementGrade();
		// std::cout << bob << std::endl;

		bob.decrementGrade();
		std::cout << bob << std::endl;

		bob.decrementGrade();
		std::cout << bob << std::endl;

		alice.incrementGrade();
		std::cout << alice << std::endl;

		alice.decrementGrade();
		std::cout << alice << std::endl;

		/* Uncomment to catch an exception on decrement: */
		// alice.decrementGrade();
		// std::cout << alice << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught for decrement/increment: " << e.what() << std::endl;
	}
}

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;

		testBureaucratOperations(bob, alice);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught for creation: " << e.what() << std::endl;
	}
}