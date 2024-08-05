/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:46:25 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/05 20:49:17 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "USAGE: ./filterHarl [LEVEL]" << std::endl;
		return 1;
	}
	Harl h;
	h.complain(argv[1]);
	return 0;
}
