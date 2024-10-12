/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:17:58 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/12 13:56:00 by lebarbos         ###   ########.fr       */
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

void testCopyAssignment()
{
    std::cout << LIGHT_BLUE << "\n\n== Testing Copy Assignment Operator ==" << RESET << std::endl;
    try {
        Form formA("FormA", 50, 100);
        Form formB("FormB", 20, 80);

        std::cout << "Before assignment:" << std::endl;
        std::cout << "Form A: " << formA << std::endl;
        std::cout << "Form B: " << formB << std::endl;

        formB = formA; // Using the copy assignment operator

        std::cout << "After assignment:" << std::endl;
        std::cout << "Form A: " << formA << std::endl;
        std::cout << "Form B (after assignment): " << formB << std::endl;
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
        Form remake("Remake", 50, 100);
        bob.signForm(remake);
		bob.signForm(remake);
        // Additional tests
        testCopyConstructor();
        testCopyAssignment();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
