/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:55:38 by lebarbos          #+#    #+#             */
/*   Updated: 2025/09/24 11:02:35 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <value>" << std::endl;
		return 1;
	}
	
	try {
		ScalarConverter::convert(argv[1]);
	} catch (const std::exception& e) {
		std::cout << "Error: invalid input" << std::endl;
	}
	
	return 0;
}