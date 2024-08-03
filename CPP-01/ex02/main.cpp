/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:08:31 by lebarbos          #+#    #+#             */
/*   Updated: 2024/08/03 15:41:35 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define ROSE "\033[38;5;217m"
#define ORANGE "\033[38;5;208m"
#define YELLOW "\033[38;5;228m"
#define GREEN "\033[38;5;148m"
#define CYAN "\033[38;5;159m"
#define BLUE "\033[38;5;153m"
#define PURPLE "\033[38;5;177m"
#define WHITE "\033[38;5;231m"
#define RED "\033[38;5;124m"
#define PINK "\033[38;5;198m"
#define RESET "\033[0m"
#define BOLD "\e[1m"

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << BOLD << RED << "The memory address of the string variable: " << RESET << &str << std::endl;
	std::cout << BOLD << RED << "The memory address held by stringPTR: " << RESET << stringPTR << std::endl;
	std::cout << BOLD << RED << "The memory address held by stringREF: " << RESET << &stringREF << std::endl;
	std::cout << BOLD << ORANGE << "The value of the string variable: " << RESET << str << std::endl;
	std::cout << BOLD << ORANGE << "The value pointed to by stringPTR: " << RESET << *stringPTR << std::endl;
	std::cout << BOLD << ORANGE << "The value pointed to by stringREF: " << RESET << stringREF << std::endl;
	return 0;
}
