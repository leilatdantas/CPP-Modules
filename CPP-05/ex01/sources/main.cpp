/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:17:58 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/13 12:30:32 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

#include "../includes/Form.hpp"

void testCopyConstructor()
{
    std::cout << LIGHT_BLUE << "\n\n== Testing Copy Constructor ==" << RESET << std::endl;
    try {
        Form originalForm("Original", 50, 100);
        std::cout << originalForm << std::endl;

        Form copiedForm(originalForm); // Using the copy constructor
        std::cout << copiedForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    try
    {
   		std::cout << LIGHT_BLUE << "\n\n== Initial tests ==" << RESET << std::endl;
        Bureaucrat bob("Bob", 10);
        Form remake("Remake", 20, 100);
        std::cout << remake << std::endl;
        bob.signForm(remake);
		bob.signForm(remake);
        std::cout << remake << std::endl;
        std::cout << bob << std::endl;
        // testCopyConstructor();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
