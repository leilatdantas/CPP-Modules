/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:03:17 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/29 14:23:43 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main()
{
	Bureaucrat bob("Bob", 2);
	try
	{
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << " for Bureaucrat " << bob.getName() << '\n';
	}
	std::cout << bob << std::endl;
}