/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:03:17 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/12 14:39:50 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;

		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;
		// try {
		// 	bob.incrementGrade();
		// 	std::cout << bob << std::endl;
			
		// 	// bob.incrementGrade();
		// 	// std::cout << bob << std::endl;

		// 	bob.decrementGrade();
		// 	std::cout << bob << std::endl;

		// 	bob.decrementGrade();
		// 	std::cout << bob << std::endl;

		// 	bob.incrementGrade();
		// 	std::cout << bob << std::endl;
			
		// 	alice.incrementGrade();
		// 	std::cout << alice << std::endl;
			
		// 	alice.decrementGrade();
		// 	std::cout << alice << std::endl;

		// 	alice.decrementGrade();
		// 	std::cout << alice << std::endl;
			
		// } catch (std::exception& e){
		// 	std::cerr << "Exception caught for decrement/increment: " << e.what() <<  std::endl;
		// }
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught for creation: " << e.what() <<  std::endl;
	}
}