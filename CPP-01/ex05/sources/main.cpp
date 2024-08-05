/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:06:40 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/05 19:27:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main()
{
	Harl h;

	std::cout << std::endl;
	std::cout <<  "DEBUG:" << std::endl;
    h.complain("DEBUG");
	std::cout <<  "INFO:" << std::endl;
    h.complain("INFO");
	std::cout <<  "WARNING:" << std::endl;
    h.complain("WARNING");
	std::cout <<  "ERROR:" << std::endl;
    h.complain("ERROR");
	std::cout <<  "UNKNOWN:" << std::endl;
    h.complain("UNKNOWN");
	std::cout << std::endl;
	return 0;
}
