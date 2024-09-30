/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:17:58 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/29 20:22:46 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

int main()
{
	Bureaucrat bob("Bob", 2);
	Form remake("Remake", 120, 100);
	try
	{
		bob.signForm(remake);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}